/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:29:20 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/22 23:15:28 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	initialize_game_data(struct s_GameState *game_state)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_state->rows)
	{
		j = 0;
		while (j < game_state->cols)
		{
			if (game_state->map[i][j] == 'P')
			{
				game_state->player_x = j;
				game_state->player_y = i;
				game_state->pcount = game_state->pcount + 1;
			}
			if (game_state->map[i][j] == 'C')
				game_state->total_collectibles++;
			j++;
		}
		i++;
	}
	return (0);
}

char	**read_map_file(const char *file_path, struct s_GameState *game_state)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nUnable to open the map file\n");
		return (NULL);
	}
	game_state->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game_state->map = realloc(game_state->map, sizeof(char *)
				* (game_state->rows + 1));
		game_state->cols = ft_strlen(line);
		game_state->map[game_state->rows] = malloc(game_state->cols + 1);
		ft_strcpy(game_state->map[game_state->rows], line);
		game_state->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (game_state->map);
}

void	triplecheck(struct s_GameState *game_state)
{
	int	i;

	i = 0;
	while (i < game_state->rows)
	{
		if (game_state->map[i][0] != '1')
		{
			ft_printf("Error\nMap is not closed1\n");
			freemapstuff(game_state);
		}
		if (game_state->map[i][game_state->cols - 1] != '1')
		{
			ft_printf("Error\nMap is not closed2\n");
			freemapstuff(game_state);
		}
		i++;
	}
	continuecheck(game_state);
}

void	continuecheck(struct s_GameState *game_state)
{
	int	i;

	i = 0;
	while (i < game_state->cols)
	{
		if (game_state->map[0][i] != '1')
		{
			ft_printf("Error\nMap is not closed\n");
			freemapstuff(game_state);
		}
		if (game_state->map[game_state->rows - 1][i] != '1')
		{
			ft_printf("Error\nMap is not closed\n");
			freemapstuff(game_state);
		}
		i++;
	}
	lencheck(game_state);
}

void	lencheck(struct s_GameState *game_state)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_state->rows)
	{
		j = 0;
		while (j < game_state->cols)
		{
			if (game_state->map[i][j] != '1' && game_state->map[i][j] != '0'
				&& game_state->map[i][j] != 'C' && game_state->map[i][j] != 'E'
					&& game_state->map[i][j] != 'P' &&
						game_state->map[i][j] != 'D')
			{
				ft_printf("Error\nWrong map obj\n");
				freemapstuff(game_state);
			}
			j++;
		}
		i++;
	}
}
