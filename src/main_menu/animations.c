#include "../includes/main_menu.h"

void	animate_scroll(t_menu *menu, long now)
{
	if (now > menu->scroll_seconds + 15 && menu->in_settings == true)
	{
		menu->scroll_seconds = now;
		if (menu->scroll_frame < 33)
		{
			if (menu->scroll_frame > 13)
				menu->imgs[menu->scroll_frame - 1]->enabled = false;
			menu->imgs[menu->scroll_frame]->enabled = true;
			menu->scroll_frame++;
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