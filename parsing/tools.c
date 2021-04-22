/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:31:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 10:39:04 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_isdigit(char c)
{
	int		i;
	char	*digits;

	i = 0;
	digits = "0123456789";
	while (digits[i])
	{
		if (digits[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_spacebar(char c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (1);
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	ft_swap(char *c)
{
	if ((*c) == ' ')
		(*c) = '1';
	if ((*c) == '-')
		(*c) = '*';
	if ((*c) == '+')
		(*c) = '*';
}
