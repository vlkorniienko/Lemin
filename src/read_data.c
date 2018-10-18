/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:27:15 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/02 18:27:17 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_ants(t_all *a)
{
	a->res = ft_strnew(0);
	while (get_next_line(0, &(a->line)) && my_strchr(a->line, '#'))
	{
		if (!ft_strcmp(a->line, "##start") || !ft_strcmp(a->line, "##end"))
			error2(3);
		a->res = join(a->res, a->line);
		a->res = join(a->res, "\n");
		free(a->line);
	}
	if (strcmp(a->line, "") == 0)
		error(7);
	if (!digit_checker(a->line))
		error(5);
	a->ants = ft_atoi(a->line);
	a->res = join(a->res, a->line);
	a->res = join(a->res, "\n");
	if (a->ants <= 0)
		error(5);
	free(a->line);
}

int		digit_checker(char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' && s[1] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	write_start_coord(t_l *new, char *s1, char *s2)
{
	int x;

	x = 0;
	if (!digit_checker(s1))
		error(3);
	if (!digit_checker(s2))
		error(3);
	if (ft_strlen(s1) > 11 || ft_strlen(s2) > 11)
		error(4);
	new->x = my_atoi(s1, 1);
	new->y = my_atoi(s2, 1);
}

void	write_start_str(t_all *a)
{
	int i;

	i = 0;
	a->res = join(a->res, a->line);
	a->res = join(a->res, "\n");
	free(a->line);
	while (get_next_line(0, &(a->line)) && ft_strchr(a->line, '#'))
	{
		if (ft_strcmp(a->line, "") == 0)
			error(7);
		if (!ft_strcmp(a->line, "##start") || !ft_strcmp(a->line, "##end"))
			error(1);
		if (a->line[0] != '#')
			break ;
		a->res = join(a->res, a->line);
		a->res = join(a->res, "\n");
		free(a->line);
		i++;
	}
}

int		check_room_n(char *s)
{
	int i;

	i = 0;
	if (s[0] == 'L')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			return (0);
		i++;
	}
	return (1);
}
