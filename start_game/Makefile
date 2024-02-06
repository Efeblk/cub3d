NOM = libstart_game.a
SRC = init_game.c mlx_window.c start_game.c load_assets.c #draw_minimap.c draw_player_2d.c draw_player_3d.c key_pressed.c 
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