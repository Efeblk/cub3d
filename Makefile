NAME = cub3d
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
# EXEC = exec
PARSER = parser
UTILS = utils
# BUILTIN = builtin

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(UTILS)
	@make -s -C $(PARSER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PARSER)/libparser.a $(UTILS)/libutils.a

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@make clean -s -C $(PARSER)
	@make clean -s -C $(UTILS)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(PARSER)
	@make fclean -s -C $(UTILS)

re: fclean all

.PHONY: all clean fclean re