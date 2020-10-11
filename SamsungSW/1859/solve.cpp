#include <iostream>
#include <vector>
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
        int N;
        cin >> N;

        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        long long int result = 0;
        int max = v.back();
        for (int j = v.size() - 2; j >= 0; j--)
        {
            if (max > v[j])
                result += max - v[j];
            else
            {
                max = v[j];
            }
        }

        cout << "#" << i + 1 << " " << result << endl;
    }
}