/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 16:46:50 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyse(Data *Values, va_list ap)
{
	if (Values->type == 'c')
		ft_print_c(Values, va_arg(ap, int));
	else if (Values->type == '%')
		ft_print_pourcent(Values);
	else if (Values->type == 's')
		ft_print_str(Values, va_arg(ap, char *));
	/*else if (Values->type == 'd' || Values->type == 'i')
		ft_print_d(Values, va_arg(ap, int));*/
}

void    ft_pars(Data *Values, va_list ap, char *str)
{
    int i;

    i = Values->i;
    ft_struct_reinit(Values);
    while (!ft_ccheck("cspdiuxX%", str[i]))
	{
		if (str[i] == '0' && Values->width == 0 && Values->minus == 0)
			Values->zero = 1;
		if (str[i] == '.')
			i += ft_init_dot(&str[i], Values, ap);
		if (str[i] == '-')
        {
            Values->minus = 1;
            Values->zero = 0;
        }
		if (str[i] == '*')
			ft_init_star(ap, Values);
		if (ft_isdigit(str[i]))
			ft_init_digit(str[i], Values);
		if (ft_ccheck("cspdiuxX%", str[i]))
		{
			Values->type = str[i];
			break;
		}
		i++;
	}
	Values->i = i;
    Values->type = str[i];
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
    Data Values;

    ft_struct_init(&Values);
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[Values.i])
	{
		if (str[Values.i] == '%' && str[Values.i + 1])
		{
            Values.i++;
            ft_pars(&Values, ap, (char *)str);
            //ft_print_struct(&Values);
			if (ft_ccheck("cspdiuxX%", str[Values.i]))
				ft_analyse(&Values, ap);
			else
			{
				ft_putchar(str[Values.i++]);
            	Values.print++;
			}
		}
		else
        {
            ft_putchar(str[Values.i++]);
            Values.print++;
        }
	}	
    //ft_print_struct(&Values);
	va_end(ap);
	return (Values.print);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int i;
	int j;
	
	i = ft_printf("%s", "0");
	j = printf("%s", "0"); 
	printf("\nEXPECTED : %d\n", j);
	printf("YOU : %d\n", i);
	
	return (0);
}*/