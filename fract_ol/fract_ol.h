#ifndef  FRACT_OL_H
#define FRACT_OL_H
#define MAX_ITERATION 60
#define WIDTH 800
#define HEIGHT 600

typedef struct t_fract_julia
{
    double  julia_x;
    double  julia_y;
} s_fract_julia;

typedef struct t_fract_ol_limit
{
    double  c_real;
    double  c_imag;
    double  min_r;
    double  max_r;
    double  min_i;
    double  max_i;
} s_fol;

typedef struct t_fract_ol
{
    void	*src_ptr;
    void	*win_ptr;
    void	*img_ptr;
    char	*addr;
    int		bitperpix;
    int		size_line;
    int		endian;
    s_fol   fol;
    s_fract_julia   *julia;
} s_fract_ol;


void		fract_ol();
void		print_pixel(s_fract_ol *fract, int x, int y, int color);
int			calculate_mandelbrot(s_fract_ol *fract ,int x, int y);
int			calculate_julia(s_fract_ol *fract ,int x, int y);
s_fract_ol	*get_mapping(s_fract_ol *fract ,int x, int y);

void 		render_fractal(s_fract_ol *fract);
int			key_handler(int keycode, s_fract_ol *fract);
int			mouse_handler(int keycode, int x, int y, s_fract_ol *fract);
char        *ft_strnstr(const char *big, const char *little, int len);
double      ft_atof(const char *str);

#endif