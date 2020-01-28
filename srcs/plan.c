/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 03:09:09 by mderri            #+#    #+#             */
/*   Updated: 2019/10/07 22:10:53 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

long double			intersection_p(t_rt *r, t_plane *p)
{
	long double		t;
	double			i;

	i = dot(normalise(p->normal), r->u);
	if (fabs(i) > MIN)
	{
		t = dot(normalise(p->normal), sub(p->o, r->ray.org)) / i;
		if (t > MIN && r->dis > t)
		{
			r->dis = t;
			return (1);
		}
	}
	return (0);
}

int					rat_trace_plane(t_rt *r, t_obj *obj)
{
	t_plane			*plane;

	plane = (t_plane *)obj->obj;
	if (intersection_p(r, plane))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
