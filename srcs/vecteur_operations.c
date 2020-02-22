/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:40:08 by mderri            #+#    #+#             */
/*   Updated: 2019/09/30 23:56:35 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vecteur		sum(t_vecteur v1, t_vecteur v2)
{
	t_vecteur v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vecteur		sub(t_vecteur v1, t_vecteur v2)
{
	t_vecteur v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vecteur		kv(t_vecteur v1, long double k)
{
	t_vecteur v3;

	v3.x = k * v1.x;
	v3.y = k * v1.y;
	v3.z = k * v1.z;
	return (v3);
}

double		dot(t_vecteur v1, t_vecteur v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vecteur		vcross(t_vecteur v1, t_vecteur v2)
{
	t_vecteur v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}
