/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_t_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:32:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 10:37:51 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_freestruct(t_data *data)
{
	int	i;

	i = 0;
	if ((*data).sprite)
		free((*data).sprite);
	if ((*data).no)
		free((*data).no);
	if ((*data).so)
		free((*data).so);
	if ((*data).we)
		free((*data).we);
	if ((*data).ea)
		free((*data).ea);
	if ((*data).map == NULL)
	{
		free((*data).map);
		return ;
	}
	while ((*data).map[i])
	{
		free((*data).map[i]);
		i++;
	}
	free((*data).map);
}

int		ft_printerror(char *error)
{
	write(1, "Error\n", 6);
	write(1, error, ft_strlen(error));
	return (-1);
}

int		ft_printerrorfree(char *error, t_data *data)
{
	write(1, "Error\n", 6);
	write(1, error, ft_strlen(error));
	ft_freestruct(data);
	return (-1);
}

void	ft_errors_init(t_errors *errors)
{
	(*errors).one = "File failed to open\n";
	(*errors).two = "File extension not .cub\n";
	(*errors).three = "Wrong number of arguments\n";
	(*errors).four = "Missing values before map\n";
	(*errors).five = "Incorrect floor colour values\n";
	(*errors).six = "Incorrect ceiling colour values\n";
	(*errors).seven = "Multiple or no player starting positions\n";
	(*errors).eight = "Malloc failed or incorrect file provided\n";
	(*errors).nine = "Map contains bad char\n";
	(*errors).ten = "Map not surrounded by 1s/ duplicates/ chars before map\n";
	(*errors).eleven = "The only valid third argument is --save\n";
	(*errors).twelve = "Incorrect floor/ceiling/res input\n";
	(*errors).thirteen = "Res input must be above 0 and below INT_MAX\n";
	(*errors).fourteen = "You have bad chars in your res/floor/ceiling input\n";
	(*errors).fifteen = "First/last char in map row is not a wall\n";
	(*errors).sixteen = "First/Last line in map not just walls\n";
	(*errors).svteen = "Invalid file path\n";
	(*errors).eighteen = "Invalid chars in path information\n";
	(*errors).nineteen = "Invalid text in map or missing info\n";
	(*errors).twenty = "Colour values must be between 0 and 255\n";
	(*errors).tone = "Duplicate information\n";
	(*errors).ttwo = "Malloc failed\n";
}

int		ft_printerror_int(char *error, int (*array)[3], int no)
{
	int	i;

	i = 0;
	while (i < no)
	{
		(*array)[i] = -1;
		i++;
	}
	write(1, "Error\n", 6);
	write(1, error, ft_strlen(error));
	return (-1);
}
