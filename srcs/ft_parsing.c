/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/02 12:40:49 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	ft_check(int argc, char **argv)
{
	int	i;
	int j;

	j = 0;
	char tab[4] = ".ber";
	if (argc <= 1 || argc > 2)
	{
		ft_printf("nombre d'argument incorrect");
		return (0);
	}
	i = ft_strlen(argv[1]);
	if (i == 4)
	{
		ft_printf("error");
		return (0);
	}
	while(argv[1][i - 4])
	{
		if (argv[1][i - 4] == tab[j])
			j++;
		i++;
	}
	if (j != 4)
	{
		ft_printf("type de fichier incorrect");
		return (1);
	}
	else
		ft_printf("ok");
	return (0);
}

// int	ft_check_map(int argc, char **argv)
// {
// 	int	fd;

// 	fd = open(argv[1], O_RDWR);

// }
