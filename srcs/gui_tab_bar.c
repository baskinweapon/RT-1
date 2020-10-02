/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_tab_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:03:59 by user              #+#    #+#             */
/*   Updated: 2020/10/02 16:26:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "rt.h"

void	color_tab_render(t_window *win, t_colors *color, t_all_rect *all_rect)
{
	// render_tab_bar(win, &color->title_text_color, &all_rect->tab_main_button, WIDTH - WIDTH_MENU / 2 - WIDTH_MENU / 4, "MAIN");
	// render_tab_bar(win, &color->tab_pressed_color, &all_rect->tab_render_button, WIDTH - WIDTH_MENU / 2 + WIDTH_MENU / 4, "RENDER");
	// hlineRGBA(rt->sdl.render, WIDTH - WIDTH_MENU / 2, WIDTH - MARGIN, (FONT_TITLE_SIZE + MARGIN_Y) * 4 - MARGIN_Y,
	// color->tab_pressed_color.r, color->tab_pressed_color.g, color->tab_pressed_color.b, 255);
	// hlineRGBA(rt->sdl.render, WIDTH_OFFSET + MARGIN, WIDTH - WIDTH_MENU / 2, (FONT_TITLE_SIZE + MARGIN_Y) * 4 - MARGIN_Y, 217, 217, 217, 255);
}

void	color_tab_main(t_window *win, t_colors *color, t_all_rect *all_rect)
{
	// render_tab_bar(win, &color->tab_pressed_color, &all_rect->tab_main_button, WIDTH - WIDTH_MENU / 2 - WIDTH_MENU / 4, "MAIN");
	// render_tab_bar(win, &color->title_text_color, &all_rect->tab_render_button, WIDTH - WIDTH_MENU / 2 + WIDTH_MENU / 4, "RENDER");
	// hlineRGBA(rt->sdl.render, WIDTH_OFFSET + MARGIN, WIDTH - WIDTH_MENU / 2, (FONT_TITLE_SIZE + MARGIN_Y) * 4 - MARGIN_Y,
	// color->tab_pressed_color.r, color->tab_pressed_color.g, color->tab_pressed_color.b, 255);
	// hlineRGBA(rt->sdl.render, WIDTH - WIDTH_MENU / 2, WIDTH - MARGIN, (FONT_TITLE_SIZE + MARGIN_Y) * 4 - MARGIN_Y, 217, 217, 217, 255);
}

SDL_Texture	*create_tab_subtitles(t_window *win, char *str, SDL_Color *color)
{
	SDL_Texture *text;

	text = render_text(str, "font/Title.ttf",
	*color, FONT_TITLE_SIZE, win->renderer);
	return (text);
}

void	render_tab_bar(t_window *win, SDL_Color *color, SDL_Rect *rect, int x, char *str)
{
	SDL_Texture *text;
	int w;
	int h;

	text = create_tab_subtitles(win, str, color);
	SDL_QueryTexture(text, NULL, NULL, &w, &h);
	render_texture(text, win->renderer, x, rect->h - h);
}

void	gui_tab_bar(t_window *win, t_all_rect *rect, t_colors *color)
{
	// roundedBoxRGBA(rt->sdl.render, rect->tab_main_button.x, rect->tab_main_button.y, rect->tab_main_button.w, rect->tab_main_button.h, 1, color->background_color.r, color->background_color.r, color->background_color.r, 255);
	// roundedBoxRGBA(rt->sdl.render, rect->tab_render_button.x, rect->tab_render_button.y, rect->tab_render_button.w, rect->tab_render_button.h, 1, color->background_color.r, color->background_color.r, color->background_color.r, 255);
	render_tab_bar(win, &color->title_text_color, &rect->tab_camera_button, WIDTH_OFFSET + MARGIN, "CAMERA");
	render_tab_bar(win, &color->title_text_color, &rect->tab_objects_button, DEFAULT_WIDTH - WIDTH_MENU / 2, "OBJECTS");
	render_tab_bar(win, &color->title_text_color, &rect->tab_options_button, DEFAULT_WIDTH - WIDTH_MENU / 3, "OPTIONS");
}
