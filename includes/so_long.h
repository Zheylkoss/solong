/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:56:59 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/08 15:21:51 by zhamdouc         ###   ########.fr       */
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

typedef struct	s_list
{
	int		i;
	int		e;
	int		c;
	int		x;
	int		y;
	int		p;
	int		fd;
	char **tab;
	int		a_p;
	int		j_p;
	int		ec;
	int		ec_copy;
	int		**path;
	int		**matrix;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	char	*relative_path;
	char	*relative_path2;
	char	*relative_path3;
	char	*relative_path4;
	char	*relative_path5;
	int		img_width;
	int		img_height;
	int		w_y;
	int		w_x;
	int		x_pers;
	int		y_pers;
}				t_list;
void	put_tree(t_list *list);
void	put_floor(int w_x, int w_y, void *mlx, void *win, void *img2);
int	ft_check(int argc, char **argv);
int	ft_check_map(char **argv, t_list *list);
int path_valid(t_list *list);
int	check_mouv_d(t_list *list);
int	check_mouv_a(t_list *list);
int	check_mouv_s(t_list *list);
int	check_mouv_w(t_list *list);

#endif
