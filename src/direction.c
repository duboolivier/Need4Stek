/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "need4stek.h"

void set_direction(char **out, float angle)
{
    char *ang_str[4];
    float moy_mid = (atof(out[18]) + atof(out[19]) + atof(out[20])) / 3;
    float moy_left = (atof(out[3]) + atof(out[6]) + atof(out[9])) / 3;
    float moy_right = (atof(out[26]) + atof(out[29]) + atof(out[32])) / 3;

    if (strncmp(out[35], "Track Cleared", 14) == 0 ||
        (moy_left < 200 && moy_right < 200 && moy_mid < 200)) {
        send_read_cmd(CAR_FORWARD, "0.0");
        usleep(300000);
        send_read_cmd(END_SIM, NULL);
    }
    angle = (angle > 1) ? 1 : angle;
    angle = (angle < -1) ? -1 : angle;
    if (moy_left < moy_right) {
        angle -= (1 / moy_mid) * TURNING_MULIPLIER;
    } else {
        angle += (1 / moy_mid) * TURNING_MULIPLIER;
    }
    send_read_cmd(WHEELS_DIR, gcvt(angle, 2, ang_str));
}
