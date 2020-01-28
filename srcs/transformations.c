/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:48:46 by mderri            #+#    #+#             */
/*   Updated: 2019/09/26 15:48:51 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			deg_to_rad(double angle)
{
	return ((angle * PI) / 180);
}

t_vecteur		rotatez(t_vecteur vec, double angle)
{
	t_vecteur	newv;

	newv.x = cos(deg_to_rad(angle)) * vec.x - sin(deg_to_rad(angle)) * vec.y;
	newv.y = cos(deg_to_rad(angle)) * vec.y + sin(deg_to_rad(angle)) * vec.x;
	newv.z = vec.z;
	return (newv);
}

t_vecteur		rotatex(t_vecteur vec, double angle)
{
	t_vecteur	newv;

	newv.y = cos(deg_to_rad(angle)) * vec.y - sin(deg_to_rad(angle)) * vec.z;
	newv.z = cos(deg_to_rad(angle)) * vec.z - sin(deg_to_rad(angle)) * vec.y;
	newv.x = vec.x;
	return (newv);
}

t_vecteur		rotatey(t_vecteur vec, double angle)
{
	t_vecteur	newv;

	newv.z = cos(deg_to_rad(angle)) * vec.z - sin(deg_to_rad(angle)) * vec.x;
	newv.x = cos(deg_to_rad(angle)) * vec.x + sin(deg_to_rad(angle)) * vec.z;
	newv.y = vec.y;
	return (newv);
}

t_vecteur		translation(t_vecteur old_pos, t_vecteur tr)
{
	t_vecteur	new_pos;

	new_pos.x = old_pos.x + tr.x;
	new_pos.y = old_pos.y + tr.y;
	new_pos.z = old_pos.z + tr.z;
	return (new_pos);
}
