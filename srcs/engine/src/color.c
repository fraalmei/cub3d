/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:48:19 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/10 11:52:15 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/engine.h"

int	extract_color(t_vector3 color)
{
	int	ret_color;

    if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
        (fprintf(stderr, "Invalid color value\n"), exit(EXIT_FAILURE));

    ret_color = (0 << 24 | (int)color.x << 16 | (int)color.y << 8 | (int)color.z);
	return (ret_color);
}
