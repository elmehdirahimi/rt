/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_load_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:51:53 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/29 19:23:46 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			load_texture(t_rt *rt)
{
		rt->txt.img = mlx_xpm_file_to_image(rt->mlx_ptr, "xpm/7.xpm", &rt->txt.w,&rt->txt.h);
		if (!rt->txt.img)
			return (0);
		rt->txt.buf = (int *)mlx_get_data_addr(rt->txt.img, &rt->bpp,&rt->size_line, &rt->endian);
	return (1);
}
