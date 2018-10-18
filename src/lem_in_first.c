/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:45:24 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/02 13:45:28 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_data(t_l **p, t_all *a)
{
	if (ft_count_word(a->line) == 3)
		write_room(p, a);
	else if (ft_strchr(a->line, '-'))
		write_links(*p, a);
	else
		error(7);
}

void	write_start_cont(t_l *p, char **s, t_all *a)
{
	if (a->str_or_end == 's')
	{
		p->name = join(p->name, s[0]);
		p->is_line = 50;
		a->start_id = p->id;
		a->cc += 10;
	}
	else
	{
		p->name = join(p->name, s[0]);
		p->is_line = 51;
		a->end_id = p->id;
		a->cc++;
	}
	if (!check_room_n(p->name))
		error(2);
	write_start_coord(p, s[1], s[2]);
}

void	write_start(t_l **p, t_all *a)
{
	char	**s;

	a->str_or_end = a->line[2];
	write_start_str(a);
	if (ft_count_word(a->line) != 3)
		error(6);
	count_spaces(a->line);
	s = ft_strsplit(a->line, ' ');
	if ((*p)->name != NULL)
		(*p) = make_new_node(p);
	write_start_cont(*p, s, a);
	a->res = join(a->res, a->line);
	a->res = join(a->res, "\n");
	ft_splitdel(s);
	free(a->line);
}

void	second_function(t_l **p, t_all *a)
{
	while (get_next_line(0, &(a->line)) > 0)
	{
		if (a->checker == -42)
			a->res = join(a->res, "\n");
		if (!ft_strcmp(a->line, "##start") || !ft_strcmp(a->line, "##end"))
			write_start(p, a);
		else if (a->line[0] == '#' && a->line[1] != '#')
		{
			a->res = join(a->res, a->line);
			if (a->checker != -42)
				a->res = join(a->res, "\n");
			free(a->line);
		}
		else if (a->line[0] == '#' && a->line[1] == '#')
			free(a->line);
		else
			write_data(p, a);
	}
	if (a->cc != 59)
		error(11);
	begin_search(a, *p);
}

int		main(void)
{
	t_l			*p;
	t_all		*a;

	p = (t_l *)malloc(sizeof(t_l));
	a = (t_all *)malloc(sizeof(t_all));
	p->name = NULL;
	p->next = NULL;
	p->ant = 0;
	a->checker = 0;
	p->id = 0;
	a->cc = 48;
	write_ants(a);
	second_function(&p, a);
}
