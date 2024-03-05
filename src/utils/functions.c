/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:07:17 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/13 22:04:33 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	linelencheck(struct s_GameState *game_state)
{
	int	i;
	int	j;
	int	oldi;

	oldi = -1;
	i = 0;
	while (i < game_state->rows)
	{
		j = 0;
		while (game_state->map[i][j] != '\0')
		{
			j++;
		}
		if (oldi == -1)
			oldi = j;
		if (i == (game_state->rows -1))
			j++;
		if (j != oldi)
		{
			ft_printf("Error\nMap is not rectangular\n");
			freemapstuff(game_state);
		}
		i++;
	}
	triplecheck(game_state);
}

void	map_validator(struct s_GameState *game_state)
{
	if (game_state->total_collectibles == 0)
	{
		ft_printf("Error\nThere are no collectibles\n");
		freemapstuff(game_state);
	}
	if (game_state->rows < 2 || game_state->cols < 2)
	{
		ft_printf("Error\nMap is too small\n");
		freemapstuff(game_state);
	}
	if (game_state->player_x == -1 || game_state->player_y == -1
		|| game_state->pcount != 1)
	{
		ft_printf("Error\nNot one player per map\n");
		freemapstuff(game_state);
	}
	linelencheck(game_state);
	checkexit(game_state);
	if (game_state->valid == 0)
	{
		ft_printf("Error\nThere is no reachable exit\n");
		freemapstuff(game_state);
	}
}
