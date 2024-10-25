/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#ifndef AZE_
    #define AZE_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <sys/param.h>

    #define OK 0
    #define KO 84

    #define BASE_SPEED "0.6"
    #define SLOW_SPEED "0.3"
    #define TURNING_SPEED "0.2"
    #define TURNING_MULIPLIER 100

    #define START_SIM "START_SIMULATION"
    #define END_SIM "STOP_SIMULATION"
    #define GET_INFO_LIDAR "GET_INFO_LIDAR"
    #define GET_CURRENT_SPEED "GET_CURRENT_SPEED"
    #define GET_CURRENT_WHEELS "GET_CURRENT_WHEELS"
    #define GET_CAR_SPEED_MAX "GET_CAR_SPEED_MAX"
    #define GET_CAR_SPEED_MIN "GET_CAR_SPEED_MIN"
    #define GET_INFO_SIMTIME "GET_INFO_SIMTIME"
    #define CAR_FORWARD "CAR_FORWARD:"
    #define CAR_BACKWARDS "CAR_BACKWARDS:"
    #define WHEELS_DIR "WHEELS_DIR:"
    #define CYCLE_WAIT "CYCLE_WAIT:"

char **my_line_to_words(char *input_string, char *tokens);
char **send_read_cmd(char *command_base, char *arg);
int main_loop(void);
void set_direction(char **out, float angle);

#endif /* !aze */
