#include <iostream>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        long long int arr[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long int max1_val = -1, max2_val = -1;
        long long int max1_idx = -1, max2_idx = -1;

        for (long long int i = 0; i < n; i++)
        {
            if (arr[i] > max1_val)
            {

                max2_val = max1_val;
                max2_idx = max1_idx;

                max1_val = arr[i];
                max1_idx = i;
            }
            else if (arr[i] > max2_val && arr[i] != max1_val)
            {
                max2_val = arr[i];
                max2_idx = i;
            }
        }

        if (max2_idx < max1_idx)
        {
            cout << max2_idx << " " << max1_idx << endl;
        }
        else
        {
            cout << max1_idx << " " << max2_idx << endl;
        }
    }

    return 0;
}
