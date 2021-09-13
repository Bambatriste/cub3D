/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 14:17:27 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/30 17:35:21 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub.h"

int	main_loop(t_game *game)
{
	if (game->move_down == 1)
		move_down(game);
	if (game->move_up == 1)
		move_up(game);
	if (game->move_left == 1)
		move_left(game);
	if (game->move_right == 1)
		move_right(game);
	if (game->rotate_left == 1)
		rotate_left(game);
	if (game->rotate_right == 1)
		rotate_right(game);
	if (game->move == 1)
		update_window(game, game->window);
	return (1);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_window	window;
	t_params	params;
	t_textures	tex;

	if (ac != 2)
		ft_exit(INCORRECT_ARG_NB, &game);
	game.mlx = mlx_init();
	game.params = &params;
	game.window = &window;
	params.map_path = av[1];
	game_init(&game);
	parse_file(&params, &game);
	parse_map(&game, &params);
	copy_map(&game, &params);
	fill_map(game.pos_x, game.pos_y, params.testmap, &game);
	init_textures(&game, &tex, &params, 0);
	window_init(&game, &window, &params);
	update_window(&game, &window);
	mlx_hook(window.window, KeyPress, KeyPressMask, &key_hook, &game);
	mlx_hook(window.window, KeyRelease, KeyReleaseMask, &key_release, &game);
	mlx_hook(window.window, DestroyNotify, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (1);
}
