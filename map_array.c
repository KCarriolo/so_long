/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:03:13 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/27 10:57:59 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_array(t_data *aux, char *map)
{
	int		fd;
	char	*str;
	char	*join;

	join = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile descriptor error!");
		exit(0);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		join = ft_strjoin(join, str);
		//free(str);
	}
	//free(str);
	close(fd);
	aux->array = ft_split(join, '\n');
	ft_map_validation(aux, join);
	free(join);
	return (aux->array);
}
