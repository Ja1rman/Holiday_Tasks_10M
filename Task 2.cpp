#include <iostream>
#include <cmath>

using namespace std;

int* delete_annoying_primes(int* Array, int n)
{
    int* arr = new int[n + 1];

    int F = 1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;

        for (int k = 2; k <= sqrt(Array[i]); k++)
            if (Array[i] % k == 0)
                cnt++;

        if (cnt == 0 && Array[i] != 0)
        {
            int p = 0;

            for (int j = 1; j <= n; j++)
                if (Array[i] == Array[j])
                    p++;


            if (p == 1)
            {
                arr[F] = Array[i];
                F++;
            }

        }
        else
        {
            arr[F] = Array[i];
            F++;
        }
    }
    arr[0] = F - 1;

    return arr;
}

int main()
{
    int n;

    cin >> n;

    int* Array = new int[n + 1];

    Array[0] = n;

    for (int i = 1; i <= n; i++)
        cin >> Array[i];

    Array = delete_annoying_primes(Array, n);

    for (int i = 1; i <= Array[0]; i++)
        cout << Array[i] << " ";

    delete [] Array;

    return 0;
}
