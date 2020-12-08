/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/07 14:34:11 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_printf(const char *str, ...)
{
	int i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(ap, char), 0);
				if(str[i + 2])
					i += 2;
				else
					return (0);
			} 	
		}
		ft_putchar_fd(str[i], 0);
		i++;
	}	

	va_end(ap);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char c;	

	c = 'L';
	ft_printf("Salut je test ce caractere : %c %c et %c%c%c", c, 'T', 'A', 'B', 'C');
	return (0);
}
