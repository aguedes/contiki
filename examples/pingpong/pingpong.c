#include <stdio.h>
#include <stdbool.h>

#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"
#include "simple-udp.h"

#define PORT 1234
#define TIMEOUT (3 * CLOCK_SECOND)

PROCESS(pingpong_process, "Pingpong process");
AUTOSTART_PROCESSES(&pingpong_process);

static bool has_token = false;
static bool init = true;

static struct simple_udp_connection conn;
static struct ctimer timer;

static void send_token(void)
{
    uip_ipaddr_t addr;

    leds_off(LEDS_GREEN);

    uip_create_linklocal_allnodes_mcast(&addr);
    simple_udp_sendto(&conn, "T", 1, &addr);

    has_token = false;

    printf("token has been sent\n");
}

static void on_timeout(void *data)
{
    printf("timeout has expired\n");

    send_token();
}

static void on_packet(struct simple_udp_connection *c,
                        const uip_ipaddr_t *sender_addr, uint16_t sender_port,
                        const uip_ipaddr_t *receiver_addr,
                        uint16_t receiver_port, const uint8_t *data,
                        uint16_t datalen)
{
    printf("token has been received\n");

    has_token = true;
    leds_on(LEDS_GREEN);
    ctimer_set(&timer, TIMEOUT, on_timeout, NULL);
}

PROCESS_THREAD(pingpong_process, ev, data)
{
    int res;

    PROCESS_BEGIN();

    leds_blink();

    SENSORS_ACTIVATE(button_sensor);

    res = simple_udp_register(&conn, PORT, NULL, PORT, on_packet);
    if (res == 0) {
        printf("Failed register connection\n");
        // What is the right way to bail out in a contiki program?
    }

    while (1) {
        PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data == &button_sensor);

        printf("button has been pressed\n");

        if (!has_token && !init)
            continue;

        init = false;

        ctimer_stop(&timer);
        send_token();
    }

    PROCESS_END();
}
