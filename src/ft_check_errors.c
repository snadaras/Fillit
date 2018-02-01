/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:04:32 by snadaras          #+#    #+#             */
/*   Updated: 2018/01/26 12:05:21 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_check_shape(char *str_item)
{
	int		i;

	i = 0;
	if ((ft_strlen(str_item) / 5) != 4)
		return (1);
	while (i < 20)
	{
		if (i % 5 == 4 && str_item[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_nb_hash(char *str_item)
{
	int		i;
	int		count;
	char	symb;

	i = 0;
	count = 0;
	symb = '#';
	while (i < 20)
		if (str_item[i++] == symb)
			count++;
	if (count != 4)
		return (1);
	else
		return (0);
}

int		ft_check_last_nl(char *str_items)
{
	int	size;

	size = ft_strlen(str_items) - 1;
	if (str_items[size] == '\n' && str_items[size - 1] == '\n')
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

int		ft_isempty(char *str_items)
{
	if (ft_strcmp(str_items, "") == 0)
	{
		ft_putendl("error");
		exit(1);
	}
	return (0);
}

int		ft_check_dothash(char *str_item)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str_item[i] != '.' && str_item[i] != '#' && str_item[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
