/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadTexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:12:30 by erahimi           #+#    #+#             */
/*   Updated: 2020/01/30 20:12:31 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			load_texture(t_rt *r)
{

	r->txt.img = mlx_xpm_file_to_image(r->m.ptr, "xpm/7.xpm", &r->txt.w,&r->txt.h);
	if (!r->txt.img)
			return (-1);
		r->txt.buf = (int *)mlx_get_data_addr(r->txt.img, &r->m.d.bpp,&r->m.d.s_l, &r->m.d.endian);
	return (1);
}