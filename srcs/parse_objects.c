/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:59:48 by mderri            #+#    #+#             */
/*   Updated: 2019/10/07 22:19:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			parse3(t_rt *r, char **tab)
{
	int			i;
	char		**spltd;

	i = -1;
	while (tab[++i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "camera:"))
			create_camera(r, tab, i);
		free_splited(spltd);
	}
}

void			parse_plane(t_obj **obj, t_obj **tmp, char **tab, int i)
{
	t_plane		*plane;

	plane = add_plane(tab, i);
	(*obj)->type = tplane;
	(*obj)->obj = (void *)plane;
	(*obj)->color = plane->color;
	(*obj)->next = (t_obj *)ft_memalloc(sizeof(t_obj));
	*tmp = *obj;
	*obj = (*obj)->next;
}

void			parse_sphere(t_obj **obj, t_obj **tmp, char **tab, int i)
{
	t_sphere	*sphere;

	sphere = add_sphere(tab, i);
	(*obj)->type = tsphere;
	(*obj)->obj = (void *)sphere;
	(*obj)->color = sphere->color;
	(*obj)->next = (t_obj *)ft_memalloc(sizeof(t_obj));
	*tmp = *obj;
	*obj = (*obj)->next;
}

void			parse_cylinder(t_obj **obj, t_obj **tmp, char **tab, int i)
{
	t_cylinder	*cylinder;

	cylinder = add_cylinder(tab, i);
	(*obj)->type = tcylinder;
	(*obj)->obj = (void *)cylinder;
	(*obj)->color = cylinder->color;
	(*obj)->next = (t_obj *)ft_memalloc(sizeof(t_obj));
	*tmp = *obj;
	*obj = (*obj)->next;
}

void			parse_cone(t_obj **obj, t_obj **tmp, char **tab, int i)
{
	t_cone		*cone;

	cone = add_cone(tab, i);
	(*obj)->type = tcone;
	(*obj)->obj = (void *)cone;
	(*obj)->color = cone->color;
	(*obj)->next = (t_obj *)ft_memalloc(sizeof(t_obj));
	*tmp = *obj;
	*obj = (*obj)->next;
}
