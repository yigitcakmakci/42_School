/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:55:11 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 17:59:28 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define MAX_ITERATION 30
# define WIDTH 800
# define HEIGHT 600

typedef struct s_zoom
{
	double			ratio_x;
	double			ratio_y;
	double			range_r_old;
	double			range_i_old;
	double			range_r_new;
	double			range_i_new;
	double			shift_r;
	double			shift_i;
}					t_zoom;

typedef struct s_fract_julia
{
	double			julia_x;
	double			julia_y;
}					t_fract_julia;

typedef struct s_fract_ol_limit
{
	double			c_real;
	double			c_imag;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
}					t_fol;

typedef struct s_fract_ol
{
	void			*src_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bitperpix;
	int				size_line;
	int				endian;
	t_fol			fol;
	t_fract_julia	*julia;
	t_zoom			event_ctrl;
}					t_fract_ol;

void				fract_ol(t_fract_julia *fract_julia);
void				print_pixel(t_fract_ol *fract, int x, int y, int color);
int					calculate_mandelbrot(t_fract_ol *fract, int x, int y);
int					calculate_julia(t_fract_ol *fract, int x, int y);
t_fract_ol			*get_mapping(t_fract_ol *fract, int x, int y);

void				render_fractal(t_fract_ol *fract);
int					key_handler(int keycode, t_fract_ol *fract);
int					mouse_handler(int keycode, int x, int y, t_fract_ol *fract);
char				*ft_strncmp(const char *big, const char *little, int len);
double				ft_atof(const char *str);

#endif