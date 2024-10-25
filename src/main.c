/*
** EPITECH PROJECT, 2024
** eza
** File description:
** eza
*/

#include "need4stek.h"

int main(const int argc, const char *const *argv)
{
    write(1, "START_SIMULATION\n", 18);
    fputs("LAUNCH OF THE AI\n", stderr);
    main_loop();
    send_read_cmd(END_SIM, NULL);
    return (OK);
}
