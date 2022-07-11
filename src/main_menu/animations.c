#include "../includes/main_menu.h"

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
		animate_scroll_text(menu);
}

void	animate_scroll(t_menu *menu, long now)
{
	if (now > menu->scroll_seconds + 15 && menu->scroll_mode == 'O')
		open_scroll(menu, now);
	else if (now > menu->scroll_seconds + 15 && menu->scroll_mode == 'C')
	{
		menu->scroll_seconds = now;
		if (menu->scroll_frame == 33)
			disable_all(menu, 33, 65);
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

void	play_music(t_menu *menu, long now)
{
	if (now > menu->music_start + 94)
	{
		menu->music_start = now;
		system("afplay ./music/main_menu.mp3 &");
	}
}

void	animate_menu(t_menu *menu)
{
	struct timeval	time;
	long			now;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	play_music(menu, time.tv_sec);
	animate_bg(menu, now);
	animate_scroll(menu, now);
}
