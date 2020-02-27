/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:16:04 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/28 21:38:10 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect addition(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return (vect);
}

t_vect soustraction(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

t_vect multiplication(t_vect vect1, double x)
{
	t_vect vect;

	vect.x = vect1.x * x;
	vect.y = vect1.y * x;
	vect.z = vect1.z * x;
	return (vect);
}
double  dot(t_vect vect1, t_vect vect2)
{
	double d;

	d = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (d);
}

double  module(t_vect vect)
{
	return (sqrt(dot(vect, vect)));
}

t_vect normale(t_vect vect)
{
	return (multiplication(vect, 1 / module(vect)));
}

t_vect  constrector(double x, double y, double z)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect  cross(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return (vect);
} 
t_vect division(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.x / vect2.x;
	vect.y = vect1.y / vect2.y;
	vect.z = vect1.z / vect2.z;
	return (vect);
}

int equal(t_vect vect1, t_vect vect2)
{
	if (vect1.y == vect2.y)
		return (1);
	if (vect1.y == -vect2.y)
		return (2);
	return (0);
}

t_vect		project(t_vect direction, t_vect rotation)
{
	t_vect new;
	double		previous_x;

	new.x = direction.x;
	new.y = direction.y * cos(rotation.x) + direction.z * sin(rotation.x);
	new.z = -direction.y * sin(rotation.x) + direction.z * cos(rotation.x);

	previous_x = new.x;
	new.x = new.x * cos(rotation.y) + new.z * sin(rotation.y);
	new.z = -new.x * sin(rotation.y) + new.z * cos(rotation.y);

	previous_x = new.x;
	new.x = new.x * cos(rotation.z) - new.y * sin(rotation.z);
	new.y = previous_x * sin(rotation.z) + new.y * cos(rotation.z);
	return (new);
}

double clamp(double v, double max, double min)
{
	if (v < min)
		v = min;
	else if (v > max)
		v = max;
	return (v);
}

t_vect   extraConsterctor(char *image, int *j)
{
	t_vect vect;

	vect.x = ft_atod(image, j);
	vect.y = ft_atod(image, j);
	vect.z = ft_atod(image, j);
	return (vect);
}