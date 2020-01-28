/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:37:32 by slaanani          #+#    #+#             */
/*   Updated: 2019/09/30 04:31:49 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		put_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int			rgb(int r, int g, int b)
{
	unsigned char	color[4];

	r = fmin(r, 255);
	g = fmin(g, 255);
	b = fmin(b, 255);
	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;
	return (*((int *)color));
}

t_vecteur	create_v(long double x, long double y, long double z)
{
	t_vecteur		v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int			distances(t_rt *r)
{
	if (((r->sol2 < r->sol1 || r->sol1 < MIN) && r->sol2 > MIN)
			&& (r->sol2 < r->dis))
	{
		r->dis = r->sol2;
		return (1);
	}
	else if (((r->sol1 < r->sol2 || r->sol2 < MIN) && r->sol1 > MIN)
			&& (r->sol1 < r->dis))
	{
		r->dis = r->sol1;
		return (1);
	}
	else
		return (0);
}

void		free_splited(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
