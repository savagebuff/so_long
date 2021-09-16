/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:15 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:23:16 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_width(t_game *game)
{
	int	len;
	int	height;

	len = 0;
	height = 0;
	while (game->arr[height][len])
	{
		if (game->arr[height][len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

int	ft_height(char **str)
{
	int	hieght;
	int	width;

	hieght = 0;
	while (str[hieght])
	{
		width = 0;
		while (str[hieght][width])
			width++;
		hieght++;
	}
	return (hieght);
}

int	give_mem(t_game *game)
{
	game->img_p = (struct s_data *)malloc(sizeof(t_data));
	if (game->img_p == 0)
		return (0);
	game->walls = (struct s_data *)malloc(sizeof(t_data));
	if (game->walls == 0)
		return (0);
	game->floor = (struct s_data *)malloc(sizeof(t_data));
	if (game->floor == 0)
		return (0);
	game->door = (struct s_data *)malloc(sizeof(t_data));
	if (game->door == 0)
		return (0);
	game->coin = (struct s_data *)malloc(sizeof(t_data));
	if (game->coin == 0)
		return (0);
	game->enemy = (struct s_data *)malloc(sizeof(t_data));
	if (game->enemy == 0)
		return (0);
	return (1);
}
