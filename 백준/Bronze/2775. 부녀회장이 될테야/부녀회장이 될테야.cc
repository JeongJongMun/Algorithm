#include <iostream>

using namespace std;

int test_case, k, n; // k층 n호

int cal(int k, int n) {
    if (k == 0) return n;
    if (n == 1) return 1;
    return (cal(k-1, n) + cal(k, n-1));
}

int main()
{
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++) {
        cin >> k >> n;
        cout << cal(k,n) << endl;
    }

    return 0;
}
