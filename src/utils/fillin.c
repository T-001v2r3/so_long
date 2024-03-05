/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:41:29 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 18:25:46 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkposition(struct s_GameState *game_state, int i, int j)
{
	if (game_state->maptwo[i][j] == '0' || game_state->maptwo[i][j] == 'C')
	{
		game_state->lastx = i;
		game_state->lasty = j;
	}
	if (game_state->maptwo[i][j] == 'X')
		return (1);
	game_state->maptwo[i][j] = 'X';
	return (0);
}

int	checkplayer(struct s_GameState *game_state, int i, int j)
{
	if (game_state->maptwo[i + 1][j] == 'P')
		return (1);
	else if (game_state->maptwo[i][j + 1] == 'P')
		return (1);
	else if (game_state->maptwo[i][j - 1] == 'P')
		return (1);
	else if (game_state->maptwo[i - 1][j] == 'P')
		return (1);
	else
		return (0);
}

void	checkothers(struct s_GameState *game_state, int i, int j)
{
	if (((game_state->maptwo[i][j + 1] == '0' || game_state->maptwo[i][j + 1]
		== 'C') && checkposition(game_state, i, j + 1) == 0))
		startfill(game_state, i, j + 1);
	if (((game_state->maptwo[i - 1][j] == '0' || game_state->maptwo[i - 1][j]
		== 'C') && checkposition(game_state, i - 1, j) == 0))
		startfill(game_state, i - 1, j);
	if (((game_state->maptwo[i + 1][j] == '0' || game_state->maptwo[i + 1][j]
		== 'C') && checkposition(game_state, i + 1, j) == 0))
		startfill(game_state, i + 1, j);
	if (((game_state->maptwo[i][j - 1] == '0' || game_state->maptwo[i][j - 1]
		== 'C') && checkposition(game_state, i, j - 1) == 0))
		startfill(game_state, i, j - 1);
}

int	startfill(struct s_GameState *game_state, int i, int j)
{	
	while (i < game_state->rows)
	{
		while (j < game_state->cols)
		{
			if (checkplayer(game_state, i, j) == 1)
			{
				game_state->valid = 1;
				return (1);
			}
			else
				checkothers(game_state, i, j);
			j++;
			return (0);
		}
		i++;
	}
	return (0);
}

int	checkexit(struct s_GameState *game_state)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_state->rows)
	{
		j = 0;
		while (j++ < game_state->cols)
			if (game_state->maptwo[i][j] == 'E')
				return (startfill(game_state, i, j));
		i++;
	}
	return (0);
}
