/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nice_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:01:57 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/22 15:01:33 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'r')
	{
		if (str[i - 1] == 'e')
		{
			if (str[i - 2] == 'b')
			{
				if (str[i - 3] == '.')
					return ;
			}
		}
	}	
	ft_printf("%s\n", "Map format is not correct! Must be .ber");
	exit(0);
}

int	ft_nice_x(char *map)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Invalid fd!");
		return (1);
	}
	str = get_next_line(fd);
	while (str[i])
		i++;
	i -= 1;
	free(str);
	close (fd);
	return (i);
}

int	ft_nice_y(char *map)
{
	int		i;
	int		fd;
	char	*str;

	i = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Invalid fd!");
		return (1);
	}
	str = get_next_line(fd);
	if (str)
	{
		while (str)
		{
			free(str);
			str = get_next_line(fd);
			i++;
		}
		i -= 1;
	}
	free(str);
	close (fd);
	return (i);
}
