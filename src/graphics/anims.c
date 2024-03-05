/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anims.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:14:57 by gperfeit          #+#    #+#             */
/*   Updated: 2024/03/05 18:34:27 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	image_selector_player(int i, int j, struct s_GameState *game_state)
{
	game_state->playerimg++;
	if (game_state->playerimg > 3)
		game_state->playerimg = 0;
	if (game_state->playerimg == 0)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->cat_0, j * 100, i * 100);
	else if (game_state->playerimg == 1)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->cat_1, j * 100, i * 100);
	else if (game_state->playerimg == 2)
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->cat_2, j * 100, i * 100);
	else
		mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
			game_state->cat_3, j * 100, i * 100);
	return (0);
}

int	getimg(struct s_GameState *game_state)
{
	game_state->monsterimg++;
	if (game_state->monsterimg > 3)
		game_state->monsterimg = 0;
	return (0);
}

int	randomizer(struct s_GameState *game_state)
{
	int	r;
	int	o;

	r = rand();
	o = r % 10;
	if (o == 1 || o == 2)
		game_state->enemystatus = 1;
	if (o == 3 || o == 4)
		game_state->enemystatus = 2;
	if (o == 6 || o == 7)
		game_state->enemystatus = 3;
	if (o == 9 || o == 0)
		game_state->enemystatus = 4;
	return (0);
}

void	freemapstuff(struct s_GameState *game_state)
{
	free_map_memory(game_state);
	freemap2(game_state);
	exit(0);
}

int	textcreator(struct s_GameState *game_state)
{
	char	*moves;

	moves = ft_itoa(game_state->movements);
	mlx_string_put(game_state->mlx, game_state->mlx_win, 10,
		((game_state->rows * 100) + 25), 0x00FFFFFF, "MOVEMENTS: ");
	mlx_string_put(game_state->mlx, game_state->mlx_win, 150,
		((game_state->rows * 100) + 25), 0x00FFFFFF, moves);
	free(moves);
	return (0);
}
