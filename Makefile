NAME = push_swap

SRC = pushswap.c sort.c parsing.c free.c error.c operations.c rotate.c sort_utils.c radix_sort.c utils.c\

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:c=o)

LIBFT = Libft

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	${CC} $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $@

clean:
	${RM} $(OBJ)
	make clean -C ${LIBFT}

fclean: clean
	${RM} $(NAME)
	make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean all