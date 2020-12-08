/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:36:31 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/08 16:27:04 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int     ft_printf(const char *str, ...)
{
        int i;
        int print;

        print = 0;
        i = 0;
        if (!str)
            return (0);
        while (str[i])
        {
            if (str[i] != '%')
            {
                ft_putchar(str[i++]);
                print++;
            }
            else if (str[i] == '%' && str[i + 1] == '%')
            {
                ft_putchar('%');
                i += 2;
                print++;
            }
        }
        return (print);
}

int main()
{
    int i;

    i = ft_printf("123456789");
    printf("\ni = %d", i);
    return (0);    
}