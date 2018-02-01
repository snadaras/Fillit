/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:37:07 by snadaras          #+#    #+#             */
/*   Updated: 2018/01/26 12:53:34 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_check_errors(char *str_item)
{
	if (ft_check_shape(str_item) || ft_check_dothash(str_item) ||
		ft_check_nb_hash(str_item) || ft_match_invalid(str_item) ||
		ft_match_invalid2(str_item) || ft_match_items(str_item))
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

int		ft_check_nl(char nl)
{
	if (nl != '\n')
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

char	*ft_get_items(char *filename)
{
	int		fd;
	int		ret;
	char	buf[21];
	char	*items;

	items = "";
	ret = 0;
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 20)))
	{
		buf[ret] = '\0';
		if (ft_check_errors(buf))
			return ("");
		items = ft_strjoin(items, buf);
		if ((ret = read(fd, buf, 1)))
		{
			buf[ret] = '\0';
			if (ft_check_nl(*buf))
				return ("");
			items = ft_strjoin(items, buf);
		}
	}
	close(fd);
	return (items);
}
