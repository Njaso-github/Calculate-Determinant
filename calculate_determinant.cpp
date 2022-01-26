#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
long double D[N][N];

int ftr(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * ftr(n - 1);
}

int r_odr(string odr) {
    int cnt = 0;
    for (int i = 0; i < (int) odr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (odr[j] > odr[i]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cout << "Input the dimension of determinant" << endl;
    int n;
    cin >> n;
    string odr = "0";
    for (int i = 1; i <= n; i++) {
        odr += (char) (i + '0');
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> D[i][j];
        }
    }
    long double ans = 0;
    for (int k = 0; k < ftr(n); k++) {
        next_permutation(odr.begin() + 1, odr.end());
        long double cnt = 1.0;
        for (int i = 1; i <= n; i++) {
            cnt *= D[i][(int) odr[i] - '0'];
        }
        if (r_odr(odr) % 2 == 1) { cnt *= -1.0; }
        ans += cnt;
    }
    cout << "Answer: " << ans << endl;
    return 0;
}