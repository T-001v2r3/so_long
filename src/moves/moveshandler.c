/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveshandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:20:18 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/13 23:28:18 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	input_update_state(struct s_GameState *game_state, int input)
{
	if (input == 'w' || input == 'W')
		pressup(game_state);
	else if (input == 'a' || input == 'A')
		pressleft(game_state);
	else if (input == 's' || input == 'S')
		pressdown(game_state);
	else if (input == 'd' || input == 'D')
		pressright(game_state);
	ft_printf("%d\n", game_state->movements);
	finalizeinput(game_state);
}

int	key_press(int keycode, struct s_GameState *game_state)
{
	if (keycode == ESC)
		deinitialize_library(game_state);
	if (keycode == W || keycode == UP)
		input_update_state(game_state, 'w');
	if (keycode == S || keycode == DOWN)
		input_update_state(game_state, 's');
	if (keycode == A || keycode == LEFT)
		input_update_state(game_state, 'a');
	if (keycode == D || keycode == RIGHT)
		input_update_state(game_state, 'd');
	return (0);
}
