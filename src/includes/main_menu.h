#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "cub3d.h"

/* hooks */
void	animate_scroll_text(t_menu *menu);
void	disable_all(t_menu *menu, int start, int end);
void	menu_buttons(mouse_key_t k, action_t act, modifier_key_t mod, void *ag);
void	menu_sliders(t_game *game, int x, int y);

/* actions */
void	load_png(t_game *game, int pos, char *name, bool enabled);
void	start_game(t_game *game);

/* settings */
void	init_settings(t_game *game);

/* textures */
void	init_textures(t_game *game);

#endif
