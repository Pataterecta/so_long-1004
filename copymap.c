int copymap(t_param *par)
{
    char    *str;

    str = get_next_line(par->fd);
    while (str != NULL)
    {
        copyline(str, par);
        free(str);
        str = get_next_line(par->fd);
    }
    free (str);
    return (1);
}

int copyline(char *str, t_param *par)
{
    t_mapline   *line;
    t_mapline   *currline;

    currline = par->map;
        line = malloc(sizeof(t_mapline));
    if (!line)
    {
        freemap(par);
        return (0);
    }
    line->next = NULL;
    line->line = ft_strdup(str);
    if (par->map == NULL)
        par->map = line;
    else
    {
        while (currline->next != NULL)
            currline = currline->next;
        currline->next = line;
    }
    return (1);
}

void    freemap(t_param *par)
{
    t_mapline   *currline;
    t_mapline   *nextline;

    currline = par->map;
    while (currline)
    {
        nextline = currline->next;
        free (currline->line);
        free (currline);
        currline = nextline;
    }
    free (currline);
}

int check_map(t_param *par)
{
    int map_line;

    map_line = check_line_len(par);
    par->win_height = map_line * par->he;
    par->win_width = (ft_strlen(par->map->line) - 1) * par->wi;
    if (map_line)
        if (check_wall(par, map_line))
            if (check_map_char(par))
                return (1);
    return (0);
}

int check_line_len(t_param *par)
{
    t_mapline   *curline;
    int         before_line_len;
    int         curr_line_len;
    int         line_count;
    
}