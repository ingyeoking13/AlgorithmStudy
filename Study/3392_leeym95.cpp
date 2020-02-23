#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define MOD 1000000007
using namespace std;

struct waterTank {
	int y, width, isStart;

	bool operator<(const waterTank o) {
		return y < o.y;
	}
};
int N, M;
vector<waterTank> vt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int s, h, w, d;
		cin >> s >> h >> w >> d;
		vt.push_back({ s, w * d, 1 }); //���� ����
		vt.push_back({ s + h, w * d, 0 }); //������ ����
	}
	cin >> M; //��ü ���� ����
	sort(vt.begin(), vt.end());


	int sum = 0; //���� ���� ä�� ����
	int prevY = vt[0].y;
	int sumW = vt[0].width; //���� ��ȿ�� ������ ������ ��
	int ans = prevY; //�������� ����� ����
	bool chk = true;
	for (int i = 1; i < vt.size(); ++i)
	{
		int y = vt[i].y;
		int w = vt[i].width;
		int diff = y - prevY;

		if (sum + diff * sumW >= M) {
			chk = false;
			break;
		}
		ans += diff;
		sum += diff * sumW;
		prevY = y;
		if (vt[i].isStart) sumW += w; //������ �߰��Ǵ� �����̸�
		else sumW -= w; //������ ������ �����̸�
	}
	cout << fixed;
	cout.precision(2);

	if (!chk) {
		double left = M - sum;
		left /= sumW;
		cout << ans + left << '\n';
	} else {
		cout << "OVERFLOW" << '\n';
	}
	return 0;
}