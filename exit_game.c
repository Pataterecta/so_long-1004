#include "so_long.h"

int esc_press(int keycode, t_param *par)
{
    if (keycode == KEY_ESC)
    {
        printf ("press ESC button plz");
        //예시에선 여기서 프리함
        exist(0);
    }
    return (0);
}
int redbut(t_param *par)
{
    printf ("press red button");
    //예시에선 여기서 프리함
    exit (0);
    return (0);
}