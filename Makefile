NAME = cub3d
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
# EXEC = exec
PARSER = parser
UTILS = utils
GNL = get_next_line
MLX = mlx
IG = init_game
# BUILTIN = builtin

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(GNL)
	@make -s -C $(UTILS)
	@make -s -C $(PARSER)
	@make -s -C $(IG)
	@make -s -C $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PARSER)/libparser.a $(UTILS)/libutils.a $(GNL)/libget_next_line.a $(MLX)/libmlx.a $(IG)/libinit_game.a -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@make clean -s -C $(GNL)
	@make clean -s -C $(PARSER)
	@make clean -s -C $(UTILS)
	@make clean -s -C $(IG)
	@make clean -s -C $(MLX)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(GNL)
	@make fclean -s -C $(PARSER)
	@make fclean -s -C $(UTILS)
	@make fclean -s -C $(IG)

re: fclean all

.PHONY: all clean fclean re