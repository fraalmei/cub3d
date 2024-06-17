/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:54:41 by p                 #+#    #+#             */
/*   Updated: 2024/06/17 12:18:29 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int print_textures(t_texture **textures)
{
    int     i;

    if (!textures)
        return (0);
    i = -1;
    while (textures[++i])
    {
        ft_printf_fd(1, "#######################\n");
        if (textures[i]->name)
            ft_printf_fd(1, "Name: %s\n", textures[i]->name);
        if (textures[i]->dir)
        {
            ft_printf_fd(1, "Dir: %s\n", textures[i]->dir);
            ft_printf_fd(1, "Img?: %d\n", is_img(textures[i]->dir));
        }
        if (textures[i]->img)
            ft_printf_fd(1, "Img: OK\n");
        if (textures[i]->size.width)
            ft_printf_fd(1, "Width: %d\n", textures[i]->size.width);
        if (textures[i]->size.height)
            ft_printf_fd(1, "Height: %d\n", textures[i]->size.height);
        ft_printf_fd(1, "#######################\n");
    }
    return (0);
}
