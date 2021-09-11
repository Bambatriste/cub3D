#include "./headers/cub.h"

void	set_pos_v(t_vector *vector, float x, float y)
{
	vector->x = x;
	vector->y = y;
}

int	rgb_to_int(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
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
	free(game->params->NO_texture);
	free(game->params->SO_texture);
	free(game->params->WE_texture);
	free(game->params->EA_texture);
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
	if (game->worldMap != NULL)
	{
		while (i < game->params->map_x_max)
		{
			free(game->worldMap[i]);
			free(game->params->testmap[i]);
			i++;
		}
		free(game->worldMap);
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
