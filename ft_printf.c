/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 12:00:01 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_pars(Data *Values, va_list ap, char *str)
{
    int i;
    int j;

    i = Values->i;
    j = 0;
    while (!ft_ccheck("cspdiuxX", str[i]))
    {
        if (str[i] == '-')
            Values->flags[j++] = '-';
        else if (str[i] == '0')
            Values->flags[j++] = '0';
        if (str[i] == '*')
            Values->width += va_arg(ap, int);
        if (ft_isdigit(str[i]) && !Values->width)
            Values->width += ft_atoi(&str[i]);
        if (str[i] == '.')
            Values->prec = 1;
        i++;
    }
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
			if (str[Values.i + 1] == '%')
			{
				ft_putchar(str[Values.i]);
                Values.print++;
				Values.i += 2;
			}
			else
            {
                ft_pars(&Values, ap, (char *)str);
				//while (str[Values.i] != Values.type)
                Values.i++;
            }
		}
		else
        {
            ft_putchar(str[Values.i++]);
            Values.print++;
        }
	}	
    ft_print_struct(&Values);
	va_end(ap);
	return (Values.print);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
    //char str[] = "test";

	ft_printf("Hey boyy %% logan %-09856d");
	//printf("Hey boy %c tu as %d ans\n", 'A', -214748364899);
	
	
	return (0);
}