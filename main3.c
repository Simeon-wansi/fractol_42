#include "minilibx_opengl_20191021/mlx.h"

int key_handler(int key , int x, int y)
{
    printf("%d\n", key);


    return (0);
}


int main() {

    void *mlx;
    void *win;

    mlx = mlx_init();
    mlx_mouse_hook(win, key_handler, mlx);
    win = mlx_new_window(mlx, 500, 500, "simon");
    mlx_loop(mlx);
}