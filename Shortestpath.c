#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define M 10
#define N 10
void M416(int mat[M][N], int visited[M][N], int i, int j,int x, int y, int *ptr, int dist);
int min(int num1, int num2); 
bool isSafe(int mat[M][N], int visited[M][N], int x, int y);
bool isValid(int x, int y);
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y]) {
        return false;
    }
 
    return true;
}
 
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0) {
        return true;
    }
 
    return false;
}

 
void M416(int mat[M][N], int visited[M][N], int i, int j,int x, int y, int *ptr, int dist)
{
   
    if (i == x && j == y)
    {
        *ptr = min(dist, *ptr);
        return;
    }
 
    visited[i][j] = 1;
 
    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j)) {
        M416(mat, visited, i + 1, j, x, y, ptr, dist + 1);
    }
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1)) {
        M416(mat, visited, i, j + 1, x, y, ptr, dist + 1);
    }
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j)) {
        M416(mat, visited, i - 1, j, x, y, ptr, dist + 1);
    }
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1)) {
        M416(mat, visited, i, j - 1, x, y, ptr, dist + 1);
    }
    visited[i][j] = 0;
}
 
int main()
{
    int mat[M][N] =
    {
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };
   int a,b,c,d;
    int visited[M][N];
    memset(visited, 0, sizeof visited);
    int min_dist = INT_MAX;
    int *ptr;
    ptr=&min_dist;

    printf("enter initial location (a,b) as a b \n");
    scanf("%d %d",&a,&b);
    printf("enter final location (c,d) as  c d \n");
    scanf("%d %d",&c,&d);
    M416(mat, visited, a, b, c, d, ptr, 0);
 
    if (min_dist != INT_MAX)
    {
        printf("The shortest path from source to destination has length %d",min_dist);
    }
    else {
        printf("Destination can't be reached from a given source");
    }
 
    return 0;
}
