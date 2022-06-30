#ifndef MAIN_MENU_H
# define MAIN_MENU_H

# include "../cub3d.h"
# include <sys/time.h>

/* hooks */
void	animate_menu(void *tmp);
void	menu_buttons(mouse_key_t k, action_t act, modifier_key_t mod, void *ag);

/* actions */
void	start_game(t_game *game);

#endif
