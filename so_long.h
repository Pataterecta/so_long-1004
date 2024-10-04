#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <fcnt1.h>
// # include <mlx.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
// # include "../libraries/Libft/libft.h"


typedef struct s_param
{
    int fd;
    char *result;
    char **splited_res;
    int n_of_lines;
    int count_e;
    int count_p;
    int count_c;
    int move;
    int p_x;
    int p_y;
    int C;
    int P;
    int E;
    int win_height;
    int win_width;
    int he;
    int wi;
    int x;
    int y;
    void    *g;
    void    *w;
    void    *p;
    void    *c;
    void    *e;
    void    *mlx;
    void    *mlx_win;
    void    *win;
    void    *img;           // 이미지 객체
    // char    *addr;          // 이미지 데이터의 시작 주소
    int     bits_per_pixel; // 한 픽셀당 비트 수
    int     line_length;    // 한 줄의 길이 (바이트 단위)
    int     endian;         // 엔디안 정보 (픽셀 데이터의 순서)
}   t_param;
//초기화 함수 만들기
//프리 함수 필요 - malloc 들어간애들, 구조체 자체
//나가는 함수

char	**ft_split(char const *s, char c);
void error_message(const char *message);

#endif