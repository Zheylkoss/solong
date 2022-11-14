/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:45:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/11 16:21:24 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int		path_fill(t_list *list);
void	empty_the_path(int z, t_list *list);

void	empty_the_path(int z, t_list *list)
{
	int	len;
	int	y;

	while (z < list->i)
	{
		y = 0;
		len = ft_strlen(list->tab[z]);
		while (y < len)
		{
			list->path[z][y] = '0';
			y++;
		}
		z++;
	}
}

void	verify_path(int i, int j, t_list *list)
{
	while (list->e != 0)
	{
		i = list->j_p;
		j = list->a_p;
		if (findpath_e(i, j, list) == 0)
			break ;
		empty_the_path(0, list);
	}
	found_e(list);
	empty_the_path(0, list);
	while (list->c != 0)
	{
		i = list->j_p;
		j = list->a_p;
		if (findpath_c(i, j, list) == 0)
			break ;
		empty_the_path(0, list);
	}
}

int	path_valid(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	list->ec_copy = list->c + list->e;
	list->matrix = malloc (list->i * sizeof(char *));
	if (list->matrix == NULL)
		return (1);
	list->path = malloc (list->i * sizeof(char *));
	if (list->path == NULL)
		return (1);
	if (path_fill(list) != 0)
		return (1);
	verify_path(i, j, list);
	if (list->c == 0 && list->e == 0)
		return (0);
	else
	{
		ft_printf("Error\nNo way to finish this map\n");
		return (1);
	}
	return (0);
}

void	path_fill_loop(t_list *list, int index, int a, int j)
{
	while (a < (index - 1))
	{
		list->matrix[j][a] = list->tab[j][a];
		if (list->tab[j][a] == 'P')
		{
			list->j_p = j;
			list->a_p = a;
		}
		list->path[j][a] = '0';
		a++;
	}
		list->matrix[j][a] = '\0';
		list->path[j][a] = '\0';
}

int	path_fill(t_list *list)
{
	int	j;
	int	index;
	int	a;

	j = 0;
	index = 0;
	a = 0;
	index = ft_strlen(list->tab[j]);
	while (j < list->i)
	{
		list->matrix[j] = malloc (index * sizeof(char));
		if (list->matrix == NULL)
			return (1);
		list->path[j] = malloc (index * sizeof(char));
		if (list->path == NULL)
			return (1);
		path_fill_loop(list, index, a, j);
		a = 0;
		j++;
	}
	return (0);
}
