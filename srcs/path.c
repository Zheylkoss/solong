/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:45:20 by zhamdouc          #+#    #+#             */
/*   Updated: 2022/11/04 15:44:45 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	findpath(int i, int j, t_list *list);
int path_fill(t_list *list, int **matrix, int **path);

int path_valid(t_list  *list)
{
	int i;
	int	j;

	(*list).ec = (*list).e + (*list).c;
	(*list).matrix = malloc ((*list).i * sizeof(int *));
	// if (matrix == NULL)
		// return (NULL);
	(*list).path = malloc ((*list).i * sizeof(int *));
		// if (matrix == NULL)
		// return (NULL);
	path_fill(list, (*list).matrix, (*list).path);
	i = (*list).j_p;
	j = (*list).a_p;
	findpath(i, j, list);
	if ((*list).ec == 0)
		ft_printf("un chemin vers la vitore existe \n");
	else
		ft_printf("il n'y a pas d'espoir\n");
	return (0);
}
//trouver la position de P
int	findpath(int i, int j, t_list *list)
{
	if ((*list).path[i][j] == 8)
		return (0);
	if ((*list).matrix[i][j] == 2)
	{
		(*list).path[i][j] = 0;
		(*list).matrix[i][j] = 0;
		(*list).ec--;
		findpath(i, j,list);
		return (1);
	}
	if ((*list).matrix[i][j] == 0)
	{
		(*list).path[i][j] = 8;
		if (findpath(i - 1, j, list) == 1)
			return (1);
		if (findpath(i, j - 1, list) == 1)
			return (1);
		if (findpath(i + 1, j, list) == 1)
			return (1);
		if (findpath(i, j + 1, list) == 1)
			return (1);
		(*list).path[i][j] = 1;
	}
	if ((*list).ec == 0)
	{
		ft_printf("un chemin existe");
		return (3);
	}
	return (0);
}
//appeler la fonction path fill

int path_fill(t_list *list, int **matrix, int **path)
{
	int	j;
	int	index;
	int	a;

	j = 0;
	index = 0;
	a = 0;
	while (j < (*list).i)
	{
		index  = ft_strlen((*list).tab[j]);
		matrix[j] = malloc ((index - 1) * sizeof(int));
		//if (matrix == NULL)
		//	return (freetab(matrix), NULL); prendre la fonction qui est dans push_swap
		path[j] = malloc ((index - 1) * sizeof(int));
		//if (path == NULL)
		//	return (freetab(path), NULL); prendre la fonction qui est dans push_swap ne pas oublier de free matrix
		while (a < index)
		{
			if ((*list).tab[j][a] == 'C' || (*list).tab[j][a] == 'E')
				matrix[j][a] = 2;
			else if ((*list).tab[j][a] == 'P')
			{
				matrix[j][a] = 0;
				(*list).j_p = j;
				(*list).a_p = a;
			}
			else
				matrix[j][a] = (*list).tab[j][a] - '0';
			path[j][a] = 0;
			a++;
		}
		a = 0;
		j++;
	}
	//freetab
	return (0);
}
