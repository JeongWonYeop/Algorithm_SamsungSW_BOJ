#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
int N;
int board[20][20];
//priority_queue <B_I, vector <B_I>, compare1> que1;
//priority_queue <B_I, vector <B_I>, compare2> que2;
//priority_queue <B_I, vector <B_I>, compare3> que3;
int dx[4] = { 0,0,-1,1 }; //�¿����Ʒ�
int dy[4] = { -1,1,0,0 };
typedef struct board_info {
	int xx;
	int yy;
	int sizee;
}B_I;
/*
00  01
10  11
*/

struct compare0 { //������ ����
	bool operator()(B_I &a, B_I &c) {
		if (a.xx != c.xx)
			return a.xx > c.xx;
		if (a.yy != c.yy)
			return a.yy > c.yy;
		return a.sizee > c.sizee;
	}
};

struct compare1 { //������ ����
	bool operator()(B_I &a, B_I &c) {
		if (a.xx != c.xx)
			return a.xx > c.xx;
		if (a.yy != c.yy)
			return a.yy < c.yy;
		return a.sizee > c.sizee;
	}
};

struct compare2 {//���� ���� ����
	bool operator()(B_I &a, B_I &c) {
		if (a.xx != c.xx)
			return a.xx > c.xx;
		if (a.yy != c.yy)
			return a.yy > c.yy;
		return a.sizee > c.sizee;
	}
};

struct compare3 { // ���� �Ʒ��� ����
	bool operator()(B_I &a, B_I &c) {
		if (a.xx != c.xx)
			return a.xx < c.xx;
		if (a.yy != c.yy)
			return a.yy > c.yy;
		return a.sizee > c.sizee;
	}
};



priority_queue <B_I, vector <B_I>, compare0> que0; //����������
priority_queue <B_I, vector <B_I>, compare1> que1; //����������
priority_queue <B_I, vector <B_I>, compare2> que2; //�������
priority_queue <B_I, vector <B_I>, compare3> que3; //�Ʒ������

void tilt(int orient) {
	
}

void enter() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if(board[i][j] != 0){
				B_I foradd = { i,j,board[i][j] };
				que0.push(foradd);
				que1.push(foradd);
				que2.push(foradd);
				que3.push(foradd);
			}
		}
	}
}


void see() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void quesee() {
	cout << "[que0]����������" << endl;
	while (!que0.empty()) {
		cout << que0.top().xx <<" "<<que0.top().yy<<" "<<que0.top().sizee<< endl;
		que0.pop();
	}
	cout << "[que1]����������" << endl;
	while (!que1.empty()) {
		cout << que1.top().xx << " " << que1.top().yy << " " << que1.top().sizee << endl;
		que1.pop();
	}
	cout << "[que2]�������" << endl;
	while (!que2.empty()) {
		cout << que2.top().xx << " " << que2.top().yy << " " << que2.top().sizee << endl;
		que2.pop();
	}
	cout << "[que3]�Ʒ������" << endl;
	while (!que3.empty()) {
		cout << que3.top().xx << " " << que3.top().yy << " " << que3.top().sizee << endl;
		que3.pop();
	}

}
int main() {
	/*
	7.24
		������̴� ��� ,��ġ�� ��� �ʿ��� ���̴�.
			- ��ġ�� ����� ���� ���ǰ˻縦 ���ؼ� �ش� ������ ������ ������ ���� �ִ����� ���� �˻��Ѵ�.
			
	7.23
	�ڷᱸ�� : ��� ������ ��ġ�� ����ִ� ť.
		ť�� ������ Ÿ���� ����ü�� {int x,int y, int number}.
		

	����̱�(����) �Լ�
	��,��,��,�Ʒ�
		���� �浹 (�浹�� ������ �����, �浹�� ������ ����*2) 
			���� ���̰�
			���ڰ� ����
			���̿� 0������ ������
			�̹� �ѹ� ������ �������� �˻�. -> 
				�ƴ϶�� ����.== ����*2
		�׸������� ����� ä���ֱ�.

----------------------------
<��Ʈ��ŷ..? or �迭�� �����ϴ� ���..?(�޸������̼�,dp)>


	�ټ��� �̵��ؼ� �ִ�.DFS
	��				��				��				�Ʒ� O(2^10) => O(10^2)
��,��,��,�Ʒ�	��,��,��,�Ʒ�	��,��,��,�Ʒ�	��,��,��,�Ʒ�
	*/


	enter();
	quesee();
//	tilt(0); // 0:��,1:��,2:��,3:�Ʒ�
	system("pause");
}