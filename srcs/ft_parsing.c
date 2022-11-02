/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/02 15:30:47 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	fill_tab(char **argv, char **tab, int i, int fd);
int	check_lign(char **tab, int i);

int	ft_check(int argc, char **argv)
{
	int	i;
	int j;

	j = 0;
	char tab[4] = ".ber";
	if (argc <= 1 || argc > 2)
	{
		ft_printf("nombre d'argument incorrect\n");
		return (1);
	}
	i = ft_strlen(argv[1]);
	if (i == 4)
	{
		ft_printf("error\n");
		return (1);
	}
	while(argv[1][i - 4])
	{
		if (argv[1][i - 4] == tab[j])
			j++;
		i++;
	}
	if (j != 4)
	{
		ft_printf("type de fichier incorrect\n");
		return (1);
	}
	else
		ft_printf("ok\n");
	return (0);
}

// int	ft_check_map(char **argv)
// {
// 	int	fd;
// 	char *tab;
// 	int i;

// 	i = 0;
// 	fd = 0;
// 	fd = open(argv[1], O_RDWR);
// 	tab = get_next_line (fd);
// 	if (tab[0] == '\n')
// 	{
// 		ft_printf("il y a rien");
// 		return (1); //sauf si c'est la derniere ligne
// 	}
// 	while (tab[0] != '\n')
// 	{
// 		i = 0;
// 		while (tab[i])
// 		{
// 			if (tab[i] != '1' && tab[i] != '\n')//attention au cas ou il y aura juste un "\n"
// 			{
// 				ft_printf("erreur de map\n");
// 				return (1);
// 			}
// 			i++;
// 		}
// 		tab = get_next_line (fd);
// 	}
// 	ft_printf("ok\n");
// 	return (0);

// }

int	ft_check_map(char **argv)
{
	int	fd;
	char **tab;
	char *taille;
	int i;
	//int j;

	tab = NULL;
	i = 0;
	fd = 0;
	fd = open(argv[1], O_RDWR);// securite ?
 	taille = get_next_line (fd);
	while (taille)
	{
		i++;
		taille = get_next_line (fd);
	}
	ft_printf("nombre de ligne %d\n", i);
	close(fd);//securite ??
	tab = malloc(i * sizeof(char *));
		// if (tab == NULL)
		// 	return (freeatab(tab), 1);//reprendre la fonction de push_swap pour free
	if (fill_tab(argv, tab, i, fd) == 0)
		check_lign(tab, i);
	else
		return (1);
	ft_printf("ok");
	return (0);
}

int	check_lign(char **tab, int i)
{
	int j;
	int	pos;
	int	len;
	
	j = 1;
	while (j < i)
	{
		pos = 1;
		len = ft_strlen(tab[j]);
		if (tab[j][0] != '1' && tab[j][len] != '1')
			return (1);
		while (tab[j][pos])
		{
			if (tab[j][pos] != '0')
				return (1);
			pos++;
		}
		j++;
	}
	i = 0;
	while (tab[j][i])
	{
		if (tab[j][i] != '1' && tab[j][i] != '\n')//attention au cas ou il y aura juste un "\n"
		{
			ft_printf("erreur de map\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	fill_tab(char **argv, char **tab, int i, int fd)
{
	int j;

	j = 0;
	fd = open(argv[1], O_RDWR);
	i = 0;
	tab[i] = get_next_line (fd);
	while (tab[i])
	{
		i++;
		tab[i] = get_next_line (fd);
	}
	close(fd);
	i = 0;
	j = 0;
	while (tab[j][i])
	{
		if (tab[0][i] != '1' && tab[0][i] != '\n')//attention au cas ou il y aura juste un "\n"
		{
			ft_printf("erreur de map\n");
			return (1);
		}
		i++;
	}
	return (0);
}