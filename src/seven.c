/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seven.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:45:12 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/17 13:45:14 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		index_komnata_in_way(t_ways *new, int index)
{
	t_ways	*tmp;
	int		i;

	tmp = new;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->way[i] != -1)
		{
			if (tmp->way[i] == index)
				return (tmp->way[i + 1]);
			i++;
		}
		tmp = tmp->next;
	}
	return (-1);
}

int		cycle(t_l *p, t_all *a)
{
	t_l		*tmp;
	int		i;

	i = 0;
	tmp = p;
	while (tmp)
	{
		if (tmp->ant && !a->steps[tmp->ant - 1])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		cycle2(t_l *p)
{
	t_l		*tmp;
	int		i;

	i = 0;
	tmp = p;
	while (tmp)
	{
		if (tmp->ant)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	walk_ant(t_all *a, t_l *p, t_ways *new)
{
	t_l		*tmp;
	t_l		*nxt_room;

	while (cycle(p, a))
	{
		tmp = p;
		while (tmp)
		{
			if (tmp->ant)
			{
				a->index = index_komnata_in_way(new, tmp->id);
				if (a->index != -1)
				{
					a->steps[tmp->ant - 1] = 1;
					nxt_room = index_komnata(p, a->index);
					ft_printf("L%d-%s ", tmp->ant, nxt_room->name);
					if (a->index != a->end_id)
						nxt_room->ant = tmp->ant;
				}
				tmp->ant = 0;
			}
			tmp = tmp->next;
		}
	}
}

void	ants_poehali(t_all *a, t_l *p, t_ways *new)
{
	t_ways	*ways;
	t_l		*tmp;

	a->ant_f = 1;
	a->steps = ft_memalloc(sizeof(int) * a->ants);
	while (a->ant_f <= a->ants || cycle2(p))
	{
		a->iterat = 0;
		while (a->iterat < a->ants)
			a->steps[a->iterat++] = 0;
		walk_ant(a, p, new);
		ways = new;
		while (ways && a->ant_f <= a->ants)
		{
			tmp = index_komnata(p, ways->way[1]);
			if (tmp && !tmp->ant)
			{
				a->steps[a->ant_f - 1] = 1;
				tmp->ant = a->ant_f++;
				ft_printf("L%d-%s ", tmp->ant, tmp->name);
			}
			ways = ways->next;
		}
		ft_printf("\n");
	}
}
