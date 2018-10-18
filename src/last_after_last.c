/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_after_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:33:41 by vkorniie          #+#    #+#             */
/*   Updated: 2018/09/20 14:33:43 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*my_strchr(const char *s, int c)
{
	if (!s)
		error2(5);
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s && *s != (char)c && *s)
		s++;
	if (s && *s == '\0')
		return (0);
	return ((char *)s);
}
