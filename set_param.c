#include "mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <fcntl.h>

void	set_param(t_param *par)
{
	par->fd = open("maps/map.ber", O_RDONLY);
	if (par->fd <= 0)
		return ;
	par->result = NULL; // map을 불러와서 저장할 공간
    par->splited_res = NULL;
    par->n_of_lines = 0;
	par->count_e = 0; // 탈출구의 갯수
	par->count_p = 0; // 시작지점의 갯수
	par->count_c = 0; // 수집품의 갯수
	par->win_width = 0; // 윈도우의 너비
	par->win_height = 0; // 윈도우의 높이
	par->x = 0; // 이미지의 x축 크기
	par->y = 0; // 이미지의 y축 크기
	par->move = 0; // 이동 횟수
    par->he = 0;
    par->wi = 0;
	par->p_x = 0; // 플레이어의 x좌표
	par->p_y = 0; // 플레이어의 y좌표
	par->mlx = mlx_init(); // mlx
	par->g = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/grass.xpm", &par->wi, &par->he);
    par->w = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/wall.xpm", &par->wi, &par->he);
    par->c = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/apple.xpm", &par->wi, &par->he);
    par->e = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/exit.xpm", &par->wi, &par->he);
    par->p = mlx_xpm_file_to_image(par->mlx, "/mnt/c/Users/16061/Desktop/so_long_0820-main/img/player.xpm", &par->wi, &par->he);
	par->win = NULL;// 윈도우
}