/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:03:09 by ahsalam           #+#    #+#             */
/*   Updated: 2023/07/25 19:22:27 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	get_width(char *filename, int check)
{
	int		fd;
	char	**str;
	int		i;
	char	*line;

	if (check == 1)
	{
		fd = open(filename, O_RDONLY);
		line = get_next_line(fd);
		str = ft_split(line, ' ');
	}
	else
		str = ft_split(filename, ' ');
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (check == 1)
		free (line);
	return (i);
}

int	get_height(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

int	pasting_color(int num)
{
	if (num == 0)
		return (0xFFFFFF); 
	else
		return (0xFF0000);
}

void	fill_map(int *nums, int *color, char *line)
{
	char	**s_line;
	int		i;
	int		k;

	i = 0;
	s_line = ft_split(line, ' ');
	while (s_line[i])
	{
		nums[i] = ft_atoi(s_line[i]);
		k = 0;
		while (s_line[i][k] != ',' && s_line[i][k])
			k++;
		if (s_line[i][k++] == ',')
			color[i] = hex_color(&s_line[i][k]);
		else
		{
			color[i] = pasting_color(nums[i]);
		}
		i++;
	}
	i = 0;
	while (s_line[i])
		free(s_line[i++]);
	free(s_line);
}

void	read_fdf(char *filename, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || check_dir(filename))
		invalid_file();
	i = 0;
	data->width = get_width(filename, 1);
	data->height = get_height(filename);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->color_map = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->width);
		data->color_map[i] = (int *)malloc(sizeof(int) * data->width);
		line = get_next_line(fd);
		if (data->width != get_width(line, 0))
			invalid_file();
		fill_map(data->map[i], data->color_map[i], line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
}
