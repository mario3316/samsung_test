#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int result[t];
    fill_n(result, t, 0);

    int temp = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> temp;
            if (temp % 2 == 1)
                result[i] += temp;
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }

    return 0;
}