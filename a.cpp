#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long modpow(long long a, long long n) {
    long long r = 1;

    while (n > 0) {
        if (n & 1) r = r * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }

    return r;
}

int main() {
    int X, Y;
    cin >> X >> Y;

    int N = X + Y;

    vector<long long> fact(N + 1), invfact(N + 1);

    fact[0] = 1;

    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[N] = modpow(fact[N], MOD - 2);

    for (int i = N; i >= 1; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    long long ans =
        fact[N] * invfact[X] % MOD * invfact[Y] % MOD;

    cout << ans << endl;
}
