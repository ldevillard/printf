/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 09:13:30 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char    *pars(char *flags, va_list ap, Data *Values)
{
    char    *dest;

    dest = NULL;
    if (Values->type == 'c')
        dest = set_c(ap, dest, flags); 
    else if (Values->type == 's')
        dest = set_s(ap, dest);
    else if (Values->type == 'd')
        dest = set_d(ap, dest);
    /*else if (Values->type == 'p')
    
    else if (Values->type == 'i')
    
    else if (Values->type == 'u')
    
    else if (Values->type == 'x')
    
    else if (Values->type == 'X')*/
    //printf("DEST = %s\n", dest);
    free(flags);
    return (dest);
}

char    *analyse(char *str, va_list ap)
{
    int i;
    Data Values;
    char    *flags;
    
    i = 0;
    Values.flag_0 = 0;
    Values.flag_minus = 0;
    Values.flag_point = 0;
    Values.flag_star = 0;
    while (!ft_ccheck("cspdiuxX", str[i]))
    {
        if (str[i] == '-')
            Values.flag_minus = 1;
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
    if (!(flags = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while(i < Values.len - 1)
    {
        flags[i] = str[i + 1];
        i++;
    }
    flags[i] = '\0';
    //print_struct(&Values);
    return (pars(flags, ap, &Values));
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list ap;
    char    *tmp;

	i = 0;
    tmp = NULL;
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
                tmp = analyse((char *)&str[i], ap);
				ft_putstr(tmp);
                i += 2;
            }
		}
		else
            ft_putchar(str[i++]);
	}	
	va_end(ap);
    free(tmp);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
    //char str[] = "test";

	ft_printf("\n\n\nSalut ca va, je m'appelle %s et j'ai %d ans !, j'adore les %10c\n\n\n", "Logan", 18, 'P');
	//printf("Hey boy %c tu as %d ans\n", 'A', -214748364899);
	
	
	return (0);
}