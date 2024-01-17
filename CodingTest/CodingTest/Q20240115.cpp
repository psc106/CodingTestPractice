#include "header.h"



Q_20240115::Q_20240115() {

    vector<string> q11 = { "muzi", "ryan", "frodo", "neo" };
    vector<string> q21 = { "joy", "brad", "alessandro", "conan", "david" };
    vector<string> q31 = { "a", "b", "c" };
    vector<string> q12 = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };
    vector<string> q22 = { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" };
    vector<string> q32 = { "a b", "b a", "c a", "a c", "a c", "c a" };

    q1_1.push_back(q11);
    q1_1.push_back(q21);
    q1_1.push_back(q31);
    q1_2.push_back(q12);
    q1_2.push_back(q22);
    q1_2.push_back(q32);

    vector<int> q211 = { 5, 1, 5 };
    vector<int> q212 = { 3, 2, 7 };
    vector<int> q213 = { 4, 2, 7 };
    vector<int> q214 = { 1, 1, 1 };

    int q221[] = { 30, 20, 20, 5 };

    vector<vector<int>> q231 = { {2, 10},{9, 15}, {10, 5},{11, 5} };
    vector<vector<int>> q232 = { {1, 15},{5, 16}, {8, 6} };
    vector<vector<int>> q233 = { {1, 15},{5, 16}, {8, 6} };
    vector<vector<int>> q234 = { {1, 2},{3, 2} };

    q2_1.push_back(q211);
    q2_1.push_back(q212);
    q2_1.push_back(q213);
    q2_1.push_back(q214);

    q2_2.insert(q2_2.begin(), q221, q221 + 4);

    q2_3.push_back(q231);
    q2_3.push_back(q232);
    q2_3.push_back(q233);
    q2_3.push_back(q234);

    vector<vector<string>> q311 = { {"blue", "red", "orange", "red"},{"red", "red", "blue", "orange"},{"blue", "orange", "red", "red"},{"orange", "orange", "red", "blue"} };
    vector<vector<string>> q312 = { {"yellow", "green", "blue"},{"blue", "green", "yellow"},{"yellow", "blue", "blue"} };

    int q321[] = { 1, 0 };
    int q331[] = { 1, 1 };

    q3_1.push_back(q311);
    q3_1.push_back(q312);

    q3_2.insert(q3_2.begin(), q321, q321 + 2);
    q3_3.insert(q3_3.begin(), q331, q331 + 2);

    vector<vector<int>> q411 = { { {1, 20300104, 100, 80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8} } };
    string q42[] = {"data"};
    int q43[] = {20300501};
    string q44[] = {"remain"};
    q4_1.push_back(q411);
    q4_2.insert(q4_2.begin(), q42, q42 + 1);
    q4_3.insert(q4_3.begin(), q43, q43 + 1);
    q4_4.insert(q4_4.begin(), q44, q44 + 1);

}

    /*
Q1 문제 설명
선물을 직접 전하기 힘들 때 카카오톡 선물하기 기능을 이용해 축하 선물을 보낼 수 있습니다. 
당신의 친구들이 이번 달까지 선물을 주고받은 기록을 바탕으로 다음 달에 누가 선물을 많이 받을지 예측하려고 합니다.

두 사람이 선물을 주고받은 기록이 있다면, 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받습니다.
예를 들어 A가 B에게 선물을 5번 줬고, B가 A에게 선물을 3번 줬다면 다음 달엔 A가 B에게 선물을 하나 받습니다.
두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받습니다.
선물 지수는 이번 달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값입니다.
예를 들어 A가 친구들에게 준 선물이 3개고 받은 선물이 10개라면 A의 선물 지수는 -7입니다. 
B가 친구들에게 준 선물이 3개고 받은 선물이 2개라면 B의 선물 지수는 1입니다. 
만약 A와 B가 선물을 주고받은 적이 없거나 정확히 같은 수로 선물을 주고받았다면, 다음 달엔 B가 A에게 선물을 하나 받습니다.
만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않습니다.
위에서 설명한 규칙대로 다음 달에 선물을 주고받을 때, 당신은 선물을 가장 많이 받을 친구가 받을 선물의 수를 알고 싶습니다.

친구들의 이름을 담은 1차원 문자열 배열 friends 이번 달까지 친구들이 주고받은 선물 기록을 담은 1차원 문자열 배열 gifts가 매개변수로 주어집니다. 
이때, 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 return 하도록 solution 함수를 완성해 주세요.

2 ≤ friends의 길이 = 친구들의 수 ≤ 50
friends의 원소는 친구의 이름을 의미하는 알파벳 소문자로 이루어진 길이가 10 이하인 문자열입니다.
이름이 같은 친구는 없습니다.
1 ≤ gifts의 길이 ≤ 10,000
gifts의 원소는 "A B"형태의 문자열입니다. A는 선물을 준 친구의 이름을 B는 선물을 받은 친구의 이름을 의미하며 공백 하나로 구분됩니다.
A와 B는 friends의 원소이며 A와 B가 같은 이름인 경우는 존재하지 않습니다.

입출력 예
friends	gifts	result
["muzi", "ryan", "frodo", "neo"]	["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]	2
["joy", "brad", "alessandro", "conan", "david"]	["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]	4
["a", "b", "c"]	["a b", "b a", "c a", "a c", "a c", "c a"]	0
    */

int Q_20240115::solutionQ1(vector<string> friends, vector<string> gifts) {

    std::unordered_map<string, int> nameToIndex;
    int friendSize = friends.size();
    int answer = 0;

    int** table = new int* [friendSize];
    int* diff = new int[friendSize];
    int* result = new int[friendSize];

    for (int i = 0; i < friendSize; i++)
    {
        nameToIndex.insert({ friends[i], i });
        table[i] = new int[friendSize];
        result[i] = 0;
        diff[i] = 0;
        for (int j = 0; j < friendSize; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        string givePerson;
        string getPerson;
        for (int j = 0; j < gifts[i].size(); j++)
        {
            if (gifts[i][j] == ' ') {
                givePerson = gifts[i].substr(0, j);
                getPerson = gifts[i].substr(j + 1, gifts[i].size() - j - 1);

                table[nameToIndex[getPerson]][nameToIndex[givePerson]] += 1;
                diff[nameToIndex[getPerson]] -= 1;
                diff[nameToIndex[givePerson]] += 1;
                break;
            }
        }
    }


    for (int i = 0; i < friendSize; i++)
    {
        for (int j = i + 1; j < friendSize; j++) {
            if (table[j][i] < table[i][j])
            {
                result[j] += 1;
                answer = (answer > result[j] ? answer : result[j]);
            }
            else if (table[j][i] > table[i][j])
            {
                result[i] += 1;
                answer = (answer > result[i] ? answer : result[i]);
            }
            else
            {
                if (diff[i] < diff[j]) {
                    result[j] += 1;
                    answer = (answer > result[j] ? answer : result[j]);
                }
                else if (diff[i] > diff[j]) {
                    result[i] += 1;
                    answer = (answer > result[i] ? answer : result[i]);
                }
            }
        }
    }

    return answer;
}

void Q_20240115::Result1() {

    cout << solutionQ1(q1_1[0], q1_2[0]) << endl;
    cout << solutionQ1(q1_1[1], q1_2[1]) << endl;
    cout << solutionQ1(q1_1[2], q1_2[2]) << endl;
}


/*
어떤 게임에는 붕대 감기라는 기술이 있습니다.


붕대 감기는 t초 동안 붕대를 감으면서 1초마다 x만큼의 체력을 회복합니다.
//t * x만큼 회복
t초 연속으로 붕대를 감는 데 성공한다면 y만큼의 체력을 추가로 회복합니다.
//(t * x) + y 만큼 회복
게임 캐릭터에는 최대 체력이 존재해 현재 체력이 최대 체력보다 커지는 것은 불가능합니다.
//최대 체력만큼 가능

기술을 쓰는 도중 몬스터에게 공격을 당하면 기술이 취소되고, 공격을 당하는 순간에는 체력을 회복할 수 없습니다.
//같은 프레임에서 일어난 일은 공격이 최우선

몬스터에게 공격당해 기술이 취소당하거나 기술이 끝나면 그 즉시 붕대 감기를 다시 사용하며, 연속 성공 시간이 0으로 초기화됩니다.
//공격이 일어난 다음 프레임이 아닌 해당 프레임에 일어난다는 뜻인가?
//예외 사항 봐야할듯
//인풋 본 결과 다음 프레임에 회복

몬스터의 공격을 받으면 정해진 피해량만큼 현재 체력이 줄어듭니다. 
//공격

이때, 현재 체력이 0 이하가 되면 캐릭터가 죽으며 더 이상 체력을 회복할 수 없습니다.
//체력 0

당신은 붕대감기 기술의 정보, 캐릭터가 가진 최대 체력과 몬스터의 공격 패턴이 주어질 때 캐릭터가 끝까지 생존할 수 있는지 궁금합니다.


붕대 감기 기술의 시전 시간, 1초당 회복량, 추가 회복량을 담은 1차원 정수 배열 bandage와 최대 체력을 의미하는 정수 health,

몬스터의 공격 시간과 피해량을 담은 2차원 정수 배열 attacks가 매개변수로 주어집니다. 

모든 공격이 끝난 직후 남은 체력을 return 하도록 solution 함수를 완성해 주세요. 

만약 몬스터의 공격을 받고 캐릭터의 체력이 0 이하가 되어 죽는다면 -1을 return 해주세요.

[5, 1, 5]	30	[[2, 10], [9, 15], [10, 5], [11, 5]]	5
[3, 2, 7]	20	[[1, 15], [5, 16], [8, 6]]	-1
[4, 2, 7]	20	[[1, 15], [5, 16], [8, 6]]	-1
[1, 1, 1]	5	[[1, 2], [3, 2]]	3
*/


int Q_20240115::solutionQ2(vector<int> bandage, int health, vector<vector<int>> attacks) {

    int frame = 1;
    int currAttack = 0;
    
    int continueSuccess = 0;
    int currHealth = health;

    while (currAttack < attacks.size()) {
        vector<int> data = attacks[currAttack];
        if (data[0] == frame) {
            //공격당했을시
            currHealth -= data[1];
            continueSuccess = 0;

            if (currHealth <= 0) {
                return -1;
            }
            currAttack += 1;
        }
        else {
            //공격안당했을시
            currHealth += bandage[1];
            continueSuccess += 1;

            if (continueSuccess == bandage[0]) {
                currHealth += bandage[2];
                continueSuccess = 0;
            }
            if (currHealth >= health) {
                currHealth = health;
            }
        }

        frame += 1;
    }

    return currHealth;

}

void Q_20240115::Result2() {

    cout << solutionQ2(q2_1[0], q2_2[0], q2_3[0]) << endl;
    cout << solutionQ2(q2_1[1], q2_2[1], q2_3[1]) << endl;
    cout << solutionQ2(q2_1[2], q2_2[2], q2_3[2]) << endl;
    cout << solutionQ2(q2_1[3], q2_2[3], q2_3[3]) << endl;
}

/*
각 칸마다 색이 칠해진 2차원 격자 보드판이 있습니다. 그중 한 칸을 골랐을 때, 위, 아래, 왼쪽, 오른쪽 칸 중 같은 색깔로 칠해진 칸의 개수를 구하려고 합니다.

보드의 각 칸에 칠해진 색깔 이름이 담긴 이차원 문자열 리스트 board와 고른 칸의 위치를 나타내는 두 정수 h, w가 주어질 때 board[h][w]와 이웃한 칸들 중 같은 색으로 칠해져 있는 칸의 개수를 return 하도록 solution 함수를 완성해 주세요.

이웃한 칸들 중 몇 개의 칸이 같은 색으로 색칠되어 있는지 확인하는 과정은 다음과 같습니다.

1. 정수를 저장할 변수 n을 만들고 board의 길이를 저장합니다.
2. 같은 색으로 색칠된 칸의 개수를 저장할 변수 count를 만들고 0을 저장합니다.
3. h와 w의 변화량을 저장할 정수 리스트 dh, dw를 만들고 각각 [0, 1, -1, 0], [1, 0, 0, -1]을 저장합니다.
4. 반복문을 이용해 i 값을 0부터 3까지 1 씩 증가시키며 아래 작업을 반복합니다.
    4-1. 체크할 칸의 h, w 좌표를 나타내는 변수 h_check, w_check를 만들고 각각 h + dh[i], w + dw[i]를 저장합니다.
    4-2. h_check가 0 이상 n 미만이고 w_check가 0 이상 n 미만이라면 다음을 수행합니다.
        4-2-a. board[h][w]와 board[h_check][w_check]의 값이 동일하다면 count의 값을 1 증가시킵니다.
5. count의 값을 return합니다.
위의 의사코드와 작동방식이 다른 코드를 작성해도 상관없습니다.

[["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]]	1	1	2
[["yellow", "green", "blue"], ["blue", "green", "yellow"], ["yellow", "blue", "blue"]]	0	1	1
*/


int Q_20240115::solutionQ3(vector<vector<string>> board, int h, int w) {
    int dh[] = { 0, 1, -1, 0 };
    int dw[] = { 1, 0, 0, -1 };

    string currColor = board[h][w];

    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (h + dh[i] >= board.size() || h + dh[i] < 0) continue;
        if (w + dw[i] >= board[w].size() || w + dw[i] < 0) continue;
        if (board[h + dh[i]][w + dw[i]] == currColor) {
            count += 1;
        }
    }

    return count;
}

void Q_20240115::Result3() {

    cout << solutionQ3(q3_1[0], q3_2[0], q3_3[0]) << endl;   
    cout << solutionQ3(q3_1[1], q3_2[1], q3_3[1]) << endl;

}

/*
AI 엔지니어인 현식이는 데이터를 분석하는 작업을 진행하고 있습니다. 
데이터는 ["코드 번호(code)", "제조일(date)", "최대 수량(maximum)", "현재 수량(remain)"]으로 구성되어 있으며
현식이는 이 데이터들 중 조건을 만족하는 데이터만 뽑아서 정렬하려 합니다.

예를 들어 다음과 같이 데이터가 주어진다면

data = [[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]]
이 데이터는 다음 표처럼 나타낼 수 있습니다.

code	date	maximum	remain
1	20300104	100	80
2	20300804	847	37
3	20300401	10	8
주어진 데이터 중 "제조일이 20300501 이전인 물건들을 현재 수량이 적은 순서"로 정렬해야 한다면 조건에 맞게 가공된 데이터는 다음과 같습니다.

data = [[3,20300401,10,8],[1,20300104,100,80]]
정렬한 데이터들이 담긴 이차원 정수 리스트 data와 어떤 정보를 기준으로 데이터를 뽑아낼지를 의미하는 문자열 ext, 
뽑아낼 정보의 기준값을 나타내는 정수 val_ext, 정보를 정렬할 기준이 되는 문자열 sort_by가 주어집니다.

data에서 ext 값이 val_ext보다 작은 데이터만 뽑은 후, sort_by에 해당하는 값을 기준으로 오름차순으로 정렬하여
return 하도록 solution 함수를 완성해 주세요. 단, 조건을 만족하는 데이터는 항상 한 개 이상 존재합니다.

[[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]]	"date"	20300501	"remain"	[[3,20300401,10,8],[1,20300104,100,80]]
*/
vector<vector<int>> Q_20240115::solutionQ4(vector<vector<int>> data, string ext, int val_ext, string sort_by) {

    std::unordered_map<string, int> mappingData = { {"code", 0},{"date", 1},{"maximum",2}, {"remain", 3}};

    int diffIndex = mappingData[ext];
    int sortIndex = mappingData[sort_by];
    vector<vector<int>> successData;

    for (int i = 0; i < data.size(); i++) {
        if (data[i][diffIndex] < val_ext) {
            successData.push_back(data[i]);
        }
    }

    for (int i = 0; i < successData.size()-1; i++) {
        for (int j = i+1; j < successData.size(); j++) {
            if (successData[i][sortIndex] > successData[j][sortIndex]) {
                swap(successData[i], successData[j]);
            }
        }
    }

    return successData;
}
void Q_20240115::Result4() {

    auto data = solutionQ4(q4_1[0], q4_2[0], q4_3[0], q4_4[0]);

    for (int i = 0; i < data.size(); i++) {

        for (int j = 0; j < data.size(); j++) {

            cout << data[i][j] << endl;
        }
    }
}