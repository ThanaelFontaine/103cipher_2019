/*
** EPITECH PROJECT, 2019
** main
** File description:
** main for 103cipher
*/

#include "103cipher.h"

void error(int ac, char **av, int *error)
{
    if (ac != 4)
        *error = 84;
    if (av[3][0] != 1 && av[3][0] != 0)
        *error = 84;
}

void h_text(int ac, char**av, int *error)
{
    int fd = 0;
    const char c = '\n';
    int size = 900;
    char *buffer;

    fd = open("images/h_file.txt", O_RDONLY);
    buffer = malloc(sizeof(char) * (size + 3));
    read(fd, buffer, size);
    write(1, buffer, size - 1);
    write(1, &c, 1);
    *error = 0;
}

int main (int ac, char **av)
{
    int error = 0;

    if (ac == 2)
        h_text(ac, av, &error);
    else
        cipher(ac, av);
    return (error);
}