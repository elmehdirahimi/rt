/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 04:20:03 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/10 14:12:21 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				isdouble(char *str)
{
	int			i;
	int			flag;

	if (!str || (basic_test(str)) == 0)
		return (0);
	i = 0;
	flag = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (i == 0)
				return (0);
			if (flag == 0)
				flag = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

t_light			add_light(char **tab, int i)
{
	t_light		l;
	char		**splt;
	int			j;

	j = 0;
	while (++j < 4)
	{
		splt = ft_strsplit(tab[i + j], ' ');
		if (j == 1)
			l.org = create_v(ft_f(splt[1]), ft_f(splt[2]), ft_f(splt[3]));
		else if (j == 2)
			l.color = c(ft_atoi(splt[1]), ft_atoi(splt[2]), ft_atoi(splt[3]));
		else
			l.intensity = ft_f(splt[1]);
		free_splited(splt);
	}
	return (l);
}

void			create_camera(t_rt *r, char **s, int i)
{
	t_vecteur	up;
	int			j;
	char		**sp;

	j = 1;
	while (j < 4)
	{
		sp = ft_strsplit(s[i + j], ' ');
		if (j == 1)
			r->cam.position = create_v(ft_f(sp[1]), ft_f(sp[2]), ft_f(sp[3]));
		else if (j == 2)
			r->cam.lookat = create_v(ft_f(sp[1]), ft_f(sp[2]), ft_f(sp[3]));
		else
			r->cam.focal_length = ft_f(sp[1]);
		free_splited(sp);
		j++;
	}
	up = normalise(create_v(0.000001, 1 + r->m.h - r->m.h, 0.000001));
	r->cam.forward = normalise(sub(r->cam.lookat, r->cam.position));
	r->cam.left = normalise(vcross(up, r->cam.forward));
	r->cam.up = normalise(vcross(r->cam.forward, r->cam.left));
	r->cam.frame_height = (long double)r->m.h / (long double)r->m.w;
	r->cam.frame_width = r->cam.frame_height * (long double)r->m.w /
(long double)r->m.h;
}

long double		module(t_vecteur v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_vecteur		normalise(t_vecteur v1)
{
	t_vecteur u;

	u.x = v1.x / module(v1);
	u.y = v1.y / module(v1);
	u.z = v1.z / module(v1);
	return (u);
}
