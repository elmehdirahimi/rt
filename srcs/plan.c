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
		// if (fabs(dot(sub(obj->inter, plane->o), plane->repere.i)) > plane->limitx || fabs(dot(sub(obj->inter, plane->o), plane->repere.j)) > plane->limity)
		// 	return (0);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

void GetAnglePlan(t_rt *r)
{
    t_plane *obj;
	obj = (t_plane *)r->obj->obj;
    t_vecteur p;

    p = sub(obj->o ,create_v(dot(r->obj->inter,create_v(1.0 ,0.0, 0.0)), dot(r->obj->inter, create_v(0.0 ,1.0, 0.0)), dot(r->obj->inter, create_v(0.0 ,0.0, 1.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
	r->Um = p.x * 0.01;
	r->Vm = p.y * 0.01;
	r->Um -= floor(r->Um);
	r->Vm -= floor(r->Vm);
}