#include <mlx.h>
#include <stdio.h>

int main()
{
    void    *mlx;        // MiniLibX 연결을 위한 포인터
    void    *win;        // 창을 생성하기 위한 포인터
    void    *img;        // 이미지를 위한 포인터
    int     img_width;   // 이미지의 너비
    int     img_height;  // 이미지의 높이

    // 1. MiniLibX 초기화
    mlx = mlx_init();
    if (mlx == NULL)
    {
        printf("Error: mlx_init() failed\n");
        return (1);
    }

    // 2. 창 생성 (400x400 크기의 창)
    win = mlx_new_window(mlx, 400, 400, "Simple Window with Image");
    if (win == NULL)
    {
        printf("Error: mlx_new_window() failed\n");
        return (1);
    }

    // 3. 이미지 파일을 XPM 형식으로 로드 (이미지 크기는 자동으로 할당됨)
    img = mlx_xpm_file_to_image(mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/grass.xpm", &img_width, &img_height);
    if (img == NULL)
    {
        printf("Error: mlx_xpm_file_to_image() failed\n");
        return (1);
    }

    // 4. 이미지를 창의 (100, 100) 위치에 표시
    mlx_put_image_to_window(mlx, win, img, 100, 100);

    // 5. 이벤트 루프 시작 (창이 유지되도록)
    mlx_loop(mlx);

    return 0;
}
