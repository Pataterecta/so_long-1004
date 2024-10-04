#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "so_long.h"
# define BUFFER_SIZE 42

int   add_lines(t_param *par)// 
{
    char    *str;
    char    *temp;

    temp = NULL;
    par->result = ft_strdup("");
    if (!par->result)
        return (1);
    while (1)
    {
        str = get_next_line(par->fd);
        if (str == NULL)
            break;
        temp = ft_strjoin(par->result, str);
        free(par->result);
        free(str);
        if (temp == NULL)
            return (0);
        par->result = temp; 
    }
    if (temp == NULL)
    {
        printf("Error\nnothing to read.\n");
        return (2);
    }
    return (1);
}

int check_element_map(t_param *par)
{
    int i;

    i = 0;
    while (par->result[i] != '\0')
    {
        if (par->result[i] != '0' && par->result[i] != '1' &&
            par->result[i] != 'C' && par->result[i] != 'E' && par->result[i] != 'P' && par->result[i] != '\n')
        {
            printf("NO u no eyes!? INVALID components\n");
            return (1); // 오류가 있으면 1 반환
        }
        i++;
    }
    return (0); // 모든 문자가 유효하면 0 반환
}

int check_empty_line(t_param *par)
{
    int i;

    i = 0;
    if (par->result[0] == '\n')
    {
        printf("Error\nempty line found\n");
            return (1);
    }
    while (par->result[i] != '\0')
    {
        if (par->result[i] == '\n' && par->result[i + 1] == '\n')
        {
            printf("Error\nempty line found\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int check_all_ones(char *str)
{   
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
        {
            printf("Error\nwall line missing\n");
            return (1);
        }
        i++;
    }
    return (0);
}
int check_one_boundaries(char *str)
{
    int i;

    i = 0;
    if (str[0] != '1')
        return (1);
    while (str[i])
    {
        i++;
    }
    if (str[i - 1] == '1')
        return (0);
    return (1);
}

//배열의 마지막줄이 몇번째 줄인지 확인하는 함수
void howmanylines(t_param *par)
{
    int i;

    i = 0;
    while (par->splited_res[i] != NULL)
    {
        i++;
    }
    par->n_of_lines = i - 1;
}
//배열의 중간줄들에 1~막줄 전까지 1__1 확인하는 함수
int middle_lines(t_param *par)
{
    int i;

    i = 1;
    while (i < par->n_of_lines)
    {
        if (check_one_boundaries(par->splited_res[i]) != 0)
        {   
            printf("Error\nwall column fked up");
            return (1);
        }
        i++;
    }
    return (0);
}

//요소 갯수 체크하기
int count_compo(t_param *par)
{
    par->C = 0;
    par->P = 0;
    par->E = 0;

    int i;

    i = 0;
    while (par->result[i])
    {
        if (par->result[i] == 'C')
            par->C += 1;
        if (par->result[i] == 'P')
            par->P += 1;
        if (par->result[i] == 'E')
            par->E += 1;
        i++;
    }
    if (par->C < 1 || par->E != 1 || par->P != 1)
    {
        printf("Error\nCompenents problem.");
        return (1);
    }
    return (0);
}

//스플릿 한 애들의 길이를 다 비교한다 comparer la taille de chaque ligne qui est "SPLITed"
int    length_compare(t_param *par)
{
    int i;
    size_t len;
    
    i = 1;
    len = ft_strlen(par->splited_res[0]);
    while (par->splited_res[i])
    {
        if (ft_strlen(par->splited_res[i]) != len)
        {
            printf("EACH lines arent the same length");
            return (1);
        }
        i++;
    }
    return (0);
}

int map_checker(t_param *par)
{
    int i;

    i = 0;    
    par->splited_res = ft_split(par->result, '\n');
    howmanylines(par);
    if (check_element_map(par) != 0)
        exit(EXIT_FAILURE);
    if (length_compare(par) != 0)
        exit(EXIT_FAILURE);
    if (check_empty_line(par) != 0)
        exit(EXIT_FAILURE);
    if (check_all_ones(par->splited_res[0]) != 0)
        exit(EXIT_FAILURE);
    if (check_all_ones(par->splited_res[par->n_of_lines]) != 0)
        exit(EXIT_FAILURE);
    if (middle_lines(par) != 0)
        exit(EXIT_FAILURE);
    if (count_compo(par) != 0)
        exit(EXIT_FAILURE);
    return (0);
}

void error_message(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

// int drawmap(t_param *par)
// {
//     char        *str;
//     int         x;
//     int         y;
//     int         i;

//     x = 0;
//     y = 0;
//     i = 0;
//     mlx_clear_window(par->mlx, par->win);
//     str = par->result;
//     while (str[i] != '\0')
//     {
//         if (str[i] == '\n')
//         {
//             x = 0;
//             y += par->he;
//         }
//         else
//         {
//             draw_imag(str[i], par, x, y);
//             x += par->wi;
//         }
//         i++;
//     }
//     return(0)
// }
// void    draw_img(char a, t_param *par, int x, int y)
// {
//     if (a == '0')
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
//     else if (a == '1')
//     {
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
//         mlx_put_image_to_window(par->mlx, par->win, par->w, x, y);
//     }
//     else if (a == 'P' || a == 'C' || a == 'E')
//     {
//         mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);//땅그리기 먼저
//         if (a == 'P')
//             mlx_put_image_to_window(par->mlx, par->win, par->p, x, y);
//         else if (a == 'C')
//             mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
//         else if (a == 'E')
//             mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
//     }
// }

int main()
{
    t_param par;

    par.fd = open("./map1.ber", O_RDONLY);
    if (par.fd == -1)
    {
        perror("파일 열기 실패");
        return 1;
    }
    if (add_lines(&par) == 2)
    {
        close(par.fd);
        exit(EXIT_FAILURE);
    }
    if (!par.result)
    {
        perror("파일 읽기 실패");
        close(par.fd);
        return 1;
    }
    close(par.fd);
    // map_checker(&par);
    // free(par.result);
    if (map_checker(&par) != 0)
    {
        free(par.result);
        error_message("Error : invalid map!");
        return (1);
    }
    free(par.result);
    par.mlx = mlx_init();
    if (!par.mlx)
    {
        error_message("mlx_init() 실패");
        return (1);
    }
    par.win = mlx_new_window(par.mlx, 500, 500, "Map");
    if (!par.win)
    {
        error_message("mlx_new_window() 실패");
        return (1);
    }
    mlx_loop(par.mlx);
    return (0);
}