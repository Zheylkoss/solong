/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:56:59 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/31 13:41:37 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "./../libs/minilibx-linux/mlx.h"
#include <unistd.h>
#include "./../libs/printf/libftprintf.h"

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
}				t_vars;
void	put_tree(int w_x, int w_y, void *mlx, void *win, void *img3);

#endif