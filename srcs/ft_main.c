/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakariyahamdouchi <zakariyahamdouchi@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/27 18:25:15 by zakariyaham      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar("X");
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win_ptr;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(win_ptr, deal_key, 0);
	mlx_loop(mlx);
}
