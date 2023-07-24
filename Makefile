SRC = pushswap.c sort.c parsing.c free.c\

PUSH = pushswap.c

PUSH_NAME = pushswap

OBJ = $(SRC:.c=.o)

LIBFT = ./Libft

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(PUSH_NAME)

$(PUSH_NAME) : $(PUSH) $(OBJ)
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) sort.c $(LIBFT)/libft.a $(PUSH) -o $(PUSH_NAME)
clean:
	rm -f $(OBJ)
	cd $(LIBFT) && $(MAKE) fclean
fclean: clean
	rm -f $(PUSH_NAME)
	cd $(LIBFT) && $(MAKE) fclean
re: fclean all

.PHONY: all clean fclean all