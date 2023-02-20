/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:42:31 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/24 17:03:25 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(void *mlx, void *mlx_win, int x_resize, int y_resize)
{
	char	*wall_path;
	void	*wall;
	int		img_width;
	int		img_height;

	wall_path = "sprites/wall.xpm";
	wall = mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, wall, 64 * x_resize, 64 * y_resize);
}

void	ft_put_floor(void *mlx, void *mlx_win, int x_resize, int y_resize)
{
	char	*floor_path;
	void	*floor;
	int		img_width;
	int		img_height;

	floor_path = "sprites/floor.xpm";
	floor = mlx_xpm_file_to_image(mlx, floor_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, floor, 64 * x_resize,
		(64 * y_resize) + 12);
}

void	ft_put_collect(t_data *aux, int x_resize, int y_resize)
{
	char	*collect_path;
	void	*collect;
	int		img_width;
	int		img_height;

	aux->collectible_total++;
	collect_path = "sprites/collect.xpm";
	collect = mlx_xpm_file_to_image(aux->mlx, collect_path,
			&img_width, &img_height);
	mlx_put_image_to_window(aux->mlx, aux->mlx_win,
		collect, (64 * x_resize) + 12,
		(64 * y_resize) + 24);
}

void	ft_put_player(void *mlx, void *mlx_win, int x_resize, int y_resize)
{
	char	*player_path;
	void	*player;
	int		img_width;
	int		img_height;

	player_path = "sprites/cat.xpm";
	player = mlx_xpm_file_to_image(mlx, player_path,
			&img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, player,
		(64 * x_resize) + 14, (64 * y_resize) + 18);
}

void	ft_put_exit(void *mlx, void *mlx_win, int x_resize, int y_resize)
{
	char	*exit_path;
	void	*exit;
	int		img_width;
	int		img_height;

	exit_path = "sprites/kitty.xpm";
	exit = mlx_xpm_file_to_image(mlx, exit_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, exit,
		(64 * x_resize) + 8, 64 * y_resize);
}
