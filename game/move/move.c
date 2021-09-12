/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 22:17:23 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/30 18:29:20 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	move_up(t_game *game)
{
	if (game->map[(int)(game->pos_x + game->dir.x
			* P_SPEED)][(int)(game->pos_y)] == '0')
		game->pos_x += game->dir.x * P_SPEED;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y + game->dir.y
			* P_SPEED)] == '0')
		game->pos_y += game->dir.y * P_SPEED ;
}

void	move_down(t_game *game)
{
	if (game->map[(int)(game->pos_x - game->dir.x
			* P_SPEED)][(int)(game->pos_y)] == '0')
		game->pos_x -= game->dir.x * P_SPEED;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y - game->dir.y
			*P_SPEED)] == '0')
		game->pos_y -= game->dir.y * P_SPEED;
}

void	move_left(t_game *game)
{
	if (game->map[(int)(game->pos_x - game->plane.x
			* P_SPEED)][(int)(game->pos_y)] == '0')
		game->pos_x -= game->plane.x * P_SPEED;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y - game->plane.y
			* P_SPEED)] == '0')
		game->pos_y -= game->plane.y * P_SPEED;
}

void	move_right(t_game *game)
{
	if (game->map[(int)(game->pos_x + game->plane.x
			* P_SPEED)][(int)(game->pos_y)] == '0')
		game->pos_x += game->plane.x * P_SPEED;
	if (game->map[(int)(game->pos_x)][(int)(game->pos_y + game->plane.y
			* P_SPEED)] == '0')
		game->pos_y += game->plane.y * P_SPEED;
}
