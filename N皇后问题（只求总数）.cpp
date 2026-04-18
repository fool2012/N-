#include <iostream>
using namespace std;

int n;
long long ans;
int all;

void dfs(int row, int col, int ld, int rd) {
    if (row == n) {
        ++ans;
        return;
    }
    int valid = all & ~(col | ld | rd);
    while (valid) {
        int pos = valid & -valid;
        valid ^= pos;
        dfs(row + 1, col | pos, (ld | pos) << 1, (rd | pos) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    all = (1 << n) - 1;

    int half = (n + 1) / 2;          // 左半部分列数
    for (int c = 0; c < half; ++c) {
        int pos = 1 << c;
        dfs(1, pos, pos << 1, pos >> 1);
    }
    ans *= 2;                         // 对称翻倍
    if (n % 2 == 1) {                 // 若 N 为奇数，中间列多算了一次，需要扣除
        int pos = 1 << (n / 2);
        long long mid = 0;
        // 临时计算中间列的解数
        long long old = ans;
        ans = 0;
        dfs(1, pos, pos << 1, pos >> 1);
        mid = ans;
        ans = old * 2 - mid;
    }
    cout << "total: " << ans << '\n';
    return 0;
}
