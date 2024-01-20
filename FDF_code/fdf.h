/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:17:36 by ahsalam           #+#    #+#             */
/*   Updated: 2023/07/26 10:01:23 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../previous_projects/libft/libft.h"
# include "../previous_projects/get_next_line/get_next_line.h"
# include "../minilibx_macos/mlx.h"

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# define WIN_WIDTH 4000
# define WIN_HEIGHT 3000

typedef struct fdf
{
	int		bpx;
	int		s_line;
	int		endian;
	void	*mlx;
	void	*img;
	void	*win;
	char	*img_addr;
	int		height;
	int		width;
	int		**map;
	int		**color_map;
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		p;
	float	anglex;
	float	angley;
	int		depth;
}	t_fdf;

void	read_fdf(char *filename, t_fdf *data);
void	invalid_file(void);
int		hex_color(char *hex);
void	draw(t_fdf *data);
int		press(int key, t_fdf *data);
int		mouseh(int button, int x, int y, t_fdf *data);
float	max(float a, float b);
void	dda_algo(t_fdf *data);
void	menu1(t_fdf *data);
float	max(float a, float b);
int		check_dir(char *filename);
void	clear_image(t_fdf *data);

#endif
