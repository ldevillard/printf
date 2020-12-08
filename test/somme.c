/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:41:15 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/07 14:06:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		somme(int a, ...)
{
	int i;
	int somme;
	va_list args;

	i = 1;
	somme = a;
	va_start(args, a);
	while (i != 0)
	{
		i = va_arg(args, int);
		somme += i;
	}
	va_end(args);
	return (somme);
}

int main()
{
	printf("la somme est : %d \n",somme(1, 45, 8, 0));
	return (0);
}
