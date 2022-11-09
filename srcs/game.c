/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:15 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/09 18:33:17 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	ft_close_mouse (t_list *list)
{
	mlx_loop_end(list->mlx);
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
	free(list->mlx);// ????
	return (0);
}