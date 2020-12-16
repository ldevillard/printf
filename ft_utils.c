/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 14:38:45 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_struct(t_struct *t_values)
{
	ft_putchar('\n');
	ft_putstr("PRINTED : ");
	ft_putnbr(t_values->print);
	ft_putchar('\n');
	ft_putstr("PRECISION : ");
	ft_putnbr(t_values->dot);
	ft_putchar('\n');
	ft_putstr("HAS DOT : ");
	ft_putnbr(t_values->has_dot);
	ft_putchar('\n');
	ft_putstr("WIDTH : ");
	ft_putnbr(t_values->width);
	ft_putchar('\n');
	ft_putstr("TYPE : ");
	ft_putchar(t_values->type);
	ft_putchar('\n');
	ft_putstr("STAR : ");
	ft_putnbr(t_values->star);
	ft_putchar('\n');
	ft_putstr("ZERO : ");
	ft_putnbr(t_values->zero);
	ft_putchar('\n');
	ft_putstr("MINUS : ");
	ft_putnbr(t_values->minus);
	ft_putchar('\n');
	ft_putstr("i : ");
	ft_putnbr(t_values->i);
	ft_putchar('\n');
	ft_putstr("TMP : ");
	ft_putstr(t_values->tmp);
	ft_putchar('\n');
}

void	ft_putstr_l(char *str, int lengt)
{
	int i;

	i = 0;
	while (str[i] && i < lengt)
		ft_putchar(str[i++]);
}

void	ft_putchar_print(char c, t_struct *t_values)
{
	write(1, &c, 1);
	t_values->print++;
}

void	ft_print_d_utils_minus(t_struct *t_values, char *tmp)
{
	if ((int)ft_strlen(tmp) > t_values->dot)
	{
		ft_putstr(tmp);
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp);
	}
	else
	{
		ft_putchar_print('-', t_values);
		ft_width(t_values->dot, ft_strlen(tmp) - 1, 1, t_values);
		ft_putstr(tmp + 1);
		if (t_values->dot)
			ft_width(t_values->width, t_values->dot + 1, 0, t_values);
		else
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		t_values->print += ft_strlen(tmp) - 1;
	}
}

void	ft_print_d_utils(t_struct *t_values, char *tmp)
{
	if ((int)ft_strlen(tmp) > t_values->dot)
	{
		ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_putstr(tmp);
		t_values->print += ft_strlen(tmp);
	}
	else
	{
		if (t_values->dot)
			ft_width(t_values->width, t_values->dot + 1, 0, t_values);
		else
			ft_width(t_values->width, ft_strlen(tmp), 0, t_values);
		ft_putchar_print('-', t_values);
		ft_width(t_values->dot, ft_strlen(tmp) - 1, 1, t_values);
		ft_putstr(tmp + 1);
		t_values->print += ft_strlen(tmp) - 1;
	}
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	int			size;
	char		*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (j < ft_strlen(s1))
	{
		str[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
	{
		str[j + i] = s2[i];
		i++;
	}
	str[size] = '\0';
	free((char *)s2);
	return (str);
}