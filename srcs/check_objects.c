/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:01:28 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/10 18:58:59 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_spheres(char **tab)
{
	t_holders	h;

	init_sphere_holders(&h, 4);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "sphere:"))
		{
			h.sn++;
			check_format(&h, tab);
			free_splited(h.s);
			while (h.j++ < 4)
			{
				if (!tab[h.i + h.j])
					return (0);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_sphere_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	return ((h.sh[0] == h.sn && h.sh[1] == h.sn &&
	h.sh[2] == h.sn && h.sh[3] == h.sn));
}

int		check_planes(char **tab)
{
	t_holders	h;

	init_plane_holders(&h, 5);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "plane:"))
		{
			h.pn++;
			check_format(&h, tab);
			free_splited(h.s);
			while (h.j++ < 5)
			{
				if (!tab[h.i + h.j])
					return (0);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_plane_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	return ((h.ph[0] == h.pn && h.ph[1] == h.pn &&
	h.ph[2] == h.pn && h.ph[3] == h.pn && h.ph[4] == h.pn));
}

int		check_cylinders(char **tab)
{
	t_holders	h;

	init_cylinder_holders(&h, 6);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "cylinder:"))
		{
			h.cn++;
			check_format(&h, tab);
			free_splited(h.s);
			while (h.j++ < 6)
			{
				if (!tab[h.i + h.j])
					return (0);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_cylinder_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	return ((h.ch[0] == h.cn && h.ch[1] == h.cn && h.ch[2] == h.cn &&
	h.ch[3] == h.cn && h.ch[4] == h.cn && h.ch[5] == h.cn));
}

int		check_cones(char **tab)
{
	t_holders	h;

	init_cone_holders(&h, 6);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "cone:"))
		{
			h.con++;
			check_format(&h, tab);
			free_splited(h.s);
			while (h.j++ < 6)
			{
				if (!tab[h.i + h.j])
					return (0);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_cone_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	return ((h.coh[0] == h.con && h.coh[1] == h.con && h.coh[2] == h.con &&
	h.coh[3] == h.con && h.coh[4] == h.con && h.coh[5] == h.con));
}

int		check_lights(char **tab)
{
	t_holders	h;

	init_light_holders(&h, 3);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "light:"))
		{
			h.lgn++;
			check_format(&h, tab);
			free_splited(h.s);
			while (h.j++ < 3)
			{
				if (!tab[h.i + h.j])
					return (0);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_light_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	return ((h.lgh[0] == h.lgn && h.lgh[1] == h.lgn && h.lgh[2] == h.lgn));
}
