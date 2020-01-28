/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:25:08 by mderri            #+#    #+#             */
/*   Updated: 2019/10/08 19:25:09 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sphere_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->sn = 0;
	h->sh = (int *)ft_memalloc(sizeof(int) * n);
	h->sh = ft_memset(h->sh, 0, n);
}

void	init_plane_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->pn = 0;
	h->ph = (int *)ft_memalloc(sizeof(int) * n);
	h->ph = ft_memset(h->ph, 0, n);
}

void	init_cylinder_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->cn = 0;
	h->ch = (int *)ft_memalloc(sizeof(int) * n);
	h->ch = ft_memset(h->ch, 0, n);
}

void	init_cone_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->con = 0;
	h->coh = (int *)ft_memalloc(sizeof(int) * n);
	h->coh = ft_memset(h->coh, 0, n);
}

void	init_light_holders(t_holders *h, int n)
{
	h->i = 0;
	h->j = 1;
	h->lgn = 0;
	h->lgh = (int *)ft_memalloc(sizeof(int) * n);
	h->lgh = ft_memset(h->lgh, 0, n);
}
