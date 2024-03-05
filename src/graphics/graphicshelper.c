/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphicshelper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:20:37 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/25 19:00:02 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deinitialize_library(struct s_GameState *game_state)
{
	mlx_destroy_image(game_state->mlx, game_state->player1img);
	mlx_destroy_image(game_state->mlx, game_state->wallimg);
	mlx_destroy_image(game_state->mlx, game_state->coin1img);
	mlx_destroy_image(game_state->mlx, game_state->exitimg);
	mlx_destroy_image(game_state->mlx, game_state->monster_0);
	mlx_destroy_image(game_state->mlx, game_state->monster_1);
	mlx_destroy_image(game_state->mlx, game_state->monster_2);
	mlx_destroy_image(game_state->mlx, game_state->monster_3);
	mlx_destroy_image(game_state->mlx, game_state->cat_0);
	mlx_destroy_image(game_state->mlx, game_state->cat_1);
	mlx_destroy_image(game_state->mlx, game_state->cat_2);
	mlx_destroy_image(game_state->mlx, game_state->cat_3);
	mlx_destroy_window(game_state->mlx, game_state->mlx_win);
	mlx_destroy_display(game_state->mlx);
	free(game_state->mlx);
	freemapstuff(game_state);
	return (0);
}

int	load_game_images(struct s_GameState *game_state)
{
	int	size;

	size = 100;
	game_state->player1img = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/player.xpm", &size, &size);
	game_state->wallimg = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_1.xpm", &size, &size);
	game_state->coin1img = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_C.xpm", &size, &size);
	game_state->exitimg = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_E.xpm", &size, &size);
	load_game_images_second(game_state);
	return (0);
}

int	load_game_images_second(struct s_GameState *game_state)
{
	int	size;

	size = 100;
	game_state->monster_0 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/monster_0.xpm", &size, &size);
	game_state->monster_1 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/monster_1.xpm", &size, &size);
	game_state->monster_2 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/monster_2.xpm", &size, &size);
	game_state->monster_3 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/monster_3.xpm", &size, &size);
	game_state->cat_0 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/cat_0.xpm", &size, &size);
	game_state->cat_1 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/cat_1.xpm", &size, &size);
	game_state->cat_2 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/cat_2.xpm", &size, &size);
	game_state->cat_3 = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/cat_3.xpm", &size, &size);
	return (0);
}

void	initgamestate(struct s_GameState *game_state)
{
	game_state->mlx = NULL;
	game_state->mlx_win = NULL;
	game_state->col_col = 0;
	game_state->total_collectibles = 0;
	game_state->movements = 0;
	game_state->player_x = -1;
	game_state->player_y = -1;
	game_state->game_is_running = 0;
	game_state->map = NULL;
	game_state->rows = 0;
	game_state->cols = 0;
	game_state->player1img = NULL;
	game_state->wallimg = NULL;
	game_state->coin1img = NULL;
	game_state->exitimg = NULL;
	initgamestatedois(game_state);
}

void	initgamestatedois(struct s_GameState *game_state)
{
	game_state->monster_0 = NULL;
	game_state->monster_1 = NULL;
	game_state->monster_2 = NULL;
	game_state->monster_3 = NULL;
	game_state->cat_0 = NULL;
	game_state->cat_1 = NULL;
	game_state->cat_2 = NULL;
	game_state->cat_3 = NULL;
	game_state->maptwo = NULL;
	game_state->lastmappos = NULL;
	game_state->lastx = 0;
	game_state->lasty = 0;
	game_state->valid = 0;
	game_state->pcount = 0;
	game_state->monsterimg = 0;
	game_state->playerimg = 0;
	game_state->total_enemies = 0;
	game_state->bufferingz = 0;
	game_state->enemystatus = 0;
}
