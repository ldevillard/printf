LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_convert_base.c \
		ft_print_c.c \
		ft_print_d.c \
		ft_print_lowx.c \
		ft_print_p.c \
		ft_print_pourcent.c \
		ft_print_str.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_flags.c \
		ft_struct_init.c \
		ft_utils.c \
		ft_width.c  

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDE = ft_printf.h

OBJS = $(SRCS:.c=.o)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf *.o
	rm -rf *.a

re : fclean all

.PHONY: clean fclean re all