/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/10 19:12:07 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	free_matrix(t_list *list);
// void	free_path(t_list *list);
void	free_tabchar(char **tab, t_list *list);

size_t	strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	list;
	int	b;
	int	c;

	list.tab = NULL;
	list.i = 0;
	list.fd = 0;
	list.e = 0;
	list.c = 0;
	list.p = 0;
	b = 0;
	c = 0;
	if (ft_check(argc, argv) == 0)
	{
		if (ft_check_map(argv, &list) == 0)
		{
			if (path_valid(&list) == 0)
				picture(&list);
		}
	}
	free_tabchar(list.tab, &list);
	free_tabchar(list.path, &list);
	free_tabchar(list.matrix, &list);
	return (0);
}

void free_tabchar(char **tab, t_list *list)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (i < list->i && tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

// void	free_path(t_list *list)
// {
// 	int a;

// 	a = 0;
// 	if (list->path != NULL)
// 	{
// 		while (a < list->i)
// 		{
// 			ft_printf("path a = %d\n", list->path[a][0]);
// 			free(list->path[a]);
// 			ft_printf("ligne = %d\n", a);
// 			a++;
// 		}
// 		free(list->path);
// 	}
// }

// void	free_matrix(t_list *list)
// {
// 	int a;

// 	a = 0;
// 	if (list->matrix != NULL)
// 	{
// 		while (a < list->i)
// 		{
// 			free(list->matrix[a]);
// 			a++;
// 		}
// 		free(list->matrix);
// 	}
// }