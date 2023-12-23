#include "cub3d.h"

//ALTTAKİNİ SİLMEYİ UNUTMA
void print_char_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        printf("%s\n", array[i]);
        ++i;
    }
}

void free_char_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        ++i;
    }
    free(array);
}