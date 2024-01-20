/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:33:34 by ahsalam           #+#    #+#             */
/*   Updated: 2023/07/26 10:53:34 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	float	a;

	a = *x;
	*x = (*x - *y) * cos(data->anglex);
	*y = (a + *y) * sin(data->angley) - z;
}

void	controller(t_fdf *data)
{
	int	z;
	int	z1;

	z = data->map[(int)data->y][(int)data->x] * data->depth;
	z1 = data->map[(int)data->y1][(int)data->x1] * data->depth;
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	if (data->p == 1)
	{
		isometric(&data->x, &data->y, z, data);
		isometric(&data->x1, &data->y1, z1, data);
	}
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}

void	dda_algo(t_fdf *data)
{
	float	delta_x;
	float	delta_y;
	float	max_value;
	int		img_i;

	controller(data);
	delta_x = data->x1 - data->x;
	delta_y = data->y1 - data->y;
	max_value = max(abs((int)delta_x), abs((int)delta_y));
	delta_x /= max_value;
	delta_y /= max_value;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		if (data->x >= 0 && data->x < WIN_WIDTH && data->y >= 0 \
			&& data->y < WIN_HEIGHT)
		{
			img_i = (int)data->y * data->s_line + \
			((int)data->x * (data->bpx / 8));
			*(int *)(data->img_addr + img_i) = data->color;
		}
		data->x += delta_x;
		data->y += delta_y;
	}
}

void	set_coordinate(t_fdf *data, int x, int y, int check)
{
	if (check == 0)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
	}
	if (check == 1)
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y + 1;
	}
	dda_algo(data);
}

/* 
//mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->color);
void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	menu1(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->color = data->color_map[y][x];
			if (x < data->width - 1)
				set_coordinate(data, x, y, 0);
			if (y < data->height - 1)
				set_coordinate(data, x, y, 1);
			x++;
		}
		y++;
	}
}
 */

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	clear_image(data);
	menu1(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->color = data->color_map[y][x];
			if (x < data->width - 1)
				set_coordinate(data, x, y, 0);
			if (y < data->height - 1)
				set_coordinate(data, x, y, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 200, 0);
}
