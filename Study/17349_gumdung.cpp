#include<bits/stdc++.h>

using namespace std;

struct info {
	int a, b;
};

set<int> ans;
vector<info> player;
int state[2][10];
void search();
void clear();

//����
//1. �ݵ�� �������� �ϰ� �ִ� ����� 1���̾�� �ȴ�
//2. 1����� �ݵ�� 1�� �����ؾ� �Ѵ�.
//3. 1����� ��Ȯ�� ��� Ÿ������ �˼� �־�� �Ѵ�.

int main()
{
	int a, b;
	int cur = -1;
	for (int i = 0; i < 9; i++) {
		cin >> a >> b;
		player.push_back({ a, b });
	}
	for (int i = 0; i < 9; i++) {
		int check = 0;
		//���� ����� �������� �ϰ� �ִٰ� ����
		//��,1 A ��� �������� �� ����� �������� �ϰ� ������
		//[0][A] �� ���� üũ
		if (player[i].a == 0)
			state[1][player[i].b] = 1;
		else
			state[0][player[i].b] = 1;
		//�������� �ؾߵǴ� ����� �ݵ�� 1���̾�� �Ǵ�
		//������ ������� ���� ���� ����.
		//1 A ��� �������� 
		//[1][A] �� ���� üũ
		for (int j = 0; j < 9; j++) {
			int now = player[j].b;
			if (i == j)continue;
			if (player[j].a == 0)
				state[0][now] = 1;
			else
				state[1][now] = 1;
			//����1
				//���� ����� ����ٸ� ������ ���� x 
			if (state[0][now] == 1 && state[1][now] == 1)goto t;
		}
		search();
	t:
		//state �迭 �ʱ�ȭ
		clear();
	}
	//����3
		//��Ȯ�� 1����� ������ �� ���ٸ� ����x
		//ex)
			//0 1
			//1 1
			//0 2
			//0 3
			//0 4
			//0 5
			//0 6
			//0 7
			//0 7
		//1�� Ÿ�ڰ� �������� �� ��� => 1��Ÿ�ڰ� 1���
		//2�� Ÿ�ڰ� �������� �� ���
			// => 8,9 �� Ÿ�ڰ� 1����� �� ���� ����
		//��, 1����� ��Ȯ�� ���� ���� ����.
	if (ans.size() != 1)
		cout << -1;
	else {
		auto u = ans.begin();
		cout << *u;
	}
}
void search()
{
	int cnt = 0;
	int ret = -1;
	for (int i = 1; i < 10; i++)
	{
		if (state[1][i] == 1)
		{
			cnt++;
			ret = i;
		}
	}
	//����2
		//1����� �������� ��Ÿ���ٸ� ����x
	if (cnt > 1)return;
	else if (cnt == 1) {
		ans.insert(ret);
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (state[0][i] == 0)
			ans.insert(i);
	}
	return;
}
void clear()
{
	for (int i = 0; i < 10; i++)
		state[0][i] = state[1][i] = 0;
}