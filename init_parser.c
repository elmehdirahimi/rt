/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:31:28 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/12/17 22:31:30 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
int		ft_new_atoi(char *str, int *j)
{
	int i;
	int nb;
	int sgn;

	nb = 0;
	i = *j;
	sgn = 1;
	while (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sgn = -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	*j = i;
	return (nb * sgn);
}

double		ft_atod(char *str, int *j)
{
	double		nbr;
	int			i;
	double		chfr;
	static int	signe;

	
	nbr = (double)ft_new_atoi(str, j);	
	i = *j;
	chfr = 10;
	if (str[i] && str[i] == '.')
	{
		i++;
		while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
		{
			nbr = nbr >= 0 && !signe ? nbr + (double)(str[i++] - 48) / chfr :
				nbr - (double)(str[i++] - 48) / chfr;
			chfr *= 10;
		}
	}
	*j = i;
	return (nbr);
}


int   initialiser(t_rt *rt, char *argv)
{
	
    if ((rt->fd = open(argv, O_RDONLY)) == -1)
		return (-1);
    rt->nb_line = 0;
	rt->light = NULL;
	rt->object = NULL;
    return (1);
}

char    *get_buffer(t_rt *rt)
{
    char *buff;
    char *line;
	int  d;

	buff = NULL;
    while ((d = get_next_line(rt->fd, &line)) != 0)
    {
		if (d == -1)
			rt_close2(&rt);
		if(rt->nb_line == 0)
			buff =	ft_mystrjoin(line, "\n", 'F');
		else
			buff = ft_mystrjoin(buff,ft_mystrjoin(line, "\n", 'F'), 'B');
		if((rt->nb_line == 0) && (buff[0] != '['))
			return (NULL);
       rt->nb_line++;
    }
    close(rt->fd);
    return (buff);
}