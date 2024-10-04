
int is_all_ones(char *line)
{
    int i;
    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
    {
        if (line[i] != '1')
        {    
            return (1);
        }
        i++;
    }
    return (0);
}

int has_boundary_ones(char *line, int line_length)
{
    if (line[0] == '1' && line[line_length - 1] == '1')
        return (0);
    else
        return (1);
}

int get_line_length(char *result, int *index)
{
    int length;

    length = 0;
    while (result[*index] != '\n' && result[*index] != '\0')
    {
        length++;
        (*index)++;
    }
    if (result[* index] == '\n')
    {
        (*index)++;
    }
    return (length);
}

int check_line_length_consistency(char *result, int line_length)
{
    int i;
    int current_line_length;

    i = 0;
    while (result[i] != '\0')
    {
        current_line_length = get_line_length(result, &i);
        if (current_line_length != line_length)
            return (1);
    }
    return (0);
}

int check_first_line(char *result, int *index, int *line_length)
{
    *line_length = get_line_length(result, index);
    if (line[0] == '1' && line[length  - 1] == '1')
        return (0);
    else
        return (1);
}

int check_middle_lines(char *result, int *index, int line_length)
{
    int current_line_length;
    while (result[*index] != '\0')
    {
        int line_start = *index;
        current_line_length = get_line_length(result, index);
        if (current_line_length != line_length)
            return (1);
        if (has_boundary_ones(&result[line_start], current_line_length) = 1)
            return (1);
    }
    return (0);
}

int check_last_line(char *result, int index, int line_length)
{
    if (is_all_ones(&result[index - line_length], line_length) = 1)
        return (1);
    else
        return (0);
}

int check_wall_boundary(char *result)
{
    int index;
    int line_length;

    index = 0;
    line_length = 0;
    if (result == NULL || result[0] == '\0')//input is NULL or empty
        return (1);
    if (check_first_line(result, &index, &line_length) = 1)
    {//오류메세지들 적기
        return (1);
    }
    if (check_middle_lines(result, &index, line_length) = 1)
    {    
        return (1);
    }
    if (check_last_line(result, index, line_length) = 1)
    {    
        return (1);
    }
    return (0);
}