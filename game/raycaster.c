/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:51:13 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/30 18:17:44 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub.h"

/* DDA : on avance le rayon 1 carre a la fois jusqu a hit */
void	find_side(t_ray *ray, t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			game->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			game->map_y += ray->step_y;
			ray->side = 1;
		}	
		if (game->map[game->map_x][game->map_y] != '0')
		{
			hit = 1;
			game->color = game->map[game->map_x][game->map_y];
		}
	}
}

void	find_side_distances(t_ray *ray, t_game *game)
{
	if (ray->x < 0)
	{
		ray->side_distx = (game->pos_x - (float)game->map_x)
			* ray->delta_distx;
		ray->step_x = -1;
	}
	else
	{
		ray->side_distx = ((float)game->map_x + 1.0 - game->pos_x)
			* ray->delta_distx;
		ray->step_x = 1;
	}
	if (ray->y < 0)
	{
		ray->side_disty = (game->pos_y - (float)game->map_y) * ray->delta_disty;
		ray->step_y = -1;
	}
	else
	{
		ray->side_disty = ((float)game->map_y + 1 - game->pos_y)
			* ray->delta_disty;
		ray->step_y = 1;
	}
}

void	find_perp_w_dist(t_ray *ray, t_game *game)
{
	float	step_dist_x;
	float	step_dist_y;

	step_dist_x = (game->map_x - game->pos_x + (1 - ray->step_x) / 2 );
	step_dist_y = (game->map_y - game->pos_y + (1 - ray->step_y) / 2 );
	if (ray->side == 0)
		ray->perp_wdist = step_dist_x / ray->x;
	else
		ray->perp_wdist = step_dist_y / ray->y;
}

void	find_ray_wdist(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
	{
		ray->w_dist_x = game->pos_y + ray->perp_wdist * ray->y;
		ray->w_dist_x -= (floor)(ray->w_dist_x);
	}
	if (ray->side == 1)
	{
		ray->w_dist_x = game->pos_x + ray->perp_wdist * ray->x;
		ray->w_dist_x -= (floor)(ray->w_dist_x);
	}
}

void	raycast(t_ray *ray, t_game *game)
{
	ray->x = game->dir.x + (game->plane.x * ray->camera_x);
	ray->y = game->dir.y + (game->plane.y * ray->camera_x);
	if (ray->y == 0)
		ray->delta_distx = 0;
	else if (ray->x == 0)
		ray->delta_distx = 1;
	else
		ray->delta_distx = sqrt(1 + (ray->y * ray->y) / (ray->x * ray->x));
	if (ray->x == 0)
		ray->delta_disty = 0;
	else if (ray->y == 0)
		ray->delta_disty = 1;
	else
		ray->delta_disty = sqrt(1 + (ray->x * ray->x) / (ray->y * ray->y));
	find_side_distances(ray, game);
	find_side(ray, game);
	find_perp_w_dist(ray, game);
	find_ray_wdist(ray, game);
}
