/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:44:41 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/22 01:56:42 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		sphere_intersection(t_rt *rt, t_object *sphere_temp, double *dist)
{
	t_vect	vect;
	double	all[6];

	vect = soustraction(rt->cam.cam_ray.o, sphere_temp->position);
	all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d);
	all[1] = 2.0 * dot(vect, rt->cam.cam_ray.d);
	all[2] = dot(vect, vect) - sphere_temp->r * sphere_temp->r;
	all[3] = all[1] * all[1] - 4.0 * all[0] * all[2];
	if (all[3] >= 0.0)
	{
		all[4] = (-all[1] - sqrt(all[3])) / (2.0 * all[0]);
		all[5] = (-all[1] + sqrt(all[3])) / (2.0 * all[0]);
	if (all[5] > all[4] && all[4] >= 1e-4 && getColorFromTexture(rt, sphere_temp, all[4]))
			*dist = all[4];
		else
			*dist = all[5];
		if(*dist >= 1e-4 && getColorFromTexture(rt, sphere_temp, *dist))
			return (1);
	}
	return (0);
}

void 	GetAngleSphere(t_rt *rt, t_object *sphere_temp , t_vect inter)
{
    t_vect p;
	double phi;
	double theta;

p = soustraction(sphere_temp->position,constrector(dot(inter,constrector(0.0 ,0.0, 1.0)), dot(inter, constrector(0.0 ,-1.0, 0.0)), dot(inter, constrector(1.0 ,0.0, 0.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
 phi = atan2(p.z, p.x);
	theta = asin(p.y / sphere_temp->r) ;
	
//if (dot(obj->repere.k, create_v(0, 0, -1)) >= 0.0)
//		u = (phi + M_PI) / (2.0 * M_PI);
//	else
	rt->Um = 1 - (phi + M_PI) / (2.0 * M_PI);
    rt->Vm = (theta + M_PI / 2.0) / M_PI;
}