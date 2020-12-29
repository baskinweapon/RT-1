/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <cool.3meu@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:39:11 by alex              #+#    #+#             */
/*   Updated: 2020/12/22 00:18:49 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft.h"
#include "rt.h"
#include "rt_error.h"

void			get_intensive_data(int ptr, char *string, char **str)
{
	str[0] = ft_strdup(string);
	rt_is_dead(system_err, system_malloc_error, !str[0], "gui_get_data 1");
	if (ptr == 0)
		str[1] = ft_strdup("ambient");
	else if (ptr == 1)
		str[1] = ft_strdup("ambient_occluder");
	else if (ptr == 2)
		str[1] = ft_strdup("directional");
	else if (ptr == 3)
		str[1] = ft_strdup("point");
	else if (ptr == 4)
		str[1] = ft_strdup("area");
	else if (ptr == 5)
		str[1] = ft_strdup("enviromental");
	rt_is_dead(system_err, system_malloc_error, !str[1], "gui_get_data 2");
	str[2] = NULL;
	str[3] = NULL;
}

void			get_texture_data(int ptr, char *string, char **str)
{
	str[0] = ft_strdup(string);
	rt_is_dead(system_err, system_malloc_error, !str[0], "gui_get_data 3");
	if (ptr == 0)
		str[1] = ft_strdup("solid");
	else if (ptr == 1)
		str[1] = ft_strdup("checker");
	else if (ptr == 2)
		str[1] = ft_strdup("checker2d");
	else if (ptr == 3)
		str[1] = ft_strdup("transparent_checker");
	else if (ptr == 4)
		str[1] = ft_strdup("reflective_checker");
	else if (ptr == 5)
		str[1] = ft_strdup("perlin");
	else if (ptr == 6)
		str[1] = ft_strdup("smooth_perlin");
	else if (ptr == 7)
		str[1] = ft_strdup("turbulence_perlin");
	else if (ptr == 8)
		str[1] = ft_strdup("wave_perlin");
	else if (ptr == 9)
		str[1] = ft_strdup("image");
	rt_is_dead(system_err, system_malloc_error, !str[1], "gui_get_data 4");
	str[2] = NULL;
	str[3] = NULL;
}

void			get_shape_data_2(int ptr, char **str)
{
	if (ptr == triangle)
		str[1] = ft_strdup("triangle");
	else if (ptr == box)
		str[1] = ft_strdup("box");
	else if (ptr == disk)
		str[1] = ft_strdup("disk");
	else if (ptr == rectangle)
		str[1] = ft_strdup("rectangle");
	else if (ptr == generic_shere)
		str[1] = ft_strdup("generic_shere");
	rt_is_dead(system_err, system_malloc_error, !str[1], "gui_get_data 5");
}

void			get_shape_data(int ptr, char *string, char **str)
{
	str[0] = ft_strdup(string);
	rt_is_dead(system_err, system_malloc_error, !str[0], "gui_get_data 6");
	if (ptr == cone)
		str[1] = ft_strdup("cone");
	else if (ptr == cylinder)
		str[1] = ft_strdup("cylinder");
	else if (ptr == paraboloid)
		str[1] = ft_strdup("paraboloid");
	else if (ptr == plane)
		str[1] = ft_strdup("plane");
	else if (ptr == sphere)
		str[1] = ft_strdup("sphere");
	else if (ptr == torus)
		str[1] = ft_strdup("torus");
	rt_is_dead(system_err, system_malloc_error, !str[1], "gui_get_data 7");
	get_shape_data_2(ptr, str);
	str[2] = NULL;
	str[3] = NULL;
}

void			get_material_data(int ptr, char *string, char **str)
{
	str[0] = ft_strdup(string);
	rt_is_dead(system_err, system_malloc_error, !str[0], "gui_get_data 8");
	if (ptr == matte)
		str[1] = ft_strdup("matte");
	else if (ptr == phong)
		str[1] = ft_strdup("phong");
	else if (ptr == emissive)
		str[1] = ft_strdup("emissive");
	else if (ptr == mirror)
		str[1] = ft_strdup("mirror");
	else if (ptr == conductor)
		str[1] = ft_strdup("conductor");
	else if (ptr == dielectric)
		str[1] = ft_strdup("dielectric");
	else if (ptr == plastic)
		str[1] = ft_strdup("plastic");
	else
		str[1] = ft_strdup("no material");
	rt_is_dead(system_err, system_malloc_error, !str[1], "gui_get_data 9");
	str[2] = NULL;
	str[3] = NULL;
}
