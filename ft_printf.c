/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 14:17:08 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void    print_struct(Data *Values)
{
    printf("Len : %d\n", Values->len);
    printf("Type : %c\n", Values->type);
    if (Values->flag_0 == 1)
            printf("Flag = 0\n");
    if (Values->flag_moin == 1)
            printf("Flag = -\n");
    if (Values->flag_star == 1)
            printf("Flag = *\n");
    if (Values->flag_point == 1)
            printf("Flag = .\n");
}

void    analyse(char *str, va_list ap)
{
    int i;
    Data Values;
    
    Values.flag_0 = 0;
    Values.flag_moin = 0;
    Values.flag_point = 0;
    Values.flag_star = 0;
    while (!ft_ccheck("cspdiuxX", str[i]))
    {
        if (str[i] == '-')
            Values.flag_moin = 1;
        else if (str[i] == '0')
            Values.flag_0 = 1;
        else if (str[i] == '.')
            Values.flag_point = 1; 
        else if (str[i] == '*')
            Values.flag_star = 1; 
        i++;
    }
    Values.len = i;
    Values.type = str[i];
    print_struct(&Values);
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
            {
				analyse((char *)(&str[i]), ap);
                i++;
            }
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
	
	ft_printf("Hey boy %-0.c tu as %d ans\n", 'A', -214748364899);
	//printf("Hey boy %c tu as %d ans\n", 'A', -214748364899);
	
	
	return (0);
}