/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:10:06 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 10:32:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_struct_init(Data *Values)
{
    Values->print = 0;
    ft_bzero(Values->flags, 3);
    Values->prec = 0;
    Values->width = 0;
    Values->type = 0;
    Values->len = 0;
    Values->i = 0;
}