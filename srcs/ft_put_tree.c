/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:57:43 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/10/31 15:41:54 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tree(int w_x, int w_y, void *mlx, void *win, void *img3)
{
	int	compteur_i;
	int compteur_y;
	int i;
	int y;

	compteur_i = 0;
	compteur_y = 0;
	i = 0;
	y = 0;
	compteur_i = w_x / 70;
	compteur_y = w_y / 70;
	while (0 < compteur_i)
	{
		mlx_put_image_to_window(mlx, win, img3, i, 0);
		i = i + 70;
		compteur_i--;	
	}
	y = 70;
	i = i - 70;
	while (2 < compteur_y)
	{
		mlx_put_image_to_window(mlx, win, img3, 0, y);
		mlx_put_image_to_window(mlx, win, img3, i, y);
		y = y + 70;
		compteur_y--;
	}
	i = 0;
	w_x = w_x - 70;
	while (i <= w_x)
	{
		mlx_put_image_to_window(mlx, win, img3, i, y);
		i = i + 70;	
	}
}

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