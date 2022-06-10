/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lol.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2wizard <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 22:34:59 by W2wizard      #+#    #+#                 */
/*   Updated: 2022/02/17 22:34:59 by W2wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// If you wish to modify this file edit the .vert or .frag file!

#include "MLX42/MLX42_Int.h"

const char* vert_shader = "#version 330 core\n"
	"layout(location = 0) in vec3 aPos;"
	"layout(location = 1) in vec2 aTexCoord;"
	"layout(location = 2) in int aTexIndex;"
	"out vec2 TexCoord;"
	"flat out int TexIndex;"
	"uniform mat4 ProjMatrix;"
	"void main()"
	"{"
	"	gl_Position = ProjMatrix * vec4(aPos, 1.0);"
	"	TexCoord = aTexCoord;"
	"	TexIndex = aTexIndex;"
	"}";
