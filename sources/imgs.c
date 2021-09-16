/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:07 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 16:37:55 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	win_close(void)
{
	ft_putstr_fd("Close window\n", 1);
	exit(1);
}

int	main_loop(t_game *game)
{
	if (game->coin->count <= 0)
		put_img(game, "xpm/dooropen.xpm", game->door->img, 'E');
	return (1);
}

int	map_print(t_game *game)
{
	if (!give_mem(game))
		exit(0);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 20,
			 game->height * 20 + 25, "so_long");
	game->coin->count = counter_c(game, 'C');
	game->count = 0;
	game->count_wall = 1;
	put_img(game, "xpm/wall.xpm", game->walls->img, '1');
	put_img(game, "xpm/door.xpm", game->door->img, 'E');
	put_img(game, "xpm/coin.xpm", game->coin->img, 'C');
	put_img(game, "xpm/floor.xpm", game->floor->img, '0');
	put_img(game, "xpm/player1.xpm", game->img_p->img, 'P');
	put_img(game, "xpm/enemy.xpm", game->enemy->img, 'R');
	mlx_string_put(game->mlx, game->win, 11, 2, 0xFFFFFF, "count steps: ");
	mlx_hook(game->win, 17, 1L << 0, win_close, game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, &game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	return (1);
}
