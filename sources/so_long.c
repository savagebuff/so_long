/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:22:40 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:22:43 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_ex(t_game **game, int y, int x)
{
	if ((*game)->arr[(*game)->y + y][(*game)->x + x] == 'C')
		(*game)->coin->count--;
	if ((*game)->arr[(*game)->y + y][(*game)->x + x] == 'E')
	{
		if ((*game)->coin->count > 0)
			pr_img(*game, "xpm/player1.xpm", (*game)->img_p->img);
		else
		{
			print_walls(*game);
			exit(1);
		}
		return (0);
	}
	else if ((*game)->arr[(*game)->y + y][(*game)->x + x] == 'R')
	{
		write(1, "You die!\n", 9);
		exit(1);
	}
	return (1);
}

void	change_pos(t_game **game, int y, int x, int key)
{
	if (ft_ex(game, y, x))
	{
		if ((*game)->arr[(*game)->y + y][(*game)->x + x] == '1')
			pr_img(*game, "xpm/player1.xpm", (*game)->img_p->img);
		else
		{
			print_walls(*game);
			(*game)->count++;
			(*game)->count_wall++;
			pr_img(*game, "xpm/floor.xpm", (*game)->floor->img);
			(*game)->y = (*game)->y + y;
			(*game)->x = (*game)->x + x;
			if ((*game)->count && key != 0)
				pr_img(*game, "xpm/player1.xpm", (*game)->img_p->img);
			else if ((*game)->count && key == 0)
				pr_img(*game, "xpm/player2.xpm", (*game)->img_p->img);
		}
	}
}

int	key_hook(int keycode, t_game **game)
{
	int	n;

	n = 0;
	if (keycode == 53)
	{
		print_walls(*game);
		exit(1);
	}
	if (keycode == 13)
		change_pos(game, -1, 0, 13);
	else if (keycode == 0)
		change_pos(game, 0, -1, 0);
	else if (keycode == 1)
		change_pos(game, 1, 0, 1);
	else if (keycode == 2)
		change_pos(game, 0, 1, 2);
	return (1);
}

char	**make_map(t_list **list, int size)
{
	t_list	*head;
	char	**map;
	int		i;

	i = 0;
	head = *list;
	map = (char **) malloc((size + 1) * sizeof(char *));
	if (map == 0)
		return (0);
	while (head)
	{
		map[i] = head->content;
		head = head->next;
		i++;
	}
	map[i] = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*list;
	t_game	game;
	char	*name_map;

	if (argc == 2)
		name_map = argv[1];
	else
		return (0);
	list = NULL;
	fd = open(name_map, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&list, ft_lstnew(line));
	ft_lstadd_back(&list, ft_lstnew(line));
	game.arr = make_map(&list, ft_lstsize(list));
	game.width = ft_width(&game);
	game.height = ft_height(game.arr);
	if (check_map(game.arr, &game) == -1)
	{
		ft_putstr_fd("Map is not valid!\n", 1);
		return (0);
	}
	map_print(&game);
}
