/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:00:54 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/09 16:14:21 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			parse_objs(t_obj **obj, t_obj **tmp, t_holders *h, char **tab)
{
	if (ft_strequ(h->s[0], "plane:"))
		parse_plane(obj, tmp, tab, h->i);
	if (ft_strequ(h->s[0], "sphere:"))
		parse_sphere(obj, tmp, tab, h->i);
	if (ft_strequ(h->s[0], "cylinder:"))
		parse_cylinder(obj, tmp, tab, h->i);
	if (ft_strequ(h->s[0], "cone:"))
		parse_cone(obj, tmp, tab, h->i);
}

void			parse_nw(t_rt *r, char **splited, char **tab, int i)
{
	if (ft_strequ(splited[0], "name:"))
		r->name = ft_strdup(splited[1]);
	if (ft_strequ(splited[0], "window:"))
		get_window(r, tab, i);
}

t_obj			*parse1(t_rt *r, char **tab)
{
	t_obj		*obj_lst;
	t_obj		*obj;
	t_obj		*tmp;
	t_holders	h;

	h.i = -1;
	obj_lst = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj_lst->next = NULL;
	obj = obj_lst;
	while (tab[++h.i])
	{
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "name:") || ft_strequ(h.s[0], "window:") ||
		ft_strequ(h.s[0], "camera:"))
			parse_nw(r, h.s, tab, h.i);
		if (ft_strequ(h.s[0], "plane:") || ft_strequ(h.s[0], "cone:") ||
		ft_strequ(h.s[0], "sphere:") || ft_strequ(h.s[0], "cylinder:"))
			parse_objs(&obj, &tmp, &h, tab);
		free_splited(h.s);
	}
	tmp->next = NULL;
	return (obj_lst);
}

t_light_lst		*parse2(char **tab)
{
	t_light_lst	*light_lst;
	t_light_lst	*light;
	t_light_lst	*tmp;
	int			i;
	char		**spltd;

	i = -1;
	light_lst = NULL;
	light_lst = (t_light_lst *)ft_memalloc(sizeof(t_light_lst));
	light_lst->next = NULL;
	light = light_lst;
	while (tab[++i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "light:"))
		{
			light->light = add_light(tab, i);
			light->next = (t_light_lst *)ft_memalloc(sizeof(t_light_lst));
			tmp = light;
			light = light->next;
		}
		free_splited(spltd);
	}
	tmp->next = NULL;
	return (light_lst);
}

t_obj			*parsing(char *file, t_rt *r)
{
	char	**tab;
	t_obj	*obj_list;

	obj_list = NULL;
	tab = read_file(file);
	if (0 || check_file(tab))
	{
		obj_list = parse1(r, tab);
		r->light = parse2(tab);
		parse3(r, tab);
	}
	else
		put_error(SYNTAX_ERROR);
	free_splited(tab);
	return (obj_list);
}
