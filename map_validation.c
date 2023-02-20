/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:41:41 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/24 16:58:59 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_validation(t_data *aux, char *join)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_is_a_rectangle(aux->array, x, y);
	ft_check_components(aux->array, x, y);
	ft_valid_path(aux, join);
}

void	ft_is_a_rectangle(char **array, int x, int y)
{
	int	x_sample;
	int	y_sample;

	x_sample = 0;
	y_sample = 0;
	while (array[y_sample][x_sample])
		x_sample++;
	while (array[y_sample])
		y_sample++;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
			x++;
		if (x != x_sample)
		{
			ft_printf("Error\nMap format is not functional in this program!");
			exit(0);
		}
		y++;
	}	
	x = 0;
	y = 0;
	ft_check_borderline(array, x_sample, y_sample);
}

void	ft_check_components(char **array, int x, int y)
{
	int	p_flag;
	int	e_flag;
	int	c_flag;

	p_flag = 0;
	e_flag = 0;
	c_flag = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'P')
				p_flag++;
			if (array[y][x] == 'C')
				c_flag++;
			if (array[y][x] == 'E')
				e_flag++;
			x++;
		}
		y++;
	}
	ft_analyze_components(p_flag, c_flag, e_flag);
}

void	ft_analyze_components(int p_flag, int c_flag, int e_flag)
{
	if (p_flag != 1)
	{
		ft_printf("Error\nPlayer count is not correct! Must be 1.");
		exit(0);
	}	
	if (e_flag != 1)
	{
		ft_printf("Error\nExit count is not correct! Must be 1.");
		exit(0);
	}
	if (c_flag <= 0)
	{
		ft_printf("Error\nCollectible count is not correct! At least 1.");
		exit(0);
	}
}

void	ft_check_borderline(char **array, int x_max, int y_max)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y][x])
	{
		if (array[y][x] != '1' || array[y_max - 1][x] != '1')
		{
			ft_printf("Error\nThe map borderlines must be surrounded by walls!");
			exit(0);
		}
		x++;
	}
	while (++y < (y_max - 1))
	{
		if (!(array[y][0] == '1') && !(array[y][x_max] == '1'))
		{
			ft_printf("Error\nThe map borderlines must be surrounded by walls!");
			exit(0);
		}
	}
}
