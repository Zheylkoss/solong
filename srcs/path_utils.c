/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:24:52 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:41:31 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	found_e(t_list *list)
{
	int a;
	int	b;
	int d;

	d = 0;
	a = 0;
	b = 0;
	while (a < list->i)
	{
		d = ft_strlen(list->tab[a]);
		while (b < d)
		{
			if (list->tab[a][b] == 'E')
			{
				list->matrix[a][b] = '1';
				return (0);
			}
			b++;
		}
		b = 0;
		a++;
	}
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

int	findpath_c(int i, int j, t_list *list)
{
	if (list->path[i][j] == '0' && list->matrix[i][j] != '1' && list->path[i][j] != '8')
	{
		list->path[i][j] = '8';
		if (list->matrix[i][j] == '2')
		{
			list->path[i][j] = '0';
			list->matrix[i][j] = '0';
			list->c--;
			return (1);
		}
		if (findpath_c(i - 1, j, list) == 1)
			return (1);
		if (findpath_c(i, j - 1, list) == 1)
			return (1);
		if (findpath_c(i, j + 1, list) == 1)
			return (1);
		if (findpath_c(i + 1, j, list) == 1)
			return (1);
		list->path[i][j] = 1;
	}
	if (list->c == 0)
		return (3);
	return (0);
}

int	findpath_e(int i, int j, t_list *list)
{
	if (list->path[i][j] == '0' && list->matrix[i][j] != '1' && list->path[i][j] != '8')
	{
		list->path[i][j] = '8';
		if (list->matrix[i][j] == '4')
		{
			list->path[i][j] = '0';
			list->matrix[i][j] = '0';
			list->e--;
			return (1);
		}
		if (findpath_e(i - 1, j, list) == 1)
			return (1);
		if (findpath_e(i, j - 1, list) == 1)
			return (1);
		if (findpath_e(i, j + 1, list) == 1)
			return (1);
		if (findpath_e(i + 1, j, list) == 1)
			return (1);
		list->path[i][j] = 1;
	}
	if (list->e == 0)
		return (3);
	return (0);
}