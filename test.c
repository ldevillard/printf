/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 12:54:02 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		i ++;
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
	
	ft_printf("Hey boy %c et toi %c aussi %c%c%     c\n", 'A', 'B', 'C', 'D', 'E');
	printf("Hey boy %c et toi %c aussi %c%c%     c\n", 'A', 'B', 'C', 'D', 'E');
	return (0);
}
