/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:25:24 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/12/28 21:38:40 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int     init_camera(t_rt *rt, int j)
{
	if (check_camera_format(rt))
		rt_close1(&rt);
	rt->cam.cam_ray.o =  extraConsterctor(rt->image[2], &j);
	if (rt->image[2][j] != ')')
		rt_close1(&rt);
	j = 8;
	rt->cam.look_at =  extraConsterctor(rt->image[3], &j);
	if (rt->image[3][j] != ')')
		rt_close1(&rt);
	j = 12;
	rt->cam.cam_ray.translation = extraConsterctor(rt->image[4], &j);
	if (rt->image[4][j] != ')')
		rt_close1(&rt);
	return (1);
}

int			add_light(t_rt *rt, int *k, int j)
{
	t_light *l;
	t_light *tmp;

	if (!(l = (t_light *)malloc(sizeof(t_light))))
		rt_close1(&rt);
	tmp = rt->light;
	if (check_light_format(rt, k))
		rt_close1(&rt);
	l->color = extraConsterctor(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')' || !(j = 9))
		rt_close1(&rt);
	l->position = extraConsterctor(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')' || !(j = 12))
		rt_close1(&rt);
	l->translation = extraConsterctor(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')')
		rt_close1(&rt);
	l->next = tmp;
	rt->light = l;
	*k += 6;
	return (1);
}

int			add_sphere(t_rt *rt, int *k, int j)
{

	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		rt_close1(&rt);
	if (check_sphere_format(rt, k))
		rt_close1(&rt);
	object->color = extraConsterctor(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')' || !(j = 9))
		rt_close1(&rt);
	object->position = extraConsterctor(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')' || !(j = 2))
		rt_close1(&rt);
	object->r = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')' || !(j = 12))
		rt_close1(&rt);
	object->translation = extraConsterctor(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')' || !(object->type = 1))
		rt_close1(&rt);
	swap_object(rt, object);
	*k += 7;
	return(1);
}

int			add_cylinder(t_rt *rt, int *k, int j)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		rt_close1(&rt);
	if (check_cylinder_format(rt, k))
		rt_close1(&rt);
	object->color	= extraConsterctor(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')' || !(j = 9))
		rt_close1(&rt);
	object->position = extraConsterctor(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')' || !(j = 2))
		rt_close1(&rt);
	object->r = ft_atod(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')' || !(j = 10))
		rt_close1(&rt);
	return(cylinder_suit(rt, object, j, k));
}

int			add_plane(t_rt *rt, int *k, int j)
{
	t_object	*object;
	
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		rt_close1(&rt);
	if (check_plan_format(rt, k))
		rt_close1(&rt);
	object->color	= extraConsterctor(rt->image[*k + 2], &j);
	if (rt->image[*k + 2][j] != ')' || !(j = 9))
		rt_close1(&rt);
	object->position = extraConsterctor(rt->image[*k + 3], &j);
	if (rt->image[*k + 3][j] != ')' || !(j = 10))
		rt_close1(&rt);
	object->direction = extraConsterctor(rt->image[*k + 4], &j);
	if (rt->image[*k + 4][j] != ')' || !(j = 9))
		rt_close1(&rt);
	object->rotation = extraConsterctor(rt->image[*k + 5], &j);
	if (rt->image[*k + 5][j] != ')' || !(j = 12))
		rt_close1(&rt);
	object->translation = extraConsterctor(rt->image[*k + 6], &j);
	if (rt->image[*k + 6][j] != ')' || !(object->type = 2))
		rt_close1(&rt);
	swap_object(rt, object);
	*k += 8;
	return(1);
}
