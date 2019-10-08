/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:56:23 by ysalihi           #+#    #+#             */
/*   Updated: 2018/11/20 21:56:26 by ysalihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			if (i * i <= nb && (i + 1) * (i + 1) >= nb)
				return (i);
			i++;
		}
	}
	return (0);
}

void		print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

t_coord		*tetr_to_list(char *file)
{
	t_coord		*list;
	t_coord		*tmp;
	char		**tab;

	tab = tetr_to_tab(file);
	list = tab_to_list(tab, file);
	list->tab = left_up_tetr(list->tab, list->name);
	tmp = list;
	while (list)
	{
		list->tab = left_up_tetr(list->tab, list->name);
		list = list->next;
	}
	return (tmp);
}

void		free_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}
