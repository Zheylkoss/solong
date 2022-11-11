/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/11 15:16:18 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	fill_tab(char **argv, char **tab, int i, t_list *list);
int	nb_lign(char **argv, t_list *list);
int	first_lign(int i, int j, char **tab);

int	ft_check(char **argv)
{
	int		i;
	int		j;
	char	tab[5];

	tab[0] = '.';
	tab[1] = 'b';
	tab[2] = 'e';
	tab[3] = 'r';
	tab[4] = '\0';
	j = 0;
	i = ft_strlen(argv[1]);
	while (argv[1][i - 4])
	{
		if (argv[1][i - 4] == tab[j])
			j++;
		i++;
	}
	if (j != 4 || i < 4)
		ft_printf("type de fichier incorrect\n");
	else
		return (0);
	return (1);
}

int	ft_check_map(char **argv, t_list *list)
{
	int	n;

	n = 0;
	if (nb_lign(argv, list) == 1)
		return (1);
	list->tab = malloc(list->i * sizeof(char *));
	if (list->tab == NULL)
		return (1);
	if (fill_tab(argv, list->tab, list->i, list) == 0)
	{
		n = n + check_len(1, list->tab, list->i, list);
		n = n + check_lign(1, list->tab, list->i);
		n = n + check_items(0, list->tab, list->i, list);
		if (n != 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	nb_lign(char **argv, t_list *list)
{
	char	*taille;

	taille = NULL;
	list->fd = open(argv[1], O_RDWR);
	if (list->fd == -1)
		return (1);
	while (1)
	{
		taille = get_next_line (list->fd);
		if (taille == NULL)
			break ;
		list->i++;
		free(taille);
	}
	close(list->fd);
	if (list->fd == -1)
		return (1);
	return (0);
}

int	fill_tab(char **argv, char **tab, int i, t_list *list)
{
	int	j;

	j = 0;
	list->fd = open(argv[1], O_RDWR);
	if (list->fd == -1)
		return (1);
	i = 0;
	while (i < list->i)
	{
		tab[i] = get_next_line (list->fd);
		i++;
	}
	close(list->fd);
	if (list->fd == -1)
		return (1);
	if (tab[0] == NULL || tab[0][0] != '1')
	{
		ft_printf("fichier vide ou debut de ligne incorrect\n");
		return (1);
	}
	if (first_lign(0, 0, tab) == 1)
		return (1);
	return (0);
}

int	first_lign(int i, int j, char **tab)
{
	while (tab[j][i])
	{
		if (tab[0][i] != '1' && tab[0][i] != '\n')
		{
			ft_printf("erreur mur premiere ligne\n");
			return (1);
		}
		i++;
	}
	return (0);
}
