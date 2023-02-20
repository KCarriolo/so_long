/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:45:40 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 10:37:20 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_rend(t_data *aux)
{
	int	x;
	int	y;

	y = 0;
	while (aux->array[y])
	{
		x = 0;
		while (aux->array[y][x])
		{
			ft_put_tiles(aux, x, y);
			x++;
		}
		y++;
	}
	ft_printf("%i\n", aux->count_moves);
	return ;
}

void	ft_put_tiles(t_data *aux, int x, int y)
{
	if (aux->array[y][x] == '1')
	{
		ft_put_floor(aux->mlx, aux->mlx_win, x, y);
		ft_put_wall(aux->mlx, aux->mlx_win, x, y);
	}
	if (aux->array[y][x] == '0')
		ft_put_floor(aux->mlx, aux->mlx_win, x, y);
	if (aux->array[y][x] == 'C')
	{
		ft_put_floor(aux->mlx, aux->mlx_win, x, y);
		ft_put_collect(aux, x, y);
	}
	if (aux->array[y][x] == 'P')
	{
		ft_put_floor(aux->mlx, aux->mlx_win, x, y);
		ft_put_player(aux->mlx, aux->mlx_win, x, y);
	}
	if (aux->array[y][x] == 'E')
	{
		ft_put_floor(aux->mlx, aux->mlx_win, x, y);
		ft_put_exit(aux->mlx, aux->mlx_win, x, y);
	}
}
