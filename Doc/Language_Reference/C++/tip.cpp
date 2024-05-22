//>> tip 0 : include �� ������� ���� ���� ����
/*
���� ��� name1.h �� include �� �ÿ� ���� �� �ٿ�
#ifndef NAME1_H // ���� NAME1_H �̶�� ��ũ�ΰ� ���ǵǾ� ���� �ʴٸ�
#define NAME1_H  // NAME1_H �� ������ ���� �����϶�
~�ڵ� ����~
#endif // ifndef ����
�� �� ������ ����
// */

#ifndef TIP_CPP
#define TIP_CPP

//>> tip 1 : ������ �����ϱ� ������ ��
/*#include <bits/stdc++.h>
*/

#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
//>> tip 2 : /*���� / �ϳ��� �߰��ϸ� �ش� ������ �ּ��� �����ȴ�.
/*
int main() {
	return 0;
}
//*/

//>> tip 3 : �ڵ� ���� �ð� üũ
/*
class Timer {
//#include <iostream> #include <time.h> #include <vector> ���� �� ��밡��
private:
	vector<clock_t> start;
	vector<clock_t> end;
	vector<unsigned int> time;
public:
	Timer(int index) {
		cout << "[Timer Activate]" << endl;
		this->start = vector<clock_t>(index);
		this->end = vector<clock_t>(index);
		this->time = vector<unsigned int>(index);
	};
	~Timer() {
		cout << "[Timer Deactivate]" << endl;
	};
	void Start(int index) { 
		start[index] = clock(); 
		return;
	}
	void End(int index) { 
		end[index] = clock();
		time[index] = end[index] - start[index];
		return;
	}
	unsigned int Time(int index) {
		return time[index];
	}
	void Display(int index) {
		cout << "[TIME " << index << "] : " << time[index] << " ms" << endl;
	}

	void DisplayAll() {
		for (int i = 0; i < time.size(); i++) cout << "[TIME " << i << "] : " << time[i] << " ms" << endl;
	}
};

int main() {
	Timer* timer = new Timer(2);
	timer->Start(0);
	timer->Start(1);
	int sum = 0;  for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) sum += i * j;
	timer->End(0);
	for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) sum += i * j;
	timer->End(1);
	timer->Display(0);
	timer->DisplayAll();
	delete timer;
	return 0;
}
//*/

//>> tip 4 : sort ���� ��������, �������� ����
/*
bool compare(int prev, int next) { return prev > next; }

int main() {
	vector<int> v = { 3,5,4,9,8,6,7,2,1 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end());
	cout << "[�������� ���� v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end(),compare);
	cout << "[�������� ���� v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	
	return 0;
}
//*/

//>> tip 5 : transform ��ȯ
/*
int main() {
	vector<int> v = { 3,5,4,9,8,6,7,2,1 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	transform(v.begin(), v.end(), v.begin(), [](int n) {
		if (n > 5) return 0;
		else return n;
		}
	);
	cout << "[5 ���� 0���� ��ȯ v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	
	cout << endl;

	string s = "I am the one, don't weigh a ton";
	cout << "[s] : " << s << endl;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << "[�ҹ��� ��ȯ s] : " << s << endl;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << "[�빮�� ��ȯ s] : " << s << endl;

	return 0;
}
//*/

//>> tip 6 : unique �ߺ�����
/*
int main() {
	//vector<int> v = { 3,5,8,4,9,8,2,6,7,2,1,1 };
	vector<int> v = { 9, 9, 9, 9, 9, 9 };
	cout << "[v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	sort(v.begin(), v.end());
	cout << "[���� v] : "; for (auto& i : v) cout << i << ' '; cout << endl;

	v.resize(unique(v.begin(), v.end()) - v.begin());
	cout << "[�ߺ����� v] : "; for (auto& i : v) cout << i << ' '; cout << endl;
	return 0;
}
//*/

#endif