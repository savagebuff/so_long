/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:30 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:23:31 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_check_strchr(char *s, char ch)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	check_symb(char **map)
{
	char	*symb;
	int		x;
	int		y;

	y = 0;
	symb = "01ECPR";
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_check_strchr(symb, map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	count_sprites(char **map)
{
	t_loc	loc;

	loc.x = 0;
	loc.y = 0;
	loc.e = 0;
	loc.c = 0;
	loc.p = 0;
	while (map[loc.y])
	{
		loc.x = 0;
		while (map[loc.y][loc.x])
		{
			if (map[loc.y][loc.x] == 'E')
				loc.e++;
			if (map[loc.y][loc.x] == 'P')
				loc.p++;
			if (map[loc.y][loc.x] == 'C')
				loc.c++;
			loc.x++;
		}
		loc.y++;
	}
	if ((loc.e == 0 || loc.e > 1) || (loc.p == 0 || loc.p > 1) || loc.c == 0)
		return (1);
	return (0);
}

int	check_map(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][0] != '1' || map[0][x] != '1')
				return (-1);
			if (map[y][game->width - 1] != '1')
				return (-1);
			if (map[game->height - 1][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	if (count_sprites(map) || check_symb(map))
		return (-1);
	return (1);
}
