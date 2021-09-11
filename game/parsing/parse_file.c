#include "../headers/cub.h"

int found_all_settings(t_settings settings)
{
    if (settings.R && settings.C && settings.F && settings.EA && settings.WE && settings.NO && settings.SO)
        return (1);
    else
        return (0);
}

void get_buffer_first_str(char *buffer, t_game *game)
{
    int i;
    int j;
    int size;

    i = 0;
    size = 0;
    j = 0;
    while(ft_is_space(buffer[i]))
        i++;
    while((buffer[size + i]) && !ft_is_space(buffer[size + i]))
        size++;
    game->params->first_str = malloc(sizeof(char) * size + 1);
    ft_memset(game->params->first_str , 0, size + 1);
    while (buffer[i +j] && !ft_is_space(buffer[i + j]))
    {
        game->params->first_str[j] = buffer[i + j];
        j++;
    }
    check_param_str(size, game);
}

void    get_settings(t_params *params, t_game *game)
{
    if (ft_strncmp(params->first_str, "R", 1) == 0)
        get_resolution(params, params->line_buff, game);
    if (ft_strncmp(params->first_str, "NO", 2) == 0)
        get_path(params->line_buff , &params->settings.NO, game, NO);
    if (ft_strncmp(params->first_str, "SO", 2) == 0)
        get_path(params->line_buff, &params->settings.SO, game, SO);
    if(ft_strncmp(params->first_str, "EA", 2) == 0)
        get_path(params->line_buff, &params->settings.EA, game, EA);
    if(ft_strncmp(params->first_str, "WE", 2) == 0)
        get_path(params->line_buff, &params->settings.WE, game, WE);
    if (ft_strncmp(params->first_str, "C", 1) == 0)
        fill_rgb(params->line_buff, &params->settings.C, &params->ceil_color, game);
    if (ft_strncmp(params->first_str, "F", 1) == 0)
        fill_rgb(params->line_buff, &params->settings.F, &params->floor_color, game);
}

void parse_file(t_params *params, t_game *game)
{
    int gnlreturn;
    int map_w = 0;

    gnlreturn = 1;
    check_cub(params, game);
    while (gnlreturn == 1)
    {
        gnlreturn = get_next_line(params->fd , &params->line_buff);
        params->map_x_max++;
        map_w = ft_strlen(params->line_buff);
        if (map_w > params->map_y_max)
            params->map_y_max = map_w;
        if(!found_all_settings(params->settings))
        {
            get_buffer_first_str(params->line_buff, game);
            params->map_start++;
            get_settings(params, game);
            free(params->first_str);
            params->first_str = NULL;
        }
        free(params->line_buff);
        params->line_buff = NULL;
    }
    if (!found_all_settings(params->settings))
        ft_exit(MISSING_PARAM, game);
    if (game->params->first_error != NONE)
    {
        printf("1\n");
        ft_exit(game->params->first_error, game);
        printf("2\n");
    }
   close(params->fd);
}
