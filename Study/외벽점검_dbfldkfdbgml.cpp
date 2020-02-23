#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <sstream>

//namespaces
using namespace std;

//global variables

int comparator(int a, int b) {
	if (a > b) {
		return 1;
	} else if (a < b) {
		return -1;
	} else {
		return 0;
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {

	if (weak.size() == 0) {
		return 0;
	}

	//answer�� ��� ������ ���� �� ����.
	int answer = (int)dist.size() + 1;

	//������ 2���� �迭�� ���� ������ �����Ѵ�.
	int N = n * 2;
	bool * visited = new bool[N];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < weak.size(); i++) {
		visited[weak[i]] = true;
		visited[weak[i] + n] = true;
	}

	//next permutation�� �Ἥ ��� ����� ���� �������� ������ �� �ȴ�
	//dist 3, 6, 4
	//weak 1, 7, 10, 14, 15, 18
	//next permutation�� ���� ���� �� �� sort�Ѵ�
	sort(dist.begin(), dist.end());
	//do while�� �Ἥ ó�� �� ���� �ǰ� ���ش�.
	do {
		for (int i = 0; i < n; i++) {
			int now = i;
			int end = now + n;
			int index = 0;
			int cnt = 0;
			if (visited[now] == false) {
				continue;
			}
			while (now < end) {
				//���� ���� �ƴϸ� �Ѿ��
				if (visited[now] == false) {
					now++;
					continue;
				}
				//����� ������ �����Ѵ�
				if (index >= dist.size()) {
					break;
				}
				//����� �� �� ���� ��ŭ ���� �ܺ��� �����Ѵ�
				for (int j = 0; (j <= dist[index]) & (now < end); j++, now++) {
					if (visited[now]) {
						cnt++;
					}
				}
				//���� ������� �ѱ��
				index++;

			}
			//������ ���� ���� �ܺ��� ���� ���ٸ�
			if (cnt == weak.size()) {
				answer = min(answer, index);
			}
		}
	} while (next_permutation(dist.begin(), dist.end()));

	//������ �ִ� �� ������ ���� �ʾҴٸ�
	if (answer == dist.size() + 1) {
		return -1;
	}

	return answer;
}

//main method
int main() {
	//speedy reading option
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 50;
	vector<int> weak(1);
	weak[0] = 1;
	/*weak[1] = 3;
	weak[2] = 10;
	weak[3] = 16;
	weak[4] = 22;
	weak[5] = 25;*/

	vector<int> dist(1);
	dist[0] = 6;
	/*dist[1] = 3;
	dist[2] = 2;
	dist[3] = 1;*/
	/*dist[1] = 1;
	dist[2] = 1;
	dist[3] = 1;
	dist[4] = 100;
	*/
	cout << solution(n, weak, dist) << "\n";


	//��������� �ݵ�� 0�� �����ؾ��մϴ�.
	return 0;
}
