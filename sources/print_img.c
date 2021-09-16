/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:22:54 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 17:49:53 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pr_img(t_game *game, char *path, void *img)
{
	img = mlx_xpm_file_to_image(game->mlx, path, &game->width, &game->height);
	mlx_put_image_to_window(game->mlx, game->win,
		 img, game->x * 20, game->y * 20 + 25);
}

void	print_walls(t_game *game)
{
	char	*num;

	num = ft_itoa(game->count_wall);
	mlx_string_put(game->mlx, game->win, 150, 1, 0x0, num);
	mlx_string_put(game->mlx, game->win, 152, 3, 0x0, num);
	mlx_string_put(game->mlx, game->win, 149, 0, 0x0, num);
	mlx_string_put(game->mlx, game->win, 154, 4, 0x0, num);
	mlx_string_put(game->mlx, game->win, 151, 2, 0xFFFFFF, num);
	free(num);
}

int	counter_c(t_game *game, char c)
{
	int	i;
	int	h;
	int	len;
	int	count;

	h = 0;
	count = 0;
	while (game->arr[h])
	{
		i = 0;
		len = ft_strlen(game->arr[h]);
		while (len--)
		{
			if (game->arr[h][i] == c)
				count++;
			i++;
		}	
		h++;
	}
	return (count);
}

void	put_img(t_game *game, char *p, char *img, char c)
{
	int	i;
	int	h;
	int	len;

	h = -1;
	while (game->arr[++h])
	{
		i = -1;
		len = ft_strlen(game->arr[h]);
		while (len-- && ++i > -2)
		{
			if (game->arr[h][i] == c)
			{
				img = mlx_xpm_file_to_image(game->mlx, p,
						 &game->width, &game->height);
				if (c != 'R' && c != 'E')
				{
					game->x = i;
					game->y = h;
				}
				mlx_put_image_to_window(game->mlx, game->win,
					 img, i * 20, h * 20 + 25);
			}
		}
	}
}
