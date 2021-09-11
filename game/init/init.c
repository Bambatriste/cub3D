/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:36:19 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/02 20:32:02 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	window_init(t_game *game, t_window *window, t_params *params)
{
	window->bits_per_pixel = 32;
	window->size_line = params->screenW;
	window->endian = 0;
	window->img = mlx_new_image(game->mlx, params->screenW, params->screenH);
	window->img_data = (int *)mlx_get_data_addr(window->img,
			&window->bits_per_pixel, &window->size_line, &window->endian);
	window->window = mlx_new_window(game->mlx,
			params->screenW, params->screenH, "cub3D");
}

void	init_textures(t_game *game, t_textures *tex, t_params *params)
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	int			en;

	en = 0;
	no.img = mlx_xpm_file_to_image(game->mlx, params->NO_texture, &no.w, &no.h);
	so.img = mlx_xpm_file_to_image(game->mlx, params->SO_texture, &so.w, &so.h);
	ea.img = mlx_xpm_file_to_image(game->mlx, params->EA_texture, &ea.w, &ea.h);
	we.img = mlx_xpm_file_to_image(game->mlx, params->WE_texture, &we.w, &we.h);
	no.img_data = (int *)mlx_get_data_addr(no.img, &no.bpp, &no.size_line, &en);
	ea.img_data = (int *)mlx_get_data_addr(ea.img, &ea.bpp, &ea.size_line, &en);
	so.img_data = (int *)mlx_get_data_addr(so.img, &so.bpp, &so.size_line, &en);
	we.img_data = (int *)mlx_get_data_addr(we.img, &we.bpp, &we.size_line, &en);
	tex->no = no;
	tex->so = so;
	tex->ea = ea;
	tex->we = we;
	game->tex = tex;
}

void	game_init(t_game *game)
{
	game->rotate_left = 0;
	game->rotate_right = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
	game->move = 0;
	game->mlx = NULL;
	game->window->img = NULL;
	game->window->window = NULL;
	game->worldMap = NULL;
	game->params->testmap = NULL;
	game->tex = NULL;
	settings_init(&game->params->settings);
	params_init(game->params);
}

void	settings_init(t_settings *settings)
{
	settings->R = 0;
	settings->NO = 0;
	settings->SO = 0;
	settings->WE = 0;
	settings->EA = 0;
	settings->F = 0;
	settings->C = 0;
	settings->player_pos = 0;
}

void	params_init(t_params *params)
{
	params->screenW = 0;
	params->screenH = 0;
	params->map_x_max = 0;
	params->map_y_max = 0;
	params->map_start = 0;
	params->SO_texture = NULL;
	params->NO_texture = NULL;
	params->EA_texture = NULL;
	params->WE_texture = NULL;
	params->first_str = NULL;
	params->line_buff = NULL;
	params->first_error = NONE;
}
