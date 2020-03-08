/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:51:53 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/29 19:23:46 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int			load_texture(t_rt *rt)
{
	t_object *temp;

	temp = rt->object;
	while(temp)
	{
		temp->tc = 1;
		temp->txt.img = mlx_xpm_file_to_image(rt->mlx_ptr, "xpm/4.xpm", &temp->txt.w,&temp->txt.h);
		if (!temp->txt.img)
			return (0);
		temp->txt.buf = (int *)mlx_get_data_addr(temp->txt.img, &rt->bpp,&rt->size_line, &rt->endian);
		temp = temp->next;
	}
	return (1);
}