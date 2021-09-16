/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:25:39 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:25:41 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx_mms_20200219/mlx.h"
# include "../libft/libft.h"

typedef struct s_data
{
	char	*addr;
	void	*img;
	int		x;
	int		y;
	int		count;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game {
	void			*mlx;
	void			*win;
	char			**arr;
	char			**players_images;
	int				x;
	int				y;
	int				width;
	int				height;
	int				count;
	int				count_wall;
	struct s_data	*img_p;
	struct s_data	*walls;
	struct s_data	*coin;
	struct s_data	*floor;
	struct s_data	*door;
	struct s_data	*enemy;
}				t_game;

typedef struct s_loc {
	int	y;
	int	x;
	int	c;
	int	p;
	int	e;
}				t_loc;

// get_next_line

size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_get_save(char *save);
char	*ft_get_line(char *str);
int		ft_check_mem(int fd, char **buf, char **line);
int		get_next_line(int fd, char **line);
int		ft_check_new(char *str);

// so_long.c

char	**make_map(t_list **list, int size);
int		key_hook(int keycode, t_game **game);
void	change_pos(t_game **game, int y, int x, int key);
int		ft_ex(t_game **game, int y, int x);

// helper.c

int		ft_width(t_game *game);
int		ft_height(char **str);
int		give_mem(t_game *game);

// checker.c

int		check_map(char **map, t_game *game);
int		count_sprites(char **map);
int		check_symb(char **map);
char	ft_check_strchr(char *s, char ch);

// imgs.c

int		map_print(t_game *game);

//	print_img.c

int		counter_c(t_game *game, char c);
void	put_img(t_game *game, char *p, char *img, char c);
void	print_walls(t_game *game);
void	pr_img(t_game *game, char *path, void *img);

#endif