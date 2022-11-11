/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:12:17 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/11 15:02:30 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_mouv_d(t_list *list)
{
	int	i;
	int	j;

	i = list->y_pers / 64;
	j = list->x_pers / 64;
	if (list->tab[i][j + 1] == '0')
	{
		list->tab[i][j + 1] = 'P';
		list->tab[i][j] = '0';
		return (0);
	}
	if (list->tab[i][j + 1] == 'C')
	{
		list->tab[i][j + 1] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	else if (list->tab[i][j + 1] == 'E' && list->ec_copy == 1)
		list->ec_copy = list->ec_copy - 1;
	return (1);
}

int	check_mouv_a(t_list *list)
{
	int	i;
	int	j;

	i = list->y_pers / 64;
	j = list->x_pers / 64;
	if (list->tab[i][j - 1] == '0')
	{
		list->tab[i][j - 1] = 'P';
		list->tab[i][j] = '0';
		return (0);
	}
	if (list->tab[i][j - 1] == 'C')
	{
		list->tab[i][j - 1] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	else if (list->tab[i][j - 1] == 'E' && list->ec_copy == 1)
		list->ec_copy = list->ec_copy - 1;
	return (1);
}

int	check_mouv_w(t_list *list)
{
	int	i;
	int	j;

	i = list->y_pers / 64;
	j = list->x_pers / 64;
	if (list->tab[i - 1][j] == '0')
	{
		list->tab[i - 1][j] = 'P';
		list->tab[i][j] = '0';
		return (0);
	}
	if (list->tab[i - 1][j] == 'C')
	{
		list->tab[i - 1][j] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	else if (list->tab[i - 1][j] == 'E' && list->ec_copy == 1)
		list->ec_copy = list->ec_copy - 1;
	return (1);
}

int	check_mouv_s(t_list *list)
{
	int	i;
	int	j;

	i = list->y_pers / 64;
	j = list->x_pers / 64;
	if (list->tab[i + 1][j] == '0')
	{
		list->tab[i + 1][j] = 'P';
		list->tab[i][j] = '0';
		return (0);
	}
	if (list->tab[i + 1][j] == 'C')
	{
		list->tab[i + 1][j] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	else if (list->tab[i + 1][j] == 'E' && list->ec_copy == 1)
		list->ec_copy = list->ec_copy - 1;
	return (1);
}
