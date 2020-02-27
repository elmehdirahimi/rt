/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:28:58 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/15 14:28:59 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int sphere_check(t_light *t, t_object *o)
{
	if(module(soustraction(t->position, o->position)) == o->r)
		return (1);
	return (0);
}

int plan_check(t_light *t, t_object *o)
{
	if(dot(soustraction(t->position, o->position), o->direction) == 0.0)
		return (1);
	return (0);
}

int cylinder_check(t_light *t, t_object *o)
{
	t_vect vect;

	vect = soustraction(t->position, o->position);
      if((dot(vect, vect) - (pow((vect.x * o->direction.x + vect.y * o->direction.y + vect.z * o->direction.z), 2) / dot(o->direction, o->direction))) == pow(o->r, 2))
	   return (1);
	return (0);
}

int cone_check(t_light *t, t_object *o)
{
	t_vect vect;

	vect = soustraction(t->position, o->position);
	    if((dot(vect, vect) - (pow((vect.x * o->direction.x + vect.y * o->direction.y + vect.z * o->direction.z), 2) / dot(o->direction, o->direction))) ==
		 (pow((vect.x * o->direction.x + vect.y * o->direction.y + vect.z * o->direction.z), 2) / dot(o->direction, o->direction) * pow(tan(o->r), 2)))
	   return (1);
	return (0);
}

int check_enable(t_rt *rt, t_light *t)
{
		t_object *o;

		o = rt->object;
		while(o)
		{
			if (o->type == 1 && sphere_check(t, o))
				return (0);
			if (o->type == 2 && plan_check(t, o))
				return (0);
			if (o->type == 3 && cylinder_check(t, o))
				return (0);
			if (o->type == 3 && cone_check(t, o))
				return (0);
			o = o->next;
		}
		return (1);
}

void check_light(t_rt *rt)
{
	t_light *t;

	t = rt->light;
	while(t)
	{
		t->enable = check_enable(rt, t);
		t = t->next;
	}
}

