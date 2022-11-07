/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhamdouc <zhamdouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:02:02 by zakariyaham       #+#    #+#             */
/*   Updated: 2022/11/07 14:46:19 by zhamdouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

//peut etre devoir tout mettre dans liste car peut etre qu'on reussira pas a envoyer 2 struct

void	check_mouv(t_vars *vars, t_list *list)
{
	int	i;
	int	j;

	i = vars->y_pers / 64;
	j = vars->x_pers / 64;
	if (list->tab[i][j + 1] != 1)
	{
		list->tab[i][j + 1] = 'P';
		list->tab[i][j] = '0';
	}
	
}

int	close1(int keycode, t_vars *vars, t_list *list)
{
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	if (keycode == 100)
	{
		//put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		check_mouv(vars, list);
		put_tree(vars, list);
	//	vars->x_pers = vars->x_pers + 64;
	//	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 97)
	{
		//put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars, list);
		vars->x_pers = vars->x_pers - 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 115)
	{
		//put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars, list);
		vars->y_pers = vars->y_pers + 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	if (keycode == 119)
	{
		//put_floor(vars->w_x, vars->w_y, vars->mlx, vars->win, vars->img2);
		put_tree(vars, list);
		vars->y_pers = vars->y_pers - 64;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x_pers, vars->y_pers);
	}
	return (0);
}

// int	key_d(int keycode, t_vars *vars)
// {
// 	return (0);
// }
int	ft_close_mouse (t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	picture(t_list *list)
{
	t_vars	vars;
	int	len;

	vars.x_pers = 64;
	vars.y_pers = 64;
	vars.w_x = 64 * list->i;
	len = ft_strlen(list->tab[0]);
	vars.w_y = 100* len;
	vars.mlx = mlx_init();
	vars.relative_path = "./image/dwarf.xpm";
	vars.relative_path2 = "./image/wall.xpm";
	vars.relative_path3 = "./image/tree.xpm";
	vars.relative_path4 = "./image/ring.xpm";
	vars.relative_path5 = "./image/real_end_door.xpm";
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.img_width, &vars.img_height);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path2, &vars.img_width, &vars.img_height);
	vars.img3 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path3, &vars.img_width, &vars.img_height);
	vars.img4 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path4, &vars.img_width, &vars.img_height);
	vars.img5 = mlx_xpm_file_to_image(vars.mlx, vars.relative_path5, &vars.img_width, &vars.img_height);
	vars.win = mlx_new_window(vars.mlx, vars.w_x, vars.w_y, "Hello world!");
	mlx_hook(vars.win, 17, 1L<<17, ft_close_mouse, &vars);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img2, 400, 100);
	//put_floor(vars.w_x, vars.w_y, vars.mlx, vars.win, vars.img2);
	put_tree(&vars, list);
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 80, 100);// mettre l'image sur le p, envoyer les coordonnes dans cette fonction et ensuite les envoyer au fonction de mouvement
	mlx_hook(vars.win, 2, 1L<<0, close1, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	return (0);

}

int	main(int argc, char **argv)
{
	t_list	list;
	int	b;
	int	c;
	int d;
	
	list.i = 0;
	b = 0;
	c = 0;
	if (ft_check(argc, argv) == 0)
	{
		if (ft_check_map(argv, &list) == 0)
		{
			if (path_valid(&list) == 0)
				picture(&list);
		}
	}
	//ft_printf("%d", list.i);
	while (b < list.i)
	{
		d = ft_strlen(list.tab[b]);
		while (c < d)
		{
			ft_printf("%c", list.tab[b][c]);
			c++;
		}
		c = 0;
		b++;
	}
	return (0);
}

