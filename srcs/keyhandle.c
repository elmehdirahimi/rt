/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:21:38 by mderri            #+#    #+#             */
/*   Updated: 2019/10/09 17:13:37 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_close(t_rt *r)
{
	mlx_destroy_image(r->m.ptr, r->m.d.img_ptr);
	mlx_destroy_window(r->m.ptr, r->m.win);
	free_all(r);
	exit(0);
}

int		event_handle(int keycode, t_rt *r)
{
	if (keycode == ESC)
		ft_close(r);
	return (0);
}
