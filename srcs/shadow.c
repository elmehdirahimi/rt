/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:56:37 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/03 01:50:58 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				shadow_s(t_rt *r, t_obj *obj)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->obj;
	if (intersection_s(r, sphere))
		return (1);
	return (0);
}

int				shadow_p(t_rt *r, t_obj *obj)
{
	t_plane		*plane;

	plane = (t_plane *)obj->obj;
	if (intersection_p(r, plane))
		return (1);
	return (0);
}

int				shadow_co(t_rt *r, t_obj *obj)
{
	t_cone		*cone;

	cone = (t_cone *)obj->obj;
	if (intersection_co(r, cone))
		return (1);
	return (0);
}

int				shadow_c(t_rt *r, t_obj *obj)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)obj->obj;
	if (intersection_c(r, cylinder))
		return (1);
	return (0);
}

int				cast_shadow(t_rt *r)
{
	t_obj		*obj_list;

	obj_list = r->head;
	while (obj_list)
	{
		if (obj_list == r->obj)
		{
			if (obj_list->next)
				obj_list = obj_list->next;
			else
				break ;
		}
		if ((obj_list->type == tsphere) && shadow_s(r, obj_list))
			return (1);
		if ((obj_list->type == tplane) && shadow_p(r, obj_list))
			return (1);
		if ((obj_list->type == tcone) && shadow_co(r, obj_list))
			return (1);
		if ((obj_list->type == tcylinder) && shadow_c(r, obj_list))
			return (1);
		obj_list = obj_list->next;
	}
	return (0);
}
