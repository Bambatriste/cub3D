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

float ft_abs(float nbr)
{
   if (nbr > -nbr)
    return (nbr);
  else
    return (-nbr);
}
void	move_up(t_game *game)
{
    if(game->worldMap[(int)(game->pos_x + game->dir.x * P_SPEED)][(int)(game->pos_y)] == '0')
      game->pos_x += game->dir.x * P_SPEED;
    if(game->worldMap[(int)(game->pos_x)][(int)(game->pos_y + game->dir.y * P_SPEED)] == '0')
      game->pos_y += game->dir.y *P_SPEED ;
}

void	move_down(t_game *game)
{
    if(game->worldMap[(int)(game->pos_x - game->dir.x *P_SPEED)][(int)(game->pos_y)] == '0')
        game->pos_x -= game->dir.x * P_SPEED;
    if(game->worldMap[(int)(game->pos_x)][(int)(game->pos_y - game->dir.y *P_SPEED)] == '0')
        game->pos_y -= game->dir.y * P_SPEED;
}

void	move_left(t_game *game)
{

  if(game->worldMap[(int)(game->pos_x -  game->plane.x * P_SPEED)][(int)(game->pos_y)] == '0')
    game->pos_x -= game->plane.x * P_SPEED;
  if(game->worldMap[(int)(game->pos_x)][(int)(game->pos_y - game->plane.y * P_SPEED)] == '0')
    game->pos_y -= game->plane.y * P_SPEED;
}

void	move_right(t_game *game)
{
 
  
  if(game->worldMap[(int)(game->pos_x +  game->plane.x *P_SPEED)][(int)(game->pos_y)] == '0')
    game->pos_x += game->plane.x * P_SPEED;
  if(game->worldMap[(int)(game->pos_x)][(int)(game->pos_y + game->plane.y * P_SPEED)] == '0')
    game->pos_y += game->plane.y * P_SPEED;
}

void	rotate_left(t_game *game)
{
      float old_dirx = game->dir.x;
      float old_planex = game->plane.x;

      game->dir.x = game->dir.x * cos(R_SPEED)- game->dir.y * sin(R_SPEED);
      game->dir.y = old_dirx * sin(R_SPEED)+ game->dir.y * cos(R_SPEED);
      game->plane.x = game->plane.x * cos(R_SPEED) - game->plane.y * sin(R_SPEED);
      game->plane.y = old_planex * sin(R_SPEED) + game->plane.y * cos(R_SPEED);
}

void	rotate_right(t_game *game)
{
      float old_dir_x = game->dir.x;
      float old_plane_x = game->plane.x;

      game->dir.x = game->dir.x * cos(-R_SPEED) - game->dir.y * sin(-R_SPEED);
      game->dir.y = old_dir_x * sin(-R_SPEED)+ game->dir.y * cos(-R_SPEED);
      game->plane.x = game->plane.x * cos(-R_SPEED)- game->plane.y * sin(-R_SPEED);
      game->plane.y = old_plane_x* sin(-R_SPEED)+ game->plane.y * cos(-R_SPEED);
}
