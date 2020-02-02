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

int main() {

	pair<int, int> conditions[10];

	for (int i = 1; i <= 9; i++) {
		cin >> conditions[i].first >> conditions[i].second;
	}
	bool check[10];
	for (int i = 1; i <= 9; i++) {
		check[i] = false;
	}

	//i��° Ÿ�ڰ� 1���
	for (int i = 1; i <= 9; i++) {
		//j��° Ÿ�ڰ� ����������
		for (int j = 1; j <= 9; j++) {
			//k��° ������ �����̶�� �ڷ� �Ѿ��.
			bool flag = true;
			for (int k = 1; k <= 9; k++) {
				int judge = conditions[k].first;
				int num = conditions[k].second;
				if (j == k) {//������ ���ϰ� ���� ��
					judge = 1 - judge;
					if (judge == 1 && num != i) {//���� ����� 1����� �ƴϹǷ� ���
						flag = false;
						break;
					}

					if (judge == 0 && num == i) {//�ƴ϶�� ����� 1����̹Ƿ� ���
						flag = false;
						break;
					}
				} else {//���� ���ϰ� ���� ��
					if (judge == 1 && num != i) {//���� ����� 1����� �ƴϹǷ� ���
						flag = false;
						break;
					}

					if (judge == 0 && num == i) {//�ƴ϶�� ����� 1����̹Ƿ� ���
						flag = false;
						break;
					}

				}

			}

			if (flag) {
				check[i] = true;
			}

		}

	}

	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		if (check[i]) {
			cnt++;
		}
	}

	if (cnt == 1) {
		for (int i = 1; i <= 9; i++) {
			if (check[i]) {
				cout << i;
				break;
			}
		}
	} else {
		cout << -1;
	}


	return 0;
}