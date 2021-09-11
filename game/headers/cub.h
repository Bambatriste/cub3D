/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <aedouard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:29:21 by aedouard          #+#    #+#             */
/*   Updated: 2020/07/30 16:27:41 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "mlx.h"
# include <X11/Xlib.h>
# include "keys_linux.h"
# include "../../libs/libft/libft.h"
# include <fcntl.h>
# define P_SPEED 0.0777777
# define R_SPEED M_PI_2/30

typedef enum e_error_type
{
	NONE,
	MULTIPLE_RES,
	MULTI_TEX,
	MULTI_SPR,
	MULTI_CEIL,
	NOT_CLOSED,
	MISSING_PARAM,
	MULTI_PLAYER_POS,
	WRONG_ARG_RGB,
	INVALID_MAPS_CHARS,
	INVALID_PARAM,
	WRONG_RES_SETTINGS,
	WRONG_RES_VALUES,
	WRONG_PATH,
	WRONG_COLOR,
	WRONG_TEX_PATH,
	WRONG_TEX_PATH_FORMAT,
	WRONG_RGB_VALUE,
	WRONG_MAP_FORMAT,
	CANT_OPEN_MAP_FILE,
	INCORRECT_ARG_NB
}	t_error_type;

typedef enum e_tex_name
{
	EA,
	WE,
	NO,
	SO
}	t_tex_name;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_ray
{
	float	x;
	float	y;
	float	camera_x;
	float	delta_distx;
	float	delta_disty;
	float	side_distx;
	float	side_disty;
	float	perp_wdist;
	float	line_h;
	float	w_dist_x;
	int		side;
	int		step_x;
	int		step_y;
	int		tex_dir;
}	t_ray;

typedef struct s_settings
{
	int	R;
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	F;
	int	C;
	int	player_pos;

}	t_settings;

typedef struct s_params
{
	t_settings	settings;
	char	*map_path;
	int	screenW;
	int	screenH;
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*S_path;
	int	floor_color;
	int	ceil_color;
	int	map_x_max;
	int	map_y_max;
	int	map_start;
	int	fd;
	char	**testmap;
	char	*first_str;
	char	*line_buff;
	int	first_error;

}	t_params;

typedef struct s_texture
{
	void	*img;
	int	h;
	int	w;
	int	*img_data;
	int	bpp;
	int	size_line;
	int	x;
	float	y;
	float	step;
	int	pos;

}	t_texture;

typedef struct s_textures
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
}	t_textures;

typedef struct s_window
{
	void	*img;
	int	*img_data;
	void	*window;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	int	draw_start;
	int	draw_end;
	int	x;
	int	y;
}	t_window;

typedef struct s_game
{
	int		move;
	char		color;
	void		*mlx;
	int		map_x;
	int		map_y;
	float		pos_x;
	float		pos_y;
	char		**worldMap;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
	t_vector	dir;
	/* orientation du joueur vers le plan (ex : -1;0) ici regarde a gauche*/
	t_vector	plane;
	/* vecteur du plan (toujours a 90degres avec dir) (ex : 0;0.66) perpendiculaire lorsque le produit scalaire des deux vecteurs == 0 : ici (0 * -1) + ( 0 * 0.66) == 0*/
	t_params	*params;
	t_window	*window;
	t_ray		*ray;
	t_textures	*tex;
}	t_game;

void	ft_save_error(t_params *params, int errtype);
void	game_init(t_game *game);
void	window_init(t_game *game,t_window *window ,t_params *params);
void	init_textures(t_game *game, t_textures *tex, t_params *params);
void	params_init(t_params *params);
void	settings_init(t_settings *settings);
void	raycast(t_ray *ray, t_game *game);
void	draw_vertical_line_img (t_game *game, t_ray *ray, t_window *window, t_params *params);
void	vector_init(t_vector *vector);
int	key_hook (int keycode, void *param);
void	debug();
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	parse_map(t_game *game, t_params *params);
void	copy_map(t_game *game, t_params *params);
void	fill_map(int x,  int y, char **map, t_game *game);
void	parse_file(t_params *params, t_game * game);
void	get_buffer_first_str(char *buffer, t_game *game);
void	get_settings(t_params *params ,t_game *game);
int	found_all_settings(t_settings settings);
void	get_resolution(t_params *params , char *buffer, t_game *game);
void	get_path(char *buffer, int *is_set, t_game *game, int name);
void	fill_rgb(char *buffer, int *is_set, int *color, t_game *game);
void	print_error(int errortype);
void	ft_exit(int errtype, t_game *game);
void	check_cub(t_params *params, t_game *game);
void	check_xpm(char *path, t_game *game);
void	check_colors(int rgb[3], t_game *game);
void	check_param_str(int size, t_game *game);
void	check_map_buff(char *buffer, t_game *game);
void	update_window(t_game *game, t_window *window);
void	set_pos_v(t_vector *vector, float x, float y);
int	key_release (int keycode, void *param);
int	rgb_to_int(int r, int g, int b);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	ft_free_all(t_game *game);
int	close_game(void *param);

#endif
