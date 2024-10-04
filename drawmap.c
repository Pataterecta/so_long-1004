#include "mlx.h"
#include "so_long.h"
#include <fcntl.h>

void    draw_img(char a, t_param *par, int x, int y)
{
    if (a == '0')
        mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
    else if (a == '1')
    {
        mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
        mlx_put_image_to_window(par->mlx, par->win, par->w, x, y);
    }
    else if (a == 'P' || a == 'C' || a == 'E')
    {
        mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);//땅그리기 먼저
        if (a == 'P')
            mlx_put_image_to_window(par->mlx, par->win, par->p, x, y);
        else if (a == 'C')
            mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
        else if (a == 'E')
            mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
    }
}

int drawmap(t_param *par)
{
    char        *str;
    int         x;
    int         y;
    int         i;

    x = 0;
    y = 0;
    i = 0;
    mlx_clear_window(par->mlx, par->win);
    str = par->result;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            x = 0;
            y += par->he;
        }
        else
        {
            draw_img(str[i], par, x, y);
            x += par->wi;
        }
        i++;
    }
    return(0);
}

#define PIC_SIZE 64
int win_map_size(t_param *par)
{
    par->win_height = PIC_SIZE * par->he;
    par->win_width = PIC_SIZE * par->wi;
    return (0);
}

int win_image(t_param *par) 
{
    par->mlx = mlx_init();
    if (!par->mlx) {
        printf("Error: mlx_init() failed\n");
        return (1);
    }

    par->win = mlx_new_window(par->mlx, par->win_width, par->win_height, "Hello world!");
    if (!par->win) {
        printf("Error: mlx_new_window() failed\n");
        return (1);
    }

    // 이미지 로드 및 에러 체크
    par->g = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/grass.xpm", &par->wi, &par->he);
    if (!par->g) {
        printf("Error: failed to load grass image\n");
        return (1);
    } else {
        printf("Loaded grass image, width: %d, height: %d\n", par->wi, par->he);
    }

    par->w = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/wall.xpm", &par->wi, &par->he);
    if (!par->w) {
        printf("Error: failed to load wall image\n");
        return (1);
    } else {
        printf("Loaded wall image, width: %d, height: %d\n", par->wi, par->he);
    }

    par->c = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/apple.xpm", &par->wi, &par->he);
    if (!par->c) {
        printf("Error: failed to load apple image\n");
        return (1);
    } else {
        printf("Loaded apple image, width: %d, height: %d\n", par->wi, par->he);
    }

    par->e = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/exit.xpm", &par->wi, &par->he);
    if (!par->e) {
        printf("Error: failed to load exit image\n");
        return (1);
    } else {
        printf("Loaded exit image, width: %d, height: %d\n", par->wi, par->he);
    }

    par->p = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/imgs/player.xpm", &par->wi, &par->he);
    if (!par->p) {
        printf("Error: failed to load player image\n");
        return (1);
    } else {
        printf("Loaded player image, width: %d, height: %d\n", par->wi, par->he);
    }

    // 이미지를 서로 다른 위치에 그리기
    mlx_put_image_to_window(par->mlx, par->win, par->g, 0, 0); // 배경 이미지
    mlx_put_image_to_window(par->mlx, par->win, par->w, 64, 0); // 벽 이미지
    mlx_put_image_to_window(par->mlx, par->win, par->c, 128, 0); // 수집품 이미지
    mlx_put_image_to_window(par->mlx, par->win, par->e, 192, 0); // 탈출구 이미지
    mlx_put_image_to_window(par->mlx, par->win, par->p, 256, 0); // 플레이어 이미지

    mlx_loop(par->mlx);  // 이벤트 루프 시작
    return (0);
}
