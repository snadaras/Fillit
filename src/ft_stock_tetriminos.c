/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:07:37 by snadaras          #+#    #+#             */
/*   Updated: 2017/12/29 15:37:56 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char		**ft_get_tetri2(void)
{
	char	**tetri;

	if (!(tetri = (char**)malloc(sizeof(char*) * 19)))
		return (NULL);
	tetri[0] = "00102021";
	tetri[1] = "10111202";
	tetri[2] = "00011121";
	tetri[3] = "00100102";
	tetri[4] = "00102011";
	tetri[5] = "10011112";
	tetri[6] = "10011121";
	tetri[7] = "00011102";
	tetri[8] = "00102001";
	tetri[9] = "00101112";
	tetri[10] = "20011121";
	tetri[11] = "00010212";
	tetri[12] = "10200111";
	tetri[13] = "00011112";
	tetri[14] = "00101121";
	tetri[15] = "10011102";
	tetri[16] = "00010203";
	tetri[17] = "00102030";
	tetri[18] = "00100111";
	return (tetri);
}

int			ft_count_items(char *str_items)
{
	return ((ft_strlen(str_items) + 1) / 21);
}

void		ft_print_grid(char **tab)
{
	int i;
	int	nb;

	i = 0;
	nb = ft_get_gridsize(tab);
	while (i < nb)
		ft_putendl(tab[i++]);
}

static int	ft_ctoi(char c)
{
	if (c >= '0' && c <= '9')
		c -= 48;
	return (c);
}

t_item		*ft_stock_items(char *str_items, int nb_items)
{
	int		i;
	t_item	*tab;
	t_item	item;
	char	**tetri;
	int		nb;

	i = 0;
	nb = 1;
	tetri = ft_get_tetri2();
	tab = (t_item*)malloc(sizeof(t_item) * nb_items);
	while (i < nb_items)
	{
		item.id = nb++;
		item.b1.x = ft_ctoi(tetri[ft_get_pattern(str_items)][0]);
		item.b1.y = ft_ctoi(tetri[ft_get_pattern(str_items)][1]);
		item.b2.x = ft_ctoi(tetri[ft_get_pattern(str_items)][2]);
		item.b2.y = ft_ctoi(tetri[ft_get_pattern(str_items)][3]);
		item.b3.x = ft_ctoi(tetri[ft_get_pattern(str_items)][4]);
		item.b3.y = ft_ctoi(tetri[ft_get_pattern(str_items)][5]);
		item.b4.x = ft_ctoi(tetri[ft_get_pattern(str_items)][6]);
		item.b4.y = ft_ctoi(tetri[ft_get_pattern(str_items)][7]);
		tab[i++] = item;
		str_items += 21;
	}
	return (tab);
}
