/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:35:06 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/11/20 23:01:10 by ysalihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_list
{
	char				name;
	char				**tab;
	struct s_list		*next;
}				t_coord;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

int				open_file(char *file);
char			*read_file(int fd);
int				check(char *buff, int rd);
int				valid_tetrim(char *buff);
char			**tetr_to_tab(char *str);
int				nbr_of_tetr(char *str);
int				*get_min_x_y(char **tab);
char			**left_up_tetr(char **tab, char c);
t_coord			*one_tetr(char **tetr_tab, int i);
t_coord			*tab_to_list(char **tab, char *str);
char			**tab_solve(t_coord *tetr, char **tab,
					int valid_x, int valid_y);
int				is_valid_pos(t_coord *tetr, char **tab,
					t_point point, int lengt);
char			**create_tab(int size);
int				recursif_add(t_coord *tetr, int size, char **tab);
void			print_tab(char **tab);
char			**free_last_tetr_aded(t_coord *tetr, char **tab);
t_point			ft_zero(t_point point);
t_point			recursif_add_s1(t_point point, int size);
int				*tab1(char **tab, int *tab_min, int i, int j);
int				ft_sqrt(int nb);
t_coord			*tetr_to_list(char *file);
void			free_tab(char **tab, int size);

#endif
