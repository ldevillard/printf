/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/14 10:34:11 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*void    ft_analyse_data(Data *Values, va_list ap)
{

}*/

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
    //Values->type = str[i];
    //ft_analyse_data(Values, ap);
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
            ft_print_struct(&Values);
			while (str[Values.i] != Values.type)
                Values.i++;
            Values.i++;
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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
    //char str[] = "test";

	ft_printf("Hey boyy %012.*d",12, 5);
	printf("Hey boyy %012.*d",12, 5);
	//printf("Hey boyy %15.*s", 5, "test");
   // printf("Hey boyy %.4% logan %9.*d\n", 10, 30);
	
	return (0);
}