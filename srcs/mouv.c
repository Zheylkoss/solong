/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:12:17 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/07 17:50:20 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//soit il faut considerer E comme un mur, soit il faut pouvoir mettre le P sur la case E tout en conservant la case E en memoire
//pour pouvoir remmtre le E une fois que P a quitte la case

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
	if (list->tab[i][j + 1] == 1)
	{
		list->tab[i][j + 1] = '1';
		list->tab[i][j] = 'P';
		return (1);
	}
	if (list->tab[i][j + 1] == 'C')
	{
		list->tab[i][j + 1] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	if (list->tab[i][j + 1] == 'E' && list->ec_copy != 1)
	{
		list->tab[i][j + 1] = 'E';
		list->tab[i][j] = 'P';
		return (1);
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
	if (list->tab[i][j - 1] == 1)
	{
		list->tab[i][j - 1] = '1';
		list->tab[i][j] = 'P';
		return (1);
	}
	if (list->tab[i][j - 1] == 'C')
	{
		list->tab[i][j - 1] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	if (list->tab[i][j - 1] == 'E' && list->ec_copy != 1)
	{
		list->tab[i][j - 1] = 'E';
		list->tab[i][j] = 'P';
		return (1);
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
		list->tab[i- 1][j] = 'P';
		list->tab[i][j] = '0';
		return (0);
	}
	if (list->tab[i - 1][j] == 1)
	{
		list->tab[i - 1][j] = '1';
		list->tab[i][j] = 'P';
		return (1);
	}
	if (list->tab[i - 1][j] == 'C')
	{
		list->tab[i - 1][j] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	if (list->tab[i - 1][j] == 'E' && list->ec_copy != 1)
	{
		list->tab[i - 1][j] = 'E';
		list->tab[i][j] = 'P';
		return (1);
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
	if (list->tab[i + 1][j] == 1)
	{
		list->tab[i + 1][j] = '1';
		list->tab[i][j] = 'P';
		return (1);
	}
	if (list->tab[i + 1][j] == 'C')
	{
		list->tab[i + 1][j] = 'P';
		list->tab[i][j] = '0';
		list->ec_copy = list->ec_copy - 1;
		return (0);
	}
	if (list->tab[i + 1][j] == 'E' && list->ec_copy != 1)
	{
		list->tab[i + 1][j] = 'E';
		list->tab[i][j] = 'p';
		return (1);
	}
	else if (list->tab[i + 1][j] == 'E' && list->ec_copy == 1)
		list->ec_copy = list->ec_copy - 1;
	return (1);
}