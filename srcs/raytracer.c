/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:32:07 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/07 22:11:02 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

long double		map(long double x, double size, int w)
{
	return (x * size / w - (size / 2));
}

void			make_ray(t_rt *r)
{
	t_vecteur	left;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	sumupleft;

	left = kv(r->cam.left, map(r->v1.x, r->cam.frame_width, r->m.w));
	up = kv(r->cam.up, map(r->v1.y, r->cam.frame_height, r->m.h));
	forward = kv(r->cam.forward, r->cam.focal_length);
	sumupleft = sum(up, left);
	r->ray.direct = sum(sumupleft, forward);
	r->ray.org = create_v(r->cam.position.x, r->cam.position.y,
	r->cam.position.z);
}

int				cast_object(t_rt *r)
{
	t_obj		*obj;

	obj = r->head;
	r->obj = NULL;
	while (obj)
	{
		if (obj->type == tplane)
			rat_trace_plane(r, obj);
		else if (obj->type == tsphere && rat_trace_sphere(r, obj) != 0)
				printf("hhhh\n");
		else if (obj->type == tcylinder)
			rat_trace_cylinder(r, obj);
		else if (obj->type == tcone)
			rat_trace_cone(r, obj);
		obj = obj->next;
	}
	if (r->obj)
		return (1);
	return (0);
}

void			raytracer(t_rt *r)
{
	r->v1.y = 0;
	while (r->v1.y < r->m.h)
	{
		r->v1.x = 0;
		while (r->v1.x < r->m.w)
		{
			make_ray(r);
			r->u = normalise(r->ray.direct);
			r->dis = MAX;
			if (cast_object(r))
			{
				lighting(r);
				r->m.d.pic_str[(int)(r->v1.y * r->m.w + r->v1.x)] =
				rgb(r->color.r,
				r->color.g, r->color.b);
			}
			r->v1.x++;
		}
		r->v1.y++;
	}
}
