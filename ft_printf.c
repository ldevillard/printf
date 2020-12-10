/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 13:23:28 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void    analyse(char *str, va_list ap)
{
    int i;

    i = 0;
    while (str[i] && !ft_ccheck("cspdiuxX", str[i]))
        i++;
    if (str[i] == 'c')
        ft_putchar(va_arg(ap, int));
        
    
}

int     ft_printf(const char *str, ...)
{
        int i;
        va_list ap;

        i = 0;
        va_start(ap, str);
        if (!str)
            return (0);
        while (str[i])
        {
            if (str[i] != '%')
                ft_putchar(str[i++]);
            else if (str[i] == '%' && str[i + 1] == '%')
            {
                ft_putchar('%');
                i += 2;
            }
            else if (str[i] == '%' && str[i + 1])
                analyse((char *)(&str[i]), ap);
        }
        va_end(ap);
        return (i);
}

int main()
{
    char i;

    i = 'v';
    ft_printf("Salut ca va ? %%  %c", i);
    return (0);
}