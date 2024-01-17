#include "header.h"

Q_20240117::Q_20240117() {

}
/*
�ڵ� ���� Ʈ���̴�
�ڵ� ó���ϱ�

���ڿ� code�� �־����ϴ�.
code�� �տ������� �����鼭 ���� ���ڰ� "1"�̸� mode�� �ٲߴϴ�. mode�� ���� code�� �о�鼭 ���ڿ� ret�� �������ϴ�.

mode�� 0�� 1�� ������, idx�� 0 ���� code�� ���� - 1 ���� 1�� Ű�������鼭 code[idx]�� ���� ���� ������ ���� �ൿ�մϴ�.

mode�� 0�� ��
code[idx]�� "1"�� �ƴϸ� idx�� ¦���� ���� ret�� �� �ڿ� code[idx]�� �߰��մϴ�.
code[idx]�� "1"�̸� mode�� 0���� 1�� �ٲߴϴ�.
mode�� 1�� ��
code[idx]�� "1"�� �ƴϸ� idx�� Ȧ���� ���� ret�� �� �ڿ� code[idx]�� �߰��մϴ�.
code[idx]�� "1"�̸� mode�� 1���� 0���� �ٲߴϴ�.
���ڿ� code�� ���� ������� ���ڿ� ret�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

��, ������ �� mode�� 0�̸�, return �Ϸ��� ret�� ���� �� ���ڿ��̶�� ��� "EMPTY"�� return �մϴ�.
*/


string Q_20240117::solutionQ1(string code) {
	int mode = 0;
	string result = "";

	for (int i = 0; i < code.length(); i++) {
		if (code[i] == '1') {
			mode = (mode + 1) % 2;
			continue;
		}

		if (i % 2 == mode) {
			result.append(1, code[i]);
		}
	}

	if (result.length()==0) {
		return "EMPTY";
	}

	return result;

}

/*
�ڵ� ���� Ʈ���̴�
���������� Ư���� �׸� ���ϱ�

�� ���� a, d�� ���̰� n�� boolean �迭 included�� �־����ϴ�.
ù°���� a, ������ d�� ������������ included[i]�� i + 1���� �ǹ��� ��,
�� ���������� 1�׺��� n�ױ��� included�� true�� �׵鸸 ���� ���� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
*/

int Q_20240117::solutionQ2(int a, int d, vector<bool> included) {
	int result = 0;

	for (int i = 0; i < included.size(); i++) {
		int curr = a + d * i;
		if (included[i]) {
			result += curr;
		}
	}


	return result;
}


/*
�ڵ� ���� Ʈ���̴�
�ֻ��� ���� 2
	
1���� 6���� ���ڰ� ���� �ֻ����� �� �� �ֽ��ϴ�. �� �ֻ����� ������ �� ���� ���ڸ� ���� a, b, c��� ���� �� ��� ������ ������ �����ϴ�.

�� ���ڰ� ��� �ٸ��ٸ� a + b + c ���� ����ϴ�.
�� ���� �� ��� �� ���ڴ� ���� ������ �ٸ� ���ڴ� �ٸ��ٸ� (a + b + c) �� (a^2 + b^2 + c^2 )���� ����ϴ�.
�� ���ڰ� ��� ���ٸ� (a + b + c) �� (a^2 + b^2 + c^2 ) �� (a^3 + b^3 + c^3 )���� ����ϴ�.
�� ���� a, b, c�� �Ű������� �־��� ��, ��� ������ return �ϴ� solution �Լ��� �ۼ��� �ּ���.
*/
int Q_20240117::solutionQ3(int a, int b, int c) {
	int result = a+b+c;

	if (b == c || a == b || a == c) {
		result *= a * a + b * b + c * c;
		if (a == b && a == c) {
			result *= a * a * a + b * b * b + c * c * c;
		}
	}
	return result;
}

/*
�ڵ� ���� Ʈ���̴�
���ҵ��� ���� ��

������ ��� ����Ʈ num_list�� �־��� ��, 
��� ���ҵ��� ���� ��� ���ҵ��� ���� �������� ������ 1�� ũ�� 0�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
num_list	result
[3, 4, 5, 2, 1]	1
[5, 7, 8, 3]	0
*/


int Q_20240117::solutionQ4(vector<int> num_list) {
	int sum = 0;
	int multi = 1;

	for (int i = 0; i < num_list.size(); i++) {
		sum += num_list[i];
		multi *= num_list[i];
	}

	return sum*sum > multi;
}


/*
* �ڵ� ���� Ʈ���̴�
�̾� ���� ��

������ ��� ����Ʈ num_list�� �־����ϴ�.
num_list�� Ȧ���� ������� �̾� ���� ���� ¦���� ������� �̾� ���� ���� ���� return�ϵ��� solution �Լ��� �ϼ����ּ���.
*/

int Q_20240117::solutionQ5(vector<int> num_list) {
	int even = 0;
	int odd = 0;

	for (int i = 0; i < num_list.size(); i++) {
		if (num_list[i] % 2 == 0) {
			even = (even * 10) + num_list[i];
		}
		else {
			odd = (odd * 10) + num_list[i];
		}
	}

	return even + odd;
}

/*
2022 KAKAO BLIND RECRUITMENT
�Ű� ��� �ޱ�

���Ի�� ������ �Խ��� �ҷ� �̿��ڸ� �Ű��ϰ� ó�� ����� ���Ϸ� �߼��ϴ� �ý����� �����Ϸ� �մϴ�. ������ �����Ϸ��� �ý����� ������ �����ϴ�.

�� ������ �� ���� �� ���� ������ �Ű��� �� �ֽ��ϴ�.
�Ű� Ƚ���� ������ �����ϴ�. ���� �ٸ� ������ ����ؼ� �Ű��� �� �ֽ��ϴ�.
�� ������ ���� �� �Ű��� ���� ������, ������ ������ ���� �Ű� Ƚ���� 1ȸ�� ó���˴ϴ�.
k�� �̻� �Ű�� ������ �Խ��� �̿��� �����Ǹ�, �ش� ������ �Ű��� ��� �������� ���� ����� ���Ϸ� �߼��մϴ�.
������ �Ű��� ��� ������ �����Ͽ� �������� �Ѳ����� �Խ��� �̿� ������ ��Ű�鼭 ���� ������ �߼��մϴ�.
������ ��ü ���� ����� ["muzi", "frodo", "apeach", "neo"]�̰�, k = 2(��, 2�� �̻� �Ű���ϸ� �̿� ����)�� ����� �����Դϴ�.

����	ID		������ �Ű��� ID		����
"muzi"		"frodo"				"muzi"��		"frodo"��	�Ű��߽��ϴ�.
"apeach"	"frodo"				"apeach"��	"frodo"��	�Ű��߽��ϴ�.
"frodo"		"neo"				"frodo"��	"neo"��		�Ű��߽��ϴ�.
"muzi"		"neo"				"muzi"��		"neo"��		�Ű��߽��ϴ�.
"apeach"	"muzi"				"apeach"��	"muzi"��		�Ű��߽��ϴ�.
�� �������� �Ű���� Ƚ���� ������ �����ϴ�.

���� ID		�Ű���� Ƚ��
"muzi"		1
"frodo"		2
"apeach"	0
"neo"		2
�� ���ÿ����� 2�� �̻� �Ű���� "frodo"�� "neo"�� �Խ��� �̿��� �����˴ϴ�. 
�̶�, �� �������� �Ű��� ���̵�� ������ ���̵� �����ϸ� ������ �����ϴ�.

���� ID		������ �Ű��� ID		������ ID
"muzi"		["frodo", "neo"]	["frodo", "neo"]
"frodo"		["neo"]				["neo"]
"apeach"	["muzi", "frodo"]	["frodo"]
"neo"		����					����
���� "muzi"�� ó�� ��� ������ 2ȸ, 
"frodo"�� "apeach"�� ���� ó�� ��� ������ 1ȸ �ް� �˴ϴ�.

�̿����� ID�� ��� ���ڿ� �迭 id_list, 
�� �̿��ڰ� �Ű��� �̿����� ID ������ ��� ���ڿ� �迭 report, 
���� ������ �Ǵ� �Ű� Ƚ�� k�� �Ű������� �־��� ��, 
�� �������� ó�� ��� ������ ���� Ƚ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

id_list								report																k	result
["muzi", "frodo", "apeach", "neo"]	["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]	2	[2,1,1,0]
["con", "ryan"]						["ryan con", "ryan con", "ryan con", "ryan con"]					3	[0,0]
*/


//�������� �� �� 
//������ ��� + �Ű��� ���
//�Ű��� ������ �̸����� ���� ������ ����Ʈ
//��� ������ ��� ����Ʈ
//������ ������ ����Ʈ
vector<int> solutionQ6(vector<string> id_list, vector<string> report, int k) {
	unordered_map<string, int> nameToIdx;
	unordered_map<int, vector<int>> reportPeople;
	unordered_set<int> banList;
	int* warningList = new int[id_list.size()];
	vector<int> getMailList;

	for (int i = 0; i < id_list.size(); i++) {
		nameToIdx.insert({ id_list[i], i });
		warningList[i] = 0;
		getMailList.push_back(0);
	}

	for (int i = 0; i < report.size(); i++) {
		int idx = report[i].find(" ");
		string user = report[i].substr(0, idx);
		string ban  = report[i].substr(idx + 1, report[i].size());
		int userNum = nameToIdx[user];
		int banNum  = nameToIdx[ban];

		if (reportPeople.count(banNum)==0) {
			reportPeople.emplace(banNum, vector<int>());
		}
		if (find(reportPeople[banNum].begin(), reportPeople[banNum].end(), userNum) == reportPeople[banNum].end()) {
			reportPeople[banNum].push_back(userNum);
			warningList[banNum] += 1;

			if (warningList[banNum] >= k) {
				banList.insert(banNum);
			}
		}

	}

	for (int banUser : banList) {
		for (int getMailUser : reportPeople[banUser]) {
			getMailList[getMailUser] += 1;
		}
	}

	return getMailList;

}