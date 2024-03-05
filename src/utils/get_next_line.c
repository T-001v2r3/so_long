/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:17:49 by gperfeit          #+#    #+#             */
/*   Updated: 2023/04/25 19:13:30 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[BUFFER_SIZE];
	static ssize_t	buff_i = 0;
	static ssize_t	res = 0;
	size_t			linelen;

	line = NULL;
	linelen = 0;
	if (fd > -1 && (!is_prevfd(fd) || buff_i == res))
	{
		res = read(fd, buff, BUFFER_SIZE);
		buff_i = 0;
	}
	while (res > 0 && (!line || line[linelen - 1] != '\n'))
	{
		if (buff_i >= res)
		{
			res = read(fd, buff, BUFFER_SIZE);
			buff_i = 0;
		}
		buff_i += parse_buff(buff + buff_i, buff + res, &line, &linelen);
	}
	return (line);
}
