NOM = libparser.a
SRC = parse_arg.c parse_map.c parse_map_xpm.c parse_map_rgb.c parse_map_rgb2.c parse_map_rgb3.c map_init.c check_infos_set.c parse_map_line.c read_write_map.c check_vertical_walls.c check_line.c read_write_map2.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I..
AR = ar

all: $(NOM)

$(NOM): $(OBJ)
	$(AR) -rcs $(NOM) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) *~

fclean: clean
	$(RM) $(NOM)

re: fclean all

.PHONY: all clean fclean re