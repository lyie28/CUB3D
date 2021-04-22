/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:38:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 10:26:54 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static int	ft_init_fillstring(char **place, char *str, int *start)
{
	int	i;

	i = 0;
	if ((*place) != NULL)
		return (-2);
	while (ft_spacebar(str[i]))
		i++;
	(*start) = i;
	while (str[i] && (!ft_spacebar(str[i])))
		i++;
	if (!ft_xpmcheck(&(str[i - 4])))
		return (-2);
	return (i);
}

static int	ft_fillstring(char **place, char *str)
{
	int	size;
	int	i;
	int	start;

	start = 0;
	i = ft_init_fillstring(place, str, &start);
	if (i < 0)
		return (i);
	size = i - start;
	while (str[i])
	{
		if (!ft_spacebar(str[i]))
			return (-2);
		i++;
	}
	if (!((*place) = malloc(sizeof(char) * (size + 1))))
		return (-2);
	i = -1;
	start--;
	while (str[++start] && ++i < size)
		(*place)[i] = str[start];
	(*place)[i + 1] = '\0';
	return (0);
}

static int	ft_fillint_loop(int (*place)[3], int no, char *str, t_errors errors)
{
	int	count;
	int	i;

	i = 0;
	count = -1;
	while (++count < no)
	{
		while (ft_spacebar(str[i]))
			i++;
		if (!(ft_isdigit(str[i])))
			return (ft_printerror(errors.twelve));
		while (ft_isdigit(str[i]))
			ft_number_builder(&(*place)[count], &i, str[i]);
		if (no == 3 && ((*place)[count] < 0 || (*place)[count] > 255))
			return (ft_printerror(errors.twenty));
		while (ft_spacebar(str[i]))
			i++;
		if (str[i] != ',' && no == 3 && count != 2)
			return (ft_printerror_int(errors.fourteen, place, no));
		if (no == 2 && str[i - 1] != ' ' && count != 1)
			return (ft_printerror_int(errors.fourteen, place, no));
		if (str[i] == ',' && count != 2)
			i++;
	}
	return (i);
}

static int	ft_fillint(int (*place)[3], char *str, int no, t_errors errors)
{
	int	i;

	if (no == 3 && (*place)[0] + (*place)[1] + (*place)[2] != -3)
		return (ft_printerror(errors.tone));
	if (no == 2 && (*place)[0] + (*place)[1] != -2)
		return (ft_printerror(errors.tone));
	(*place)[0] = 0;
	(*place)[1] = 0;
	if (no == 3)
		(*place)[2] = 0;
	i = ft_fillint_loop(place, no, str, errors);
	if (i == -1)
		return (-1);
	while (str[i])
	{
		if (!ft_spacebar(str[i]))
			return (ft_printerror_int(errors.fourteen, place, no));
		i++;
	}
	return (0);
}

int			ft_fillin(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] == 'C' && str[i + 1] == ' ')
		i = ft_fillint(&((*data).ceiling), &str[i + 2], 3, data->errors);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		i = ft_fillint(&((*data).floor), &(str[i + 2]), 3, data->errors);
	else if (str[i] == 'R' && str[i + 1] == ' ')
		i = ft_fillint(&((*data).res), &(str[i + 2]), 2, data->errors);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		i = ft_fillstring(&((*data).sprite), &str[i + 2]);
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		i = ft_fillstring(&((*data).so), &str[i + 3]);
	else if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		i = ft_fillstring(&((*data).no), &str[i + 3]);
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		i = ft_fillstring(&((*data).ea), &str[i + 3]);
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		i = ft_fillstring(&((*data).we), &str[i + 3]);
	else if (str[0] && !ft_spacebar(str[0]) && str[0] != '\n')
		return (ft_printerror(data->errors.nineteen));
	if (i == -2)
		return (ft_printerror(data->errors.eighteen));
	return (i);
}
