NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = ft_printf.h
LIBC = ar rc
LIBI = ranlib
SRCS = ft_printf.c ft_flags.c ft_print_c.c ft_print_d.c ft_print_pourcent.c ft_print_str.c ft_struct_init.c ft_utils.c ft_width.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_itoa.c libft/ft_ccheck.c libft/ft_strlen.c libft/ft_isdigit.c libft/ft_strrev.c libft/ft_itoa.c libft/ft_u_itoa.c ft_print_u.c libft/ft_strdup.c ft_convert_base.c ft_print_x.c ft_print_lowx.c libft/ft_tolower.c ft_print_p.c
OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBI) $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean re all