/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:41:39 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/10 13:01:41 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_links(char **s, t_l *p, t_all *a)
{
	t_l *new;

	new = p;
	while (new->next)
	{
		if (ft_strcmp(s[0], new->name) == 0)
			break ;
		new = new->next;
	}
	if (new->next == NULL && ft_strcmp(s[0], new->name) != 0)
		error(8);
	new = p;
	while (new->next)
	{
		if (ft_strcmp(s[1], new->name) == 0)
			break ;
		new = new->next;
	}
	if (new->next == NULL && ft_strcmp(s[1], new->name) != 0)
		error(8);
	a->res = join(a->res, a->line);
	write_matrix(p, a, s);
}

void	write_links(t_l *p, t_all *a)
{
	int		i;
	int		c;
	char	**s;

	i = 0;
	c = 0;
	if (a->checker != -42)
		make_matrix(p, a);
	while (a->line[i] != '\0')
	{
		if (a->line[i] == '-')
		{
			if (a->line[i - 1] && !ft_isalnum(a->line[i - 1])
				&& a->line[i + 1] && !ft_isalnum(a->line[i + 1]))
				error(8);
			c++;
		}
		i++;
	}
	if (c > 1)
		error(8);
	s = ft_strsplit(a->line, '-');
	free(a->line);
	check_links(s, p, a);
}

void	error2(int i)
{
	if (i == 1)
		ft_putendl("ERROR: no way");
	if (i == 2)
		ft_putendl("ERROR: to many spaces in string");
	if (i == 3)
		ft_putendl("ERROR: no ants");
	if (i == 4)
		ft_putendl("ERROR: no links");
	if (i == 5)
		ft_putendl("ERROR: please put file instead of folder");
	exit(0);
}

void	write_room(t_l **p, t_all *a)
{
	char	**s;
	int		count;

	count = 0;
	if (a->checker == -42)
		error(9);
	if (ft_count_word(a->line) != 3)
		error(6);
	a->res = join(a->res, a->line);
	a->res = join(a->res, "\n");
	s = ft_strsplit(a->line, ' ');
	if ((*p)->name != NULL)
		(*p) = make_new_node(p);
	(*p)->name = join((*p)->name, s[0]);
	if (!check_room_n((*p)->name))
		error(2);
	write_start_coord((*p), s[1], s[2]);
	count_spaces(a->line);
	A;
}

t_l		*make_new_node(t_l **p)
{
	t_l			*new;
	static int	count = 1;

	new = (t_l *)malloc(sizeof(t_l));
	new->id = count;
	new->name = NULL;
	new->is_line = 49;
	count++;
	new->next = (*p);
	new->ant = 0;
	(*p) = new;
	return (*p);
}
