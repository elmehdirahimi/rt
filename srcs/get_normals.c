/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 02:35:11 by slaanani          #+#    #+#             */
/*   Updated: 2019/08/31 04:18:26 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			sphere_normal(t_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj;
	obj->normal = sub(obj->inter, sphere->centre);
	obj->normal = normalise(obj->normal);
}

void			plane_normal(t_obj *obj)
{
	t_plane		*plane;

	plane = (t_plane *)obj->obj;
	obj->normal = normalise(plane->normal);
}

void			cylinder_normal(t_rt *r, t_obj *obj)
{
	t_cylinder	*cylinder;
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	cylinder = (t_cylinder *)obj->obj;
	v = normalise(cylinder->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, cylinder->st), v);
	assist = sub(obj->inter, cylinder->st);
	obj->normal = sub(assist, kv(v, m));
	obj->normal = normalise(obj->normal);
}

void			cone_normal(t_rt *r, t_obj *obj)
{
	t_cone		*cone;
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	cone = (t_cone *)obj->obj;
	v = normalise(cone->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, cone->st), v);
	assist = sub(obj->inter, cone->st);
	obj->normal = sub(assist, kv(v, (1 + cone->k * cone->k) * m));
	obj->normal = normalise(obj->normal);
}

void			get_normal(t_rt *r, t_obj *obj)
{
	if (obj->type == tplane)
		plane_normal(obj);
	if (obj->type == tsphere)
		sphere_normal(obj);
	if (obj->type == tcylinder)
		cylinder_normal(r, obj);
	if (obj->type == tcone)
		cone_normal(r, obj);
}
