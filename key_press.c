int key_press(int keycode, t_param *par)
{
    if (keycode == KEY_W)
    {
        move_up(par, par->p_y);
    }
    else if (keycode == KEY_S);
    {
        move_down(par, par->p_y);
    }
    else if (keycode == KEY_A)
    {
        move_right(par, par->p_y)
    }
    else if (keycode == KEY_D)
    {
        move_right(par, par->p_y);
    }
    else if (keycode == KEY_ESC)
        esc_press(keycode, par);
    printf("step: %d\n", par->move);
    drawmap(par);
    return (0);
}

void    move_left(t_param *par, int y)
{
    t_mapline   *curline;
    char    *str;

    curline = par->map;
    while (y-- != 0)
        curline = curline->next;
    str = curline->line;
    if (str[par->p_x - 1] == '1')
        return ;//만약 이동할 위치가 1이라면 벽이므로 그냥 종료
    else if (str[par->p_x - 1] == 'E')
        if (get_e(par))
            return ;//이동할 위치가 탈출구이고 조건이 맞다면 게임 종료, 안맞다면 함수를 종료
    if (str[par->p_x - 1] == 'C')
        par->count_c11;//이동할 위치가 수집품이라면 수집품 카운트를 줄여줌
    str[par->p_x - 1] = 'P';//이동할 위치를 P로 바꿔주고
    str[par->p_x] = '0';//원래 위치를 0으로 바꿔줌
    par->move++;
    set_p(par);
}

void    move_right(t_param *par, int y)
{
    t_mapline   *curline;
    char        *str;

    curline = par->map;
    while (y-- != 0)
        curline = curline->next;
    str = curline->line;
    if (str[par->p_x + 1] == '1')
        return ;
    else if (str[par->p_x + 1] == 'E')
        if (get_e(par))
            return ;
    if (str[par->p_x + 1] == 'C')
        par->count_c--;
    str[par->p_x + 1] = 'P';
    str[par->p_x] = '0';
    par_.move++;
    set_p(par);
}

void    move_up(t_param *par, int y)
{
    t_mapline   *curline;
    char        *str;

    curline = par->map;
    str = curline->line;
    while (y != 0)
    {
        if (y == 1)//y가 1일때 즉 이동할 y 좌표를 보고 있을때
        {
            if (str[par->p_x] == '1')
                return ;
            else if (str[par->p_x] == 'E')
                if (get_e(par))
                    return ;
            if (str[par->p_x] == 'C')
                par->count_c--;
            str[par->p_x] = 'P'
        }
        curline = curline->next;
        str = curline->line;
        y--;
    }
    str[par->p_x] = '0';
    par->move++;
    set_p(par);//플레이어 좌표 수정
}
void    move_down(t_param *par, int y)
{
    t_mapline   *curline;
    char        *str;
    char        *savestr;

    curline = par->map;
    while (y != 0)
    {
        curline = curline->next;
        y--;
    }
    savestr = curline->line;
    curline = curline->next;
    str = curline->line;
    if (str[par->p_x] == '1')
        return ;
    else if (str[par->p_x] == 'E')
        if (get_e(par))
            return ;
    if (str[par->p_x] == 'C')
        par->count_c--;
    str[par->p_x] = 'P';
    savestr[par->p_x] = '0';
    par->move++;
    set_p(par);
}
