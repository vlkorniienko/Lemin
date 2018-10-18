/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:14:36 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/12 14:14:37 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways	*make_new_way(t_ways **old, t_all *a)
{
	t_ways *new;

	new = (t_ways *)malloc(sizeof(t_ways));
	new->next = (*old);
	new->way = (int *)malloc(sizeof(int) * (a->matr_size + 1));
	new->way[0] = a->start_id;
	make_minus_one(new, a);
	new->flag = 1;
	return (new);
}

t_ways	*delete_last(t_ways *a)
{
	t_ways *new;

	while (a && !a->flag)
	{
		free(a->way);
		free(a);
		a = a->next;
	}
	new = a;
	while (new->next)
	{
		if (new->next->flag == 0)
		{
			free(new->next->way);
			free(new->next);
			new->next = new->next->next;
		}
		else
			new = new->next;
	}
	return (a);
}

void	make_minus_one(t_ways *new, t_all *a)
{
	int i;

	i = 1;
	while (i < a->matr_size + 1)
	{
		new->way[i] = -1;
		i++;
	}
}

void	count_spaces(char *s)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			counter++;
		i++;
	}
	if (counter > 2)
		error2(2);
}

int		my_atoi(char *str, int r)
{
	int			i;
	long long	res;
	int			c;

	i = 0;
	res = 0;
	c = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			c = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if ((res > 2147483647 || res < -2147483648) && r == 1)
		error(3);
	if (res > 2147483647 && r == 2)
		error(5);
	return (res * c);
}
