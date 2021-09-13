/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:24:02 by aedouard          #+#    #+#             */
/*   Updated: 2021/09/12 18:24:05 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	ft_exit(int errtype, t_game *game)
{
	print_error(errtype);
	if (errtype != INCORRECT_ARG_NB)
		ft_free_all(game);
	exit(EXIT_FAILURE);
}

void	print_error2(int errortype)
{
	if (errortype == INVALID_PARAM)
		ft_putstr_fd("Error : invalid parameter name or missing parameter\n", 2);
	else if (errortype == WRONG_RES_SETTINGS)
		ft_putstr_fd("Error : wrong number of settings for resolution\n", 2);
	else if (errortype == WRONG_RES_VALUES)
		ft_putstr_fd("Error : invalid resolution settings\n", 2);
	else if (errortype == WRONG_PATH)
		ft_putstr_fd("Error : incorrect path settings\n", 2);
	else if (errortype == WRONG_COLOR)
		ft_putstr_fd("Error : invalid color settings\n", 2);
	else if (errortype == WRONG_TEX_PATH)
		ft_putstr_fd("Error : invalid texture path\n", 2);
	else if (errortype == WRONG_TEX_PATH_FORMAT)
		ft_putstr_fd("Error : texture path is not a .xpm format\n", 2);
	else if (errortype == WRONG_RGB_VALUE)
		ft_putstr_fd("Error : RBG value is negative or over 255\n", 2);
	else if (errortype == WRONG_MAP_FORMAT)
		ft_putstr_fd("Error : incorrect map format (must end with .cub)\n", 2);
	else if (errortype == CANT_OPEN_MAP_FILE)
		ft_putstr_fd("Error : can t open map File\n", 2);
	else if (errortype == INCORRECT_ARG_NB)
		ft_putstr_fd("Error : incorrect number of arguments for ./cub3D\n", 2);
	else if (errortype == CORRUPTED_TEX)
		ft_putstr_fd("Error : one or several corrupted texture.xpm file\n", 2);
}

void	print_error(int errortype)
{
	if (errortype == MULTIPLE_RES)
		ft_putstr_fd("Error : multiple entries for resolution\n", 2);
	else if (errortype == MULTI_TEX)
		ft_putstr_fd("Error : multiple entries for same texture \n", 2);
	else if (errortype == MULTI_SPR)
		ft_putstr_fd("Error : multiple entries for sprite\n", 2);
	else if (errortype == MULTI_CEIL)
		ft_putstr_fd("Error : multiple entries for ceil color\n", 2);
	else if (errortype == NOT_CLOSED)
		ft_putstr_fd("Error : map is not closed\n", 2);
	else if (errortype == MISSING_PARAM)
		ft_putstr_fd("Error : missing one or several parameters\n", 2);
	else if (errortype == MULTI_PLAYER_POS)
		ft_putstr_fd("Error : multiple player starting positions\n", 2);
	else if (errortype == WRONG_ARG_RGB)
		ft_putstr_fd("Error : wrong number of arguments for RGB\n", 2);
	else if (errortype == INVALID_MAPS_CHARS)
		ft_putstr_fd("Error : invalid characters in map\n", 2);
	else if (errortype == FAIL_MALLOC)
		ft_putstr_fd("Error : memory allocation problem\n", 2);
	print_error2(errortype);
}
