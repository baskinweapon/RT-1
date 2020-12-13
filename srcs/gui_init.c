/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:33:27 by user              #+#    #+#             */
/*   Updated: 2020/12/13 08:29:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "window.h"
#include "rt_options.h"
#include "rt.h"

static void	init_rect_tree(t_all_rect *rect, t_window *win)
{
	if (rect == NULL || win == NULL)
		rt_error("init_rect_tree(): given NULL pointer");
	rect->third_button = init_rect_size(win->width - win->width / 4 +
		SPACER, rect->second_button.y + rect->second_button.h +
		MARGIN_Y * 4, win->width / 4, 30);
	rect->fourth_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->third_button.y + rect->third_button.h +
		MARGIN_Y * 4, win->width / 4, 30);
	rect->fifth_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->fourth_button.y + rect->fourth_button.h + MARGIN_Y * 4,
		win->width / 4, 30);
	rect->sixth_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->fifth_button.y + rect->fifth_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
	rect->seven_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->sixth_button.y + rect->sixth_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
	rect->eight_button = init_rect_size(win->width - win->width / 4 +
	SPACER, rect->seven_button.y + rect->seven_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
}

static void	init_rect_two(t_all_rect *rect, t_window *win)
{
	if (rect == NULL || win == NULL)
		rt_error("init_rect_two(): given NULL pointer");
	rect->nine_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->eight_button.y + rect->eight_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
	rect->ten_button = init_rect_size(win->width - win->width / 4 +
	SPACER, rect->nine_button.y + rect->nine_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
	rect->eleven_button = init_rect_size(win->width - win->width / 4 +
	SPACER, rect->ten_button.y + rect->ten_button.h + MARGIN_Y * 2,
		win->width / 4, 30);
	rect->save_img_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->third_button.y + rect->third_button.h + MARGIN_Y * 4,
		win->width / 4, 30);
}

void		init_rect(t_all_rect *rect, t_window *win)
{
	if (rect == NULL || win == NULL)
		rt_error("init_rect(): given NULL pointer");
	rect->title_button = init_rect_size(win->width - win->width / 4,
		MARGIN_Y, win->width / 4 - MARGIN_Y, MARGIN_Y * 3);
	rect->background = init_rect_size(win->width - win->width / 4,
		0, win->width / 4, win->height);
	rect->tab_camera_button = init_rect_size(win->width - win->width / 4,
		win->height / 9, (win->width / 4) / 3, 30);
	rect->tab_objects_button = init_rect_size(win->width - win->width / 4
		+ rect->tab_camera_button.w,
		win->height / 9, (win->width / 4) / 3, 30);
	rect->tab_options_button = init_rect_size(win->width - win->width / 4 +
		rect->tab_camera_button.w + rect->tab_objects_button.w,
		win->height / 9, (win->width / 4) / 3, 30);
	rect->first_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->tab_camera_button.y + rect->tab_camera_button.h + MARGIN_Y,
		win->width / 4, 30);
	rect->second_button = init_rect_size(win->width - win->width / 4 + SPACER,
		rect->first_button.y + rect->first_button.h + MARGIN_Y,
		win->width / 4, 30);
	init_rect_tree(rect, win);
	init_rect_two(rect, win);
}

void		init_colors(t_colors *color)
{
	if (color == NULL)
		rt_error("init_colors(): given NULL pointer");
	color->background_color = init_color(0, 0, 0, 0);
	color->border_color = init_color(43, 43, 45, 0);
	color->inside_color = init_color(28, 28, 30, 0);
	color->text_color = init_color(255, 255, 255, 0);
}
