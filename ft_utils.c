/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 16:28:44 by ldevilla         ###   ########lyon.fr   */
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

char    *set_c(va_list ap, char *dest)
{
    dest = malloc(sizeof(char) * 2);
    if (!dest)
        return (NULL);
    dest[0] = va_arg(ap, int);
    return (dest);
}

char    *set_s(va_list ap, char *dest)
{
   // dest = malloc(sizeof(char) * ft_strlen((va_arg(ap, char *))));
    //if (!dest)
      //  return (NULL);
    //printf("ARG : %s\n", va_arg(ap, char *));
    dest = ft_strdup(va_arg(ap, char *));
    return (dest);
}

char    *set_d(va_list ap, char *dest)
{
    dest = ft_itoa(va_arg(ap, int));
    return (dest);
}