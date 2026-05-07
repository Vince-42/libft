NAME =	libft.a

SOURCE = ft_strlen.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c

OBJ = $(SOURCE:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
