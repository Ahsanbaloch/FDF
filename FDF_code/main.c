/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:55:04 by ahsalam           #+#    #+#             */
/*   Updated: 2024/01/21 00:06:45 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	process(char *argv)
{
	t_fdf	data;

	data.shift_x = WIN_WIDTH - 2800;
	data.shift_y = WIN_HEIGHT / 2 - 1100;
	data.p = 1;
	data.anglex = 0.523599;
	data.angley = 0.523599;
	data.depth = 1;
	read_fdf(argv, &data);
	if (data.height < 100 && data.width < 100)
		data.zoom = 35;
	else
		data.zoom = 3;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF _ Ahsan");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpx, &data.s_line, \
	&data.endian);
	draw(&data);
	mlx_key_hook(data.win, press, &data);
	mlx_mouse_hook(data.win, mouseh, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Please add correct path :)\n", 0);
		return (0);
	}
	process(argv[1]);
}
