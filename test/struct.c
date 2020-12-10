/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:47:43 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/10 09:01:50 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void    initCoord(Coord *test)
{
    test->x = 0;
    test->y = 0;    
}

int     main()
{
    Coord test;
    
    initCoord(&test);
    printf("x = %d\ny = %d\n\n", test.x, test.y);
    test.x = 10;
    test.y = 20;
    printf("x = %d\ny = %d\n", test.x, test.y);
    return 0;
}