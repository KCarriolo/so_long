/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:43 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 14:57:25 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_events(int keycode, t_data *aux)
{
	ft_find_player(aux);
	ft_handle_moves(keycode, aux);
	return (0);
}

void	ft_find_player(t_data *aux)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (aux->array[y][x] != 'P')
	{
		if (aux->array[y])
		{
			x = 0;
			while (aux->array[y][x] && aux->array[y][x] != 'P')
				x++;
			if (aux->array[y][x] == 'P')
			{
				aux->p_x = x;
				aux->p_y = y;
				return ;
			}
			y++;
		}
	}	
}

void	ft_handle_moves(int keycode, t_data *aux)
{
	if (keycode == 13)
		ft_press_w(aux);
	if (keycode == 0)
		ft_press_a(aux);
	if (keycode == 1)
		ft_press_s(aux);
	if (keycode == 2)
		ft_press_d(aux);
	if (keycode == 53)
		exit(0);
	else
		return ;
}

int	ft_click_x(void)
{
	exit(0);
	return (0);
}
