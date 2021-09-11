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

void find_pixel_line(t_game *game, t_ray *ray, t_window *window)
{

	if(ray->perp_wdist == 0)
		ray->line_h = game->params->screenW;
	else
    	ray->line_h = game->params->screenH/ ray->perp_wdist;

	//printf("ray->line_h : %f", ray->line_h);

	window->draw_start = game->params->screenH/2 -ray->line_h / 2;
	if(window->draw_start < 0)
		window->draw_start = 0;
	window->draw_end = ray->line_h / 2 + game->params->screenH / 2;
	if(window->draw_end >= game->params->screenH)
		window->draw_end = game->params->screenH - 1;
}

void update_window(t_game *game, t_window *window)
{
	t_ray ray;
	game->ray = &ray;
	window->x = 0;
	while (window->x <  game->params->screenW)
	{
		game->map_x = (int)game->pos_x;
		game->map_y = (int)game->pos_y;
        ray.camera_x = (2 * (float)window->x / (float)game->params->screenW) - 1.0;
		raycast(&ray, game);
        find_pixel_line(game, &ray , window);
		draw_vertical_line_img(game, &ray, window, game->params);
		window->x++;
	}
    mlx_put_image_to_window(game->mlx, window->window, (void *)window->img, 0, 0);
}