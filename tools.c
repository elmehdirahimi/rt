/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:31:05 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/15 14:31:06 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect     get_normal(t_vect vect, t_object *object,t_rt *rt) 
{
	t_vect v2;
	t_vect temp;

	if(object->type == 1)
		return (normale(soustraction(vect, object->position)));
	if (object->type == 2)
	{
		if (dot(rt->cam.cam_ray.d, object->direction) <= 1e-5)
			return (object->direction);
		return (multiplication(object->direction, -1.0));
	}
	v2 = soustraction(rt->cam.cam_ray.o, object->position);
	if (object->type == 3)
		return (normale(soustraction(soustraction(vect, object->position),
		 multiplication(object->direction, dot(rt->cam.cam_ray.d, object->direction) 
		 * rt->t + dot(v2, object->direction)))));
	temp = multiplication(object->direction, dot(rt->cam.cam_ray.d, object->direction)
	 * rt->t + dot(v2, object->direction));
	temp = multiplication(temp, 1 + tan(object->r) * tan(object->r));
	return (normale(soustraction(soustraction(vect, object->position), temp))); 
}

t_vect    get_reflected(t_vect vect, t_vect v, t_object *object,t_rt *rt)
{
	t_vect n;
	t_vect r;

	n = get_normal(vect, object, rt);
	r = soustraction(v, multiplication(n, 2.0 * dot(v, n)));
	return (normale(r)); 
}

int     inter(t_rt *rt, t_object *object_temp, double *dist)
{
	if (object_temp->type == 1)
		return (sphere_intersection(rt,object_temp, dist));
	else{
		if(object_temp->type == 2)
			return (plane_intersection(rt,object_temp, dist));
		else
		{
			if(object_temp->type == 3)
				return (cylinder_intersection(rt,object_temp, dist));
			else
			{
				return (cone_intersection(rt,object_temp, dist));
			}
		}
	}
}

void swap_object(t_rt *rt, t_object *object)
{
	t_object     *tmp;

	tmp = rt->object;
	object->next = tmp;
	rt->object = object;
}

int cylinder_suit(t_rt *rt, t_object *object, int j, int *k)
{
	object->direction = extraConsterctor(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')' || !(j = 9))
		return (-1);
	object->rotation = extraConsterctor(rt->image[*k + 6], &j);
	if (rt->image[*k + 6][j] != ')')
		return (-1);
	if((ft_strcmp(rt->image[*k], "cone") == 0))
		object->type = 4;
	else
		object->type = 3;
	j = 12;
	object->translation = extraConsterctor(rt->image[*k + 7], &j);
	if (rt->image[*k + 7][j] != ')')
		return (-1);
	swap_object(rt, object);
	*k += 9;
	return (1);
}