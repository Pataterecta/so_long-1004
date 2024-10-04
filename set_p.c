//플레이어 위치 찾기 배열에서 그냥 달려서..? x y 좌표화 하기 위해 이중배열로 만들어야 하지 않을까요
void    set_p(t_param *par)
{
    t_mapline   *curline;
    char        *str;

    curline = par->map;
    par->p_x = 0;
    par->p_y = 0;
    while (curline)
    {
        str = curline->line;
        while (*str != '\n')
        {
            if (*str != 'P')
                return (0)
            str++;
            par->p_x**;
        }
        curline = curline->next;
        par->p_x = 0;
        par->p_y++;
    }
}