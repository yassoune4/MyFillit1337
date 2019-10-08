/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:34:17 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/20 18:10:20 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**tetr_to_tab(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * nbr_of_tetr(str) + 1);
	tab[0] = ft_strnew(21);
	while (str[j] != '\0')
	{
		tab[i][k] = str[j];
		if (str[j] == '\n' && str[j + 1] == '\n')
		{
			tab[i][k + 1] = '\0';
			i++;
			k = -1;
			j++;
			tab[i] = ft_strnew(21);
		}
		j++;
		k++;
	}
	return (tab);
}

int				*get_min_x_y(char **tab)
{
	int i;
	int j;
	int *tab_min;
	int flag;

	flag = 0;
	i = 0;
	tab_min = (int *)malloc(sizeof(int) * 3);
	while (i < 4)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#' && flag == 0)
			{
				tab_min[0] = i;
				tab_min[1] = j;
				flag = 1;
			}
			tab_min = tab1(tab, tab_min, i, j);
			j++;
		}
		i++;
	}
	return (tab_min);
}

char			**left_up_tetr(char **tab, char c)
{
	int i;
	int j;
	int *tab_min;

	i = 0;
	j = 0;
	tab_min = get_min_x_y(tab);
	while (i < 4)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
			{
				tab[i][j] = '.';
				tab[i - tab_min[0]][j - tab_min[1]] = c;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

t_coord			*one_tetr(char **tetr_tab, int i)
{
	t_coord *new_tetr;

	new_tetr = (t_coord*)malloc(sizeof(t_coord));
	new_tetr->tab = tetr_tab;
	new_tetr->name = 'A' + i;
	new_tetr->next = NULL;
	return (new_tetr);
}

t_coord			*tab_to_list(char **tab, char *str)
{
	int			i;
	t_coord		*tetr_start;
	t_coord		*tmp;

	i = 1;
	tetr_start = NULL;
	tmp = NULL;
	tetr_start = one_tetr(ft_strsplit(tab[0], '\n'), 0);
	tmp = tetr_start;
	while (i < nbr_of_tetr(str))
	{
		tmp->next = one_tetr(ft_strsplit(tab[i], '\n'), i);
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (tetr_start);
}
