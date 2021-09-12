/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:23:02 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:23:07 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

float	ft_abs(float nbr)
{
	if (nbr > -nbr)
		return (nbr);
	else
		return (-nbr);
}

void	rotate_left(t_game *game)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = game->dir.x;
	old_planex = game->plane.x;
	game->dir.x = game->dir.x * cos(R_SPEED) - game->dir.y * sin(R_SPEED);
	game->dir.y = old_dirx * sin(R_SPEED) + game->dir.y * cos(R_SPEED);
	game->plane.x = game->plane.x * cos(R_SPEED) - game->plane.y * sin(R_SPEED);
	game->plane.y = old_planex * sin(R_SPEED) + game->plane.y * cos(R_SPEED);
}

void	rotate_right(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = game->dir.x;
	old_plane_x = game->plane.x;
	game->dir.x = game->dir.x * cos(-R_SPEED) - game->dir.y * sin(-R_SPEED);
	game->dir.y = old_dir_x * sin(-R_SPEED) + game->dir.y * cos(-R_SPEED);
	game->plane.x = game->plane.x
		* cos(-R_SPEED) - game->plane.y * sin(-R_SPEED);
	game->plane.y = old_plane_x * sin(-R_SPEED) + game->plane.y * cos(-R_SPEED);
}
