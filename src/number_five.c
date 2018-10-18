/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:02:02 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/09 17:02:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		recursion(t_all *a, int k, int number)
{
	int i;

	i = 0;
	k++;
	if (number == a->start_id)
		return (1);
	while (i < a->matr_size)
	{
		if (a->matr[number][i] != 0 && k < a->matr[number][i])
		{
			a->matr[number][i] = k;
			a->matr[i][number] = k;
			recursion(a, k, i);
		}
		i++;
	}
	return (0);
}

void	print_one_way(t_all *a)
{
	int i;
	t_l *new;

	i = 0;
	new = a->room;
	ft_printf("%s\n", a->res);
	ft_printf("\n");
	while (++i <= a->ants)
		ft_printf("L%d-%s ", i, index_komnata(new, a->end_id)->name);
	ft_printf("\n");
	exit(1);
}

int		put_zero(t_all *a, int j)
{
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
	if (a->matr[a->end_id][a->start_id] == 1)
		print_one_way(a);
	return (1);
}

int		find_way(t_all *a, t_ways **new, int i, int j)
{
	static int c = 0;

	a->temp = a->matr_size + 1;
	a->temp2 = a->start_id;
	(*new) = (++c != 1) ? make_new_way(new, a) : (*new);
	while (++i < a->matr_size && (j = -1))
	{
		while (++j < a->matr_size)
		{
			if (a->matr[a->temp2][j] != 0 && a->temp >= a->matr[a->temp2][j])
				find_way_aaa(a, j);
			if (a->temp == 1)
			{
				(*new)->way[i + 1] = a->temp3;
				return (put_zero(a, 0));
			}
		}
		(*new)->way[i + 1] = a->temp3;
		if (((j == a->matr_size) && (a->temp == a->matr_size + 1))
			|| (((*new)->way[i + 1] == (*new)->way[i])
			&& (*new)->way[i] != -1))
			return ((*new)->flag = 0);
		find_way_bbb(a);
	}
	return (0);
}

void	begin_search(t_all *a, t_l *p)
{
	t_ways	*new;
	int		flag;

	flag = 0;
	a->room = p;
	if (a->checker == 0)
		error2(4);
	new = (t_ways *)malloc(sizeof(t_ways));
	a->way_p = new;
	new->way = (int *)malloc(sizeof(int) * (a->matr_size + 1));
	new->way[0] = a->start_id;
	make_minus_one(new, a);
	new->next = NULL;
	new->flag = 1;
	recursion(a, 0, a->end_id);
	while (find_way(a, &new, -1, -1))
	{
		flag++;
		continue ;
	}
	if (!flag)
		error2(1);
	new = delete_last(new);
	print_ways(new, p, a);
	ants_poehali(a, p, new);
}
