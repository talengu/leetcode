#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> //malloc need

void print_map(int **map, int m, int n)
{
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}
#define NO false
#define MARK true
bool mdfs(char **board, int x, int y, bool **map, char *word, int offset,int len)
{

    if (board[x - 1][y - 1] != word[offset])
    {
        return false;
    }
    else if (offset == len)
    {
        return true;
    }
    offset = offset + 1;

    map[x][y] = MARK;
    // printf("----mdfs %d %d %c ----offset:%d %d\n",x,y,word[offset],offset,strlen(word) - 1);
    // print_map(map,4,3);
    if (!map[x - 1][y])
    {
        if(mdfs(board, x - 1, y, map, word, offset,len)) 
        return true;
    }
    if (!map[x + 1][y])
    {
        if(mdfs(board, x + 1, y, map, word, offset,len))
        return true;
    }
    if (!map[x][y - 1])
    {
        if(mdfs(board, x, y - 1, map, word, offset,len))
        return true;
    }
    if (!map[x][y + 1])
    {
        if(mdfs(board, x, y + 1, map, word, offset,len))
        return true;
    }
    map[x][y] = NO;
    // printf("--bb--mdfs %d %d %c\n",x,y,word[offset]);
    // print_map(map,4,3);
  
    return false;
}
bool tansuo(char **board, int m, int n, char *word)
{
    bool **map = malloc(sizeof(bool *) * (m + 2));
    for (int i = 0; i <= m + 1; i++)
    {
        map[i] = malloc(sizeof(bool) * (n + 2));
        memset(map[i], NO, sizeof(bool) * (n + 2));
    }
    // init map
    for (int i = 0; i <= m + 1; i++)
    {
        map[i][0] = MARK;
        map[i][n + 1] = MARK;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        map[0][i] = MARK;
        map[m + 1][i] = MARK;
    }
    // print_map(map,m,n);
    int len=strlen(word) - 1;
    for (int x = 1; x <= m; x++)
        for (int y = 1; y <= n; y++)
        {
            
            if (mdfs(board, x, y, map, word, 0,len))
                return true;
        }
    return false;
}



bool exist(char **board, int boardSize, int *boardColSize, char *word)
{

    return tansuo(board, boardSize, *boardColSize, word);
}
int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);

    char **board = NULL;
    char word[15];
    board = (char **)malloc(m * sizeof(char *));
    for (int i = 0; i < m; i++)
    {
        board[i] = (char *)malloc(n);
        scanf("%s", board[i]);
    }
    printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for(int j=0;j<strlen(board[i]);j++)
        printf("%c ", board[i][j]);

        printf("\n");
    }
    scanf("%s", word);
    printf("search:%s\n", word);

    printf("---------------------\n");
    // exist
    exist(board, m, &n, word) ? printf("true\n") : printf("false\n");
    printf("---------------------\n");
    // free
    // for (int i = 0; i < m; i++)
    //     free(board[i]);
    // free(board);

    return 0;
}
