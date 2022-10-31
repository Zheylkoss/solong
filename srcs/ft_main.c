/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/10/31 15:58:14 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

int	close1(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("%d", keycode);
	if (keycode == 100)
	{
		put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img3);
		vars->x_pers = vars->x_pers + 80;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 97)
	{
		put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img3);
		vars->x_pers = vars->x_pers - 80;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 115)
	{
		put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img3);
		vars->y_pers = vars->y_pers + 100;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 119)
	{
		put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img3);
		vars->y_pers = vars->y_pers - 100;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	return (0);
}

// int	key_d(int keycode, t_vars *vars)
// {
// 	return (0);
// }

int	main(void)
{
	t_vars	vars;
 
	vars.x_pers = 80;
	vars.y_pers = 100;
	vars.w_x = 80 * 10;
	vars.w_y = 100* 8;
	vars.mlx = mlx_init();
	vars.relative_path = "./image/Idle1.xpm";
	vars.relative_path2 = "./image/Dungeonfloor.xpm";
	vars.relative_path3 = "./image/arbre1.xpm";
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.img_width, &vars.img_height);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path2, &vars.img_width, &vars.img_height);
	vars.img3 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path3, &vars.img_width, &vars.img_height);
	vars.win = mlx_new_window(vars.mlx, vars.w_x, vars.w_y, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close1, &vars);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 400, 100);
	put_floor(vars.w_x, vars.w_y, vars.mlx, vars.win, vars.img2);
	put_tree(vars.w_x, vars.w_y, vars.mlx, vars.win, vars.img3);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 80, 100);// mettre l'image sur le p, envoyer les coordonnes dans cette fonction et ensuite les envoyer au fonction de mouvement 
	mlx_loop(vars.mlx);
}
