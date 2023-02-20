/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:53:01 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 11:41:56 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_around_p(t_data *aux, int x, int y)
{
	if (aux->temp_array[y + 1][x] == 'P'
			&& aux->temp_array[y - 1][x] == 'P'
			&& aux->temp_array[y][x + 1] == 'P'
			&& aux->temp_array[y][x - 1] == 'P')
		return (0);
	else
		return (1);
}

void	ft_infestation(t_data *aux)
{
	if (aux->temp_array[aux->p_y + 1][aux->p_x] == 'C'
			|| aux->temp_array[aux->p_y + 1][aux->p_x] == '0')
		aux->temp_array[aux->p_y + 1][aux->p_x] = 'P';
	if (aux->temp_array[aux->p_y][aux->p_x - 1] == 'C'
			|| aux->temp_array[aux->p_y][aux->p_x - 1] == '0')
		aux->temp_array[aux->p_y][aux->p_x - 1] = 'P';
	if (aux->temp_array[aux->p_y - 1][aux->p_x] == 'C'
			|| aux->temp_array[aux->p_y - 1][aux->p_x] == '0')
		aux->temp_array[aux->p_y - 1][aux->p_x] = 'P';
	if (aux->temp_array[aux->p_y][aux->p_x + 1] == 'C'
			|| aux->temp_array[aux->p_y][aux->p_x + 1] == '0')
		aux->temp_array[aux->p_y][aux->p_x + 1] = 'P';
}

void	ft_check_the_plague(t_data *aux, int x, int y)
{
	while (aux->temp_array[y])
	{
		x = 0;
		while (aux->temp_array[y][x])
		{
			if (aux->temp_array[y][x] == 'C')
			{
				ft_printf("Map doesn't have a valid path to win the game!");
				exit(0);
			}
			if (aux->temp_array[y][x] == 'E')
			{
				if (!(ft_check_valid_exit(aux, x, y)))
				{
					ft_printf("Map doesn't have a valid path to win the game!");
					exit(0);
				}	
			}	
			x++;
		}
		y++;
	}
}

int	ft_check_valid_exit(t_data *aux, int x, int y)
{
	if (aux->temp_array[y + 1][x] == 'P'
		|| aux->temp_array[y - 1][x] == 'P'
		|| aux->temp_array[y][x + 1] == 'P'
		|| aux->temp_array[y][x - 1] == 'P')
		return (1);
	else
		return (0);
}
