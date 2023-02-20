/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:14:19 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 11:31:06 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		map_x;
	int		map_y;
	t_data	aux;

	if (argc != 2)
	{
		ft_printf("Incorrect arguments count!");
		return (0);
	}
	aux.mlx = mlx_init();
	ft_check_extension(argv[1]);
	map_x = ft_nice_x(argv[1]);
	map_y = ft_nice_y(argv[1]);
	aux.map_size = map_x * map_y;
	aux.collectible_total = 0;
	aux.count_moves = 0;
	aux.array = ft_map_array(&aux, argv[1]);
	aux.mlx_win = mlx_new_window(aux.mlx,
			map_x * 64, map_y * 66, "so_long");
	ft_map_rend(&aux);
	aux.collectible_count = aux.collectible_total;
	mlx_key_hook(aux.mlx_win, ft_events, &aux);
	mlx_hook(aux.mlx_win, 17, (1L << 2), ft_click_x, NULL);
	mlx_loop(aux.mlx);
}
