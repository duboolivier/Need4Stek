/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** err
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int is_in_input(char *input_string, char token)
{
    for (int i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == token)
            return (1);
    }
    return (0);
}

static int nbr_of_jumps_data(char *input_string, char *tokens)
{
    int count = 1;

    for (int i = 0; i < (int)strlen(input_string); i++) {
        if (is_in_input(tokens, input_string[i])) {
            count++;
        }
    }
    return (count);
}

char **my_line_to_words(char *input_string, char *tokens)
{
    int count = nbr_of_jumps_data(input_string, tokens);
    char **lines = (char **)malloc(count * sizeof(char *) * 2);
    char *input = strdup(input_string);
    int i = 0;
    char *saveptr = NULL;
    char *tok = strtok_r(input, tokens, &saveptr);

    for (; tok != NULL; i++) {
        lines[i] = strdup(tok);
        tok = strtok_r(NULL, tokens, &saveptr);
    }
    lines[i] = NULL;
    free(input);
    return lines;
}
