/*
** EPITECH PROJECT, 2024
** eza
** File description:
** eza
*/

#include "need4stek.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(const int argc, const char *const *argv)
{
    write(1, "START_SIMULATION\n", 18);
    fputs("LAUNCH OF THE AI\n", stderr);
    main_loop();
    send_read_cmd(END_SIM, NULL);
    printf("SIMULATION_ENDED\n");
    return (OK);
}
