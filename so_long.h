/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefernan <kefernan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:02:00 by kefernan          #+#    #+#             */
/*   Updated: 2022/09/26 10:28:49 by kefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx_mms_20200219/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_events
{
	void		*mlx;
	void		*mlx_win;
	char		**array;
	char		**temp_array;
	int			map_size;
	int			p_x;
	int			p_y;
	int			count_moves;
	int			collectible_count;
	int			collectible_total;
}	t_data;

char	**ft_map_array(t_data *aux, char *map);

void	ft_map_rend(t_data *aux);

void	ft_put_tiles(t_data *aux, int x, int y);

void	ft_put_wall(void *mlx, void *mlx_win, int x_resize, int y_resize);

void	ft_put_floor(void *mlx, void *mlx_win, int x_resize, int y_resize);

void	ft_put_collect(t_data *aux, int x_resize, int y_resize);

void	ft_put_player(void *mlx, void *mlx_win, int x_resize, int y_resize);

void	ft_put_exit(void *mlx, void *mlx_win, int x_resize, int y_resize);

int		ft_nice_x(char *map);

int		ft_nice_y(char *map);

int		ft_events(int keycode, t_data *aux);

void	ft_handle_moves(int keycode, t_data *aux);

void	ft_press_w(t_data *aux);

void	ft_press_a(t_data *aux);

void	ft_press_s(t_data *aux);

void	ft_press_d(t_data *aux);

int		ft_click_x(void);

void	ft_find_player(t_data *aux);

void	ft_map_validation(t_data *aux, char *join);

void	ft_valid_path(t_data *aux, char *join);

void	ft_path_valid_find_player(t_data *aux, int x, int y);

int		ft_verify_around_p(t_data *aux, int x, int y);

void	ft_infestation(t_data *aux);

void	ft_check_the_plague(t_data *aux, int x, int y);

int		ft_check_valid_exit(t_data *aux, int x, int y);

void	ft_check_extension(char *str);

void	ft_is_a_rectangle(char **array, int x, int y);

void	ft_check_components(char **array, int x, int y);

void	ft_analyze_components(int p_flag, int c_flag, int e_flag);

void	ft_check_borderline(char **array, int x_max, int y_max);

#endif
