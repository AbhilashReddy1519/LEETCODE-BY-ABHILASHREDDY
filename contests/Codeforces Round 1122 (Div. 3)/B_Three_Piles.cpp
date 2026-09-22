#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a >= b) {
            cout << a - b + c << '\n';
        } else {
            long long d = b - a;
            cout << max(d, c - d) << '\n';
        }
    }

    return 0;
}