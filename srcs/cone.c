/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:15:54 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 20:48:49 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		cone_intersection(t_rt *rt, t_object *cone_temp, double *dist)
{
	t_vect vect;
	double all[7];

	all[6] = tan(clamp(cone_temp->r, 180.0, 0.0) * M_PI / 180.0);
	vect = soustraction(rt->cam.cam_ray.o, cone_temp->position);
	all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - (1.0 + all[6] *
			all[6]) * pow(dot(rt->cam.cam_ray.d, cone_temp->direction), 2);
	all[1] = 2.0 * (dot(rt->cam.cam_ray.d, vect) - (1.0 + all[6] * all[6]) *
			dot(rt->cam.cam_ray.d, cone_temp->direction)
			* dot(vect, cone_temp->direction));
	all[2] = dot(vect, vect) - (1.0 + all[6] * all[6]) *
		dot(vect, cone_temp->direction) * dot(vect, cone_temp->direction);
	all[3] = all[1] * all[1] - 4.0 * all[0] * all[2];
	if (all[3] >= 0.0)
	{
		all[4] = (-all[1] - sqrt(all[3])) / (2.0 * all[0]);
		all[5] = (-all[1] + sqrt(all[3])) / (2.0 * all[0]);
  if (all[5] > all[4] && all[4] > 1e-4 && getColorFromTexture(rt, cone_temp, all[4]))
      *dist = all[4];
    else
      *dist = all[5];
    if(*dist >= 1e-4 && getColorFromTexture(rt, cone_temp, *dist))
     return (1);
     }
     return (0);;
}

void GetAngleCone(t_rt *rt, t_object *cone_temp, t_vect inter)
{
  t_vect p;

    p = soustraction(cone_temp->position , constrector(dot(inter,constrector(1.0 ,0.0, 0.0)), dot(inter, constrector(0.0 ,1.0, 0.0)), dot(inter, constrector(0.0 ,0.0, -1.0))));
//p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
	rt->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	rt->Vm = (p.y + 5.0 /2 )/ 5.0;
	rt->Um -= floor(rt->Um);
	rt->Vm -= floor(rt->Vm);
}