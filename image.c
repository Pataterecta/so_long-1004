#include <mlx.h>
#include <unistd.h> // For write function

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    error_message(const char *msg) {
    while (*msg)
        write(2, msg++, 1);
}

int main(void) {
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    if (!mlx) {
        error_message("Error: mlx_init() failed\n");
        return 1;
    }
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    if (!mlx_win) {
        error_message("Error: mlx_new_window() failed\n");
        return 1;
    }
    img.img = mlx_new_image(mlx, 1920, 1080);
    if (!img.img) {
        error_message("Error: mlx_new_image() failed\n");
        return 1;
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    if (!img.addr) {
        error_message("Error: mlx_get_data_addr() failed\n");
        return 1;
    }

    // Example of checking values without printf
    // Converting numbers to strings and writing to stderr
    char    buffer[128];
    int     len;

    len = snprintf(buffer, sizeof(buffer), "Image details: bpp=%d, line_length=%d, endian=%d\n",
                   img.bits_per_pixel, img.line_length, img.endian);
    write(2, buffer, len);

    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // Drawing a red pixel at (5, 5)
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);

    return 0;
}

