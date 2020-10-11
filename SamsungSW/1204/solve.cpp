#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int array[101] = {
            0,
        };
        int temp;
        int T_num;
        cin >> T_num;

        for (int j = 0; j < 1000; j++)
        {
            cin >> temp;
            array[temp]++;
        }

        int result = 0;
        int max = 0;
        for (int j = 0; j < 100; j++)
        {
            if (max <= array[j])
            {
                max = array[j];
                result = j;
            }
        }

        cout << "#" << T_num << " " << result << endl;
    }
}