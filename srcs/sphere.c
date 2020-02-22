/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:42:46 by mderri            #+#    #+#             */
/*   Updated: 2019/10/04 03:30:26 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			intersection_s(t_rt *r, t_sphere *s, t_obj *o)
{
	t_vecteur	param;

	param.x = 1;
	param.y = 2 * dot(r->u, sub(r->ray.org, s->centre));
	param.z = module(sub(r->ray.org, s->centre)) * module(sub(r->ray.org,
	s->centre)) - s->rayon * s->rayon;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_s(r, s,o));
}

int			rat_trace_sphere(t_rt *r, t_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj;

	if (intersection_s(r, sphere, obj))
	{
		r->obj = obj;
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		return (1);
	}

	r->obj = NULL;
	return (0);
}

void GetAngleSphere(t_rt *r)
{
    t_vecteur p;
	t_sphere *obj;
	
	obj = (t_sphere *)r->obj->obj;
p = sub(obj->centre,create_v(dot(r->obj->inter,create_v(0.0 ,0.0, 1.0)), dot(r->obj->inter, create_v(0.0 ,-1.0, 0.0)), dot(r->obj->inter, create_v(1.0 ,0.0, 0.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
 r->phi = atan2(p.z, p.x);
r->theta = asin(p.y / obj->rayon) ;
	
//if (dot(obj->repere.k, create_v(0, 0, -1)) >= 0.0)
//		u = (phi + M_PI) / (2.0 * M_PI);
//	else
	r->Um = 1 - (r->phi + M_PI) / (2.0 * M_PI);
    r->Vm = (r->theta + M_PI / 2.0) / M_PI;
}