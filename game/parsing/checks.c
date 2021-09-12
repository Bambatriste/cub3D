/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:23:27 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:23:31 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	check_cub(t_params *params, t_game *game)
{
	int	len;

	len = ft_strlen(params->map_path);
	if (len < 4)
		ft_exit(WRONG_MAP_FORMAT, game);
	params->fd = open(params->map_path, O_RDONLY);
	if (params->fd == -1)
	{
		close(params->fd);
		ft_exit(CANT_OPEN_MAP_FILE, game);
	}
	if (params->map_path[len - 1] != 'b' || params->map_path[len - 2] != 'u'
		|| params->map_path[len - 3] != 'c' || params->map_path[len - 4] != '.')
		ft_exit(WRONG_MAP_FORMAT, game);
}

void	check_map_buff(char *buffer, t_game *game)
{
	int			i;
	const char	*set = " \f\t\n\r\v01NSEW";

	i = 0;
	while (buffer[i])
	{
		if (!ft_inset(buffer[i], set))
			ft_save_error(game->params, INVALID_MAPS_CHARS);
		i++;
	}
}

void	check_param_str(int size, t_game *game)
{
	if (ft_strncmp(game->params->first_str, "R", size) != 0
		&& ft_strncmp(game->params->first_str, "NO", size) != 0
		&& ft_strncmp(game->params->first_str, "SO", size) != 0
		&& ft_strncmp(game->params->first_str, "WE", size) != 0
		&& ft_strncmp(game->params->first_str, "EA", size) != 0
		&& ft_strncmp(game->params->first_str, "S", size) != 0
		&& ft_strncmp(game->params->first_str, "F", size) != 0
		&& ft_strncmp(game->params->first_str, "C", size) != 0)
		ft_save_error(game->params, INVALID_PARAM);
}

void	check_xpm(char *path, t_game *game)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_save_error(game->params, WRONG_TEX_PATH);
	if ((path[len - 1] != 'm' || path[len - 2] != 'p'
			|| path[len - 3] != 'x' || path[len - 4] != '.')
		&& ((path[len - 1] != 'M' || path[len - 2] != 'P'
				|| path[len - 3] != 'X' || path[len - 4] != '.')))
		ft_save_error(game->params, WRONG_TEX_PATH_FORMAT);
}

void	check_colors(int rgb[3], t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255 )
			ft_save_error(game->params, WRONG_RGB_VALUE);
		i++;
	}
}
