#include <iostream>

using namespace std;

void put_snake(int** Snake, int n, int m)
{
    int x, y, k = 0;

    x = 0;
    y = m;

    int max_x = n;
    int max_y = m;
    int min_x = 0;
    int min_y = 0;
    int nm = n * m;

    while (k <= nm)
    {
        for (; y >= min_y && k <= nm; y--, k++)
            Snake[x][y] = k;

        y++;
        x++;
        min_y++;

        for (; x < max_x && k <= nm; x++, k++)
            Snake[x][y] = k;

        x--;
        y++;
        min_x++;

        for (; y < max_y && k <= nm; y++, k++)
            Snake[x][y] = k;

        y--;
        x--;
        max_y--;

        for (; x >= min_x && k <= nm; x--, k++)
            Snake[x][y] = k;

        x++;
        y--;
        max_x--;



    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << '\t' << Snake[i][j];

        cout << endl;
    }

}

int main()
{
    int n, m;

    cin >> n >> m;

    int **Snake= new int* [n];

    for (int i = 0; i < n; i++)
        Snake[i] = new int [m];

    put_snake((int**)Snake, n, m);

    for (int i = 0; i < m; i++)
        delete [] Snake[i];

    delete [] Snake;

  return 0;
}
