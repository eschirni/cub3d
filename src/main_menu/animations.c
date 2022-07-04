#include "../includes/main_menu.h"

static void	animate_text(t_menu *menu, bool enable)
{
	menu->imgs[33]->enabled = enable;
	menu->imgs[34]->enabled = enable;
	menu->imgs[35]->enabled = enable;
	menu->imgs[36]->enabled = enable;
	if (menu->settings->cross_type == 'C')
		menu->imgs[38]->enabled = enable;
	else
		menu->imgs[37]->enabled = enable;
	if (menu->settings->cross_type == 'D')
		menu->imgs[40]->enabled = enable;
	else
		menu->imgs[39]->enabled = enable;
	if (menu->settings->cross_type == 'E')
		menu->imgs[42]->enabled = enable;
	else
		menu->imgs[41]->enabled = enable;
}

static void	open_scroll(t_menu *menu, long now)
{
	menu->scroll_seconds = now;
	if (menu->scroll_frame < 33)
	{
		if (menu->scroll_frame > 13)
			menu->imgs[menu->scroll_frame - 1]->enabled = false;
		if (menu->scroll_frame > 12)
			menu->imgs[menu->scroll_frame]->enabled = true;
		menu->scroll_frame++;
	}
	else
		animate_text(menu, true);
}

void	animate_scroll(t_menu *menu, long now)
{
	if (now > menu->scroll_seconds + 15 && menu->scroll_mode == 'O')
		open_scroll(menu, now);
	else if (now > menu->scroll_seconds + 15 && menu->scroll_mode == 'C')
	{
		menu->scroll_seconds = now;
		if (menu->scroll_frame == 33)
			animate_text(menu, false);
		if (menu->scroll_frame > 12)
		{
			if (menu->scroll_frame < 33)
				menu->imgs[menu->scroll_frame]->enabled = false;
			if (menu->scroll_frame != 13)
				menu->imgs[menu->scroll_frame - 1]->enabled = true;
			else
				menu->scroll_mode = 'N';
			menu->scroll_frame--;
		}
	}
}

static void	animate_bg(t_menu *menu, long now)
{
	int	i;

	if (now > menu->back_seconds + 150)
	{
		menu->back_seconds = now;
		i = 0;
		while (i < 6)
		{
			menu->imgs[i]->enabled = false;
			i++;
		}
		menu->imgs[menu->back_frame]->enabled = true;
		menu->back_frame++;
		if (menu->back_frame > 5)
			menu->back_frame = 0;
	}
}

void	animate_menu(t_menu *menu)
{
	struct timeval	time;
	long			now;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	animate_bg(menu, now);
	animate_scroll(menu, now);
}
