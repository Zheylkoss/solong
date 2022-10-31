/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/31 12:57:41 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close1(int keycode)
// {
// //	mlx_destroy_window(vars->mlx, vars->win);
// 	ft_printf("%d", keycode);
// 	return (0);
// }

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
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	char	*relative_path = "./image/Attack2.xpm";
	char	*relative_path2 = "./image/Attack3.xpm";
	char	*relative_path3 = "./image/arbre1.xpm";
	int		img_width;
	int		img_height;
	int w_y;
	int w_x;

	w_x = 500;
	w_y = 500;
	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, relative_path3, &img_width, &img_height);
	win = mlx_new_window(mlx, w_x, w_y, "Hello world!");
	// mlx_put_image_to_window(mlx, win, img, 200, 100);
	// mlx_put_image_to_window(mlx, win, img2, 400, 100);
	put_tree(w_x, w_y, mlx, win, img3);
	mlx_loop(mlx);
}
