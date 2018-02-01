/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:50:53 by snadaras          #+#    #+#             */
/*   Updated: 2018/01/26 12:38:38 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str_items;
	t_item	*tab;
	char	**grid;
	int		nb_items;

	if (ac == 2)
	{
		str_items = ft_get_items(av[1]);
		ft_isempty(str_items);
		ft_check_last_nl(str_items);
		nb_items = ft_count_items(str_items);
		tab = ft_stock_items(str_items, nb_items);
		grid = ft_all(tab, nb_items);
		ft_print_grid(grid);
	}
	else
		ft_putendl("error");
	return (0);
}
