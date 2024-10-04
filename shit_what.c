typedef struct s_map_check
{
    int x; //맵의 가로 길이
    int y; //맵의 세로 길이
    int *dfs_map;
    int dfs_c;
    int dfs_e;
} t_map_check;

#include <stdio.h>

void    print_1d_as_2d(int *arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i * cols + j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = 3, cols = 4;
    int arr[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int player = 5; //2d (1,1)

    int up = player - cols;
    int down = player + cols;
    int left = player - 1;
    int right = player + 1;

    print_1d_as_2d(arr, rows, cols);
}