/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:37:32 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 21:43:27 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			put_pixel(t_rt *rt, int x, int y, int color)
{
	if (x < WIDHT && x >= 0 && y >= 0 && y < HEIGHT)
	{
		rt->data[x + y * WIDHT] = color;
	}
}

void			ft_free_twodim(char ***to)
{
	char	**to_free;
	int		i;

	i = 0;
	to_free = *to;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
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

int				main(int argc, char **argv)
{
	t_rt *rt;

	if (argc == 2)
	{
		rt = (t_rt *)malloc(sizeof(t_rt));
		if (initialiser(rt, argv[1]) == 1)
		{
			if (parser(rt) == 1)
			{
				  int i;

  if (!(rt->ran = (t_vect *)malloc(256 * sizeof(t_vect))))
		exit(0);
    i = 0;
    	while (i < 256)
	{
		rt->ran[i].x = rand() % 255;
		rt->ran[i].y = rand() % 255;
		rt->ran[i].z = rand() % 255;
		rt->ran[i] = normale(rt->ran[i]);
        i++;
	}
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
