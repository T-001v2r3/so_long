/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anims2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:14:57 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 18:41:10 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkplayerpos(int i, int j, struct s_GameState *game_state)
{
	if (j == game_state->player_x && i == game_state->player_y)
	{	
		printf("You've been caught by the enemy! Game over.\n");
		deinitialize_library(game_state);
		game_state->game_is_running = 0;
	}
	return (0);
}	

int	getcoords(int i, int j, struct s_GameState *game_state)
{
	checkplayerpos(i, j, game_state);
	randomizer(game_state);
	if (game_state->bufferingz < 10)
		game_state->bufferingz = game_state->bufferingz + 1;
	else
	{
		game_state->bufferingz = 0;
		partedois(i, j, game_state);
		checkplayerpos(i, j, game_state);
	}
	return (0);
}

void	partedois(int i, int j, struct s_GameState *game_state)
{
	if (game_state->map[i + 1][j] == '0' && game_state->enemystatus != 4)
	{
		game_state->enemystatus = 3;
		game_state->map[i + 1][j] = 'D';
		game_state->map[i][j] = '0';
	}
	else if (game_state->map[i - 1][j] == '0' && game_state->enemystatus != 2)
	{
		game_state->enemystatus = 4;
		game_state->map[i - 1][j] = 'D';
		game_state->map[i][j] = '0';
	}
	else if (game_state->map[i][j - 1] == '0' && game_state->enemystatus != 1)
	{
		game_state->enemystatus = 1;
		game_state->map[i][j - 1] = 'D';
		game_state->map[i][j] = '0';
	}
	else if (game_state->map[i][j + 1] == '0' && game_state->enemystatus != 3)
	{
		game_state->enemystatus = 2;
		game_state->map[i][j + 1] = 'D';
		game_state->map[i][j] = '0';
	}
}

int	image_selector_enemy(int i, int j, struct s_GameState *game_state)
{
	getcoords(i, j, game_state);
	getimg(game_state);
	if (game_state->monsterimg == 0)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->monster_0, j * 100, i * 100);
	else if (game_state->monsterimg == 1)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->monster_1, j * 100, i * 100);
	else if (game_state->monsterimg == 2)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->monster_2, j * 100, i * 100);
	else
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->monster_3, j * 100, i * 100);
	return (0);
}

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
