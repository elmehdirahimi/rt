/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:27:22 by mderri            #+#    #+#             */
/*   Updated: 2019/10/09 20:26:24 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_objects(char **tab)
{
	if (there_is_light(tab))
		if (!check_lights(tab))
			return (0);
	if (there_is_plane(tab))
		if (!check_planes(tab))
			return (0);
	if (there_is_sphere(tab))
		if (!check_spheres(tab))
			return (0);
	if (there_is_cylinder(tab))
		if (!check_cylinders(tab))
			return (0);
	if (there_is_cone(tab))
		if (!check_cones(tab))
			return (0);
	return (1);
}

void	init_camera_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->flag = 0;
	h->cah = (int *)ft_memalloc(sizeof(int) * n);
	h->cah = ft_memset(h->cah, 0, n);
}

void	check_camera_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "pos:") && isdouble(h->s[1]) && isdouble(h->s[2])
	&& isdouble(h->s[3]) && !h->s[4])
		h->cah[0] = 1;
	if (ft_strequ(h->s[0], "lookat:") && isdouble(h->s[1]) && isdouble(h->s[2])
	&& isdouble(h->s[3]) && !h->s[4])
		h->cah[1] = 1;
	if (ft_strequ(h->s[0], "focal_length:") && isdouble(h->s[1]) && !h->s[2])
	{
		if (ft_f(h->s[1]) < 0.0f || ft_f(h->s[1]) > 1.0f)
			put_error(INVALID_FOCAL_LENGTH);
		h->cah[2] = 1;
	}
}

void	init_window_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->flag = 0;
	h->wh = (int *)ft_memalloc(sizeof(int) * n);
	h->wh = ft_memset(h->wh, 0, n);
}

void	check_window_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "width:") && isdouble(h->s[1]) && !h->s[2])
	{
		if (ft_atoi(h->s[1]) < 20 || ft_atoi(h->s[1]) > 1920)
			put_error(WINDOW_SIZE_ERROR);
		h->wh[0] = 1;
	}
	if (ft_strequ(h->s[0], "height:") && isdouble(h->s[1]) && !h->s[2])
	{
		if (ft_atoi(h->s[1]) < 20 || ft_atoi(h->s[1]) > 1080)
			put_error(WINDOW_SIZE_ERROR);
		h->wh[1] = 1;
	}
}
