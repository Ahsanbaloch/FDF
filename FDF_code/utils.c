/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:34:51 by ahsalam           #+#    #+#             */
/*   Updated: 2023/07/23 19:30:35 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invalid_file(void)
{
	ft_putstr_fd("invalid file\n", 1);
	exit(EXIT_FAILURE);
}

int	hex_color(char *hex)
{
	int	length;
	int	base;
	int	decimal;

	length = ft_strlen(hex) - 1;
	base = 1;
	decimal = 0;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
			decimal += (hex[length] - 48) * base;
		if (hex[length] >= 'A' && hex[length] <= 'F')
			decimal += (hex[length] - 55) * base;
		if (hex[length] >= 'a' && hex[length] <= 'f')
			decimal += (hex[length] - 87) * base;
		base *= 16;
		length--;
	}
	return (decimal);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	menu1(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xffffff,
		"Menu");
	mlx_string_put(data->mlx, data->win, 10, 35, 0xffffff,
		"ESC : Exit");
	mlx_string_put(data->mlx, data->win, 10, 70, 0xffffff,
		"Arrow key: Left-Right-Up-Down");
	mlx_string_put(data->mlx, data->win, 10, 95, 0xffffff,
		"Zoom: Mouse Wheel");
	mlx_string_put(data->mlx, data->win, 10, 120, 0xffffff,
		"Rotation Q and W");
	mlx_string_put(data->mlx, data->win, 10, 145, 0xffffff,
		"Change Depth: A - S");
	mlx_string_put(data->mlx, data->win, 10, 170, 0xffffff,
		"Projction: P");
}

int	check_dir(char *filename)
{
	int		nb;
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * 2);
	nb = read(fd, buf, 2);
	if (nb <= 0)
		return (1);
	free(buf);
	return (0);
}
