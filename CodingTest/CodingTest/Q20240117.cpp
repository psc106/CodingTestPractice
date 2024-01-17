#include "header.h"

Q_20240117::Q_20240117() {

}
/*
코딩 기초 트레이닝
코드 처리하기

문자열 code가 주어집니다.
code를 앞에서부터 읽으면서 만약 문자가 "1"이면 mode를 바꿉니다. mode에 따라 code를 읽어가면서 문자열 ret을 만들어냅니다.

mode는 0과 1이 있으며, idx를 0 부터 code의 길이 - 1 까지 1씩 키워나가면서 code[idx]의 값에 따라 다음과 같이 행동합니다.

mode가 0일 때
code[idx]가 "1"이 아니면 idx가 짝수일 때만 ret의 맨 뒤에 code[idx]를 추가합니다.
code[idx]가 "1"이면 mode를 0에서 1로 바꿉니다.
mode가 1일 때
code[idx]가 "1"이 아니면 idx가 홀수일 때만 ret의 맨 뒤에 code[idx]를 추가합니다.
code[idx]가 "1"이면 mode를 1에서 0으로 바꿉니다.
문자열 code를 통해 만들어진 문자열 ret를 return 하는 solution 함수를 완성해 주세요.

단, 시작할 때 mode는 0이며, return 하려는 ret가 만약 빈 문자열이라면 대신 "EMPTY"를 return 합니다.
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
코딩 기초 트레이닝
등차수열의 특정한 항만 더하기

두 정수 a, d와 길이가 n인 boolean 배열 included가 주어집니다.
첫째항이 a, 공차가 d인 등차수열에서 included[i]가 i + 1항을 의미할 때,
이 등차수열의 1항부터 n항까지 included가 true인 항들만 더한 값을 return 하는 solution 함수를 작성해 주세요.
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
코딩 기초 트레이닝
주사위 게임 2
	
1부터 6까지 숫자가 적힌 주사위가 세 개 있습니다. 세 주사위를 굴렸을 때 나온 숫자를 각각 a, b, c라고 했을 때 얻는 점수는 다음과 같습니다.

세 숫자가 모두 다르다면 a + b + c 점을 얻습니다.
세 숫자 중 어느 두 숫자는 같고 나머지 다른 숫자는 다르다면 (a + b + c) × (a^2 + b^2 + c^2 )점을 얻습니다.
세 숫자가 모두 같다면 (a + b + c) × (a^2 + b^2 + c^2 ) × (a^3 + b^3 + c^3 )점을 얻습니다.
세 정수 a, b, c가 매개변수로 주어질 때, 얻는 점수를 return 하는 solution 함수를 작성해 주세요.
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
코딩 기초 트레이닝
원소들의 곱과 합

정수가 담긴 리스트 num_list가 주어질 때, 
모든 원소들의 곱이 모든 원소들의 합의 제곱보다 작으면 1을 크면 0을 return하도록 solution 함수를 완성해주세요.
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
* 코딩 기초 트레이닝
이어 붙인 수

정수가 담긴 리스트 num_list가 주어집니다.
num_list의 홀수만 순서대로 이어 붙인 수와 짝수만 순서대로 이어 붙인 수의 합을 return하도록 solution 함수를 완성해주세요.
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
신고 결과 받기

신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.

각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.
다음은 전체 유저 목록이 ["muzi", "frodo", "apeach", "neo"]이고, k = 2(즉, 2번 이상 신고당하면 이용 정지)인 경우의 예시입니다.

유저	ID		유저가 신고한 ID		설명
"muzi"		"frodo"				"muzi"가		"frodo"를	신고했습니다.
"apeach"	"frodo"				"apeach"가	"frodo"를	신고했습니다.
"frodo"		"neo"				"frodo"가	"neo"를		신고했습니다.
"muzi"		"neo"				"muzi"가		"neo"를		신고했습니다.
"apeach"	"muzi"				"apeach"가	"muzi"를		신고했습니다.
각 유저별로 신고당한 횟수는 다음과 같습니다.

유저 ID		신고당한 횟수
"muzi"		1
"frodo"		2
"apeach"	0
"neo"		2
위 예시에서는 2번 이상 신고당한 "frodo"와 "neo"의 게시판 이용이 정지됩니다. 
이때, 각 유저별로 신고한 아이디와 정지된 아이디를 정리하면 다음과 같습니다.

유저 ID		유저가 신고한 ID		정지된 ID
"muzi"		["frodo", "neo"]	["frodo", "neo"]
"frodo"		["neo"]				["neo"]
"apeach"	["muzi", "frodo"]	["frodo"]
"neo"		없음					없음
따라서 "muzi"는 처리 결과 메일을 2회, 
"frodo"와 "apeach"는 각각 처리 결과 메일을 1회 받게 됩니다.

이용자의 ID가 담긴 문자열 배열 id_list, 
각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report, 
정지 기준이 되는 신고 횟수 k가 매개변수로 주어질 때, 
각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.

id_list								report																k	result
["muzi", "frodo", "apeach", "neo"]	["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]	2	[2,1,1,0]
["con", "ryan"]						["ryan con", "ryan con", "ryan con", "ryan con"]					3	[0,0]
*/


//마지막에 쓸 거 
//정지된 사람 + 신고한 사람
//신고한 유저의 이름으로 접근 가능한 리스트
//모든 유저의 경고 리스트
//정지할 유저의 리스트
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