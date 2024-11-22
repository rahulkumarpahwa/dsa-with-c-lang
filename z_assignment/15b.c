#include <stdio.h>
#include <stdlib.h>

// graph implementation:
// structure of the Graph G:
//    0---1
//    | \ |
//    3---2
//     \ /
//      4
//     / \
//    5   6

int vistedArray[7] = {0, 0, 0, 0, 0, 0, 0}; // global variable
int AdjacentMatrix[7][7] = {
    // global variable
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int i)
{
    vistedArray[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < 7; j++)
    {
        if (AdjacentMatrix[i][j] == 1 && !vistedArray[j])
        {
            DFS(j);
        }
    }
}

void main()
{
    // DFS:
    int k = 0; // source Node
    DFS(k);
}