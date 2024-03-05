/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:20:13 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/22 23:15:01 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pressup(struct s_GameState *game_state)
{
	if (game_state->map[game_state->player_y - 1][game_state->player_x] != '1')
	{
		game_state->player_y--;
		game_state->movements++;
	}
}

void	pressleft(struct s_GameState *game_state)
{
	if (game_state->map[game_state->player_y][game_state->player_x - 1] != '1')
	{
		game_state->player_x--;
		game_state->movements++;
	}
}

void	pressdown(struct s_GameState *game_state)
{
	if (game_state->map[game_state->player_y + 1][game_state->player_x] != '1')
	{
		game_state->player_y++;
		game_state->movements++;
	}
}

void	pressright(struct s_GameState *game_state)
{
	if (game_state->map[game_state->player_y][game_state->player_x + 1] != '1')
	{
		game_state->player_x++;
		game_state->movements++;
	}
}

void	finalizeinput(struct s_GameState *game_state)
{
	if (game_state->map[game_state->player_y][game_state->player_x] == 'C')
	{
		ft_printf("Collectible found!\n");
		game_state->col_col++;
		game_state->map[game_state->player_y][game_state->player_x] = '0';
	}
	else if (game_state->map[game_state->player_y][game_state->player_x] == 'E')
	{
		if (game_state->col_col == game_state->total_collectibles)
		{
			ft_printf("Exited in %d movements.\n", game_state->movements);
			game_state->game_is_running = 0;
			deinitialize_library(game_state);
		}
		else
			ft_printf("Error\nGet all collectibles!\n");
	}
	else if (game_state->map[game_state->player_y][game_state->player_x] == 'D')
	{
		printf("You've been caught by the enemy! Game over.\n");
		deinitialize_library(game_state);
		game_state->game_is_running = 0;
	}
}
