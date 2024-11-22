#include <stdio.h>
#include <stdlib.h>

int vistedArray[] = {0, 0, 0, 0, 0, 0, 0}; // global variable.
int AdjacentMatrix[7][7] = {
    // global variable.
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int i) // i is the source node
{
    vistedArray[i] = 1; // setting the source node as visted.
    printf("%d ", i);
    for (int j = 0; j < 7; j++)
    {

        if (AdjacentMatrix[i][j] == 1 &&
            !vistedArray[j]) // or visitedArray[j] == 0
        {
            DFS(j);
        }
    }
}

void main()
{
    // structure of the Graph G:
    //    0---1
    //    | \ |
    //    3---2
    //     \ /
    //      4
    //     / \
    //     5  6

    int i = 1; // source node from where we start the traversal.
    DFS(i);
}
