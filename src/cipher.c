/*
** EPITECH PROJECT, 2019
** cipher
** File description:
** crypt message
*/

#include "103cipher.h"

void calculate(int *key, int *message, int **crypt, int len)
{
    int height = ceil((float) len / 3);
    int *cryptate = malloc(sizeof(int) * len);
    for (int i = 0 ; i < len ; ++i) {
        cryptate[i] = 0;
    }
    for (int i = 0; i < height; i += 1){
        cryptate[i * 3 + 0] =  key[0] * message[i * 3 + 0] + \
                            key[3] * message[i * 3 + 1] + \
                            key[6] * message[i * 3 + 2];
        cryptate[i * 3 + 1] =  key[1] * message[i * 3 + 0] + \
                            key[4] * message[i * 3 + 1] + \
                            key[7] * message[i * 3 + 2];
        cryptate[i * 3 + 2] =  key[2] * message[i * 3 + 0] + \
                            key[5] * message[i * 3 + 1] + \
                            key[8] * message[i * 3 + 2];
    }
    *crypt = cryptate;
}

void get_key_matrix(int **key, char *arg)
{
    const int size = strlen(arg);
    const float square_root = sqrt(size);
    const int width = ceil(square_root);
    int *keys = malloc(sizeof(int) * (width * width));

    for (int i = 0 ; i < width * width; ++i)
        keys[i] = 0;
    for (int i = 0 ; i < size ; ++i)
        keys[i] = (int) {arg[i]};
    
    *key = keys;
}

void get_message(int **message, char *arg)
{
    int *msg = malloc(sizeof(int) * strlen(arg));

    for (int i = 0 ; arg[i] ; ++i)
        msg[i] = arg[i];

    *message = msg;
}

void crypt(int ac, char **av)
{
    int *key = NULL;
    int *message = NULL;
    int *crypt = NULL;
    int len = strlen(av[1]);

    get_key_matrix(&key, av[2]);
    get_message(&message, av[1]);
    calculate(key, message, &crypt, len);
    printf("Key matrix:\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n\n", key[0], \
    key[1], key[2], key[3], key[4], key[5], key[6], key[7], key[8]);
    printf("Encrypted message:\n");
    for (int i = 0; i < len - 1; i += 1)
        printf("%d ", crypt[i]);
    printf("%d", crypt[len - 1]);

    free(key);
    free(message);
    free(crypt);
}

void cipher(int ac, char **av)
{
    crypt(ac, av);
}