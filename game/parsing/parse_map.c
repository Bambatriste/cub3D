/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:48 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:52 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	is_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	adjust_dir(char c, t_game *game)
{
	if (c == 'N')
	{
		set_pos_v(&game->dir, -1, 0);
		set_pos_v(&game->plane, 0, 0.66);
	}
	if (c == 'S')
	{
		set_pos_v(&game->dir, 1, 0);
		set_pos_v(&game->plane, 0, -0.66);
	}
	if (c == 'E')
	{
		set_pos_v(&game->dir, 0, 1);
		set_pos_v(&game->plane, 0.66, 0);
	}
	if (c == 'W')
	{
		set_pos_v(&game->dir, 0, -1);
		set_pos_v(&game->plane, -0.66, 0);
	}
}

void	parse_map(t_game *game, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map = ft_calloc(sizeof(char *), params->map_x_max);
	if (game->map == NULL)
		ft_exit(FAIL_MALLOC, game);
	params->testmap = ft_calloc(sizeof(char *), params->map_x_max);
	if (params->testmap == NULL)
		ft_exit(FAIL_MALLOC, game);
	while (i < params->map_x_max)
	{
		game->map[i] = ft_calloc(sizeof(char), params->map_y_max);
		if (game->map[i] == NULL)
			ft_exit(FAIL_MALLOC, game);
		params->testmap[i] = ft_calloc(sizeof(char), params->map_y_max);
		if (params->testmap[i] == NULL)
			ft_exit(FAIL_MALLOC, game);
		i++;
	}
}

void	copy_line(int i, int len, char *buffer, t_game *game)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (is_player_pos(buffer[j]) && game->params->settings.player_pos == 0)
		{
			adjust_dir(buffer[j], game);
			game->pos_x = (float)(i) + 0.5;
			game->pos_y = (float)(j) + 0.5;
			game->map[i][j] = '0';
			game->params->testmap[i][j] = '0';
			game->params->settings.player_pos = 1;
		}
		else if (is_player_pos(buffer[j])
			&& game->params->settings.player_pos == 1)
			ft_save_error(game->params, MULTI_PLAYER_POS);
		else
		{
			game->map[i][j] = buffer[j];
			game->params->testmap[i][j] = buffer[j];
		}
		j++;
	}
}

void	copy_map(t_game *game, t_params *params)
{
	int		gnlreturn;
	int		i;
	int		len;
	char	*buffer;

	gnlreturn = 1;
	i = 0;
	params->fd = open(params->map_path, O_RDONLY);
	while (gnlreturn && gnlreturn != -1)
	{
		gnlreturn = get_next_line(params->fd, &buffer);
		len = ft_strlen(buffer);
		if (i >= params->map_start)
		{
			check_map_buff(buffer, game);
			copy_line(i, len, buffer, game);
		}
		i++;
		free(buffer);
	}
	if (game->params->first_error != NONE)
		ft_exit(game->params->first_error, game);
	close(params->fd);
}
