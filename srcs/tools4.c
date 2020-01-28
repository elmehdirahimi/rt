/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:50:06 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/04 22:01:48 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		there_is_sphere(char **tab)
{
	int		i;
	char	**spltd;

	i = 0;
	while (tab[i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "sphere:"))
			return (1);
		free_splited(spltd);
		i++;
	}
	return (0);
}

int		there_is_plane(char **tab)
{
	int		i;
	char	**spltd;

	i = 0;
	while (tab[i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "plane:"))
			return (1);
		free_splited(spltd);
		i++;
	}
	return (0);
}

int		there_is_cone(char **tab)
{
	int		i;
	char	**spltd;

	i = 0;
	while (tab[i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "cone:"))
			return (1);
		free_splited(spltd);
		i++;
	}
	return (0);
}

int		there_is_cylinder(char **tab)
{
	int		i;
	char	**spltd;

	i = 0;
	while (tab[i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "cylinder:"))
			return (1);
		free_splited(spltd);
		i++;
	}
	return (0);
}

int		there_is_light(char **tab)
{
	int		i;
	char	**spltd;

	i = 0;
	while (tab[i])
	{
		spltd = ft_strsplit(tab[i], ' ');
		if (ft_strequ(spltd[0], "light:"))
			return (1);
		free_splited(spltd);
		i++;
	}
	return (0);
}
