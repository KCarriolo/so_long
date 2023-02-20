/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:17:07 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 11:38:22 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_path(t_data *aux, char *join)
{
	aux->temp_array = ft_split(join, '\n');
	ft_path_valid_find_player(aux, 0, 0);
}

void	ft_path_valid_find_player(t_data *aux, int x, int y)
{
	while (aux->map_size >= 0)
	{
		y = 0;
		while (aux->temp_array[y])
		{
			x = 0;
			while (aux->temp_array[y][x])
			{
				if (aux->temp_array[y][x] == 'P')
				{
					if (ft_verify_around_p(aux, x, y))
					{
						aux->p_x = x;
						aux->p_y = y;
						ft_infestation(aux);
					}
				}
				x++;
			}
			y++;
		}
		aux->map_size--;
	}
	ft_check_the_plague(aux, 0, 0);
	return ;
}
