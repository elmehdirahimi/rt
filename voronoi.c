/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voronoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:40 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/27 20:04:45 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_frac(double value)
{
	return (value - floor(value));
}
float		ft_rand3dto1d(t_vect value, t_vect dot_dir)
{
	t_vect	small_value;
	float		random;

	small_value = constrector(cos(value.x), cos(value.y), cos(value.z));
	random = dot(small_value, dot_dir);
	random = ft_frac(sin(random));
	return (random);
}

t_vect	ft_rand3dto3d(t_vect value)
{
	return (constrector(
				ft_rand3dto1d(value, constrector(102.989, 708.233, 370.719)),
				ft_rand3dto1d(value, constrector(390.346, 110.135, 830.155)),
				ft_rand3dto1d(value, constrector(730.156, 502.235, 90.151))));
}
float rand1dTo1d(float value, float mutator){
	float random = ft_frac(sin(value + mutator) * 143758.5453);
	return random;
}

t_vect rand1dTo3d(float value){
	return constrector(
		rand1dTo1d(value, 3.9812),
		rand1dTo1d(value, 7.1536),
		rand1dTo1d(value, 5.7241)
	);
}
void		ft_voronoi_1(t_cell *c, t_vect value)
{
	t_cell		tmp;
    int x;
	int y;
	int z;

	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			z = -1;
			while (z <= 1)
			{
				tmp.base = c->base;
				tmp.closest = addition(c->base, constrector(x, y, z));
				tmp.cellposition = addition(tmp.closest, ft_rand3dto3d(tmp.closest));
				tmp.toclosest = soustraction(tmp.cellposition, value);
				tmp.mindisttocell = module(tmp.toclosest);
				if (tmp.mindisttocell < c->mindisttocell)
				{
	
					*c = tmp;
				}
                z++;
			}
            y++;
		}
        x++;
	}
}

t_vect	ft_vfloor(t_vect v)
{
	return (constrector(floor(v.x), floor(v.y), floor(v.z)));
}


t_vect	ft_voronoi(t_vect value)
{
	t_cell	c;
	float	random1;
	float	random2;
	float	random3;

	c.base = ft_vfloor(value);
	c.mindisttocell = 10;

	ft_voronoi_1(&c, value);
	random1 = ft_rand3dto1d(c.closest, constrector(10.0, 30.0, 0.0));
	random2 = ft_rand3dto1d(c.closest, constrector(110.0, 2000.0, 220.0));
	random3 = ft_rand3dto1d(c.closest, constrector(110.0, 120.0, 300.20));

	return (constrector(random1, random2, random3));
}

void			ft_voronoi_noise(t_object *obj, t_vect p)
{
	t_voronoi v;

	v.value = multiplication(p, 1.0);



	v.noise = ft_voronoi(v.value);
	
	obj->color = constrector(v.noise.x * 255.0, v.noise.x * 255.0, v.noise.z * 255.0);
}


void  print_vect(t_vect vect)
{
	printf("(%f,%f,%f)\n",vect.x,vect.y,vect.z); ////////////// khasha t7ayad
}