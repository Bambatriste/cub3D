/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:26 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:30 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	found_all_settings(t_settings settings)
{
	if (settings.r && settings.c && settings.f && settings.ea
		&& settings.we && settings.no && settings.so)
		return (1);
	else
		return (0);
}

void	get_buffer_first_str(char *buffer, t_game *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	j = 0;
	while (ft_is_space(buffer[i]))
		i++;
	while ((buffer[size + i]) && !ft_is_space(buffer[size + i]))
		size++;
	game->params->first_str = malloc(sizeof(char) * size + 1);
	if (game->params->first_str == NULL)
		ft_exit(FAIL_MALLOC, game);
	ft_memset(game->params->first_str, 0, size + 1);
	while (buffer[i + j] && !ft_is_space(buffer[i + j]))
	{
		game->params->first_str[j] = buffer[i + j];
		j++;
	}
	check_param_str(size, game);
}

void	get_settings(t_params *params, t_game *game)
{
	if (ft_strncmp(params->first_str, "R", 1) == 0)
		get_resolution(params, params->line_buff, game);
	if (ft_strncmp(params->first_str, "NO", 2) == 0)
		get_path(params->line_buff, &params->settings.no, game, NO);
	if (ft_strncmp(params->first_str, "SO", 2) == 0)
		get_path(params->line_buff, &params->settings.so, game, SO);
	if (ft_strncmp(params->first_str, "EA", 2) == 0)
		get_path(params->line_buff, &params->settings.ea, game, EA);
	if (ft_strncmp(params->first_str, "WE", 2) == 0)
		get_path(params->line_buff, &params->settings.we, game, WE);
	if (ft_strncmp(params->first_str, "C", 1) == 0)
	{
		fill_rgb(params->line_buff, &params->settings.c,
			&params->ceil_color, game);
	}
	if (ft_strncmp(params->first_str, "F", 1) == 0)
	{
		fill_rgb(params->line_buff, &params->settings.f,
			&params->floor_color, game);
	}
	free(params->first_str);
	params->first_str = NULL;
}

void	parsing_exit(t_game *game, t_params *params)
{
	if (params->screen_w > params->max_w)
		params->screen_w = params->max_w;
	if (params->screen_h > params->max_h)
		params->screen_h = params->max_h;
	if (!found_all_settings(params->settings))
		ft_exit(MISSING_PARAM, game);
	if (game->params->first_error != NONE)
		ft_exit(game->params->first_error, game);
	close(params->fd);
}

void	parse_file(t_params *params, t_game *game)
{
	int	gnlreturn;
	int	map_w;

	map_w = 0;
	gnlreturn = 1;
	check_cub(params, game);
	while (gnlreturn == 1)
	{
		gnlreturn = get_next_line(params->fd, &params->line_buff);
		params->map_x_max++;
		map_w = ft_strlen(params->line_buff);
		if (map_w > params->map_y_max)
			params->map_y_max = map_w;
		if (!found_all_settings(params->settings))
		{
			get_buffer_first_str(params->line_buff, game);
			params->map_start++;
			get_settings(params, game);
		}
		free(params->line_buff);
		params->line_buff = NULL;
	}
	parsing_exit(game, params);
}
