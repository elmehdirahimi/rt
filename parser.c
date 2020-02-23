/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:07:20 by erahimi           #+#    #+#             */
/*   Updated: 2019/12/28 21:40:43 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int   parser(t_rt *rt)
{
	int k;
	
	if ((k = 6) && !(rt->image = ft_strsplit(get_buffer(rt), '\n')))
		return (-1);
	if((rt->nb_line < 6 ) || init_camera(rt, 10) == -1)
		return (-1);
	while(k < rt->nb_line)
	{
		if ((rt->nb_line >= k + 6) && !ft_strcmp(rt->image[k], "light"))
			add_light(rt, &k, 6);
		else if ((rt->nb_line >= k + 7) && !ft_strcmp(rt->image[k], "sphere"))
			
				add_sphere(rt, &k, 6);
		else if ((rt->nb_line >= k + 8) && !ft_strcmp(rt->image[k], "plane"))
					add_plane(rt, &k, 6);
		else if ((rt->nb_line >= k + 9) && (!ft_strcmp(rt->image[k], "cone")
							|| !ft_strcmp(rt->image[k], "cylinder")))
						add_cylinder(rt, &k, 6);
		else if ((ft_strcmp(rt->image[k], "]") == 0))
			return (1);
		else
			return(-1);
	}
	return (1);
}
