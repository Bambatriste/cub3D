/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:22:14 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:22:22 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub.h"

void	set_pos_v(t_vector *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}

void	destroy_imgs(t_imgs *img, t_game *game)
{
	if (img->no != NULL)
		mlx_destroy_image(game->mlx, img->no);
	if (img->so != NULL)
		mlx_destroy_image(game->mlx, img->so);
	if (img->ea != NULL)
		mlx_destroy_image(game->mlx, img->ea);
	if (img->we != NULL)
		mlx_destroy_image(game->mlx, img->we);
	ft_exit(CORRUPTED_TEX, game);
}

void	ft_free_mlx(t_game *game)
{
	if (game->tex != NULL)
	{
		mlx_destroy_image(game->mlx, game->tex->no.img);
		mlx_destroy_image(game->mlx, game->tex->so.img);
		mlx_destroy_image(game->mlx, game->tex->ea.img);
		mlx_destroy_image(game->mlx, game->tex->we.img);
	}
	free(game->params->no_texture);
	free(game->params->so_texture);
	free(game->params->we_texture);
	free(game->params->ea_texture);
	if (game->window->img != NULL)
		mlx_destroy_image(game->mlx, game->window->img);
	if (game->window->window != NULL)
		mlx_destroy_window(game->mlx, game->window->window);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	free(game->params->first_str);
	free(game->params->line_buff);
	if (game->map != NULL)
	{
		while (i < game->params->map_x_max)
		{
			free(game->map[i]);
			free(game->params->testmap[i]);
			i++;
		}
		free(game->map);
		free(game->params->testmap);
	}
	ft_free_mlx(game);
}

void	ft_save_error(t_params *params, int errtype)
{
	if (params->first_error == NONE)
	{
		params->first_error = errtype;
	}
}
