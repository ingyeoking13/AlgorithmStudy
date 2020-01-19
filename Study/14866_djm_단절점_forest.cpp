#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[300005];

int d[300005], e = 1;
int cnt[300005];

//�������� ����� �����ε� ���ΰ� �ʿ���
int dfs(int i)
{
	d[i] = e;
	int ret = e++;

	for (int j : adj[i])
	{
		if (!d[j])
		{
			int o = dfs(j);
			if (o >= d[i])
				cnt[i]++;
			ret = min(ret, o);
		} else
			ret = min(ret, d[j]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cnt[1]--;
	ll ans = 0;

	//n���� ����, k���� ������Ʈ�� �� ������ ���� n - k�̸� ������Ʈ
	//n���� ����, �ϳ��� ������Ʈ, ������ ���� n - 1���̸� Ʈ��
	//m���� ����(��ü ���� ��)���� i��° ������ ���� ���� �� ���� (��ü ���� - 1) - (cnt[i] + 1) �� �Ǿ�� �Ѵ�.
	//ó���� ������Ʈ 1��
	//i��° ������ ����� cnt[i] + 1���� ������Ʈ
	//i��° ������ ����� ������ ���� n - 1��
	//(n - 1) - (cnt[i] + 1) == m - (int)adj[i].size()
	for (i = 1; i <= n; i++)
		if (m - (int)adj[i].size() == n - cnt[i] - 2)
			ans += i;
	cout << ans;
}