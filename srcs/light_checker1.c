/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_checker1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:32:29 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/23 20:45:43 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		sphere_check(t_light *t, t_object *o)
{
	if (module(soustraction(t->position, o->position)) == o->r)
		return (1);
	return (0);
}

int		plan_check(t_light *t, t_object *o)
{
	if (dot(soustraction(t->position, o->position), o->direction) == 0.0)
		return (1);
	return (0);
}

int		cylinder_check(t_light *t, t_object *o)
{
	t_vect	vect;

	vect = soustraction(t->position, o->position);
	if ((dot(vect, vect) - (pow((vect.x * o->direction.x +
							vect.y * o->direction.y +
							vect.z * o->direction.z), 2) / dot(o->direction,
							o->direction))) == pow(o->r, 2))
		return (1);
	return (0);
}

int		cone_check(t_light *t, t_object *o)
{
	t_vect	vect;

	vect = soustraction(t->position, o->position);
	if ((dot(vect, vect) - (pow((vect.x * o->direction.x + vect.y *
							o->direction.y + vect.z * o->direction.z), 2) /
					dot(o->direction, o->direction))) ==
			(pow((vect.x * o->direction.x + vect.y * o->direction.y + vect.z *
		o->direction.z), 2) / dot(o->direction, o->direction)
		* pow(tan(o->r), 2)))
		return (1);
	return (0);
}
