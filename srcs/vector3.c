/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:19:41 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/22 01:42:49 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	project(t_vect direction, t_vect rotation)
{
	t_vect	new;
	double	previous_x;

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

double	clamp(double v, double max, double min)
{
	if (v < min)
		v = min;
	else if (v > max)
		v = max;
	return (v);
}

t_vect	extraconsterctor(char *image, int *j)
{
	t_vect vect;

	vect.x = ft_atod(image, j);
	vect.y = ft_atod(image, j);
	vect.z = ft_atod(image, j);
	return (vect);
}

void  print_vect(t_vect vect)
{
	printf("(%f,%f,%f)\n",vect.x,vect.y,vect.z);
}
double	ft_frac(double value)
{
	return (value - floor(value));
}