/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include "need4stek.h"

char **send_read_cmd(char *command_base, char *arg)
{
    char *buff = malloc(sizeof(char) * 200);
    char **data;
    size_t len = 0;

    write(1, command_base, strlen(command_base));
    fputs(command_base, stderr);
    if (arg != NULL) {
        write(1, arg, strlen(arg));
        fputs(arg, stderr);
    }
    write(1, "\n", 1);
    fputs("\n", stderr);
    if (getline(&buff, &len, stdin) == -1 || strlen(buff) <= 1)
        exit(0);
    fputs(buff, stderr);
    data = my_line_to_words(buff, ":");
    free(buff);
    return (data);
}
