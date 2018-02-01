/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:13:46 by snadaras          #+#    #+#             */
/*   Updated: 2018/01/26 12:46:19 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_item
{
	int				id;
	t_pos			b1;
	t_pos			b2;
	t_pos			b3;
	t_pos			b4;
}					t_item;

t_item				*ft_stock_items(char *str_items, int nb_items);
char				*ft_get_items(char *filename);
char				**ft_all(t_item *items, int nb_items);
char				**ft_get_tetri(void);
int					ft_resolve(char **grid, char let, t_item *item, int nb_p);
int					ft_check_shape(char *str_item);
int					ft_check_nb_hash(char *str_item);
int					ft_check_dothash(char *str_item);
int					ft_check_errors(char *str_item);
int					ft_isempty(char *str_items);
int					ft_check_nl(char nl);
int					ft_check_last_nl(char *str_items);
int					ft_match_items(char *str_item);
int					ft_count_items(char *str_items);
int					ft_get_pattern(char *str_item);
int					ft_get_gridsize(char **grid);
int					ft_match_invalid(char *str_item);
int					ft_match_invalid2(char *str_item);
void				ft_print_grid(char **tab);

void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_putnbr(int n);
void				ft_putchar(char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
