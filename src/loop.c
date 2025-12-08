/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "need4stek.h"

int main_loop(void)
{
    char **out = send_read_cmd(START_SIM, NULL);
    float angle = 0;

    send_read_cmd(CAR_FORWARD, BASE_SPEED);
    while (out[0] == NULL || out[0][0] == '\n' || out[0][0] == '1') {
        out = send_read_cmd(GET_INFO_LIDAR, NULL);
        out = send_read_cmd(GET_INFO_LIDAR, NULL);
        if (atof(out[19]) < 1500 && atof(out[19]) > 1000)
            send_read_cmd(CAR_FORWARD, SLOW_SPEED);
        if (atof(out[19]) < 1000)
            send_read_cmd(CAR_FORWARD, TURNING_SPEED);
        if (atof(out[19]) < 1500)
            set_direction(out, angle);
        if (atof(out[19]) > 1500) {
            angle = 0;
            send_read_cmd(WHEELS_DIR, "0");
            send_read_cmd(CAR_FORWARD, BASE_SPEED);
        }
    }
    printf("SIMULATION_ENDED\n");
    return (1);
}


