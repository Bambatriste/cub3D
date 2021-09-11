#include "../headers/cub.h"

/* TODO : handle resolution over max H and W */
void	get_resolution(t_params *params, char *buffer, t_game *game)
{
	int		i;
	char	**split;

	if (params->settings.R == 1)
		ft_save_error(game->params, MULTIPLE_RES);
	params->settings.R = 1;
	i = 0;
	split = ft_split_set(buffer, " \f\t\n\r\v");
	while (split[i])
	{
		if (i > 0)
			if (!ft_is_only_digits(split[i]))
				ft_save_error(params, WRONG_RES_SETTINGS);
		i++;
	}
	if (i != 3)
		ft_save_error(params, WRONG_RES_SETTINGS);
	else
	{
		params->screenW = ft_atoi(split[1]);
		params->screenH = ft_atoi(split[2]);
		if (params->screenH <= 0 || params->screenW <= 0)
			ft_save_error(params, WRONG_RES_VALUES);
	}
	ft_free_split_strs(split, i);
}

void	ret_path(t_game *game, int name, char *path)
{
	if (name == EA)
		game->params->EA_texture = path;
	if (name == WE)
		game->params->WE_texture = path;
	if (name == SO)
		game->params->SO_texture = path;
	if (name == NO)
		game->params->NO_texture = path;
}

void	get_path(char *buffer, int *is_set, t_game *game, int name)
{
	char	**split;
	char	*path;
	int		i;

	path = NULL;
	if (*is_set == 1)
		ft_save_error(game->params, MULTI_TEX);
	else
	{
		*is_set = 1;
		i = 0;
		split = ft_split_set(buffer, "\f\t\n\r\v ");
		while (split[i])
			i++;
		if (i != 2)
			ft_save_error(game->params, WRONG_PATH);
		else
		{
			path = ft_strdup(split[1]);
			check_xpm(path, game);
		}
		ft_free_split_strs(split, i);
		ret_path(game, name, path);
	}
}

void	get_color(t_game *game, char **strs, int *color, int rgb[3])
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!ft_is_only_digits(strs[i]))
			ft_save_error(game->params, WRONG_COLOR);
		rgb[i] = ft_atoi(strs[i]);
		i++;
	}
	*color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
}

void	fill_rgb(char *buffer, int *is_set, int *color, t_game *game)
{
	int		i;
	int		rgb[3];
	char	**strs;

	i = 0;
	if (*is_set == 1)
		ft_save_error(game->params, MULTI_CEIL);
	else
	{
		*is_set = 1;
		while (!(*buffer == 'C' || *buffer == 'F'))
			buffer++;
		strs = ft_split_set(buffer + 1, ",");
		while (strs[i])
			i++;
		if (i != 3)
			ft_save_error(game->params, WRONG_ARG_RGB);
		else
			get_color(game, strs, color, rgb);
		check_colors(rgb, game);
		ft_free_split_strs(strs, i);
	}
}
