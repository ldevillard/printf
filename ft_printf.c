/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/15 12:18:09 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyse(t_struct *t_values, va_list ap)
{
	if (t_values->type == 'c')
		ft_print_c(t_values, va_arg(ap, int));
	else if (t_values->type == '%')
		ft_print_pourcent(t_values);
	else if (t_values->type == 's')
		ft_print_str(t_values, va_arg(ap, char *));
	else if (t_values->type == 'd' || t_values->type == 'i')
		ft_print_d(t_values, va_arg(ap, int));
}

void	ft_pars(t_struct *t_values, va_list ap, char *str)
{
	int i;

	i = t_values->i;
	ft_struct_reinit(t_values);
	while (!ft_ccheck("cspdiuxX%", str[i]))
	{
		if (str[i] == '0' && t_values->width == 0 && t_values->minus == 0)
			t_values->zero = 1;
		if (str[i] == '.')
			i += ft_init_dot(&str[i], t_values, ap);
		if (str[i] == '-')
			ft_init_minus(t_values);
		if (str[i] == '*')
			ft_init_star(ap, t_values);
		if (ft_isdigit(str[i]))
			ft_init_digit(str[i], t_values);
		if (ft_ccheck("cspdiuxX%", str[i]))
		{
			t_values->type = str[i];
			break ;
		}
		i++;
	}
	t_values->i = i;
	t_values->type = str[i];
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	t_values;

	ft_struct_init(&t_values);
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[t_values.i])
	{
		if (str[t_values.i] == '%' && str[t_values.i + 1])
		{
			t_values.i++;
			ft_pars(&t_values, ap, (char *)str);
			if (ft_ccheck("cspdiuxX%", str[t_values.i]))
				ft_analyse(&t_values, ap);
			else
				ft_putchar_print(str[t_values.i++], &t_values);
		}
		else
			ft_putchar_print(str[t_values.i++], &t_values);
	}
	va_end(ap);
	return (t_values.print);
}



/*
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int i;
	int j;
	
	i = ft_printf(" %-4.2d \n", 1);
	j = printf(" %-4.2d \n", 1); 
	printf("\nEXPECTED : %d\n", j);
	printf("YOU : %d\n", i);
	
	return (0);
}*/