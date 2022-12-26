NAME = push_swap
SRC = test3.c test4.c main.c ft_pushswap.c push_swap_function.c ft_push_swap.c function.c

CFLAGS			= -Wall -Wextra -Werror
all : $(SRC)
	gcc $(CFLAGS) $(SRC) ./libft/libft.a -o $(NAME) 


clean:
				rm $(NAME)

fclean:			clean
				

re:				fclean all