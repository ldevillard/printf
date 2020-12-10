/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 13:17:00 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		count_n(long n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int    analyse(char *str, va_list ap)
{
	int i;
	int j;
    
	i = 0;
	j = 0;
    while (str[i] && !ft_ccheck("cspdiuxX", str[i]))
        i++;
    if (str[i] == 'c')
	{
        ft_putchar(va_arg(ap, int));
		i++;
	}
	else if (str[i] == 'd')
	{
		ft_putnbr(va_arg(ap, int));
		i++; 
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
			{
				ft_putchar(str[i]);
				i += 2;
			}
			else
				i += analyse((char *)(&str[i]), ap);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}	

	va_end(ap);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft_printf("Hey boy %c tu as %d%d ans %d \n", 'A', 10000, 4, 2);
	printf("Hey boy %c tu as %d%d ans %d \n", 'A', 10000, 4, 2);
	
	
	return (0);
}
