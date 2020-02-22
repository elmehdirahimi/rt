/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:59:02 by mderri            #+#    #+#             */
/*   Updated: 2019/10/10 14:59:54 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	check_format(t_holders *h, char **tab)
{
	if (h->s[1] || !tab[h->i + 1])
		put_error(SYNTAX_ERROR);
}

void	check_format2(t_holders *h, char **tab)
{
	if (!tab[h->i + h->j])
		put_error(SYNTAX_ERROR);
}

int		basic_test(char *str)
{
	int i;

	i = ft_strlen(str);
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

void	repere_plane(t_plane *plane)
{
	// if (((t_plane *)obj)->normal.x == 0.0)
	// {
	// 	((t_plane *)obj->obj)->repere.i = vcross(((t_plane *)obj)->normal, create_v(1, 0, 0));
	// 	((t_plane *)obj->obj)->repere.j = vcross(((t_plane *)obj)->normal, ((t_plane *)obj->obj)->repere.i);
	// 	((t_plane *)obj->obj)->repere.k = ((t_plane *)obj)->normal;
	// }
	if (plane->normal.x == 0.0)
	{
		plane->repere.i = normalise(vcross(plane->normal, create_v(1.0, 0.0, 0.0)));
		//printf("hnaa: %f\n\n", dot(plane->repere.i, plane->normal));
		plane->repere.j = normalise(vcross(plane->normal, plane->repere.i));
		plane->repere.k = plane->normal;
	}
	else
	{
		plane->repere.i = normalise(vcross(plane->normal, create_v(0.0, 1.0, 0.0)));
		//printf("hnae :%f\n\n", dot(plane->repere.i, plane->normal));
		plane->repere.j = normalise(vcross(plane->normal, plane->repere.i));
		plane->repere.k = plane->normal;
	}
	
	plane->limitx = 2.0;
	plane->limity = 2.0;
}

void	repere_sphere(t_sphere *sphere)
{
	if (sphere->axe.x == 0.0)
	{
		sphere->repere.i = normalise(vcross(sphere->axe, create_v(0.0, 1.0, 0.0)));
		sphere->repere.j = normalise(vcross(sphere->axe, sphere->repere.i));
		sphere->repere.k = sphere->axe;
	}
	else
	{
		sphere->repere.i = normalise(vcross(sphere->axe, create_v(0.0, 1.0, 0.0)));
		sphere->repere.j = normalise(vcross(sphere->axe, sphere->repere.i));
		sphere->repere.k = sphere->axe;
	}
}

// void	add_reperes(t_obj *obj_list)
// {
// 	t_obj	*o;

// 	o = obj_list;
// 	while (o)
// 	{
// 		if (o->type == tplane)
// 			repere_plane((t_plane *)(o->obj));
// 		if (o->type == tsphere)
// 			repere_sphere((t_sphere *)(o->obj));
// 		o = o->next;
// 	}
// }

int		main(int argc, char **argv)
{
	t_rt	r;

	if (argc != 2)
	{
		ft_putstr("Usage : ./rtv1 scene\n");
		exit(0);
	}
	r.name = ft_strdup("RTv1 - slaanani & mderri");
	r.obj_list = parsing(argv[1], &r);
	//add_reperes(r.obj_list);
	r.head = r.obj_list;
	r.m.ptr = mlx_init();
	r.m.win = mlx_new_window(r.m.ptr, r.m.w, r.m.h, r.name);
	r.m.d.img_ptr = mlx_new_image(r.m.ptr, r.m.w, r.m.h);
	r.m.d.pic_str = (int *)mlx_get_data_addr(r.m.d.img_ptr, &r.m.d.bpp,
&r.m.d.s_l, &r.m.d.endian);
if(load_texture(&r) == -1)
	return (0);
	raytracer(&r);
	mlx_put_image_to_window(r.m.ptr, r.m.win, r.m.d.img_ptr, 0, 0);
	mlx_hook(r.m.win, 2, 1, event_handle, &r.m);
	mlx_hook(r.m.win, 17, 1, ft_close, &r.m);
	mlx_loop(r.m.ptr);
	return (0);
}
