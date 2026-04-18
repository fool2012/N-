#include <iostream>
using namespace std;
bool col[15], up[25], dw[25];
int n, pos[15];
long long ans;

void dfs(int r)
{
	if (r > n)
	{
		cout << ++ans << '\n';
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (pos[i] == j) cout << 'Q'; 
				else cout << '.';
			}
			cout << '\n';
		}
		return;
	}
	for (int c = 1; c <= n; ++c)
	{
		int u = r - c + n;
		int d = r + c;
		if (col[c] == 0 && up[u] == 0 && dw[d] == 0)
		{
			pos[r] = c;
			col[c] = up[u] = dw[d] = 1;
			dfs(r + 1);
			col[c] = up[u] = dw[d] = 0;
		}
	}
}

int main()
{
	cin >> n;
	dfs(1);
	cout <<"total:"<< ans;
}
