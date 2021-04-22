/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:15:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 09:26:41 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_endparse(t_data *d, t_checks chk, char *buff)
{
	if (chk.gnl == 0 || chk.size == 0)
	{
		d->map = ft_split(buff, '-');
		if (!d->map)
			return (ft_printerrorfree(d->errors.eight, d));
	}
	if (!buff)
		return (ft_printerrorfree(d->errors.eight, d));
	free(buff);
	if (chk.gnl == -1)
		return (ft_printerrorfree(d->errors.eight, d));
	if (chk.input == 0)
		return (ft_printerrorfree(d->errors.four, d));
	if (chk.input == -1 || chk.input == -3)
	{
		ft_freestruct(d);
		return (-1);
	}
	return (0);
}

static char	*ft_init_parse(t_checks *checks)
{
	char	*buffer;

	buffer = ft_strdup("");
	checks->gnl = 1;
	checks->input = 0;
	checks->size = 0;
	return (buffer);
}

static int	ft_parse(t_data *data, int fd, char **line)
{
	t_checks	checks;
	char		*buffer;

	buffer = ft_init_parse(&checks);
	if (!buffer)
		return (ft_printerror(data->errors.eight));
	while (checks.gnl > 0)
	{
		*line = "";
		checks.gnl = get_next_line(fd, line);
		if (checks.gnl == -1)
			break ;
		if (checks.input == 0)
			checks.input = ft_inputter(data, *line);
		else if (checks.input == -1)
			break ;
		else
			buffer = ft_line_prep(line, buffer, &checks);
		free(*line);
		if (!buffer || checks.input == -1)
			break ;
	}
	return (ft_endparse(data, checks, buffer));
}

static int	ft_startup(char *arg, t_data *data)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	line = "";
	fd = (open(arg, O_RDONLY));
	if (fd < 0)
		return (ft_printerror(data->errors.one));
	if (ft_parse(data, fd, &line) < 0)
		return (-1);
	while (data->map[rows] != NULL)
		rows++;
	if (ft_runchecks(data, rows) < 1)
		return (-1);
	if (ft_shave(data) == -1)
		return (-1);
	ft_getmaxvalues(data);
	if (ft_squarise(data) == -1)
		return (ft_printerrorfree(data->errors.ttwo, data));
	ft_mlxbuild(*data);
	return (0);
}

int			main(int argc, char **argv)
{
	int			s;
	char		*save;
	t_data		data;

	save = "--save";
	ft_data_init(&data);
	ft_errors_init(&data.errors);
	s = ft_strlen(argv[1]) - 1;
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], save))
			return (ft_printerror(data.errors.eleven));
		else
			data.save = 1;
	}
	else if (argc != 2)
		return (ft_printerror(data.errors.three));
	if (argv[1][s] != 'b' || argv[1][s - 1] != 'u' || argv[1][s - 2] != 'c'
		|| argv[1][s - 3] != '.')
		return (ft_printerror(data.errors.two));
	ft_startup(argv[1], &data);
	return (0);
}
