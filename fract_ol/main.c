#include "minilibx-linux/mlx.h"

#include <stdlib.h>  // exit fonksiyonu için
#include <stdio.h>   // printf (hata ayıklama için)

// 42'de tuş kodları Linux ve macOS arasında farklılık gösterir!
// Linux'ta ESC = 65307
// macOS'ta ESC = 53
#define KEY_ESC 65307

typedef struct  s_data
{
    void *mlx_ptr;
    void *win_ptr;
}   t_data;

int     key_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
    {
        printf("ESC TUŞUNA BASILDI, PROGRAM KAPATILIYOR.\n");
        mlx_destroy_window(data-> mlx_ptr, data-> win_ptr);
        mlx_destroy_display(data-> mlx_ptr);
        free(data -> mlx_ptr);
        exit(0);
    }
    return 0;
}

int close_window_hook(t_data *data)
{
    printf("Pencere 'X' ile kapatıldı, program sonlanıyor...\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int main(void)
{
    t_data data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return 1;

    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Fract'ol");
    if(data.win_ptr == NULL)
        return (1);

    mlx_key_hook(data.win_ptr, key_hook, &data);
    mlx_hook(data.win_ptr, 17, 0l, close_window_hook, &data);

    mlx_loop(data.mlx_ptr);
}