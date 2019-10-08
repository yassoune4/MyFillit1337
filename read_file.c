/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:29:33 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/21 19:19:50 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

char	*read_file(int fd)
{
	int		rd;
	char	*buff;
	char	*str;
	int		last;

	buff = ft_strnew(21);
	str = ft_strnew(21);
	last = 0;
	while ((rd = read(fd, buff, 21)) > 0)
	{
		buff[rd] = '\0';
		if (rd == 20)
			last = 1;
		if (!((valid_tetrim(buff) == 6 || valid_tetrim(buff) == 8)
					&& (check(buff, rd) == 0)))
		{
			return (NULL);
		}
		str = ft_strjoin(str, buff);
	}
	if (last == 0)
		return (NULL);
	if (nbr_of_tetr(str) > 26)
		return (NULL);
	return (str);
}

t_point	ft_zero(t_point point)
{
	point.x = 0;
	point.y = 0;
	return (point);
}

t_point	recursif_add_s1(t_point point, int size)
{
	if (point.x < size)
		point.x++;
	else
	{
		point.x = 0;
		point.y++;
	}
	return (point);
}

int		*tab1(char **tab, int *tab_min, int i, int j)
{
	if (tab[i][j] == '#')
	{
		tab_min[0] = (i <= tab_min[0]) ? i : tab_min[0];
		tab_min[1] = (j <= tab_min[1]) ? j : tab_min[1];
	}
	return (tab_min);
}
