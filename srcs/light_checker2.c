/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:32:51 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/22 19:35:52 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_enable(t_rt *rt, t_light *t)
{
	t_object	*o;

	o = rt->object;
	while (o)
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

void	check_light(t_rt *rt)
{
	t_light	*t;

	t = rt->light;
	while (t)
	{
		t->enable = check_enable(rt, t);
		t = t->next;
	}
}
