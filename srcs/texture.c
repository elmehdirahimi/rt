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

#include "../includes/rtv1.h"

void   GetAngle(t_rt *r)
{
	GetAngleSphere(r);
}


int		getColorFromTexture(t_rt *r, void *obj, long double s, t_obj *o)
{
	int		i;
	int		j;


	r->obj = o;
	o->obj = obj;
	r->obj->inter = sum(kv(r->u, s), r->cam.position);
	
	GetAngle(r);
	
	i = r->Um * r->txt.w;
	j = (1.0 - r->Vm) * r->txt.h - 0.001;
	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	i = (i > r->txt.w - 1) ? r->txt.w - 1 : i;
	j = (j > r->txt.h - 1) ? r->txt.h - 1 : j;
	r->obj->color.trans = (r->txt.buf[j * r->txt.w + i] >> 24) & 0xFF;
	r->obj->color.r = (r->txt.buf[j * r->txt.w + i] >> 16) & 0xFF;
	r->obj->color.g = (r->txt.buf[j * r->txt.w + i] >> 8) & 0xFF;
	r->obj->color.b = r->txt.buf[j * r->txt.w + i] & 0xFF;

/*	if(r->obj->color.trans == 255.0 && r->obj->color.r == 0 && r->obj->color.g == 0 && r->obj->color.b == 0)
	{
		
	}*/
	return (0);
	//return (1);
}
