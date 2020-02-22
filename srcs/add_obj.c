/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:58:47 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/09 19:55:29 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*add_sphere(char **s, int i)
{
	t_sphere	*s2;
	int			j;
	char		**splt;

	j = 0;
	s2 = (struct s_sphere *)ft_memalloc(sizeof(struct s_sphere));
	while (++j < 5)
	{
		splt = ft_strsplit(s[i + j], ' ');
		if (j == 1)
			s2->centre = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		else if (j == 2)
			s2->rayon = ft_atoi(splt[1]);
		else if (j == 3)
			s2->color = c(ft_atoi(splt[1]), ft_atoi(splt[2]), ft_atoi(splt[3]));
		else
			s2->tr = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		free_splited(splt);
	}
	s2->centre = translation(s2->centre, s2->tr);
	s2->axe = create_v(0.0, 1.0, 0.0);
	repere_sphere(s2);
	s2->axe = rotatey(rotatez(rotatex(s2->axe, s2->rot.x), s2->rot.z), s2->rot.y);
		s2->repere.i = normalise(rotatez(rotatey(rotatex(s2->repere.i, s2->rot.x), s2->rot.y), s2->rot.z));
	s2->repere.j = normalise(rotatez(rotatey(rotatex(s2->repere.j, s2->rot.x), s2->rot.y), s2->rot.z));
	s2->repere.k = normalise(rotatez(rotatey(rotatex(s2->repere.k, s2->rot.x), s2->rot.y), s2->rot.y));


	
	return (s2);
}

t_cylinder		*add_cylinder(char **s, int i)
{
	t_cylinder	*y;

	y = (t_cylinder *)ft_memalloc(sizeof(t_cylinder));
	y->add_cylinder_j = 0;
	while (++y->add_cylinder_j < 7)
	{
		y->s = ft_strsplit(s[i + y->add_cylinder_j], ' ');
		if (y->add_cylinder_j == 1)
			y->st = create_v(ft_f(y->s[1]), ft_f(y->s[2]), ft_f(y->s[3]));
		else if (y->add_cylinder_j == 2)
			y->axe = create_v(ft_f(y->s[1]), ft_f(y->s[2]), ft_f(y->s[3]));
		else if (y->add_cylinder_j == 3)
			y->r = ft_atoi(y->s[1]);
		else if (y->add_cylinder_j == 4)
			y->color = c(ft_atoi(y->s[1]), ft_atoi(y->s[2]), ft_atoi(y->s[3]));
		else if (y->add_cylinder_j == 5)
			y->tr = create_v(ft_f(y->s[1]), ft_f(y->s[2]), ft_f(y->s[3]));
		else
			y->rot = create_v(ft_f(y->s[1]), ft_f(y->s[2]), ft_f(y->s[3]));
		free_splited(y->s);
	}
	y->st = translation(y->st, y->tr);
	y->axe = rotatey(rotatez(rotatex(y->axe, y->rot.x), y->rot.z),
	y->rot.y);
	return (y);
}

t_plane			*add_plane(char **s, int i)
{
	t_plane		*p2;
	int			j;
	char		**splt;

	j = 0;
	p2 = (t_plane *)ft_memalloc(sizeof(t_plane));
	while (++j < 6)
	{
		splt = ft_strsplit(s[i + j], ' ');
		if (j == 1)
			p2->o = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		else if (j == 2)
			p2->normal = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		else if (j == 3)
			p2->color = c(ft_atoi(splt[1]), ft_atoi(splt[2]), ft_atoi(splt[3]));
		else if (j == 4)
			p2->tr = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		else
			p2->rot = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		free_splited(splt);
	}
	p2->o = translation(p2->o, p2->tr);
	repere_plane(p2);

	p2->normal = rotatez(rotatey(rotatex(p2->normal, p2->rot.x), p2->rot.y), p2->rot.z);
	p2->repere.i = normalise(rotatez(rotatey(rotatex(p2->repere.i, p2->rot.x), p2->rot.y), p2->rot.z));
	p2->repere.j = normalise(rotatez(rotatey(rotatex(p2->repere.j, p2->rot.x), p2->rot.y), p2->rot.z));
	p2->repere.k = normalise(rotatez(rotatey(rotatex(p2->repere.k, p2->rot.x), p2->rot.y), p2->rot.y));
	return (p2);
}

t_cone			*add_cone(char **s, int i)
{
	t_cone		*e;

	e = (t_cone *)ft_memalloc(sizeof(t_cone));
	e->add_cone_j = 0;
	while (++e->add_cone_j < 7)
	{
		e->s = ft_strsplit(s[i + e->add_cone_j], ' ');
		if (e->add_cone_j == 1)
			e->st = create_v(ft_f(e->s[1]), ft_f(e->s[2]), ft_f(e->s[3]));
		else if (e->add_cone_j == 2)
			e->axe = create_v(ft_f(e->s[1]), ft_f(e->s[2]), ft_f(e->s[3]));
		else if (e->add_cone_j == 3)
			e->k = ft_f(e->s[1]);
		else if (e->add_cone_j == 4)
			e->color = c(ft_atoi(e->s[1]), ft_atoi(e->s[2]), ft_atoi(e->s[3]));
		else if (e->add_cone_j == 5)
			e->tr = create_v(ft_f(e->s[1]), ft_f(e->s[2]), ft_f(e->s[3]));
		else
			e->rot = create_v(ft_f(e->s[1]), ft_f(e->s[2]), ft_f(e->s[3]));
		free_splited(e->s);
	}
	e->st = translation(e->st, e->tr);
	e->axe = rotatey(rotatez(rotatex(e->axe, e->rot.x), e->rot.z),
	e->rot.y);
	return (e);
}
