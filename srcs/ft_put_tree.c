/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/07 14:53:40 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tree(t_list *list)
{
	int c;
	int b;
	int d;
	int x;
	int	y;

	b = 0;
	c = 0;
	d = 0;
	x = 0;
	y = 0;
	//il manque l'image pour C et E
	while (b < list->i)
	{
		d = ft_strlen(list->tab[b]);
		while (c < d)
		{
			if (list->tab[b][c] == 'C')
				mlx_put_image_to_window(list->mlx, list->win, list->img4, x, y);
			if (list->tab[b][c] == '1')
				mlx_put_image_to_window(list->mlx, list->win, list->img3, x, y);
			if (list->tab[b][c] == '0')
				mlx_put_image_to_window(list->mlx, list->win, list->img2, x, y);
			if (list->tab[b][c] == 'P')
				mlx_put_image_to_window(list->mlx, list->win, list->img, x, y);
			if (list->tab[b][c] == 'E')
				mlx_put_image_to_window(list->mlx, list->win, list->img5, x, y);
			x = x + 64;
			c++;
		}
		c = 0;
		x = 0;
		y = y + 64;
		b++;
	}
	/*
	while (0 < compteur_i)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, i, 0);
		i = i + 70;
		compteur_i--;	
	}
	y = 70;
	i = i - 70;
	while (2 < compteur_y)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, 0, y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, i, y);
		y = y + 70;
		compteur_y--;
	}
	i = 0;
	vars->w_x = vars->w_x - 70;
	while (i <= vars->w_x)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img3, i, y);
		i = i + 70;	
	}
	*/
}
//fonction possiblement inutile si j'utilise tab pour actualiser a chaque fois 
/*
void	put_floor(int w_x, int w_y, void *mlx, void *win, void *img2)
{
	int	compteur_i;
	int compteur_y;
	int i;
	int y;
	int copy;

	compteur_i = 0;
	compteur_y = 0;
	i = 0;
	y = 0;
	copy = w_x / 127;
	compteur_y = w_y / 95;
	while (0 < compteur_y)
	{
		compteur_i = copy;
		i = 0;
		while (0 < compteur_i)
		{
			mlx_put_image_to_window(mlx, win, img2, i, y);
			i = i + 127;
			compteur_i--;	
		}
		y = y + 95;
		compteur_y--;
	}
}
*/