#include "header.h"

Q_20240118::Q_20240118() {

}


/*
코딩 기초 트레이닝
마지막 두 원소

정수 리스트 num_list가 주어질 때,
마지막 원소가 그전 원소보다 크면 마지막 원소에서 그전 원소를 뺀 값을 
마지막 원소가 그전 원소보다 크지 않다면 마지막 원소를 두 배한 값을 
추가하여 return하도록 solution 함수를 완성해주세요.
*/

vector<int> Q_20240118::solutionQ1(vector<int> num_list) {

    int last = num_list[num_list.size() - 1];
    int pre = num_list[num_list.size() - 2];

    if (last > pre) {
        num_list.push_back(last - pre);
    }
    else {
        num_list.push_back(last * 2);
    }

    return num_list;
}

/*
코딩 기초 트레이닝
수 조작하기 1

정수 n과 문자열 control이 주어집니다. control은 "w", "a", "s", "d"의 4개의 문자로 이루어져 있으며,
control의 앞에서부터 순서대로 문자에 따라 n의 값을 바꿉니다.

"w" : n이 1 커집니다.
"s" : n이 1 작아집니다.
"d" : n이 10 커집니다.
"a" : n이 10 작아집니다.
위 규칙에 따라 n을 바꿨을 때 가장 마지막에 나오는 n의 값을 return 하는 solution 함수를 완성해 주세요.
*/


int Q_20240118::solutionQ2(int n, string control) {

    int result = n;
    for (auto operate : control) {
        switch (operate)
        {
        case 'w' :
            result += 1;
            break;
        case 's':
            result -= 1;
            break;
        case 'd':
            result += 10;
            break;
        case 'a':
            result -= 10;
            break;
        }
    }
    return result;
}

/*
코딩 기초 트레이닝
수 조작하기 2

정수 배열 numLog가 주어집니다. 
처음에 numLog[0]에서 부터 시작해 "w", "a", "s", "d"로 이루어진 문자열을 입력으로 받아 순서대로 다음과 같은 조작을 했다고 합시다.

"w" : 수에 1을 더한다.
"s" : 수에 1을 뺀다.
"d" : 수에 10을 더한다.
"a" : 수에 10을 뺀다.
그리고 매번 조작을 할 때마다 결괏값을 기록한 정수 배열이 numLog입니다. 즉, numLog[i]는 numLog[0]로부터 총 i번의 조작을 가한 결과가 저장되어 있습니다.

주어진 정수 배열 numLog에 대해 조작을 위해 입력받은 문자열을 return 하는 solution 함수를 완성해 주세요.
*/


string Q_20240118::solutionQ3(vector<int> numLog) {

    string result = "";

    int pre = numLog[0];
    for (int i = 1; i < numLog.size(); i++) {

        switch (numLog[i]-pre)
        {
        case 1:
            result += 'w';
            break;
        case -1:
            result.insert(result.end(), 's');
            break;
        case 10:
            result.append(1, 'd');
            break;
        case -10:
            result.push_back('a');
            break;
        }

        pre = numLog[i];
    }
    return result;
}

/*
코딩 기초 트레이닝
수열과 구간 쿼리 3

정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. queries의 원소는 각각 하나의 query를 나타내며, [i, j] 꼴입니다.

각 query마다 순서대로 arr[i]의 값과 arr[j]의 값을 서로 바꿉니다.

위 규칙에 따라 queries를 처리한 이후의 arr를 return 하는 solution 함수를 완성해 주세요.
*/

vector<int> Q_20240118::solutionQ4(vector<int> arr, vector<vector<int>> queries) {

    for (auto query : queries) {
        int indexA = query[0];
        int indexB = query[1];

        int tmp = arr[indexA];
        arr[indexA] = arr[indexB];
        arr[indexB] = tmp;
    }
    return arr;
}


/*
코딩 기초 트레이닝
수열과 구간 쿼리 2

정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. queries의 원소는 각각 하나의 query를 나타내며, [s, e, k] 꼴입니다.

각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 k보다 크면서 가장 작은 arr[i]를 찾습니다.

각 쿼리의 순서에 맞게 답을 저장한 배열을 반환하는 solution 함수를 완성해 주세요.
단, 특정 쿼리의 답이 존재하지 않으면 -1을 저장합니다.
*/

vector<int> Q_20240118::solutionQ5(vector<int> arr, vector<vector<int>> queries) {
    vector<int> result;
    for (auto query : queries) {

        int s = query[0];
        int e = query[1];
        int k = query[2];

        int min = -1;
        for (int i = s; i <= e; i++) {
            if (arr[i] > k) {
                if (min == -1) {
                    min = arr[i];
                }
                else if (arr[i] < min) {
                    min = arr[i];
                }
            }
        }
        result.push_back(min);
    }
    return result;
}

/*
코딩 기초 트레이닝
수열과 구간 쿼리 4

정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. queries의 원소는 각각 하나의 query를 나타내며, [s, e, k] 꼴입니다.

각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 i가 k의 배수이면 arr[i]에 1을 더합니다.

위 규칙에 따라 queries를 처리한 이후의 arr를 return 하는 solution 함수를 완성해 주세요.  
*/

vector<int> Q_20240118::solutionQ6(vector<int> arr, vector<vector<int>> queries) {
    for (auto query : queries) {

        int s = query[0];
        int e = query[1];
        int k = query[2];

        for (int i = s; i <= e; i++) {
            if (i % k == 0) {
                arr[i] += 1;
            }
        }

    }
    return arr;
}

/*
코딩 기초 트레이닝
배열 만들기 2

정수 l과 r이 주어졌을 때, 
l 이상 r이하의 정수 중에서 숫자 "0"과 "5"로만 이루어진 모든 정수를 오름차순으로 저장한 배열을 return 하는 
solution 함수를 완성해 주세요.

만약 그러한 정수가 없다면, -1이 담긴 배열을 return 합니다.

l	r	result
5	555	[5, 50, 55, 500, 505, 550, 555]
10	20	[-1]
5
자리수 5*10
50
이전거 더하기50 + 5
자리수 5*100
이전거 더하기 500+5 500+50 500+55
자리수 5*1000
이전거 더하기 5000+5 5000+50 5000+55 5000+505 5000+550 5000+555

*/

//모든 5, 0의 배열을 만들어서 인덱스 찾기 < 만드는데 오래걸리는지?




vector<int> Q_20240118::solutionQ7(int l, int r) {
    vector<int> mul5;
    vector<int> tmp;
    vector<int> result;

    int count = 1;
    int num=0;
    while (count < 1000000) {
        num = count * 5;
        tmp.push_back(num);
        for (int i = 0; i < mul5.size(); i++) {
            tmp.push_back(num + mul5[i]);
        }
        mul5.insert(mul5.end(), tmp.begin()+ mul5.size(), tmp.end());
        count *= 10;
        for (int i = 0; i < mul5.size(); i++) {
            cout << mul5[i] << " ";
        }
        cout << endl;
    }

    bool check = false;
    for (int i = 0; i < mul5.size(); i++) {
        if (mul5[i] >= l && mul5[i] <= r) {
            result.push_back(mul5[i]);
            check = true;
        }
        else if (check) {
            break;
        }
    }
    if (check==false) {
        result.push_back(-1);
    }


    return result;
}

/*
* 코딩 기초 트레이닝
카운트 업

정수 start_num와 end_num가 주어질 때,
start_num부터 end_num까지의 숫자를 차례로 담은 리스트를 return하도록 solution 함수를 완성해주세요.
*/

vector<int> Q_20240118::solutionQ8(int start_num, int end_num) {
    vector<int> result;

    for (int i = start_num; i <= end_num; i++) {
        result.push_back(i);
    }

    return result;
}

/*
코딩 기초 트레이닝
콜라츠 수열 만들기

모든 자연수 x에 대해서 현재 값이 x이면 x가 짝수일 때는 2로 나누고, 
x가 홀수일 때는 3 * x + 1로 바꾸는 계산을 계속해서 반복하면 
언젠가는 반드시 x가 1이 되는지 묻는 문제를 콜라츠 문제라고 부릅니다.

그리고 위 과정에서 거쳐간 모든 수를 기록한 수열을 콜라츠 수열이라고 부릅니다.

계산 결과 1,000 보다 작거나 같은 수에 대해서는 전부 언젠가 1에 도달한다는 것이 알려져 있습니다.

임의의 1,000 보다 작거나 같은 양의 정수 n이 주어질 때 초기값이 n인 콜라츠 수열을 return 하는 solution 함수를 완성해 주세요.
*/

vector<int> Q_20240118::solutionQ9(int n) {
    vector<int> result;
    result.push_back(n);

    while (n > 1) {
        if (n%2==1) {
            n = 3 * n + 1;
        }
        else {
            n = n / 2;
        }
        result.push_back(n);

    }

    return result;
}


/*
코딩 기초 트레이닝
배열 만들기 4

정수 배열 arr가 주어집니다. arr를 이용해 새로운 배열 stk를 만드려고 합니다.

변수 i를 만들어 초기값을 0으로 설정한 후 i가 arr의 길이보다 작으면 다음 작업을 반복합니다.

만약 stk가 빈 배열이라면 arr[i]를 stk에 추가하고 i에 1을 더합니다.
stk에 원소가 있고, stk의 마지막 원소가 arr[i]보다 작으면 arr[i]를 stk의 뒤에 추가하고 i에 1을 더합니다.
stk에 원소가 있는데 stk의 마지막 원소가 arr[i]보다 크거나 같으면 stk의 마지막 원소를 stk에서 제거합니다.
위 작업을 마친 후 만들어진 stk를 return 하는 solution 함수를 완성해 주세요.
*/

vector<int> Q_20240118::solutionQ10(vector<int> arr) {
    vector<int> stk;

    for (int i = 0; i < arr.size(); i++) {
        if (stk.size() == 0 || stk.back()<arr[i]) {
            stk.push_back(arr[i]);
        }
        else {
            stk.pop_back();
            i--;
        }
    }
    return stk;
}


/*
연습문제
공원 산책

지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다. 
산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며, 명령은 다음과 같은 형식으로 주어집니다.

["방향 거리", "방향 거리" … ]
예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다. 
로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.

주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.
주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.
위 두 가지중 어느 하나라도 해당된다면, 로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.
공원의 가로 길이가 W, 세로 길이가 H라고 할 때, 공원의 좌측 상단의 좌표는 (0, 0), 우측 하단의 좌표는 (H - 1, W - 1) 입니다.

image
https://user-images.githubusercontent.com/62426665/217702316-1bd5d3ba-c1d7-4133-bfb5-36bdc85a08ba.png

공원을 나타내는 문자열 배열 park, 로봇 강아지가 수행할 명령이 담긴 문자열 배열 routes가 매개변수로 주어질 때, 
로봇 강아지가 모든 명령을 수행 후 놓인 위치를 [세로 방향 좌표, 가로 방향 좌표] 순으로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

park	                    routes	            result
["SOO","OOO","OOO"]	        ["E 2","S 2","W 1"]	[2,1]
["SOO","OXX","OOO"]	        ["E 2","S 2","W 1"]	[0,1]
["OSO","OOO","OXO","OOO"]	["E 2","S 3","W 1"]	[0,0]
*/

struct pos {
    int x;
    int y;

    pos() : x(0), y(0) {}
    pos(int x, int y) : x(x), y(y) {}
    pos operator-()
    {
        return pos(-x, -y);
    }
    pos operator+(const pos& p2)
    {
        return pos(x + p2.x, y + p2.y);
    }
    pos operator*(const int& p2)
    {
        return pos(x * p2, y * p2);
    }
};

pos dirValue[] = { {1,0},{0,1},{-1,0},{0,-1} };

vector<int> Q_20240118::solutionQ11(vector<string> park, vector<string> routes) {

    unordered_map<char, int> dirIdx;
    dirIdx.insert({ 'E',0 });
    dirIdx.insert({ 'S',1 });
    dirIdx.insert({ 'W',2 });
    dirIdx.insert({ 'N',3 });

    vector<int> answer;

    //기본 세팅(시작점 구하기)

    //e,s,w,n
    pos dog = { -1,0 };
    pos mapSize = pos(park[0].size(), park.size());
    //세로
    for (int col = 0; col < mapSize.y; col++) {
        //가로
        for (int row = 0; row < mapSize.x; row++) {
            if (park[col][row] == 'S') {
                dog.x = row;
                dog.y = col;
                break;
            }
        }
        if (dog.x != -1) break;
    }

    //명령 시작
    for (int i = 0; i < routes.size(); i++) {
        //명령 나누기
        char dirChar = routes[i][0];
        //int count = stoi(routes[i].substr(2, routes[i].size()));
        //입력 범위가 1~9이기 때문에
        int count = (int)(routes[i][2] - '0');

        cout << dirChar << count << endl;

        //방향+거리 지정
        pos dir = dirValue[dirIdx[dirChar]];
        pos order = dog + (dir * count);
        cout << order.x << " " << order.y;

        //맵 벗어나는지
        if (order.x >= 0 && order.x < mapSize.x &&
            order.y >= 0 && order.y < mapSize.y) {

            //장애물 있는지
            bool walkBool = true;
            for (int walk = 1; walk <= count; walk++) {
                pos walkPos = dog + (dir * walk);
                if (park[walkPos.y][walkPos.x] == 'X') {
                    walkBool = false;
                    cout << "장애물";
                    break;
                }
            }

            //모두 통과하면 이동
            if (walkBool)
                dog = order;
        }
        else {
            cout << "맵뚫";
        }
        cout << endl;
        cout << dog.x << " " << dog.y << endl;
    }

    //h, w 순으로 저장
    answer.push_back(dog.y);
    answer.push_back(dog.x);

    return answer;
}


/*
2023 KAKAO BLIND RECRUITMENT
개인정보 수집 유효기간

고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다. 
약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다. 
당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다. 
수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

예를 들어, A라는 약관의 유효기간이 12 달이고, 
2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 
해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

모든 달은 28일까지 있다고 가정합니다.

다음은 오늘 날짜가 2022.05.19일 때의 예시입니다.

약관 종류	유효기간
A	6 달
B	12 달
C	3 달
번호	개인정보 수집 일자	약관 종류
1	2021.05.02	A
2	2021.07.01	B
3	2022.02.19	C
4	2022.02.20	C
첫 번째 개인정보는 A약관에 의해 2021년 11월 1일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
두 번째 개인정보는 B약관에 의해 2022년 6월 28일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
세 번째 개인정보는 C약관에 의해 2022년 5월 18일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
네 번째 개인정보는 C약관에 의해 2022년 5월 19일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
따라서 파기해야 할 개인정보 번호는 [1, 3]입니다.

오늘 날짜를 의미하는 문자열 today, 
약관의 유효기간을 담은 1차원 문자열 배열 terms와
수집된 개인정보의 정보를 담은 1차원 문자열 배열 privacies가 매개변수로 주어집니다.
이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

today	        terms	                privacies	                                                                        result
"2022.05.19"	["A 6", "B 12", "C 3"]	["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]	                [1, 3]
"2020.01.01"	["Z 3", "D 5"]	        ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]	[1, 4, 5]
*/

//2000년 1월 1일
const int startDay = 0;
const int month = 28;
const int year = 12 * month;

int CalcDayStringToInt(string date) {

    int yearCnt = stoi(date.substr(0, 4)) - 2000;
    int monthCnt = stoi(date.substr(5, 2));
    int dayCnt = stoi(date.substr(8, 2));

    int result = yearCnt * year + monthCnt * month + dayCnt;

    return result;
}
int GetYear(string date) {

    int yearCnt = stoi(date.substr(0, 4)) - 2000;

    return yearCnt;
}
int GetMonth(string date) {

    int monthCnt = stoi(date.substr(5, 2));
    return monthCnt;
}

int GetDay(string date) {

    int dayCnt = stoi(date.substr(8, 2));
    return dayCnt;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> result;

    unordered_map<char, int> typeIdx;
    for (int i = 0; i < terms.size(); i++) {
        int termCnt = stoi(terms[i].substr(2, terms[i].size() - 2)) * month;

        typeIdx.insert({ terms[i][0], termCnt });
    }

    int currDay = CalcDayStringToInt(today);
    cout << currDay << "/";
    cout << GetYear(today) << "." << GetMonth(today) << "." << GetDay(today) << endl;

    for (int i = 0; i < privacies.size(); i++) {
        string contractData = privacies[i].substr(0, 10);
        char contractType = privacies[i][privacies[i].size() - 1];

        int contractDay = CalcDayStringToInt(contractData) + typeIdx[contractType] - 1;

        int y = (int)(contractDay / (float)year);
        int m = (int)((contractDay - y * year) / (float)month);
        int d = (contractDay - y * year - m * month);
        cout << contractDay << "/";
        cout << y << ".";
        cout << m << ".";
        cout << d << endl;


        if (contractDay < currDay) {
            result.push_back(i + 1);
        }
    }

    return result;
}