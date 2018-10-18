/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:22:16 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/02 13:22:47 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# define A {free(s[0]);free(s[1]);free(s[2]);free(s[3]);free(s);free(a->line);}
# define MAX 2147483647
# define MIN -2147483648

typedef struct		s_l
{
	char			*name;
	char			is_line;
	int				ant;
	int				x;
	int				y;
	int				id;
	struct s_l		*next;
}					t_l;

typedef struct		s_all
{
	char			*line;
	int				ants;
	char			*res;
	short int		checker;
	int				**matr;
	char			cc;
	char			str_or_end;
	int				matr_size;
	short int		end_id;
	short int		start_id;
	int				temp;
	int				temp2;
	int				temp3;
	int				*steps;
	struct s_ways	*way_p;
	struct s_l		*room;
	int				index;
	int				ant_f;
	int				iterat;
}					t_all;

typedef struct		s_ways
{
	int				*way;
	short int		flag;
	struct s_ways	*next;
}					t_ways;

void				write_start_str(t_all *a);
int					digit_checker(char *s);
void				write_start_coord(t_l *new, char *s1, char *s2);
void				write_ants(t_all *a);
int					check_room_n(char *s);

void				write_room(t_l **p, t_all *a);
void				write_links(t_l *p, t_all *a);
t_l					*make_new_node(t_l **p);

void				check_ifcoord_rep(t_l *p);
void				error(int i);
void				make_matrix(t_l *p, t_all *a);
void				begin_search(t_all *a, t_l *p);
void				write_matrix(t_l *p, t_all *a, char **s);

void				check_ifname_rep(t_l *p);

t_ways				*delete_last(t_ways *a);
t_ways				*make_new_way(t_ways **old, t_all *a);

void				error2(int i);
void				count_spaces(char *s);
void				make_minus_one(t_ways *new, t_all *a);
int					my_atoi(char *str, int r);

void				ants_poehali(t_all *a, t_l *p, t_ways *new);
t_l					*index_komnata(t_l *p, int index);

void				find_way_aaa(t_all *a, int j);
void				find_way_bbb(t_all *a);
t_l					*index_komnata(t_l *p, int index);
void				print_ways(t_ways *new, t_l *room, t_all *a);
char				*join(char *s1, char const *s2);

char				*my_strchr(const char *s, int c);

#endif
