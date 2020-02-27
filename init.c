/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:11:42 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/28 21:38:25 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void   corner(t_rt *rt)
{
	rt->cam.w = tan((60.0 * M_PI / 180.0) / 2.0) * 1.0;
	rt->cam.h = rt->cam.w;
	rt->up = normale(constrector(0.0, 1.0, 0.0));
	rt->to = normale(soustraction(rt->cam.cam_ray.o, rt->cam.look_at));
	if (equal(rt->up, rt->to) == 1)
	{
		rt->cam.u = constrector(1.0, 0.0, 0.0);
		rt->cam.v = constrector(0.0, 0.0, 1.0);
	}
	else
	{
		if(equal(rt->up, rt->to) == 2)
		{
			rt->cam.u = constrector(-1.0, 0.0, 0.0);
			rt->cam.v = constrector(0.0, 0.0, 1.0);
		}
		else
		{			
			rt->cam.u = cross(rt->up, rt->to);
			rt->cam.v = cross(rt->cam.u, rt->to);
		}
	}
	rt->cam.center_corner = soustraction(soustraction(soustraction(rt->cam.cam_ray.o,
	 multiplication(rt->to, 1.0)),multiplication(rt->cam.v, rt->cam.h)), 
	 multiplication(rt->cam.u, rt->cam.w));
}

void    param_init(t_rt * rt)
{
	t_light *t;
	t_object *temp;

	rt->cam.cam_ray.o = addition(rt->cam.cam_ray.o, rt->cam.cam_ray.translation);
	t = rt->light;
	while (t)
	{
		t->color = constrector(clamp(t->color.x, 255.0, 0), 
		clamp(t->color.y, 255.0, 0), clamp(t->color.z, 255.0, 0));
		t->position =  addition(t->position,t->translation);
		t = t->next;
	}
	temp = rt->object;
	while (temp)
	{
		temp->color.x = clamp(temp->color.x, 255.0, 0);
		temp->color.y = clamp(temp->color.y, 255.0, 0);
		temp->color.z = clamp(temp->color.z, 255.0, 0);
		temp->rotation = constrector(clamp(temp->rotation.x , 360.0, 0.0)* M_PI / 180.0, 
		clamp(temp->rotation.y , 360.0, 0.0)* M_PI / 180.0, 
		clamp(temp->rotation.z , 360.0, 0.0)* M_PI / 180.0);
		temp->direction = normale(project(normale(temp->direction), temp->rotation));
		temp->position = addition(temp->position, temp->translation);
		temp = temp->next;
	}
}

void	initialize(t_rt *rt, char *argv)
{
	
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDHT, HEIGHT, argv);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, WIDHT, HEIGHT);
	rt->data = (int *)mlx_get_data_addr(rt->img_ptr, &(rt->bpp),\
			&(rt->size_line), &(rt->endian));
	if (!load_texture(rt))
	{
		ft_putendl("error : failed to load teexture");
		exit (0);
	}
	param_init(rt);
	corner(rt);
}


