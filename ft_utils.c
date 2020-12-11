/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 09:13:13 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    print_struct(Data *Values)
{
    printf("Len : %d\n", Values->len);
    printf("Type : %c\n", Values->type);
   /* if (Values->flag_0 == 1)
            printf("Flag = 0\n");
    if (Values->flag_moin == 1)
            printf("Flag = -\n");
    if (Values->flag_star == 1)
            printf("Flag = *\n");
    if (Values->flag_point == 1)
            printf("Flag = .\n");
    */
}

char    *set_c(va_list ap, char *dest, char *flags)
{
    int i;
    int j;

    i = 0;
    j = 0;
    //printf ("Flags : %s\n", flags);
    if (flags[0] == '0')
        return (NULL);
    if (ft_isdigit(flags[0]) || ft_isdigit(flags[1]))
    {
        i = ft_atoi(flags);
        if (!(dest = malloc(sizeof(char) * (i + 1))))
            return (NULL);
        while (j < i)
            dest[j++] = ' ';
        dest[j] = va_arg(ap, int);
        return (dest);
    }
    dest = malloc(sizeof(char) * 2);
    if (!dest)
        return (NULL);
    dest[0] = va_arg(ap, int);
    return (dest);
}

char    *set_s(va_list ap, char *dest)
{
    dest = ft_strdup(va_arg(ap, char *));
    return (dest);
}

char    *set_d(va_list ap, char *dest)
{
    dest = ft_itoa(va_arg(ap, int));
    return (dest);
}