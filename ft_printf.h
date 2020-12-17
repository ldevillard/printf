/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:24:41 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/17 15:32:14 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	int		print;
	int		zero;
	int		star;
	int		minus;
	int		dot;
	int		has_dot;
	int		width;
	char	type;
	int		len;
	int		i;
	char	*tmp;
}				t_struct;

int				ft_printf(const char *str, ...);
void			ft_print_struct(t_struct *t_values);
void			ft_struct_init(t_struct *t_values);
void			ft_pars(t_struct *t_values, va_list ap, char *str);
void			ft_struct_reinit(t_struct *values);
int				ft_init_dot(char *str, t_struct *t_values, va_list ap);
void			ft_init_star(va_list ap, t_struct *t_values);
void			ft_init_digit(char c, t_struct *t_values);
void			ft_analyse(t_struct *t_values, va_list ap);
void			ft_print_c(t_struct *t_values, char c);
void			ft_width(int width, int i, int zero, t_struct *t_values);
void			ft_print_pourcent(t_struct *t_values);
void			ft_print_str(t_struct *t_values, char *str);
void			ft_putstr_l(char *str, int lengt);
void			ft_putchar_print(char c, t_struct *t_values);
void			ft_init_minus(t_struct *t_values);
void			ft_print_d(t_struct *t_values, int nbr);
void			ft_print_d_utils(t_struct *t_values, char *tmp);
void			ft_print_d_utils_minus(t_struct *t_values, char *tmp);
void			ft_print_u(t_struct *t_values, unsigned int nbr);
char			*ft_convert_base(unsigned int nbr, int base);
void			ft_print_x(t_struct *t_values, unsigned int nbr);
void			ft_print_lowx(t_struct *t_values, unsigned int nbr);
void			ft_print_p(t_struct *t_values, unsigned long nbr);
char			*ft_strjoin_free(char const *s1, char const *s2);
char			*ft_convert_base_u(unsigned long nbr, int base);

#endif
