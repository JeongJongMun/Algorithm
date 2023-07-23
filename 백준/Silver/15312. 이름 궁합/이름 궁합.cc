#include <iostream>
#include <cmath>
using namespace std;

int alphabet[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int arr[4000];
string n1, n2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n1 >> n2;

    int j = 0;
    for (int i = 0; i < n1.size() * 2; i += 2) 
    {
        arr[i] = alphabet[n1[j] - 'A'];
        arr[i + 1] = alphabet[n2[j] - 'A'];
        j++;
    }

    for (int i = 0; i < n1.size() * 2 - 2; i++) 
    {
        for (int j = 0; j < n1.size() * 2; j++) 
        {
            if (arr[j] + arr[j + 1] >= 10) arr[j] = arr[j] + arr[j + 1] - 10;
            else arr[j] = arr[j] + arr[j + 1];
        }
    }

    cout << arr[0] << arr[1];

    return 0;
}
