/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:06:33 by cagonzal          #+#    #+#             */
/*   Updated: 2024/11/11 10:59:15 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_LINUX_H
# define KEY_LINUX_H

/*
** Keyboard LETTERS
*/

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

/*
void run_key(int k_code, int a, int b)
    {
    static void ((*key_make)(int , int))[3] = {\
    K_A, K_B, K_C};

    key_make[k_code -K_A](a, b);
    }
*/

/*
** Keyboard ARROWS
*/

# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364

/*
** Keyboard NUMPAD
*/

# define K_NP_DIVIDE 65455
# define K_NP_MULTIPLY 65450
# define K_NP_MINUS 65453
# define K_NP_PLUS 65451

/*
** Keyboard MISC
*/

# define K_SPACE 32
# define K_ESC 65307

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

#endif