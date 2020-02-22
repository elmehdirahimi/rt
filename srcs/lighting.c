/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 03:43:43 by slaanani          #+#    #+#             */
/*   Updated: 2020/01/30 20:07:42 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void			final_color(t_rt *r)
{
	r->color.r += r->ambient.r + r->diff.r + r->spec.r;
	r->color.g += r->ambient.g + r->diff.g + r->spec.g;
	r->color.b += r->ambient.b + r->diff.b + r->spec.b;
}

void			ambient(t_rt *r, t_light_lst *lst)
{
	r->ambient.r = 0.2 * r->obj->color.r * lst->light.color.r *
		lst->light.intensity / 255;
	r->ambient.g = 0.2 * r->obj->color.g * lst->light.color.g *
		lst->light.intensity / 255;
	r->ambient.b = 0.2 * r->obj->color.b * lst->light.color.b *
		lst->light.intensity / 255;
}

void			diffuse(t_rt *r, long double d, t_light_lst *lst)
{
	r->diff.r = d * 0.6 *
		(double)(lst->light.color.r * lst->light.intensity / 255) * r->obj->color.r;
	r->diff.g = d * 0.6 *
		(double)(lst->light.color.g * lst->light.intensity / 255) * r->obj->color.g;
	r->diff.b = d * 0.6 *
		(double)(lst->light.color.b * lst->light.intensity / 255) * r->obj->color.b;
}

void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l)
{
	t_vecteur	v1;
	t_vecteur	v2;
	long double	tmp;

	if (d == 0)
		tmp = 0;
	else
	{
		v1 = kv(dir, -1.0);
		v2 = sub(kv(r->obj->normal, 2.0 * d), r->u);
		tmp = pow(fmax(dot(v2, v1), 0.0), SPECULAR_POWER);
	}
	r->spec.r = 0.6 * tmp * l->light.color.r * l->light.intensity;
	r->spec.g = 0.6 * tmp * l->light.color.g * l->light.intensity;
	r->spec.b = 0.6 * tmp * l->light.color.b * l->light.intensity;
}

void  print_vect(t_vecteur vect)
{
	printf("(%Lf,%Lf,%Lf)\n",vect.x,vect.y,vect.z); ////////////// khasha t7ayad
}

void			lighting(t_rt *r)
{
	t_vecteur	dir;
	long double	d;
	t_light_lst	*lst;

	lst = r->light;
	r->diff = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->spec = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	dir = r->ray.direct;
	while (lst)
	{
		r->ray.org = r->obj->inter;
		r->ray.direct = sub(lst->light.org, r->obj->inter);
		r->dis = module(r->ray.direct);
		r->u = normalise(r->ray.direct);
		d = fmax(dot(r->obj->normal, r->u), 0.0);
		if (!cast_shadow(r))
		{
			ambient(r, lst);
			diffuse(r, d, lst);
			specular(r, d, dir, lst);
			final_color(r);
		}
		lst = lst->next;
	}
}
