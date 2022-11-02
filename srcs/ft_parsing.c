/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/02 19:15:52 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	fill_tab(char **argv, char **tab, int i, int fd);
int	check_lign(char **tab, int i);
int	check_len(char **tab, int i);
int	check_items(char **tab, int i);

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

int	ft_check_map(char **argv)
{
	int	fd;
	char **tab;
	char *taille;
	int i;

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
	close(fd);//securite ??
	tab = malloc(i * sizeof(char *));
		// if (tab == NULL)
		// 	return (freeatab(tab), 1);//reprendre la fonction de push_swap pour free
	if (fill_tab(argv, tab, i, fd) == 0)
	{
		check_len(tab, i);
		check_lign(tab, i);
		check_items(tab, i);//return le nombre de E et C Pour le right road
	}
	else
		return (1);
	//freetab
	return (0);
}


int	check_items(char **tab, int i)
{
	int	j;
	int	e;
	int	c;
	int	p;
	int pos;

	j = 0;
	e = 0;
	c = 0;
	p = 0;
	while (j < i)
	{
		pos = 0;
		while(tab[j][pos])
		{
			if (tab[j][pos] == 'E')
				e++;
			if (tab[j][pos] == 'C')
				c++;
			if (tab[j][pos] == 'P')
				p++;
			pos++;
		}
		j++;
	}
	if (p != 1 || c < 1 || e < 1)
	{
		ft_printf("erreur item");
		return (1);
	}
	return (0);
}


//comparaison des len pour etre sur que toutes les lignes sont de la meme taille
//et que le nombre de colonne est different du nombre de ligne
int	check_len(char **tab, int i)
{
	int	len;
	int	j;
	int len_comp;

	j = 1;
	len_comp = 0;
	len = ft_strlen(tab[0]);
	while (j < i)
	{
		len_comp = ft_strlen(tab[j]);
		if (len != len_comp)
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

int	fill_tab(char **argv, char **tab, int i, int fd)
{
	int j;

	j = 0;
	fd = open(argv[1], O_RDWR);
	i = 0;
	tab[i] = get_next_line (fd);
	if (tab[i] == NULL)
	{
		ft_printf("fichier vide\n");
		return (1);
	}
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
			ft_printf("erreur mur premiere ligne\n");
			return (1);
		}
		i++;
	}
	return (0);
}