/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/31 14:22:54 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

int	close1(int keycode, void *mlx, void *win)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx, win);
	ft_printf("%d", keycode);
	return (0);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close1, &vars);
// 	mlx_loop(vars.mlx);
// }

int	main(void)
{
	t_vars	vars;

	vars.w_x = 500;
	vars.w_y = 500;
	vars.mlx = mlx_init();
	vars.relative_path = "./image/Attack2.xpm";
	vars.relative_path2 = "./image/Attack3.xpm";
	vars.relative_path3 = "./image/arbre1.xpm";
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.img_width, &vars.img_height);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path2, &vars.img_width, &vars.img_height);
	vars.img3 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path3, &vars.img_width, &vars.img_height);
	vars.win = mlx_new_window(vars.mlx, vars.w_x, vars.w_y, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close1, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 200, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 400, 100);
	put_tree(vars.w_x, vars.w_y, vars.mlx, vars.win, vars.img3);
	mlx_loop(vars.mlx);
}
