/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:12:17 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 14:35:02 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_press_w(t_data *aux)
{
	if (aux->array[aux->p_y - 1][aux->p_x] == '0'
		|| aux->array[aux->p_y - 1][aux->p_x] == 'C'
		|| aux->array[aux->p_y - 1][aux->p_x] == 'E')
	{
		if (aux->array[aux->p_y - 1][aux->p_x] == 'C')
			aux->collectible_count--;
		if (aux->array[aux->p_y - 1][aux->p_x] == 'E')
		{
			if (aux->collectible_count == 0)
			{
				aux->array[aux->p_y][aux->p_x] = '0';
				aux->array[aux->p_y - 1][aux->p_x] = 'P';
				aux->count_moves++;
				ft_printf("%i\n", aux->count_moves);
				exit(0);
			}	
			return ;
		}
		aux->array[aux->p_y][aux->p_x] = '0';
		aux->array[aux->p_y - 1][aux->p_x] = 'P';
		aux->count_moves++;
		ft_map_rend(aux);
	}	
	else
		return ;
}

void	ft_press_a(t_data *aux)
{
	if (aux->array[aux->p_y][aux->p_x - 1] == '0'
		|| aux->array[aux->p_y][aux->p_x - 1] == 'C'
		|| aux->array[aux->p_y][aux->p_x - 1] == 'E')
	{
		if (aux->array[aux->p_y][aux->p_x - 1] == 'C')
			aux->collectible_count--;
		if (aux->array[aux->p_y][aux->p_x - 1] == 'E')
		{
			if (aux->collectible_count == 0)
			{
				aux->array[aux->p_y][aux->p_x] = '0';
				aux->array[aux->p_y][aux->p_x - 1] = 'P';
				aux->count_moves++;
				ft_printf("%i\n", aux->count_moves);
				exit(0);
			}	
			return ;
		}
		aux->array[aux->p_y][aux->p_x] = '0';
		aux->array[aux->p_y][aux->p_x - 1] = 'P';
		aux->count_moves++;
		ft_map_rend(aux);
	}
	else
		return ;
}

void	ft_press_s(t_data *aux)
{
	if (aux->array[aux->p_y + 1][aux->p_x] == '0'
		|| aux->array[aux->p_y + 1][aux->p_x] == 'C'
		|| aux->array[aux->p_y + 1][aux->p_x] == 'E')
	{
		if (aux->array[aux->p_y + 1][aux->p_x] == 'C')
			aux->collectible_count--;
		if (aux->array[aux->p_y + 1][aux->p_x] == 'E')
		{
			if (aux->collectible_count == 0)
			{
				aux->array[aux->p_y][aux->p_x] = '0';
				aux->array[aux->p_y + 1][aux->p_x] = 'P';
				aux->count_moves++;
				ft_printf("%i\n", aux->count_moves);
				exit(0);
			}	
			return ;
		}
		aux->array[aux->p_y][aux->p_x] = '0';
		aux->array[aux->p_y + 1][aux->p_x] = 'P';
		aux->count_moves++;
		ft_map_rend(aux);
	}
	else
		return ;
}

void	ft_press_d(t_data *aux)
{
	if (aux->array[aux->p_y][aux->p_x + 1] == '0'
		|| aux->array[aux->p_y][aux->p_x + 1] == 'C'
		|| aux->array[aux->p_y][aux->p_x + 1] == 'E')
	{
		if (aux->array[aux->p_y][aux->p_x + 1] == 'C')
			aux->collectible_count--;
		if (aux->array[aux->p_y][aux->p_x + 1] == 'E')
		{
			if (aux->collectible_count == 0)
			{
				aux->array[aux->p_y][aux->p_x] = '0';
				aux->array[aux->p_y][aux->p_x + 1] = 'P';
				aux->count_moves++;
				ft_printf("%i\n", aux->count_moves);
				exit(0);
			}	
			return ;
		}
		aux->array[aux->p_y][aux->p_x] = '0';
		aux->array[aux->p_y][aux->p_x + 1] = 'P';
		aux->count_moves++;
		ft_map_rend(aux);
	}
	else
		return ;
}
