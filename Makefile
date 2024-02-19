NAME = cub3d
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
PARSER = parser
UTILS = utils
GNL = get_next_line
MLX = mlx
IG = start_game
RC = raycast

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(GNL)
	@make -s -C $(UTILS)
	@make -s -C $(PARSER)
	@make -s -C $(IG)
	@make -s -C $(MLX)
	@make -s -C $(RC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PARSER)/libparser.a $(UTILS)/libutils.a $(GNL)/libget_next_line.a $(MLX)/libmlx.a $(IG)/libstart_game.a $(RC)/libraycast.a -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@make clean -s -C $(GNL)
	@make clean -s -C $(PARSER)
	@make clean -s -C $(UTILS)
	@make clean -s -C $(IG)
	@make clean -s -C $(MLX)
	@make clean -s -C $(RC)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(GNL)
	@make fclean -s -C $(PARSER)
	@make fclean -s -C $(UTILS)
	@make fclean -s -C $(IG)
	@make fclean -s -C $(RC)

re: fclean all

.PHONY: all clean fclean re