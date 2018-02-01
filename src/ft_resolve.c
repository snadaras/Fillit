/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:19:48 by snadaras          #+#    #+#             */
/*   Updated: 2018/01/12 10:30:09 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test_item(char **grid, int x, int y, t_item item)
{
	if (grid[item.b1.y + y][item.b1.x + x] == '.' &&
		grid[item.b2.y + y][item.b2.x + x] == '.' &&
		grid[item.b3.y + y][item.b3.x + x] == '.' &&
		grid[item.b4.y + y][item.b4.x + x] == '.')
		return (1);
	else
		return (0);
}

int		ft_test_coord(int size, int x, int y, t_item item)
{
	if ((item.b1.y + y) < size && (item.b1.x + x) < size &&
		(item.b2.y + y) < size && (item.b2.x + x) < size &&
		(item.b3.y + y) < size && (item.b3.x + x) < size &&
		(item.b4.y + y) < size && (item.b4.x + x) < size)
		return (1);
	else
		return (0);
}

void	ft_put_item(char **grid, int xy[2], t_item item, char letter)
{
	grid[item.b1.y + xy[1]][item.b1.x + xy[0]] = letter;
	grid[item.b2.y + xy[1]][item.b2.x + xy[0]] = letter;
	grid[item.b3.y + xy[1]][item.b3.x + xy[0]] = letter;
	grid[item.b4.y + xy[1]][item.b4.x + xy[0]] = letter;
}

void	ft_rm_item(char **grid, int x, int y, t_item item)
{
	grid[item.b1.y + y][item.b1.x + x] = '.';
	grid[item.b2.y + y][item.b2.x + x] = '.';
	grid[item.b3.y + y][item.b3.x + x] = '.';
	grid[item.b4.y + y][item.b4.x + x] = '.';
}

int		ft_resolve(char **grid, char let, t_item *item, int nb_p)
{
	int		xy[3];

	xy[2] = ft_get_gridsize(grid);
	xy[1] = 0;
	while (xy[1] < xy[2])
	{
		xy[0] = 0;
		while (xy[0] < xy[2])
		{
			if (ft_test_coord(xy[2], xy[0], xy[1], *item) &&
				ft_test_item(grid, xy[0], xy[1], *item))
			{
				ft_put_item(grid, xy, *item, let);
				if (item->id == nb_p)
					return (1);
				if (ft_resolve(grid, let + 1, item + 1, nb_p))
					return (1);
				else
					ft_rm_item(grid, xy[0], xy[1], *item);
			}
			xy[0] += 1;
		}
		xy[1] += 1;
	}
	return (0);
}
