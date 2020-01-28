/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:04:42 by mderri            #+#    #+#             */
/*   Updated: 2019/10/04 03:30:31 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				intersection_c(t_rt *r, t_cylinder *c)
{
	t_vecteur	param;
	t_vecteur	newv;

	newv = c->axe;
	param.x = dot(r->u, r->u) - (dot(r->u, normalise(newv)) * dot(r->u,
	normalise(newv)));
	param.y = 2 * (dot(r->u, sub(r->ray.org, c->st)) - (dot(r->u,
	normalise(newv)) * dot(normalise(newv), sub(r->ray.org, c->st))));
	param.z = module(sub(r->ray.org, c->st)) * module(sub(r->ray.org, c->st))
	- (dot(sub(r->ray.org, c->st), normalise(newv)) * dot(sub(r->ray.org,
	c->st), normalise(newv))) - c->r * c->r;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances(r));
}

int				rat_trace_cylinder(t_rt *r, t_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)obj->obj;
	if (intersection_c(r, cylinder))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
