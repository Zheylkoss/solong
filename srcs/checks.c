/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:27:53 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/09 21:56:25 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	check_items(char **tab, int i, t_list *list)
{
	int	j;
	int	pos;

	j = 0;
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
		ft_printf("erreur item");
		return (1);
	}
	ft_printf("c : %d\ne : %e\n", list->c, list->e);
	return (0);
}


//comparaison des len pour etre sur que toutes les lignes sont de la meme taille
//et que le nombre de colonne est different du nombre de ligne
int	check_len(char **tab, int i, t_list *list)
{
	int	j;

	j = 1;
	list->len_comp = 0;
	list->len = strlen(tab[0]);
	while (j < i)
	{
		list->len_comp = strlen(tab[j]);
		if (list->len != list->len_comp)
		{
			ft_printf("probleme de taille de ligne\n");
			return (1);
		}
		j++;
	}
	j = 0;
	while (tab[i - 1][j])
	{
		if (tab[i -1][j] != '1' && tab[i - 1][j] != '\n')
		{
			ft_printf("erreur derniere ligne\n");
			return (1);
		}
		j++;
	}
	return (0);
}

//je check le contenu des lignes, ca commence est finis par 1, contient des 0 et les lettres autorise
int	check_lign(char **tab, int i)
{
	int j;
	int	pos;
	int	len;
	
	j = 1;
	while (j < (i - 1))
	{
		pos = 1;
		len = ft_strlen(tab[j]);
		if (tab[j][0] != '1' || tab[j][len - 2] != '1')
		{
			ft_printf("erreur sur les murs\n");
			return (1);
		}
		while (tab[j][pos + 2])
		{
			if (tab[j][pos] != '0' && tab[j][pos] != 'E' && tab[j][pos] != 'C' && tab[j][pos] != 'P' && tab[j][pos] != '1')
			{
				ft_printf("la terre du milieu\n");
				return (1);
			}
			pos++;
		}
		j++;
	}
	return (0);
}