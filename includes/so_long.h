/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:56:59 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/04 14:40:59 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./../libs/minilibx-linux/mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./../libs/printf/libftprintf.h"
#include "./../libs/gnl/get_next_line.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	char	*relative_path;
	char	*relative_path2;
	char	*relative_path3;
	int		img_width;
	int		img_height;
	int		w_y;
	int		w_x;
	int		x_pers;
	int		y_pers;
}				t_vars;
typedef struct	s_list
{
	int		i;
	int		e;
	int		c;
	int		p;
	int		fd;
	char **tab;
	int		a_p;
	int		j_p;
	int		ec;
	int		**path;
	int		**matrix;
}				t_list;
void	put_tree(int w_x, int w_y, void *mlx, void *win, void *img3);
void	put_floor(int w_x, int w_y, void *mlx, void *win, void *img2);
int	ft_check(int argc, char **argv);
int	ft_check_map(char **argv, t_list *list);
int path_valid(t_list *list);

#endif
