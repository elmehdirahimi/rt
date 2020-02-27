/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:21:52 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/01 12:21:55 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void   GetAngle(t_rt *rt, t_object *obj , t_vect inter)
{
	if(obj->type == 1)
		GetAngleSphere(rt,  obj , inter);
	else if (obj->type == 2)
		GetAnglePlan(rt,  obj , inter);
	else if (obj->type == 3)
		GetAngleCylinder(rt,  obj , inter);
	else if (obj->type == 4)
		GetAngleCone(rt,  obj , inter);
}



int		getColorFromTexture(t_rt *rt, t_object *obj,  double t)
{
	//int		i;
	//int		j;
	t_vect inter;


	inter = addition(multiplication(rt->cam.cam_ray.d, t), rt->cam.cam_ray.o);
	/*
	GetAngle(rt, obj, inter);
	
	i = rt->Um * rt->txt.w;
	j = (1.0 - rt->Vm) * rt->txt.h - 0.001;
	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	i = (i > rt->txt.w - 1) ? rt->txt.w - 1 : i;
	j = (j > rt->txt.h - 1) ? rt->txt.h - 1 : j;
	
	//obj->color.trans = (r->txt.buf[j * r->txt.w + i] >> 24) & 0xFF;
	if(rt->txt.buf[j * rt->txt.w + i] == -16777216)
			return(0);
	obj->color.x = (rt->txt.buf[j * rt->txt.w + i] >> 16) & 0xFF;
	obj->color.y = (rt->txt.buf[j * rt->txt.w + i] >> 8) & 0xFF;
	obj->color.z = rt->txt.buf[j * rt->txt.w + i] & 0xFF;
*/
/*	if(r->obj->color.trans == 255.0 && r->obj->color.r == 0 && r->obj->color.g == 0 && r->obj->color.b == 0)
	{
		
	}*/
	//return (0);
	//obj->color.x =  rand() % 255;
//	obj->color.y =  rand() % 255;
	//obj->color.z =  rand() % 255;*/
t_vect p;

p = soustraction(obj->position , constrector(dot(inter,constrector(1.0 ,0.0, 0.0)), dot(inter, constrector(0.0 ,1.0, 0.0)), dot(inter, constrector(0.0 ,0.0, -1.0))));

ft_voronoi_noise(obj,  p);
	return (1);
}