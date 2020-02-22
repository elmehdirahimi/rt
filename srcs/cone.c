/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:05:21 by mderri            #+#    #+#             */
/*   Updated: 2019/10/04 03:30:45 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				intersection_co(t_rt *r, t_cone *c)
{
	t_vecteur	param;

	param.x = dot(r->u, r->u) - ((dot(r->u, normalise(c->axe)) * dot(r->u,
	normalise(c->axe))) * (1 + c->k * c->k));
	param.y = 2 * (dot(r->u, sub(r->ray.org, c->st)) - ((dot(r->u,
	normalise(c->axe)) * dot(normalise(c->axe), sub(r->ray.org, c->st))))
	* (1 + c->k * c->k));
	param.z = module(sub(r->ray.org, c->st)) * module(sub(r->ray.org, c->st))
	- ((dot(sub(r->ray.org, c->st), normalise(c->axe)) * dot(sub(r->ray.org,
	c->st), normalise(c->axe))) * (1 + c->k * c->k));
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances(r));
}

int				rat_trace_cone(t_rt *r, t_obj *obj)
{
	t_cone		*cone;

	cone = (t_cone *)obj->obj;
	if (intersection_co(r, cone))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

void GetAngleCone(t_rt *r)
{
    t_cone *obj;
	obj = (t_cone *)r->obj->obj;
    t_vecteur p;

    p = sub(obj->st ,create_v(dot(r->obj->inter,create_v(1.0 ,0.0, 0.0)), dot(r->obj->inter, create_v(0.0 ,1.0, 0.0)), dot(r->obj->inter, create_v(0.0 ,0.0, -1.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
	r->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	r->Vm = (p.y + 5.0 /2 )/ 5.0;
	r->Um -= floor(r->Um);
	r->Vm -= floor(r->Vm);
}