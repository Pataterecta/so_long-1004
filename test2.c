#include "mlx.h"
#include <stdio.h>

int main(void)
{    
    void    *mlx;  // MiniLibX 초기화 포인터
    void    *win;  // 창 포인터

    // 1. MiniLibX 초기화
    mlx = mlx_init();
    if (mlx == NULL)
    {
        printf("Error: mlx_init() failed\n");
        return (1);
    }

    // 2. 500x500 크기의 새 창을 생성
    win = mlx_new_window(mlx, 500, 500, "Map");
    if (win == NULL)
    {
        printf("Error: mlx_new_window() failed\n");
        return (1);
    }

    // 3. 이벤트 루프 실행 (창을 유지)
    mlx_loop(mlx);

    return (0);
}