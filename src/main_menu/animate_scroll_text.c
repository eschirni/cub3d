#include "../includes/main_menu.h"

void	disable_all(t_menu *menu, int start, int end)
{
	while (start < end)
	{
		menu->imgs[start]->enabled = false;
		start++;
	}
}

void	animate_scroll_text(t_menu *menu)
{
	menu->imgs[33]->enabled = true;
	menu->imgs[34]->enabled = true;
	menu->imgs[35]->enabled = true;
	menu->imgs[36]->enabled = true;
	disable_all(menu, 43, 65);
}
