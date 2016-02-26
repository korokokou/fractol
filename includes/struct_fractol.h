/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fractol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:22:29 by takiapo           #+#    #+#             */
/*   Updated: 2016/02/26 13:22:32 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FRACTOL_H
# define STRUCT_FRACTOL_H

# include <mlx.h>

# include "../libft/includes/libft.h"
# include "fractol.h"


typedef struct  s_env
{
    void        *mlx;
    void        *win;
}               t_env

#endif
