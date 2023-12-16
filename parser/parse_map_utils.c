#include "cub3d.h"

void check_xpm(char *line)
{
    int i;
    printf("line: %s\n", line);
    printf("len: %zu\n", ft_strlen(line));
    printf("line first: %c\n", line[0]);
    i = ft_strlen(line) - 2;
    while (line[i])
    {
        if (line[i] == 'm' && line[i - 1] == 'p' && line[i - 2] == 'x' && line[i - 3] == '.' /*&& line[i + 1] == '\0'*/)
        {
            printf("XPM OK: %s \n", line);
            break;
        }
        else
        {
            printf("c: %c%c%c%c\n", line[i], line[i - 1], line[i - 2], line[i - 3]);
            printf("XPM ERROR %s \n", line);
            exit(0);
        }
        --i;
    }
    if (file_exists(line) == 0)
    {
        printf("XPM DOES NOT EXIST: %s\n", line);
        exit(0);
    }
}

void check_rgb(char *line)
{
    (void)line;
}