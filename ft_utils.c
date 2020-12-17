/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:11:07 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/17 13:17:15 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_l(char *str, int lengt)
{
	int i;

	i = 0;
	while (str[i] && i < lengt)
		ft_putchar(str[i++]);
}

void			ft_putchar_print(char c, t_struct *t_values)
{
	write(1, &c, 1);
	t_values->print++;
}

char			*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	int			size;
	char		*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (j < ft_strlen(s1))
	{
		str[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
	{
		str[j + i] = s2[i];
		i++;
	}
	str[size] = '\0';
	free((char *)s2);
	return (str);
}
