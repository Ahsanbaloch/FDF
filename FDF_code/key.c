/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:47:46 by ahsalam           #+#    #+#             */
/*   Updated: 2023/07/25 19:40:45 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	projection(int a)
{
	if (a == 1)
		return (0);
	return (1);
}

void	depth(int key, t_fdf *data)
{
	if (key == 0)
		data->depth += 2;
	if (key == 1)
		data->depth -= 2;
}

int	press(int key, t_fdf *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (key == 53)
		exit(0);
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 124)
		data->shift_x += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 126)
		data->shift_y -= 20;
	if (key == 12)
		data->anglex += 0.2;
	if (key == 13)
		data->angley += 0.2;
	depth(key, data);
	if (key == 35)
		data->p = projection(data->p);
	draw(data);
	return (0);
}

int	mouseh(int button, int x, int y, t_fdf *data)
{
	data->color = 0;
	mlx_clear_window(data->mlx, data->win);
	if (button == 5)
		if (data->zoom < 100)
			data->zoom += 2;
	if (button == 4)
	{
		if (data->zoom > 1)
			data->zoom -= 2;
	}
	if (button == 1)
	{
		data->shift_x = x;
		data->shift_y = y;
	}
	draw(data);
	return (0);
}

void	clear_image(t_fdf *data)
{
	int	x;
	int	y;
	int	img_i;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			img_i = y * data->s_line + (x * (data->bpx / 8));
			*(int *)(data->img_addr + img_i) = 0x000000;
			x++;
		}
		y++;
	}
}
