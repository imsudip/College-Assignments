
#include <iostream>
using namespace std;
void solve(int arr[][100], int m, int n, int i, int j, int height, int cost, int *maxH, int *maxC)
{
    if (i < 0 || j < 0 || i >= m || j >= n || arr[i][j] == 0)
    {
        return;
    }
    if (height > *maxH)
    {
        *maxH = height;
        *maxC = cost;
    }
    else if (height == *maxH && cost < *maxC)
    {
        *maxC = cost;
    }
    arr[i][j] = 0;
    solve(arr, m, n, i + 1, j, height + 1, cost + 4, maxH, maxC);
    solve(arr, m, n, i - 1, j, height - 1, cost + 1, maxH, maxC);
    solve(arr, m, n, i, j + 1, height, cost + 2, maxH, maxC);
    solve(arr, m, n, i, j - 1, height, cost + 2, maxH, maxC);
    arr[i][j] = 1;
}
int main()
{
    int m, n;
    cout << "enter the number of rows and columns of the matrix: ";
    cin >> m >> n;
    int arr[100][100];
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // print the matrix
    cout << "the matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int max = 0;
    int cost = 0;
    solve(arr, m, n, 0, 0, 0, 0, &max, &cost);
    cout << "maximum reachable height: " << max << endl;
    cout << "minimum cost to reach the maximum reachable height: " << cost << endl;
    return 0;
}
