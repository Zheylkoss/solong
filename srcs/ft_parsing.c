/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/09 19:32:03 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	fill_tab(char **argv, char **tab, int i, t_list *list);
int nb_lign(char **argv, t_list *list);
int	first_lign (int i, int j, char **tab);

int	ft_check(int argc, char **argv)
{
	int	i;
	int j;

	j = 0;
	char tab[4] = ".ber";
	if (argc <= 1 || argc > 2)
	{
		ft_printf("nombre d'argument incorrect\n");//2
		return (1);
	}
	i = ft_strlen(argv[1]);
	while(argv[1][i - 4])
	{
		if (argv[1][i - 4] == tab[j])
			j++;
		i++;
	}
	if (j != 4 || i < 4)
		ft_printf("type de fichier incorrect\n");//4
	else
		return(0);
	return (1);
}
//renvoyer une valeur differente (n) pour chaque erreur
int	ft_check_map(char **argv, t_list *list)
{
	int n;

	n = 0;
	if (nb_lign(argv, list) ==  1)
		return (1);
	list->tab = malloc(list->i * sizeof(char *));
	if (list->tab == NULL)
		return (1);
	if (fill_tab(argv, list->tab, list->i, list) == 0)
	{
		n = n + check_len(list->tab, list->i, list);
		n = n + check_lign(list->tab, list->i);
		n = n + check_items(list->tab, list->i, list);
		if (n != 0)
			return (1);
	}
	else
		return (1);
	//freetab si probleme car on utilise le tab dans path_valid
	return (0);
}

int nb_lign(char **argv, t_list *list)
{
	char *taille;
	
	taille = NULL;
	list->fd = open(argv[1], O_RDWR);// securite ?
 	//taille = get_next_line (list->fd);
	while (1)
	{
		taille = get_next_line (list->fd);
		if (taille == NULL)
			break;
		list->i++;
		free(taille);
	}
	close(list->fd);//securite ??
	return (0);
}

int	fill_tab(char **argv, char **tab, int i, t_list *list)
{
	int j;

	j = 0;
	list->fd = open(argv[1], O_RDWR);//securite
	i = 0;
	while (i < list->i)
	{
		tab[i] = get_next_line (list->fd);
		i++;
	}
	close(list->fd);//securite
	if (tab[0] == NULL || tab[0][0] != '1')//debut de fichier incorrect
	{
		ft_printf("fichier vide\n");
		return (1);
	}
	if (first_lign(0, 0, tab) == 1)
		return (1);
	// i = 0;
	// j = 0;
	return (0);
}

int	first_lign (int i, int j, char **tab)
{
	while (tab[j][i])
	{
		if (tab[0][i] != '1' && tab[0][i] != '\n')//attention au cas ou il y aura juste un "\n"
		{
			ft_printf("erreur mur premiere ligne\n");
			return (1);
		}
		i++;
	}
	return (0);
}