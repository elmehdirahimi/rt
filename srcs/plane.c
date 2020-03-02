/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:36:12 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/22 01:54:19 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		plane_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
	t_vect	vect;
	double	a;
	double	b;

	vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
	a = -dot(vect, plane_temp->direction);
	b = dot(rt->cam.cam_ray.d, plane_temp->direction);
	*dist = a / b;
	if(*dist >= 1e-4 && getColorFromTexture(rt, plane_temp, *dist))
		return (1);
	return (0);
}

void GetAnglePlan(t_rt *rt, t_object *plane_temp , t_vect inter)
{
    t_vect p;

p = soustraction(plane_temp->position,constrector(dot(inter,constrector(0.0 ,0.0, 1.0)), dot(inter, constrector(0.0 ,-1.0, 0.0)), dot(inter, constrector(1.0 ,0.0, 0.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
	rt->Um = p.x * 0.01;
	rt->Vm = p.y * 0.01;
	rt->Um -= floor(rt->Um);
	rt->Vm -= floor(rt->Vm);
}