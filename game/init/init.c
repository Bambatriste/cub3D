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
	window->size_line = params->screen_w;
	window->endian = 0;
	window->img = mlx_new_image(game->mlx, params->screen_w, params->screen_h);
	window->img_data = (int *)mlx_get_data_addr(window->img,
			&window->bits_per_pixel, &window->size_line, &window->endian);
	window->window = mlx_new_window(game->mlx,
			params->screen_w, params->screen_h, "cub3D");
}

void	init_textures(t_game *game, t_textures *tex, t_params *params, int en)
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_imgs		imgs;

	no.img = mlx_xpm_file_to_image(game->mlx, params->no_texture, &no.w, &no.h);
	so.img = mlx_xpm_file_to_image(game->mlx, params->so_texture, &so.w, &so.h);
	ea.img = mlx_xpm_file_to_image(game->mlx, params->ea_texture, &ea.w, &ea.h);
	we.img = mlx_xpm_file_to_image(game->mlx, params->we_texture, &we.w, &we.h);
	imgs.ea = ea.img;
	imgs.we = we.img;
	imgs.so = so.img;
	imgs.no = no.img;
	if (no.img == NULL || so.img == NULL || ea.img == NULL || we.img == NULL)
		destroy_imgs(&imgs, game);
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
	game->en = 0;
	game->window->img = NULL;
	game->window->window = NULL;
	game->map = NULL;
	game->params->testmap = NULL;
	game->tex = NULL;
	settings_init(&game->params->settings);
	params_init(game->params);
	mlx_get_screen_size(game->mlx, &game->params->max_w, &game->params->max_h);
}

void	settings_init(t_settings *settings)
{
	settings->r = 0;
	settings->no = 0;
	settings->so = 0;
	settings->we = 0;
	settings->ea = 0;
	settings->f = 0;
	settings->c = 0;
	settings->player_pos = 0;
}

void	params_init(t_params *params)
{
	params->screen_w = 0;
	params->screen_h = 0;
	params->map_x_max = 0;
	params->map_y_max = 0;
	params->map_start = 0;
	params->so_texture = NULL;
	params->no_texture = NULL;
	params->ea_texture = NULL;
	params->we_texture = NULL;
	params->first_str = NULL;
	params->line_buff = NULL;
	params->first_error = NONE;
}
