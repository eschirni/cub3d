#include "../includes/main_menu.h"

static void	fov_graphics_ratio(t_menu *menu)
{
	if (menu->settings->fov == 1920 && menu->settings->graphics < 32)
		menu->settings->graphics = 32;
	else if (menu->settings->fov == 960 && menu->settings->graphics < 16)
		menu->settings->graphics = 16;
	else if (menu->settings->fov == 480 && menu->settings->graphics < 8)
		menu->settings->graphics = 8;
	else if (menu->settings->fov == 240 && menu->settings->graphics < 4)
		menu->settings->graphics = 4;
	else if (menu->settings->fov == 120 && menu->settings->graphics < 2)
		menu->settings->graphics = 2;
}

static void	graphics(t_game *game, int x, int y)
{
	if (x >= 1400 && x <= 1440 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 1;
	else if (x >= 1441 && x <= 1473 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 2;
	else if (x >= 1472 && x <= 1501 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 4;
	else if (x >= 1502 && x <= 1529 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 8;
	else if (x >= 1530 && x <= 1570 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 16;
	else if (x >= 1571 && x <= 1602 && y >= 575 && y <= 593)
		game->menu->settings->graphics = 32;
}

static void	fov(t_game *game, int x, int y)
{
	if (x >= 1400 && x <= 1427 && y >= 470 && y <= 487)
		game->menu->settings->fov = 1920;
	else if (x >= 1428 && x <= 1445 && y >= 470 && y <= 487)
		game->menu->settings->fov = 960;
	else if (x >= 1446 && x <= 1473 && y >= 470 && y <= 487)
		game->menu->settings->fov = 480;
	else if (x >= 1472 && x <= 1501 && y >= 470 && y <= 487)
		game->menu->settings->fov = 240;
	else if (x >= 1502 && x <= 1529 && y >= 470 && y <= 487)
		game->menu->settings->fov = 120;
	else if (x >= 1530 && x <= 1557 && y >= 470 && y <= 487)
		game->menu->settings->fov = 60;
	else if (x >= 1558 && x <= 1585 && y >= 470 && y <= 487)
		game->menu->settings->fov = 30;
	else if (x >= 1586 && x <= 1602 && y >= 470 && y <= 487)
		game->menu->settings->fov = 15;
}

static void	rotation_speed(t_game *game, int x, int y)
{
	if (x >= 1400 && x <= 1427 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.25f;
	else if (x >= 1428 && x <= 1445 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.5f;
	else if (x >= 1446 && x <= 1473 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.75f;
	else if (x >= 1472 && x <= 1501 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1;
	else if (x >= 1502 && x <= 1529 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.25f;
	else if (x >= 1530 && x <= 1557 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.5f;
	else if (x >= 1558 && x <= 1585 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.75f;
	else if (x >= 1586 && x <= 1602 && y >= 350 && y <= 367)
		game->menu->settings->rs = 2;
}

void	menu_sliders(t_game *game, int x, int y)
{
	rotation_speed(game, x, y);
	fov(game, x, y);
	graphics(game, x, y);
	fov_graphics_ratio(game->menu);
}
