/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:33:01 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/02 11:40:37 by zakariyaham      ###   ########.fr       */
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
	i = ft_strlen(argv[2]);
	while(argv[2][i - 4])
	{
		if (argv[2][i - 4] == tab[j])
			j++;
		i++;
	}
	if (j != 3)
		return (1);
}
