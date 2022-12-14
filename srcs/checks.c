/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:27:53 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/11 16:16:39 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	check_items(int j, char **tab, int i, t_list *list)
{
	int	pos;

	while (j < i)
	{
		pos = 0;
		while (tab[j][pos])
		{
			if (tab[j][pos] == 'E')
				list->e++;
			if (tab[j][pos] == 'C')
				list->c++;
			if (tab[j][pos] == 'P')
				list->p++;
			pos++;
		}
		j++;
	}
	if (list->p != 1 || list->c < 1 || list->e != 1)
	{
		ft_printf("Error\n about item\n");
		return (1);
	}
	return (0);
}

int	check_len(int j, char **tab, int i, t_list *list)
{
	list->len_comp = 0;
	list->len = strlen(tab[0]);
	while (j < i)
	{
		list->len_comp = strlen(tab[j]);
		if (list->len != list->len_comp)
		{
			ft_printf("Error\n on line size\n");
			return (1);
		}
		j++;
	}
	j = 0;
	while (tab[i - 1][j])
	{
		if (tab[i -1][j] != '1' && tab[i - 1][j] != '\n')
		{
			ft_printf("Error\n on last line\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_lign(int j, char **tab, int i)
{
	int	pos;
	int	len;

	while (j < (i - 1))
	{
		pos = 1;
		len = ft_strlen(tab[j]);
		if (tab[j][0] != '1' || tab[j][len - 2] != '1')
		{
			ft_printf("Error\n about the walls\n");
			return (1);
		}
		while (tab[j][pos + 2])
		{
			if (tab[j][pos] != '0' && tab[j][pos] != 'E' && tab[j][pos] != 'C'
				&& tab[j][pos] != 'P' && tab[j][pos] != '1')
			{
				ft_printf("Error\n inside the map\n");
				return (1);
			}
			pos++;
		}
		j++;
	}
	return (0);
}
