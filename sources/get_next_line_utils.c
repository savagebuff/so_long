/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:25 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:23:26 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			*(char *)(dst + i - 1) = *(char *)(src + i - 1);
			i--;
		}
	}
	else if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(sizeof(char) * len);
	if (!s3)
		return (0);
	ft_memmove(s3, s1, ft_strlen(s1));
	ft_memmove(s3 + ft_strlen(s1), s2, ft_strlen(s2));
	s3[len - 1] = '\0';
	free((char *)s1);
	return (s3);
}

int	ft_check_new(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
