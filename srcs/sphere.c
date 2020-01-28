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

#include "rtv1.h"

int			intersection_s(t_rt *r, t_sphere *s)
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
	return (distances(r));
}

int			rat_trace_sphere(t_rt *r, t_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj;
	if (intersection_s(r, sphere))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
