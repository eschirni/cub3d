/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_scroll_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:44:28 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:44:29 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_menu.h"

void	disable_all(t_menu *menu, int start, int end)
{
	while (start < end)
	{
		menu->imgs[start]->enabled = false;
		start++;
	}
}

static void	rotation_speed_slider(t_menu *menu)
{
	if (menu->settings->rs == 0.25f && menu->scroll_mode == 'O')
		menu->imgs[43]->enabled = true;
	else if (menu->settings->rs == 0.5f && menu->scroll_mode == 'O')
		menu->imgs[44]->enabled = true;
	else if (menu->settings->rs == 0.75f && menu->scroll_mode == 'O')
		menu->imgs[45]->enabled = true;
	else if (menu->settings->rs == 1 && menu->scroll_mode == 'O')
		menu->imgs[46]->enabled = true;
	else if (menu->settings->rs == 1.25f && menu->scroll_mode == 'O')
		menu->imgs[47]->enabled = true;
	else if (menu->settings->rs == 1.5f && menu->scroll_mode == 'O')
		menu->imgs[48]->enabled = true;
	else if (menu->settings->rs == 1.75f && menu->scroll_mode == 'O')
		menu->imgs[49]->enabled = true;
	else if (menu->settings->rs == 2 && menu->scroll_mode == 'O')
		menu->imgs[50]->enabled = true;
}

static void	fov_slider(t_menu *menu)
{
	if (menu->settings->fov == 1920 && menu->scroll_mode == 'O')
		menu->imgs[51]->enabled = true;
	else if (menu->settings->fov == 960 && menu->scroll_mode == 'O')
		menu->imgs[52]->enabled = true;
	else if (menu->settings->fov == 480 && menu->scroll_mode == 'O')
		menu->imgs[53]->enabled = true;
	else if (menu->settings->fov == 240 && menu->scroll_mode == 'O')
		menu->imgs[54]->enabled = true;
	else if (menu->settings->fov == 120 && menu->scroll_mode == 'O')
		menu->imgs[55]->enabled = true;
	else if (menu->settings->fov == 60 && menu->scroll_mode == 'O')
		menu->imgs[56]->enabled = true;
	else if (menu->settings->fov == 30 && menu->scroll_mode == 'O')
		menu->imgs[57]->enabled = true;
	else if (menu->settings->fov == 15 && menu->scroll_mode == 'O')
		menu->imgs[58]->enabled = true;
}

static void	graphics_slider(t_menu *menu)
{
	if (menu->settings->graphics == 32 && menu->scroll_mode == 'O')
		menu->imgs[59]->enabled = true;
	else if (menu->settings->graphics == 16 && menu->scroll_mode == 'O')
		menu->imgs[60]->enabled = true;
	else if (menu->settings->graphics == 8 && menu->scroll_mode == 'O')
		menu->imgs[61]->enabled = true;
	else if (menu->settings->graphics == 4 && menu->scroll_mode == 'O')
		menu->imgs[62]->enabled = true;
	else if (menu->settings->graphics == 2 && menu->scroll_mode == 'O')
		menu->imgs[63]->enabled = true;
	else if (menu->settings->graphics == 1 && menu->scroll_mode == 'O')
		menu->imgs[64]->enabled = true;
}

void	animate_scroll_text(t_menu *menu)
{
	menu->imgs[33]->enabled = true;
	menu->imgs[34]->enabled = true;
	menu->imgs[35]->enabled = true;
	menu->imgs[36]->enabled = true;
	if (menu->settings->cross_type == 'C')
		menu->imgs[38]->enabled = true;
	else
		menu->imgs[37]->enabled = true;
	if (menu->settings->cross_type == 'D')
		menu->imgs[40]->enabled = true;
	else
		menu->imgs[39]->enabled = true;
	if (menu->settings->cross_type == 'E')
		menu->imgs[42]->enabled = true;
	else
		menu->imgs[41]->enabled = true;
	disable_all(menu, 43, 65);
	rotation_speed_slider(menu);
	fov_slider(menu);
	graphics_slider(menu);
}
