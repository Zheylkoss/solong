/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/07 19:17:39 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;
/*
typedef struct	s_vars
{
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
}				t_vars;
*/
//peut etre devoir tout mettre dans liste car peut etre qu'on reussira pas a envoyer 2 struct

int	close1(int keycode, t_list *list)
{
	if (keycode == 65307)
		mlx_loop_end(list->mlx);
	if (keycode == 100)
	{
		if (check_mouv_d(list) == 0)
			list->x_pers = list->x_pers + 64;
	}
	if (keycode == 97)
	{
		if (check_mouv_a(list) == 0)
			list->x_pers = list->x_pers - 64;
	}
	if (keycode == 115)
	{
		if (check_mouv_s(list) == 0)
			list->y_pers = list->y_pers + 64;
	}
	if (keycode == 119)
	{
		if (check_mouv_w(list) == 0)
			list->y_pers = list->y_pers - 64;
	}
	put_tree(list);
	if (list->ec_copy == 0)
		mlx_loop_end(list->mlx);
	return (0);
}

// int	key_d(int keycode, t_vars *vars)
// {
// 	return (0);
// }
int	ft_close_mouse (t_list *list)
{
	mlx_loop_end(list->mlx);
	return (0);
}

int	found_p(t_list *list)
{
	int a;
	int	b;
	int d;

	d = 0;
	a = 0;
	b = 0;
	while (b < list->i)
	{
		d = ft_strlen(list->tab[a]);
		while (b < d)
		{
			if (list->tab[a][b] == 'P')
			{
				list->x_pers = 64 * b;
				list->y_pers = 64 * a;
				return (0);
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

int	picture(t_list *list)
{
	int	len;

	found_p(list);
	len = ft_strlen(list->tab[0]) - 1;
	list->w_x = 64 * len;
	list->w_y = 64 * list->i;
	list->mlx = mlx_init();
	list->relative_path = "./image/dwarf.xpm";
	list->relative_path2 = "./image/wall.xpm";
	list->relative_path3 = "./image/tree.xpm";
	list->relative_path4 = "./image/ring.xpm";
	list->relative_path5 = "./image/real_end_door.xpm";
	list->img = mlx_xpm_file_to_image(list->mlx, list->relative_path, &list->img_width, &list->img_height);
	list->img2 = mlx_xpm_file_to_image(list->mlx, list->relative_path2, &list->img_width, &list->img_height);
	list->img3 = mlx_xpm_file_to_image(list->mlx, list->relative_path3, &list->img_width, &list->img_height);
	list->img4 = mlx_xpm_file_to_image(list->mlx, list->relative_path4, &list->img_width, &list->img_height);
	list->img5 = mlx_xpm_file_to_image(list->mlx, list->relative_path5, &list->img_width, &list->img_height);
	list->win = mlx_new_window(list->mlx, list->w_x, list->w_y, "Hello world!");
	mlx_hook(list->win, 17, 1L<<17, ft_close_mouse, list);
	put_tree(list);
	mlx_hook(list->win, 2, 1L<<0, close1, list);
	mlx_loop(list->mlx);
	mlx_destroy_window(list->mlx, list->win);
	mlx_destroy_display(list->mlx);
	return (0);

}

int	main(int argc, char **argv)
{
	t_list	list;
	int	b;
	int	c;
	int d;
	
	list.i = 0;
	b = 0;
	c = 0;
	if (ft_check(argc, argv) == 0)
	{
		if (ft_check_map(argv, &list) == 0)
		{
			if (path_valid(&list) == 0)
				picture(&list);
		}
	}
	ft_printf("%d\n", list.ec_copy);
	while (b < list.i)
	{
		d = ft_strlen(list.tab[b]);
		while (c < d)
		{
			ft_printf("%c", list.tab[b][c]);
			c++;
		}
		c = 0;
		b++;
	}
	return (0);
}

