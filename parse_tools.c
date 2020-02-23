/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:05:41 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/15 15:05:43 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int check_camera_format(t_rt *rt)
{
    if ((ft_strcmp(rt->image[0], "[camera")) || (ft_strcmp(rt->image[1], "<")) ||
    (ft_strncmp(rt->image[4], "translation(", 11)) ||\
		(ft_strcmp(rt->image[5], ">")) || (ft_strncmp(rt->image[2], "look_from(", 9))
        || (ft_strncmp(rt->image[3], "look_at(", 7)))
		return (1);
    return (0);
}

int check_light_format(t_rt *rt, int *k)
{
    if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 5], ">") 
    || (ft_strncmp(rt->image[*k + 4], "translation(", 11)) ||\
			ft_strncmp(rt->image[*k + 2], "color(", 5) || \
			ft_strncmp(rt->image[*k + 3], "position(", 8) )
		return (1);
    return (0);
}

int check_sphere_format(t_rt *rt, int *k)
{
  	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 6], ">") 
      || (ft_strncmp(rt->image[*k + 5], "translation(", 11)) ||\
			ft_strncmp(rt->image[*k + 2], "color(", 5) || ft_strncmp(rt->image[*k + 3], "position(", 8) 
            || ft_strncmp(rt->image[*k + 4], "r(", 1))
            return (1);
    return (0);
}

int check_cylinder_format(t_rt *rt, int *k)
{
  	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 8], ">")
      || (ft_strncmp(rt->image[*k + 7], "translation(", 11)) ||\
			ft_strncmp(rt->image[*k + 6], "rotation(", 9)
            || ft_strncmp(rt->image[*k + 3], "position(", 8)\
			|| ft_strncmp(rt->image[*k + 5], "direction(", 9)
            || ft_strncmp(rt->image[*k + 4], "r(", 2))
		return (1);
    return (0);
}

int check_plan_format(t_rt *rt, int *k)
{
  	if (ft_strcmp(rt->image[*k + 1], "<") || ft_strcmp(rt->image[*k + 7], ">")
      || (ft_strncmp(rt->image[*k + 6], "translation(", 11)) ||\
			ft_strncmp(rt->image[*k + 5], "rotation(", 9)\
			|| ft_strncmp(rt->image[*k + 2], "color(", 5)
            || ft_strncmp(rt->image[*k + 4], "direction(", 9)\
			|| ft_strncmp(rt->image[*k + 3], "position(", 8))
		return (1);
    return (0);
}