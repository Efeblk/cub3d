NAME = cub3d
SRC = main.c utils/array_utils.c utils/free_game.c utils/ft_atoi.c utils/utils.c utils/utils2.c utils/utils3.c utils/utils4.c start_game/draw_minimap.c start_game/draw_player.c start_game/init_game.c start_game/key_press.c start_game/load_assets.c start_game/mlx_window.c start_game/movement.c start_game/render.c start_game/start_game.c raycast/raycast_calculate.c raycast/raycast_draw.c raycast/raycast_utils.c raycast/raycast.c parser/check_infos_set.c parser/check_line.c parser/check_vertical_walls.c parser/map_init.c parser/parse_arg.c parser/parse_map_line.c parser/parse_map_rgb.c parser/parse_map_rgb2.c parser/parse_map_rgb3.c parser/parse_map_xpm.c parser/parse_map.c parser/read_write_map.c parser/read_write_map2.c get_next_line/get_next_line.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MLX = mlx

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)/libmlx.a -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make clean -s -C $(MLX)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re