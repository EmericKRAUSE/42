NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c\
	ft_c.c\
	ft_s.c\
	ft_p.c\
	ft_i.c\
	ft_u.c\
	ft_lower_x.c\
	ft_upper_x.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_count.c\
	ft_count_dix.c

MAIN = main_printf.c
MAKE_LIBFT = @make -C ./libft
LIBFT = ./libft/libft.a
EXE = exe
OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

all: $(NAME)

run: $(EXE)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar crs $@ $^

$(EXE): $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $@ $(NAME) && ./$(EXE) && rm -f $(EXE)

clean:
	rm -f *.o
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all
	$(MAKE_LIBFT) re

.PHONY: all clean fclean re run