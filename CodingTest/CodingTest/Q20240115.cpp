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
Q1 ���� ����
������ ���� ���ϱ� ���� �� īī���� �����ϱ� ����� �̿��� ���� ������ ���� �� �ֽ��ϴ�. 
����� ģ������ �̹� �ޱ��� ������ �ְ���� ����� �������� ���� �޿� ���� ������ ���� ������ �����Ϸ��� �մϴ�.

�� ����� ������ �ְ���� ����� �ִٸ�, �̹� �ޱ��� �� ��� ���̿� �� ���� ������ �� ����� ���� �޿� ������ �ϳ� �޽��ϴ�.
���� ��� A�� B���� ������ 5�� ���, B�� A���� ������ 3�� ��ٸ� ���� �޿� A�� B���� ������ �ϳ� �޽��ϴ�.
�� ����� ������ �ְ���� ����� �ϳ��� ���ų� �ְ���� ���� ���ٸ�, ���� ������ �� ū ����� ���� ������ �� ���� ������� ������ �ϳ� �޽��ϴ�.
���� ������ �̹� �ޱ��� �ڽ��� ģ���鿡�� �� ������ ������ ���� ������ ���� �� ���Դϴ�.
���� ��� A�� ģ���鿡�� �� ������ 3���� ���� ������ 10����� A�� ���� ������ -7�Դϴ�. 
B�� ģ���鿡�� �� ������ 3���� ���� ������ 2����� B�� ���� ������ 1�Դϴ�. 
���� A�� B�� ������ �ְ���� ���� ���ų� ��Ȯ�� ���� ���� ������ �ְ�޾Ҵٸ�, ���� �޿� B�� A���� ������ �ϳ� �޽��ϴ�.
���� �� ����� ���� ������ ���ٸ� ���� �޿� ������ �ְ���� �ʽ��ϴ�.
������ ������ ��Ģ��� ���� �޿� ������ �ְ���� ��, ����� ������ ���� ���� ���� ģ���� ���� ������ ���� �˰� �ͽ��ϴ�.

ģ������ �̸��� ���� 1���� ���ڿ� �迭 friends �̹� �ޱ��� ģ������ �ְ���� ���� ����� ���� 1���� ���ڿ� �迭 gifts�� �Ű������� �־����ϴ�. 
�̶�, �����޿� ���� ���� ������ �޴� ģ���� ���� ������ ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

2 �� friends�� ���� = ģ������ �� �� 50
friends�� ���Ҵ� ģ���� �̸��� �ǹ��ϴ� ���ĺ� �ҹ��ڷ� �̷���� ���̰� 10 ������ ���ڿ��Դϴ�.
�̸��� ���� ģ���� �����ϴ�.
1 �� gifts�� ���� �� 10,000
gifts�� ���Ҵ� "A B"������ ���ڿ��Դϴ�. A�� ������ �� ģ���� �̸��� B�� ������ ���� ģ���� �̸��� �ǹ��ϸ� ���� �ϳ��� ���е˴ϴ�.
A�� B�� friends�� �����̸� A�� B�� ���� �̸��� ���� �������� �ʽ��ϴ�.

����� ��
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
� ���ӿ��� �ش� ������ ����� �ֽ��ϴ�.


�ش� ����� t�� ���� �ش븦 �����鼭 1�ʸ��� x��ŭ�� ü���� ȸ���մϴ�.
//t * x��ŭ ȸ��
t�� �������� �ش븦 ���� �� �����Ѵٸ� y��ŭ�� ü���� �߰��� ȸ���մϴ�.
//(t * x) + y ��ŭ ȸ��
���� ĳ���Ϳ��� �ִ� ü���� ������ ���� ü���� �ִ� ü�º��� Ŀ���� ���� �Ұ����մϴ�.
//�ִ� ü�¸�ŭ ����

����� ���� ���� ���Ϳ��� ������ ���ϸ� ����� ��ҵǰ�, ������ ���ϴ� �������� ü���� ȸ���� �� �����ϴ�.
//���� �����ӿ��� �Ͼ ���� ������ �ֿ켱

���Ϳ��� ���ݴ��� ����� ��Ҵ��ϰų� ����� ������ �� ��� �ش� ���⸦ �ٽ� ����ϸ�, ���� ���� �ð��� 0���� �ʱ�ȭ�˴ϴ�.
//������ �Ͼ ���� �������� �ƴ� �ش� �����ӿ� �Ͼ�ٴ� ���ΰ�?
//���� ���� �����ҵ�
//��ǲ �� ��� ���� �����ӿ� ȸ��

������ ������ ������ ������ ���ط���ŭ ���� ü���� �پ��ϴ�. 
//����

�̶�, ���� ü���� 0 ���ϰ� �Ǹ� ĳ���Ͱ� ������ �� �̻� ü���� ȸ���� �� �����ϴ�.
//ü�� 0

����� �ش밨�� ����� ����, ĳ���Ͱ� ���� �ִ� ü�°� ������ ���� ������ �־��� �� ĳ���Ͱ� ������ ������ �� �ִ��� �ñ��մϴ�.


�ش� ���� ����� ���� �ð�, 1�ʴ� ȸ����, �߰� ȸ������ ���� 1���� ���� �迭 bandage�� �ִ� ü���� �ǹ��ϴ� ���� health,

������ ���� �ð��� ���ط��� ���� 2���� ���� �迭 attacks�� �Ű������� �־����ϴ�. 

��� ������ ���� ���� ���� ü���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���. 

���� ������ ������ �ް� ĳ������ ü���� 0 ���ϰ� �Ǿ� �״´ٸ� -1�� return ���ּ���.

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
            //���ݴ�������
            currHealth -= data[1];
            continueSuccess = 0;

            if (currHealth <= 0) {
                return -1;
            }
            currAttack += 1;
        }
        else {
            //���ݾȴ�������
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
�� ĭ���� ���� ĥ���� 2���� ���� �������� �ֽ��ϴ�. ���� �� ĭ�� ����� ��, ��, �Ʒ�, ����, ������ ĭ �� ���� ����� ĥ���� ĭ�� ������ ���Ϸ��� �մϴ�.

������ �� ĭ�� ĥ���� ���� �̸��� ��� ������ ���ڿ� ����Ʈ board�� �� ĭ�� ��ġ�� ��Ÿ���� �� ���� h, w�� �־��� �� board[h][w]�� �̿��� ĭ�� �� ���� ������ ĥ���� �ִ� ĭ�� ������ return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

�̿��� ĭ�� �� �� ���� ĭ�� ���� ������ ��ĥ�Ǿ� �ִ��� Ȯ���ϴ� ������ ������ �����ϴ�.

1. ������ ������ ���� n�� ����� board�� ���̸� �����մϴ�.
2. ���� ������ ��ĥ�� ĭ�� ������ ������ ���� count�� ����� 0�� �����մϴ�.
3. h�� w�� ��ȭ���� ������ ���� ����Ʈ dh, dw�� ����� ���� [0, 1, -1, 0], [1, 0, 0, -1]�� �����մϴ�.
4. �ݺ����� �̿��� i ���� 0���� 3���� 1 �� ������Ű�� �Ʒ� �۾��� �ݺ��մϴ�.
    4-1. üũ�� ĭ�� h, w ��ǥ�� ��Ÿ���� ���� h_check, w_check�� ����� ���� h + dh[i], w + dw[i]�� �����մϴ�.
    4-2. h_check�� 0 �̻� n �̸��̰� w_check�� 0 �̻� n �̸��̶�� ������ �����մϴ�.
        4-2-a. board[h][w]�� board[h_check][w_check]�� ���� �����ϴٸ� count�� ���� 1 ������ŵ�ϴ�.
5. count�� ���� return�մϴ�.
���� �ǻ��ڵ�� �۵������ �ٸ� �ڵ带 �ۼ��ص� ��������ϴ�.

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
AI �����Ͼ��� �����̴� �����͸� �м��ϴ� �۾��� �����ϰ� �ֽ��ϴ�. 
�����ʹ� ["�ڵ� ��ȣ(code)", "������(date)", "�ִ� ����(maximum)", "���� ����(remain)"]���� �����Ǿ� ������
�����̴� �� �����͵� �� ������ �����ϴ� �����͸� �̾Ƽ� �����Ϸ� �մϴ�.

���� ��� ������ ���� �����Ͱ� �־����ٸ�

data = [[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]]
�� �����ʹ� ���� ǥó�� ��Ÿ�� �� �ֽ��ϴ�.

code	date	maximum	remain
1	20300104	100	80
2	20300804	847	37
3	20300401	10	8
�־��� ������ �� "�������� 20300501 ������ ���ǵ��� ���� ������ ���� ����"�� �����ؾ� �Ѵٸ� ���ǿ� �°� ������ �����ʹ� ������ �����ϴ�.

data = [[3,20300401,10,8],[1,20300104,100,80]]
������ �����͵��� ��� ������ ���� ����Ʈ data�� � ������ �������� �����͸� �̾Ƴ����� �ǹ��ϴ� ���ڿ� ext, 
�̾Ƴ� ������ ���ذ��� ��Ÿ���� ���� val_ext, ������ ������ ������ �Ǵ� ���ڿ� sort_by�� �־����ϴ�.

data���� ext ���� val_ext���� ���� �����͸� ���� ��, sort_by�� �ش��ϴ� ���� �������� ������������ �����Ͽ�
return �ϵ��� solution �Լ��� �ϼ��� �ּ���. ��, ������ �����ϴ� �����ʹ� �׻� �� �� �̻� �����մϴ�.

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