/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:37:58 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/20 14:40:06 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab(int size)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char*) * size + 1);
	while (i < size)
	{
		j = 0;
		tab[i] = ft_strnew(size);
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

int		is_valid_pos(t_coord *tetr, char **tab, t_point point, int lengt)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_isalpha(tetr->tab[i][j]) == 1)
			{
				if ((i + point.y >= lengt) || (j + point.x >= lengt))
					return (0);
				if (ft_isalpha(tab[i + point.y][point.x + j]) == 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**tab_solve(t_coord *tetr, char **tab, int valid_x, int valid_y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetr->tab[i][j] != '.')
				tab[valid_y + i][valid_x + j] = tetr->name;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char	**free_last_tetr_aded(t_coord *tetr, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == tetr->name)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int		recursif_add(t_coord *tetr, int size, char **tab)
{
	t_point point;

	point.x = 0;
	point.y = 0;
	if (tetr != NULL)
	{
		while (point.x < size || point.y < size)
		{
			if ((is_valid_pos(tetr, tab, point, size)) == 1)
			{
				tab = tab_solve(tetr, tab, point.x, point.y);
				if (recursif_add(tetr->next, size, tab) == 1)
					return (1);
				tab = free_last_tetr_aded(tetr, tab);
			}
			point = recursif_add_s1(point, size);
		}
		point = ft_zero(point);
		return (0);
	}
	return (1);
}
