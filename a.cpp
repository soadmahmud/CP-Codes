#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, unordered_map<int, int>> memo;

int count_fibonacci_like_sequences(long long n, int k) {
    if (k == 1) {
        return (n == 0) ? 1 : 0;
    }
    if (k == 2) {
        return (n >= 0) ? 1 : 0;
    }
    if (memo[n][k] != 0) {
        return memo[n][k];
    }

    int count = 0;
    long long a = 0, b = 1;
    while (true) {
        long long c = a + b;
        if (c > n) {
            break;
        }
        if ((n - c) % (k - 1) == 0) {
            count += count_fibonacci_like_sequences((n - c) / (k - 1), k - 1);
        }
        a = b;
        b = c;
    }

    memo[n][k] = count;
    return count;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        int k;
        cin >> n >> k;
        cout << count_fibonacci_like_sequences(n, k) << endl;
    }

    return 0;
}
