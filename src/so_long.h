/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:42:00 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/25 19:49:46 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define MAX_LINE_LENGTH 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

struct s_GameState {
	void		*mlx;
	void		*mlx_win;
	int			col_col;
	int			total_collectibles;
	int			movements;
	int			player_x;
	int			player_y;
	int			game_is_running;
	char		**map;
	int			rows;
	int			cols;
	void		*player1img;
	void		*wallimg;
	void		*coin1img;
	void		*exitimg;
	void		*monster_0;
	void		*monster_1;
	void		*monster_2;
	void		*monster_3;
	void		*cat_0;
	void		*cat_1;
	void		*cat_2;
	void		*cat_3;
	char		**maptwo;
	char		**lastmappos;
	int			lastx;
	int			lasty;
	int			valid;
	int			pcount;
	int			monsterimg;
	int			playerimg;
	int			total_enemies;
	int			bufferingz;
	int			enemystatus;
};

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	map_validator(struct s_GameState *game_state);
void	pressup(struct s_GameState *game_state);
void	pressleft(struct s_GameState *game_state);
void	pressdown(struct s_GameState *game_state);
void	pressright(struct s_GameState *game_state);
void	finalizeinput(struct s_GameState *game_state);
void	freemap2(struct s_GameState *game_state);
void	createmapdois(struct s_GameState *game_state);
void	free_map_memory(struct s_GameState *game_state);
void	initialize_library(struct s_GameState *game_state);
void	input_update_state(struct s_GameState *game_state, int input);
void	draw_xpm(struct s_GameState *game_state, int x, int y, char *xpm_path);
void	render_game_volume_dois(struct s_GameState *game_state);
void	ft_put_ptr(unsigned long long p, int *l);
void	ft_put_nbr(unsigned int value, int *l, int unsig);
void	ft_put_hex(unsigned int value, int *l, int upper);
void	checkothers(struct s_GameState *game_state, int i, int j);
void	freemapstuff(struct s_GameState *game_state);
int		is_prevfd(int newfd);
int		ft_printptr(unsigned long long p);
int		printchar(char c);
int		ft_printf(const char *str, ...);
int		ft_format(va_list args, char c);
int		ft_printstr(char *s);
int		checkplayer(struct s_GameState *game_state, int i, int j);
int		validate_args(int argc, char *argv[]);
int		render_game(struct s_GameState *game_state);
int		deinitialize_library(struct s_GameState *game_state);
int		initialize_game_data(struct s_GameState *game_state);
int		key_press(int keycode, struct s_GameState *game_state);
int		load_game_images(struct s_GameState *game_state);
int		checkexit(struct s_GameState *game_state);
int		startfill(struct s_GameState *game_state, int i, int j);
int		checkposition(struct s_GameState *game_state, int i, int j);
char	*get_next_line(int fd);
char	**read_map_file(const char *file_path, struct s_GameState *game_state);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
ssize_t	parse_buff(char *buff, char *end, char **line, size_t *linelen);
size_t	ft_strlen(const char *s);
void	triplecheck(struct s_GameState *game_state);
void	continuecheck(struct s_GameState *game_state);
void	linelencheck(struct s_GameState *game_state);
void	lencheck(struct s_GameState *game_state);
void	initgamestate(struct s_GameState *game_state);
void	linecountahah(struct s_GameState *game_state);
char	*ft_itoa(int n);
int		ft_intlen(int n);
char	*ft_strrev(char *str);
int		image_selector(int i, int j, struct s_GameState *game_state);
void	initgamestatedois(struct s_GameState *game_state);
int		image_selector_player(int i, int j, struct s_GameState *game_state);
int		image_selector_enemy(int i, int j, struct s_GameState *game_state);
int		getimg(struct s_GameState *game_state);
int		getcoords(int i, int j, struct s_GameState *game_state);
int		checkplayerpos(int i, int j, struct s_GameState *game_state);
int		load_game_images_second(struct s_GameState *game_state);
int		randomizer(struct s_GameState *game_state);
void	partedois(int i, int j, struct s_GameState *game_state);
int		textcreator(struct s_GameState *game_state);

#endif
