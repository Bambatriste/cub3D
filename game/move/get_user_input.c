/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:33:19 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/30 17:48:32 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int	key_hook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game->move = 1;
	if (keycode == KEY_W)
		game->move_up = 1;
	if (keycode == KEY_A)
		game->move_left = 1;
	if (keycode == KEY_S)
		game->move_down = 1;
	if (keycode == KEY_D)
		game->move_right = 1;
	if (keycode == KEY_LEFT)
		game->rotate_left = 1;
	if (keycode == KEY_RIGHT)
		game->rotate_right = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->move_up = 0;
	if (keycode == KEY_A)
		game->move_left = 0;
	if (keycode == KEY_S)
		game->move_down = 0;
	if (keycode == KEY_D)
		game->move_right = 0;
	if (keycode == KEY_LEFT)
		game->rotate_left = 0;
	if (keycode == KEY_RIGHT)
		game->rotate_right = 0;
	if (keycode == KEY_ESCAPE)
	{
		ft_free_all(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (1);
}
