/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:01:46 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/11 11:45:10 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    int a = 155;
  //  int *p = &a;
    //printf("%.5p\n", p);
    printf("%d\n", a);
    printf("%*d\n",10, a);
    //printf("%-05d\n", a);
    printf("%05d\n", a);
    printf("%-0c\n", 'A');
}