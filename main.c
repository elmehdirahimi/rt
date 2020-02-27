/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:37:32 by erahimi           #+#    #+#             */
/*   Updated: 2020/01/25 19:41:39 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_pixel(t_rt *rt, int x, int y,int color)
{

	if (x < WIDHT && x >= 0 && y >= 0 && y < HEIGHT)
	{
		rt->data[x + y * WIDHT] = color;
	}
}

static int		key_press(int key, t_rt *rt)
{
	if (key == 53)
	{
		rt_close(&rt);
		exit(0);
	}
	return (0);
}


int main(int argc,char **argv)
{
	t_rt *rt;

	if(argc == 2)
	{
		rt = (t_rt *)malloc(sizeof(t_rt));
		if(initialiser(rt, argv[1]) == 1)
		{
			if (parser(rt) == 1)
			{
				initialize(rt, argv[1]);
				draw(rt);
				mlx_hook(rt->win_ptr, 17, 0, rt_close, &rt);
				mlx_hook(rt->win_ptr, 2, 0, key_press, rt);
				mlx_loop(rt->mlx_ptr);
			}
			else
				ft_putendl("error parsing");
		}
		else
			ft_putendl("error reading file");
	}	
	else
	ft_putendl("usage: ./rtv1 scene_file");
	return (0);
}
