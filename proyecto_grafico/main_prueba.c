#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int finish_win(void *mlx)
{
    mlx_loop_end(mlx);
    return (26);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (mlx == NULL)
        return (0);
    win = mlx_new_window(mlx, 800, 600, "Prueba");
    mlx_hook(win, 17, 1<<17, finish_win, mlx);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
}