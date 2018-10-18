/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:56:37 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/05 15:56:40 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_ifname_rep(t_l *p)
{
	t_l *p2;
	t_l *temp;

	temp = p;
	while (temp->next)
	{
		p2 = temp;
		while (p2->next)
		{
			if (ft_strcmp(temp->name, p2->next->name) == 0)
				error(12);
			p2 = p2->next;
		}
		temp = temp->next;
	}
}

void	write_matrix(t_l *p, t_all *a, char **s)
{
	int i;
	int j;
	t_l *new;

	new = p;
	while (new->next)
	{
		if (ft_strcmp(new->name, s[0]) == 0)
			break ;
		new = new->next;
	}
	i = new->id;
	new = p;
	while (new->next)
	{
		if (ft_strcmp(new->name, s[1]) == 0)
			break ;
		new = new->next;
	}
	j = new->id;
	a->matr[i][j] = a->matr_size + 1;
	a->matr[j][i] = a->matr_size + 1;
	free(s[0]);
	free(s[1]);
	free(s);
}

void	make_matrix(t_l *p, t_all *a)
{
	t_l *p2;
	int i;
	int j;

	p2 = p;
	j = 0;
	a->matr_size = p2->id + 1;
	i = p2->id + 1;
	a->matr = (int **)malloc(sizeof(int *) * i);
	while (j < i)
	{
		a->matr[j] = (int *)malloc(sizeof(int) * i);
		j++;
	}
	i = -1;
	while (++i < (p2->id + 1))
	{
		j = -1;
		while (++j < (p2->id + 1))
			a->matr[i][j] = 0;
	}
	a->checker = -42;
	check_ifcoord_rep(p);
}

void	error(int i)
{
	if (i == 1)
		ft_putendl("ERROR: too many or to less start or end strings");
	else if (i == 2)
		ft_putendl("ERROR: there is 'L' or '-' in the room name");
	else if (i == 3)
		ft_putendl("ERROR: the coordinates are not valid");
	else if (i == 4)
		ft_putendl("ERROR: the coordinates are bigger than integer");
	else if (i == 5)
		ft_putendl("ERROR: string with ants isn't valid");
	else if (i == 6)
		ft_putendl("ERROR: invalid string with coordinates");
	else if (i == 7)
		ft_putendl("ERROR: invalid string");
	else if (i == 8)
		ft_putendl("ERROR: string with links isn't valid");
	else if (i == 9)
		ft_putendl("ERROR: the map isn't valid");
	else if (i == 10)
		ft_putendl("ERROR: the room doesn't exist");
	else if (i == 11)
		ft_putendl("ERROR: not enough data");
	else if (i == 12)
		ft_putendl("ERROR: the rooms with same name");
	exit(0);
}

void	check_ifcoord_rep(t_l *p)
{
	t_l *p2;
	t_l *temp;
	int x;
	int y;

	temp = p;
	while (temp->next)
	{
		x = temp->x;
		y = temp->y;
		p2 = temp;
		while (p2->next)
		{
			if (x == p2->next->x && y == p2->next->y)
				error(3);
			p2 = p2->next;
		}
		temp = temp->next;
	}
	check_ifname_rep(p);
}
