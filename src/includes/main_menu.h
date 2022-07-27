#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "cub3d.h"

/* hooks */
void	animate_scroll_text(t_menu *menu);
void	disable_all(t_menu *menu, int start, int end);

/* actions */
void	load_png(t_game *game, int pos, char *name, bool enabled);

/* settings */
void	init_settings(t_game *game);

/* textures */
void	init_textures(t_game *game);

#endif
