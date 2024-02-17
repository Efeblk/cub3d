#include "cub3d.h"

//ALTTAKİNİ SİLMEYİ UNUTMA
void	print_char_array(char **array)
{
	int	i;

	i = 0;
	printf("print_char_array:\n");
	while (array[i])
	{
		printf("%s\n", array[i]);
		++i;
	}
	printf("print_char_array end\n");
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
}
