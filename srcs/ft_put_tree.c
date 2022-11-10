/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/10 20:11:09 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_the_correct_img(int c, int i, int len, t_list *list);

void	put_tree(t_list *list)
{
	int	c;
	int	i;
	int	len;

	i = 0;
	c = 0;
	list->x = 0;
	list->y = 0;
	while (i < list->i)
	{
		len = ft_strlen(list->tab[i]);
		put_the_correct_img(c, i, len, list);
		c = 0;
		list->x = 0;
		list->y = list->y + 64;
		i++;
	}
}

void	put_the_correct_img(int c, int i, int len, t_list *list)
{
	while (c < len)
	{
		if (list->tab[i][c] == 'C')
			mlx_put_image_to_window(list->mlx, list->win,
				list->img4, list->x, list->y);
		if (list->tab[i][c] == '1')
			mlx_put_image_to_window(list->mlx, list->win,
				list->img3, list->x, list->y);
		if (list->tab[i][c] == '0')
			mlx_put_image_to_window(list->mlx, list->win,
				list->img2, list->x, list->y);
		if (list->tab[i][c] == 'P')
			mlx_put_image_to_window(list->mlx, list->win,
				list->img, list->x, list->y);
		if (list->tab[i][c] == 'E')
			mlx_put_image_to_window(list->mlx, list->win,
				list->img5, list->x, list->y);
		list->x = list->x + 64;
		c++;
	}
}

void	init(t_list *list)
{
	int	len;

	found_p(list);
	len = ft_strlen(list->tab[0]) - 1;
	list->w_x = 64 * len;
	list->w_y = 64 * list->i;
	list->img = NULL;
	list->img2 = NULL;
	list->img3 = NULL;
	list->img4 = NULL;
	list->img5 = NULL;
	list->mlx = NULL;
	list->win = NULL;
	list->img_path = "./image/dwarf.xpm";
	list->img_path2 = "./image/wall.xpm";
	list->img_path3 = "./image/tree.xpm";
	list->img_path4 = "./image/ring.xpm";
	list->img_path5 = "./image/real_end_door.xpm";
}

void	clean_all(t_list *list)
{
	if (list->img != NULL)
		mlx_destroy_image(list->mlx, list->img);
	if (list->img != NULL)
		mlx_destroy_image(list->mlx, list->img2);
	if (list->img != NULL)
		mlx_destroy_image(list->mlx, list->img3);
	if (list->img != NULL)
		mlx_destroy_image(list->mlx, list->img4);
	if (list->img != NULL)
		mlx_destroy_image(list->mlx, list->img5);
	if (list->win != NULL)
		mlx_destroy_window(list->mlx, list->win);
	if (list->mlx != NULL)
	{
		mlx_destroy_display(list->mlx);
		free(list->mlx);
	}
}
