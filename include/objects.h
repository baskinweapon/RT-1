/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <cool.3meu@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:07:20 by dmelessa          #+#    #+#             */
/*   Updated: 2020/08/07 21:51:43 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "types.h"
# include "material.h"

typedef enum e_types		t_type;
typedef struct s_obj		t_obj;
typedef struct s_triangle	t_triangle;
typedef struct s_bbox		t_bbox;
enum	e_types
{
	cone,
	cylinder,
	paraboloid,
	plane,
	sphere,
	torus,
	triangle,
	box,
	disk,
	rectangle,
	generic_shere
	//todo(dmelessa): another generic types
};

/**
** @brief
** axis-aligned bounding box for object
*/
#ifdef _WIN64
__declspec(align(4))
#endif
struct					s_bbox
{
	cl_float4			min;
	cl_float4			max;
};

/**
** TODO: change
**
*/
# ifdef _WIN64
__declspec(align(4))
# endif
struct					s_obj
{
	t_bbox				bounding_box;
	cl_float4			origin;
	cl_float4			direction;
	cl_float4			dir2;
	cl_float4			normal;
	cl_float			r;
	cl_float			r2;
	cl_float			angle;
	cl_float			maxm;
	cl_float			minm;
	cl_int				shadows;
	cl_int				sampler_id;
};

# ifdef _WIN64
__declspec(align(4))
# endif
struct					s_triangle
{
	t_material			material;
	cl_float4			vertex1;
	cl_float4			vertex2;
	cl_float4			vertex3;
	cl_float4			vector1; //vertex2 - vertex1
	cl_float4			vector2; // vertex3 - vertex1
	cl_float4			normal;
};

#ifdef _WIN64
__declspec(align(4))
#endif
typedef struct			s_object_info
{
	t_material			material;
	t_bbox				bounding_box;
	cl_float4			origin;	//vertexe for triangle
	cl_float4			vector1;
	cl_float4			vector2;
	cl_float4			direction; //triangle or plane?
	cl_float3			rotation;	//object rotation about x, y, z axis
	cl_float3			scaling;	//scaling toward to axis
	cl_float			minm;
	cl_float			maxm;
	cl_float			r;	//torus radius1
	cl_float			r2; // torus radius2
	t_type				type;
	cl_int				transformed;
}						t_object_info;

#endif
