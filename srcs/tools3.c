/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 23:55:04 by slaanani          #+#    #+#             */
/*   Updated: 2019/10/10 15:33:37 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	c(long double red, long double green, long double blue)
{
	t_color color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
}

void	get_window(t_rt *r, char **tab, int i)
{
	int			j;
	char		**splt;

	j = 1;
	while (j < 3)
	{
		splt = ft_strsplit(tab[i + j], ' ');
		if (j == 1)
			r->m.w = ft_atoi(splt[1]);
		else
			r->m.h = ft_atoi(splt[1]);
		free_splited(splt);
		j++;
	}
}

int		calculate_lines(char *name)
{
	int		i;
	int		akhra;
	int		fd;
	char	*haja;

	i = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		put_error(OPEN_ERROR);
	while ((akhra = get_next_line(fd, &haja)) == 1)
	{
		if (akhra < 0)
			put_error(READ_ERROR);
		free(haja);
		i++;
	}
	free(haja);
	close(fd);
	return (i);
}

int		all_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**read_file(char *name)
{
	char	**tab;
	char	*line;
	int		holder[5];
	int		i;

	i = 0;
	holder[0] = calculate_lines(name);
	tab = (char **)ft_memalloc(sizeof(char *) * (holder[0] + 1));
	if ((holder[2] = open(name, O_RDONLY)) < 0)
		put_error(OPEN_ERROR);
	while ((holder[1] = get_next_line(holder[2], &line)) == 1)
	{
		if (holder[1] < 0)
			put_error(READ_ERROR);
		if (!all_spaces(line) && ft_strcmp(line, ""))
			tab[i++] = ft_strdup(line);
		if (holder[4] > MAX_FILE_SIZE)
			put_error(BIG_FILE_ERROR);
		holder[4] += ft_strlen(line);
		free(line);
	}
	tab[i] = NULL;
	free(line);
	close(holder[2]);
	return (tab);
}
