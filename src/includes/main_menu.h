#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "cub3d.h"
# include <sys/time.h>

/* hooks */
void	menu_buttons(mouse_key_t k, action_t act, modifier_key_t mod, void *ag);
void	menu_sliders(t_game *game, int x, int y);

/* actions */
void	start_game(t_game *game);
void	load_png(t_game *game, int pos, char *name, bool enabled);

/* settings */
void	init_settings(t_game *game);

#endif
