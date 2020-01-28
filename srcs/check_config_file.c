/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 03:57:36 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/10 11:47:20 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			basic_check(char **tab)
{
	int		i;
	char	**spltd;

	i = -1;
	while (tab[++i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (!ft_strequ(spltd[0], "name:") && !ft_strequ(spltd[0], "window:")
	&& !ft_strequ(spltd[0], "width:") && !ft_strequ(spltd[0], "height:")
	&& !ft_strequ(spltd[0], "light:") && !ft_strequ(spltd[0], "pos:")
	&& !ft_strequ(spltd[0], "color:") && !ft_strequ(spltd[0], "intensity:")
	&& !ft_strequ(spltd[0], "camera:") && !ft_strequ(spltd[0], "cylinder:")
	&& !ft_strequ(spltd[0], "lookat:") && !ft_strequ(spltd[0], "focal_length:")
	&& !ft_strequ(spltd[0], "cone:") && !ft_strequ(spltd[0], "plane:")
	&& !ft_strequ(spltd[0], "st:") && !ft_strequ(spltd[0], "axe:")
	&& !ft_strequ(spltd[0], "k:") && !ft_strequ(spltd[0], "translation:")
	&& !ft_strequ(spltd[0], "rotation:") && !ft_strequ(spltd[0], "ray:")
	&& !ft_strequ(spltd[0], "center:") && !ft_strequ(spltd[0], "normal:")
	&& !ft_strequ(spltd[0], "sphere:"))
			return (0);
		free_splited(spltd);
	}
	return (1);
}

int			check_name(char **tab)
{
	char	**splited;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (tab[i])
	{
		splited = ft_strsplit(tab[i], ' ');
		if (ft_strequ(splited[0], "name:"))
		{
			if (splited[1] && !splited[2])
				flag == 0 ? flag = 1 : put_error(MULT_NAME_ERROR);
			else
				return (0);
		}
		free_splited(splited);
		i++;
	}
	return (1);
}

int			check_window(char **tab)
{
	t_holders	h;

	init_window_holders(&h, 2);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "window:"))
		{
			if (h.s[1] || !tab[h.i + 1])
				return (0);
			h.flag == 0 ? h.flag = 1 : put_error(MULT_WINDOW_ERROR);
			free_splited(h.s);
			while (h.j++ < 2)
			{
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_window_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	if (h.flag == 0)
		put_error(WINDOW_NOT_FOUND);
	return (h.wh[0] == 1 && h.wh[1] == 1);
}

int			check_camera(char **tab)
{
	t_holders	h;

	init_camera_holders(&h, 3);
	while (tab[h.i])
	{
		h.j = 0;
		h.s = ft_strsplit(tab[h.i], ' ');
		if (ft_strequ(h.s[0], "camera:"))
		{
			check_format(&h, tab);
			h.flag == 0 ? h.flag = 1 : put_error(MULT_CAMERA_ERROR);
			free_splited(h.s);
			while (h.j++ < 3)
			{
				check_format2(&h, tab);
				h.s = ft_strsplit(tab[h.i + h.j], ' ');
				check_camera_params(&h);
				free_splited(h.s);
			}
		}
		h.i++;
	}
	if (h.flag == 0)
		put_error(CAMERA_NOT_FOUND);
	return (h.cah[0] == 1 && h.cah[1] == 1 && h.cah[2] == 1);
}

int			check_file(char **tab)
{
	if (!basic_check(tab))
		return (0);
	if (check_camera(tab) && check_name(tab) && check_window(tab)
	&& check_objects(tab))
		return (1);
	return (0);
}
