/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 01:31:30 by mderri            #+#    #+#             */
/*   Updated: 2019/10/10 18:51:24 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	check_sphere_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "center:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->sh[0] += 1;
	if (ft_strequ(h->s[0], "ray:") && isdouble(h->s[1]) && !h->s[2])
		h->sh[1] += 1;
	if (ft_strequ(h->s[0], "color:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->sh[2] += 1;
	if (ft_strequ(h->s[0], "translation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->sh[3] += 1;
}

void	check_plane_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "pos:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ph[0] += 1;
	if (ft_strequ(h->s[0], "normal:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ph[1] += 1;
	if (ft_strequ(h->s[0], "color:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ph[2] += 1;
	if (ft_strequ(h->s[0], "translation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ph[3] += 1;
	if (ft_strequ(h->s[0], "rotation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ph[4] += 1;
}

void	check_cylinder_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "st:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ch[0] += 1;
	if (ft_strequ(h->s[0], "axe:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ch[1] += 1;
	if (ft_strequ(h->s[0], "ray:") && isdouble(h->s[1]) && !h->s[2])
		h->ch[2] += 1;
	if (ft_strequ(h->s[0], "color:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ch[3] += 1;
	if (ft_strequ(h->s[0], "translation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ch[4] += 1;
	if (ft_strequ(h->s[0], "rotation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->ch[5] += 1;
}

void	check_cone_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "st:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->coh[0] += 1;
	if (ft_strequ(h->s[0], "axe:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->coh[1] += 1;
	if (ft_strequ(h->s[0], "k:") && isdouble(h->s[1]) && !h->s[2])
		h->coh[2] += 1;
	if (ft_strequ(h->s[0], "color:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->coh[3] += 1;
	if (ft_strequ(h->s[0], "translation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->coh[4] += 1;
	if (ft_strequ(h->s[0], "rotation:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->coh[5] += 1;
}

void	check_light_params(t_holders *h)
{
	if (ft_strequ(h->s[0], "pos:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->lgh[0] += 1;
	if (ft_strequ(h->s[0], "color:") && isdouble(h->s[1]) &&
isdouble(h->s[2]) && isdouble(h->s[3]) && !h->s[4])
		h->lgh[1] += 1;
	if (ft_strequ(h->s[0], "intensity:") && isdouble(h->s[1]) &&
!h->s[2])
	{
		if (ft_f(h->s[1]) < 0 || ft_f(h->s[1]) > 1)
			put_error(INVALID_INTENSITY);
		h->lgh[2] += 1;
	}
}
