/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:39:04 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/09 18:04:33 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_obj_list(t_obj **obj_list)
{
	t_obj	*save;

	while (*obj_list != NULL)
	{
		save = *obj_list;
		*obj_list = (*obj_list)->next;
		free(save->obj);
		save->obj = NULL;
		free(save);
		save = NULL;
	}
}

void	free_light_lst(t_light_lst **light_lst)
{
	t_light_lst *save;

	while (*light_lst != NULL)
	{
		save = *light_lst;
		*light_lst = (*light_lst)->next;
		free(save);
		save = NULL;
	}
}

void	free_all(t_rt *r)
{
	free_obj_list(&r->head);
	free_light_lst(&r->light);
	free(r->name);
}
