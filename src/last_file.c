/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:30:04 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/20 10:30:07 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_way_bbb(t_all *a)
{
	int j;

	j = 0;
	a->matr[a->temp2][a->temp3] = 0;
	a->matr[a->temp3][a->temp2] = 0;
	if (a->temp2 != a->start_id)
	{
		while (j < a->matr_size)
		{
			if (a->matr[a->temp2][j] != 1)
			{
				a->matr[a->temp2][j] = 0;
				a->matr[j][a->temp2] = 0;
			}
			j++;
		}
	}
	a->temp2 = a->temp3;
}

void	find_way_aaa(t_all *a, int j)
{
	a->temp = a->matr[a->temp2][j];
	a->temp3 = j;
}

t_l		*index_komnata(t_l *p, int index)
{
	t_l		*tmp;

	tmp = p;
	while (tmp)
	{
		if (tmp->id == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	print_ways(t_ways *new, t_l *room, t_all *a)
{
	t_ways	*p;
	t_l		*pointer;
	int		i;

	i = 0;
	p = new;
	pointer = room;
	ft_printf("%s\n", a->res);
	ft_printf("\n");
	ft_putendl("All unique ways:");
	while (p)
	{
		i = 0;
		while (p->way[i] != -1)
		{
			ft_printf("%s", index_komnata(pointer, p->way[i])->name);
			if (p->way[i + 1] != -1)
				write(1, "-", 1);
			i++;
		}
		write(1, "\n", 1);
		p = p->next;
	}
	write(1, "\n", 1);
}

char	*join(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (s2)
	{
		p = (char *)malloc((s1 ? ft_strlen(s1) : 0) + ft_strlen(s2) + 1);
		if (p == NULL)
			return (0);
		if (s1)
			while (s1[i] != '\0')
			{
				p[i] = s1[i];
				i++;
			}
		while (s2[j] != '\0')
			p[i++] = s2[j++];
		if (s1)
			free(s1);
		p[i] = '\0';
		return (p);
	}
	return (0);
}
