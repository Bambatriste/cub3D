/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:43:51 by aedouard          #+#    #+#             */
/*   Updated: 2020/08/07 16:32:21 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int check_valid(char c)
{
	if (c == '0'|| c == '1'|| c == '2'|| c == '3'|| c == '4')
		return (1);
	else
		return (0);
}

int check_around(int x , int y, char ** map, t_game *game)
{
	char char_up;
	char char_left;
	char char_down;
	char char_right;

	if (x + 1 >= game->params->map_x_max|| y + 1 >= game->params->map_y_max || x - 1 < 0 || y - 1 < 0)
		return (1);

	char_up = map[x][y + 1];
	char_left = map[x - 1][y];
	char_down = map[x][y - 1];
	char_right = map[x + 1][y];

	if (!check_valid(char_up) || !check_valid(char_down) || !check_valid(char_left) || !check_valid(char_right))
		return (1);
	else
	{
		return (0);
	}
}

void fill_map(int x,  int y, char **map, t_game *game)
{

	if (check_around(x, y, map , game))
	{
		ft_exit(NOT_CLOSED, game);
		/*printf("error en %d , %d\n", x, y);
		game->valid_map = 0;
		return ;
		*/
	}
	if (map[x + 1] [y] == '0')                
	{
		map[x + 1] [y] = '1';
			fill_map(x + 1, y , map, game);
	}
	if (map[x] [y + 1] == '0')
	{
		map[x] [y + 1] =  '1';
		fill_map(x, y + 1, map, game);
	}
	if (map[x - 1] [y] == '0')
	{
		map[x - 1] [y] =  '1';
		fill_map(x - 1, y , map, game);
	}
	if (map[x] [y - 1] == '0')
	{
		map[x] [y - 1] =  '1';
		fill_map(x, y - 1, map, game);
	}
	return ;
}
