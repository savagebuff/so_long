/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:20 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:23:21 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_get_save(char *save)
{
	char	*back;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (save == 0)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (0);
	}
	back = malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (back == 0)
		return (0);
	i++;
	while (save[i])
		back[j++] = save[i++];
	back[j] = '\0';
	free(save);
	return (back);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*back;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	back = malloc(sizeof(char) * (i + 1));
	if (!back)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		back[i] = str[i];
		i++;
	}
	back[i] = '\0';
	return (back);
}

int	ft_check_mem(int fd, char **buf, char **line)
{
	if (fd < 0 || line == 0)
		return (1);
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buf;
	int				bwr;

	if (ft_check_mem(fd, &buf, line))
		return (-1);
	bwr = 1;
	while (ft_check_new(save) == 0 && bwr != 0)
	{
		bwr = read(fd, buf, BUFFER_SIZE);
		if (bwr == -1)
		{
			free(buf);
			return (-1);
		}
		buf[bwr] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*line = ft_get_line(save);
	save = ft_get_save(save);
	if (bwr == 0)
		return (0);
	return (1);
}
