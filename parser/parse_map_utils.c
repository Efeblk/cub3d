#include "cub3d.h"

void check_xpm(char *line)
{
    int i;

    i = ft_strlen(line) - 1;
    while (line[i])
    {
        if (line[i] == 'm' && line[i - 1] == 'p' && line[i - 2] == 'x' && line[i - 3] == '.' && line[i + 1] == '\0')
        {
            printf("XPM OK\n");
            break;
        }
        else
        {
            printf("XPM ERROR\n");
            exit(0);
        }
        --i;
    }
    if (file_exists(line) == 0)
    {
        printf("XPM ERROR\n");
        exit(0);
    }
}

void check_rgb(char *line)
{
    (void)line;
}