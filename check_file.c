/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:24:37 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/21 19:15:22 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	nbr_of_tetr(char *str)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			cpt++;
		i++;
	}
	return (cpt / 4);
}

int	valid_tetrim(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if ((i + 1) < 20 && buff[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && buff[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && buff[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && buff[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int	check(char *buff, int rd)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
			count++;
		if (i % 5 < 4)
		{
			if (!(buff[i] == '.' || buff[i] == '#'))
				return (1);
		}
		else if (buff[i] != '\n')
			return (1);
		i++;
	}
	if (rd == 21 && buff[20] != '\n')
		return (1);
	if (count != 4)
		return (1);
	return (0);
}
