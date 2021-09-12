/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:34:00 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/07 22:37:50 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	init_tex(t_ray *ray, t_texture *tex, t_params *params, t_window *window)
{
	tex->x = (int)(ray->w_dist_x * (float)tex->h);
	if (ray->side == 0 && ray->x > 0)
		tex->x = tex->w - tex->x - 1;
	if (ray->side == 1 && ray->y < 0)
		tex->x = tex->w - tex->x - 1;
	tex->pos = 0;
	tex->step = (float)tex->h / ray->line_h;
	tex->y = (window->draw_start + 1 - params->screen_h / 2 + ray->line_h / 2)
		* tex->step;
}

void	get_tex(t_textures *textures, t_ray *ray, t_texture *tex)
{
	if (ray->x < 0)
	{
		if (ray->side == 0)
			*tex = textures->no;
		else if (ray->y < 0)
			*tex = textures->we;
		else
			*tex = textures->ea;
	}
	else
	{
		if (ray->side == 0)
			*tex = textures->so;
		else if (ray->y > 0)
			*tex = textures->ea;
		else
			*tex = textures->we;
	}
}

void	set_img_pixels(t_params *params, t_ray *ray,
		t_window *window, t_texture *tex)
{
	int	pos;

	pos = window->x + window->y * params->screen_w;
	if (window->y < window->draw_start)
		window->img_data[pos] = params->ceil_color;
	else if (window->y < window->draw_end)
	{
		tex->pos = tex->x + (int)tex->y * tex->w;
		window->img_data[pos] = tex->img_data[tex->pos];
		tex->y += tex->step;
		if (ray->side == 1)
			window->img_data[pos] = window->img_data[pos] / 2;
	}
	else if (window->y > window->draw_end)
		window->img_data[pos] = params->floor_color;
}

void	draw_vertical_line_img(t_game *game, t_ray *ray,
		t_window *window, t_params *params)
{
	t_texture	tex;

	get_tex(game->tex, ray, &tex);
	init_tex(ray, &tex, params, window);
	window->y = 0;
	while (window->y < params->screen_h)
	{
		set_img_pixels(params, ray, window, &tex);
		window->y++;
	}
}
