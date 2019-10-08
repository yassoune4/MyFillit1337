/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:34:10 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/23 17:04:33 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		*file;
	t_coord		*tmp;
	int			size;
	char		**t;

	if (argc == 1)
	{
		ft_putstr("usage : ./fillit file_name\n");
		return (0);
	}
	if (open_file(argv[1]) == -1 ||
		(file = read_file(open_file(argv[1]))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	tmp = tetr_to_list(file);
	size = ft_sqrt(nbr_of_tetr(file) * 4);
	t = create_tab(size);
	while (recursif_add(tmp, size, t) == 0)
		t = create_tab(++size);
	print_tab(t);
	free_tab(t, size);
	return (0);
}
