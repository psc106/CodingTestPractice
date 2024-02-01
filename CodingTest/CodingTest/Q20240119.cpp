#include "header.h"

Q_20240119_0201::Q_20240119_0201() {

}

/*
* 
* 코딩 기초 트레이닝
간단한 논리 연산

boolean 변수 x1, x2, x3, x4가 매개변수로 주어질 때, 다음의 식의 true/false를 return 하는 solution 함수를 작성해 주세요.

(x1 ∨ x2) ∧ (x3 ∨ x4)
*/

bool solution(bool x1, bool x2, bool x3, bool x4) {
    return (x1 || x2) && (x3 || x4);
}
/*
코딩 기초 트레이닝
주사위 게임 3

1부터 6까지 숫자가 적힌 주사위가 네 개 있습니다. 네 주사위를 굴렸을 때 나온 숫자에 따라 다음과 같은 점수를 얻습니다.

네 주사위에서 나온 숫자가 모두 p로 같다면 1111 × p점을 얻습니다.
세 주사위에서 나온 숫자가 p로 같고 나머지 다른 주사위에서 나온 숫자가 q(p ≠ q)라면 (10 × p + q)^2 점을 얻습니다.
주사위가 두 개씩 같은 값이 나오고, 나온 숫자를 각각 p, q(p ≠ q)라고 한다면 (p + q) × |p - q|점을 얻습니다.
어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 나온 숫자가 각각 p와 다른 q, r(q ≠ r)이라면 q × r점을 얻습니다.
네 주사위에 적힌 숫자가 모두 다르다면 나온 숫자 중 가장 작은 숫자 만큼의 점수를 얻습니다.
네 주사위를 굴렸을 때 나온 숫자가 정수 매개변수 a, b, c, d로 주어질 때, 얻는 점수를 return 하는 solution 함수를 작성해 주세요.
*/


int Q_20240119_0201::solutionQ01(int a, int b, int c, int d) {
    int numData[6] = { 0,0,0,0,0,0 };
    int inputData[] = { a,b,c,d };
    int size = 4;

    for (int i = 0; i < size; i++) {
        numData[inputData[i] - 1] += 1;
    }

    int min = 7;
    int max = 0;
    int same = -1;


    for (int i = 0; i < 6; i++) {
        switch (numData[i]) {
        case 0:
            break;
        case 1:
            if (min > i + 1) min = i + 1;
            if (max < i + 1) max = i + 1;
            break;
        case 2:
            if (same == -1) {
                same = (i + 1);
            }
            else {
                return (same + i + 1) * ((i + 1) - same);
            }
            break;
        case 3:
            same = (i + 1);
            break;
        case 4:
            return 1111 * (i + 1);
        }
    }

    if (same == -1) {
        return min;
    }
    else {
        if (min == max) {
            return (10 * same + min) * (10 * same + min);
        }
        else {
            return min * max;
        }
    }
}


/*
코딩 기초 트레이닝
글자 이어 붙여 문자열 만들기

문자열 my_string과 정수 배열 index_list가 매개변수로 주어집니다.
my_string의 index_list의 원소들에 해당하는 인덱스의 글자들을 순서대로 이어 붙인 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

string Q_20240119_0201::solutionQ02(string my_string, vector<int> index_list)
{
    string answer = "";
    for (int i = 0; i < index_list.size(); i++) {
        answer += my_string[index_list[i]];
    }

    return answer;
}


/*
코딩 기초 트레이닝
9로 나눈 나머지

음이 아닌 정수를 9로 나눈 나머지는 그 정수의 각 자리 숫자의 합을 9로 나눈 나머지와 같은 것이 알려져 있습니다.
이 사실을 이용하여 음이 아닌 정수가 문자열 number로 주어질 때, 이 정수를 9로 나눈 나머지를 return 하는 solution 함수를 작성해주세요.
*/

int Q_20240119_0201::solutionQ03(string number)
{

    int sum = 0;
    for (int i = 0; i < number.size(); i++) {
        int currNum = number[i] - '0';
        sum += currNum;
    }


    return sum % 9;
}

/*
* 코딩 기초 트레이닝
문자열 여러 번 뒤집기

문자열 my_string과 이차원 정수 배열 queries가 매개변수로 주어집니다. 
queries의 원소는 [s, e] 형태로, my_string의 인덱스 s부터 인덱스 e까지를 뒤집으라는 의미입니다.
my_string에 queries의 명령을 순서대로 처리한 후의 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

string Q_20240119_0201::solutionQ04(string my_string, vector<vector<int>> queries) {

    for (int i = 0; i < queries.size(); i++) {
        int start = queries[i][0];
        int end = queries[i][1];

        while (start < end) {
            char tmp = my_string[start];
            my_string[start] = my_string[end];
            my_string[end] = tmp;
            start += 1;
            end -= 1;
        }
    }


    return my_string;
}
/*
코딩 기초 트레이닝
배열 만들기 5

문자열 배열 intStrs와 정수 k, s, l가 주어집니다. intStrs의 원소는 숫자로 이루어져 있습니다.
배열 intStrs의 각 원소마다 s번 인덱스에서 시작하는 길이 l짜리 부분 문자열을 잘라내 정수로 변환합니다. 
이때 변환한 정수값이 k보다 큰 값들을 담은 배열을 return 하는 solution 함수를 완성해 주세요.
*/

vector<int> Q_20240119_0201::solutionQ05(vector<string> intStrs, int k, int s, int l) {

    vector<int> answer;

    for (int i = 0; i < intStrs.size(); i++) {
        string tmp = "";
        for (int j = s; j < s + l; j++) {
            tmp += intStrs[i][j];
        }
        int num = stoi(tmp);
        if (num > k)
            answer.push_back(num);
    }
    return answer;
}


/*
* 코딩 기초 트레이닝
부분 문자열 이어 붙여 문자열 만들기

길이가 같은 문자열 배열 my_strings와 이차원 정수 배열 parts가 매개변수로 주어집니다.
parts[i]는 [s, e] 형태로, my_string[i]의 인덱스 s부터 인덱스 e까지의 부분 문자열을 의미합니다.
각 my_strings의 원소의 parts에 해당하는 부분 문자열을 순서대로 이어 붙인 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

string Q_20240119_0201::solutionQ06(vector<string> my_strings, vector<vector<int>> parts) {

    string answer = "";

    for (int i = 0; i < my_strings.size(); i++) {
        int start = parts[i][0];
        int end = parts[i][1];

        for (int j = start; j <= end; j++) {
            answer += my_strings[i][j];
        }
    }

    return answer;
}


/*
코딩 기초 트레이닝
문자열의 뒤의 n글자

문자열 my_string과 정수 n이 매개변수로 주어질 때, my_string의 뒤의 n글자로 이루어진 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

string Q_20240119_0201::solutionQ07(string my_string, int n) {
    string answer = "";

    for (int i = 0; i < n; i++) {
        answer = my_string[my_string.size() - 1 - i] + answer;
    }

    answer = string { my_string.end() - n, my_string.end() };

    answer = my_string.substr(my_string.size()-n);

    answer = my_string.erase(0, my_string.size() - n);

    return answer;
}



/*
코딩 기초 트레이닝
접미사 배열

어떤 문자열에 대해서 접미사는 특정 인덱스부터 시작하는 문자열을 의미합니다. 예를 들어, "banana"의 모든 접미사는 "banana", "anana", "nana", "ana", "na", "a"입니다.
문자열 my_string이 매개변수로 주어질 때, my_string의 모든 접미사를 사전순으로 정렬한 문자열 배열을 return 하는 solution 함수를 작성해 주세요.
*/

vector<string> Q_20240119_0201::solutionQ08(string my_string) {
    vector<string> answer;

    for (int i = 0; i < my_string.size(); i++) {
        answer.push_back(my_string.substr(my_string.size() - 1 - i));
    }


    sort(answer.begin(), answer.end());

    return answer;
}

/*
코딩 기초 트레이닝
접미사인지 확인하기

어떤 문자열에 대해서 접미사는 특정 인덱스부터 시작하는 문자열을 의미합니다. 예를 들어, "banana"의 모든 접미사는 "banana", "anana", "nana", "ana", "na", "a"입니다.
문자열 my_string과 is_suffix가 주어질 때, is_suffix가 my_string의 접미사라면 1을, 아니면 0을 return 하는 solution 함수를 작성해 주세요.
*/

int Q_20240119_0201::solutionQ09(string my_string, string is_suffix) {

    int index = my_string.size() - is_suffix.size();
    if (index < 0) return 0;

    return my_string.substr(index).find(is_suffix) == -1 ? 0 : 1;
}



/*
월간 코드 챌린지 시즌3
빛의 경로 사이클
각 칸마다 S, L, 또는 R가 써져 있는 격자가 있습니다. 당신은 이 격자에서 빛을 쏘고자 합니다. 이 격자의 각 칸에는 다음과 같은 특이한 성질이 있습니다.

빛이 "S"가 써진 칸에 도달한 경우, 직진합니다.
빛이 "L"이 써진 칸에 도달한 경우, 좌회전을 합니다.
빛이 "R"이 써진 칸에 도달한 경우, 우회전을 합니다.
빛이 격자의 끝을 넘어갈 경우, 반대쪽 끝으로 다시 돌아옵니다. 예를 들어, 빛이 1행에서 행이 줄어드는 방향으로 이동할 경우, 같은 열의 반대쪽 끝 행으로 다시 돌아옵니다.
당신은 이 격자 내에서 빛이 이동할 수 있는 경로 사이클이 몇 개 있고, 각 사이클의 길이가 얼마인지 알고 싶습니다. 경로 사이클이란, 빛이 이동하는 순환 경로를 의미합니다.

예를 들어, 다음 그림은 격자 ["SL","LR"]에서 1행 1열에서 2행 1열 방향으로 빛을 쏠 경우, 해당 빛이 이동하는 경로 사이클을 표현한 것입니다.

https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f3c02c50-f82e-45d0-b633-ad3ecadba316/ex1.png

이 격자에는 길이가 16인 사이클 1개가 있으며, 다른 사이클은 존재하지 않습니다.

격자의 정보를 나타내는 1차원 문자열 배열 grid가 매개변수로 주어집니다. 주어진 격자를 통해 만들어지는 빛의 경로 사이클의 모든 길이들을 배열에 담아 오름차순으로 정렬하여 return 하도록 solution 함수를 완성해주세요.

grid	    result
["SL","LR"]	[16]
["S"]	    [1,1,1,1]
["R","R"]	[4,4]
*/


//인풋이 들어오면 
//아웃풋이 나와야함

//노드는 들어오는 빛 방향, 위치 로 구성
//즉 인풋 + 현재 위치 로 구성
//아웃 풋 = 다음 인풋+다음 위치로 구성

//현재 위치에서 4방향을 모두 검사해야한다.

//들어오는 위치에 따라서 input은 
//x,y -> x,y
//x,y -> y,x
//x,y -> -y,-x
//이 3가지 조합으로 구성됨

//즉 들어오는 순간 map에 데이터가(node) 있는 지 검사
//있다면 그건 루프가 완성된 데이터임

//만약 데이터가 없다면 루프를 검사한다.

//루프를 검사하고 데이터를 저장한다.

//모든 그리드에 대해서 해당 검사를 진행하고 마지막에 오름차순으로 정렬



class mynode {
public:
    mynode(int _pos, int _x, int _y) {
        pos = _pos;
        x = _x;
        y = _y;
    }

    int pos;
    int x;
    int y;


    static string GetString(int pos, int type) {
        string answer = "";
        string tmp = to_string(pos);

        if (type == 0) {
            answer = tmp + 'A';
        }
        else if (type == 1) {
            answer = tmp + 'B';
        }
        else if (type == 2) {
            answer = tmp + 'C';
        }
        else if (type == 3) {
            answer = tmp + 'D';
        }

        return answer;
    }
    static string GetString(int pos, int x, int y) {
        string answer = "";
        string tmp = to_string(pos);


        if (x == 1) {
            answer = tmp + 'A';
        }
        else if (x == -1) {
            answer = tmp + 'B';
        }
        else if (y == 1) {
            answer = tmp + 'C';
        }
        else if (y == -1) {
            answer = tmp + 'D';
        }

        return answer;
    }

    string GetString() {
        string answer = "";
        string tmp = to_string(pos);

        if (x == 1) {
            answer = tmp + 'A';
        }
        else if (x == -1) {
            answer = tmp + 'B';
        }
        else if (y == 1) {
            answer = tmp + 'C';
        }
        else if (y == -1) {
            answer = tmp + 'D';
        }

        return answer;
    }


    mynode GetNextNode(char type, int w, int h) {
        int nextPosX;
        int nextPosY;

        int nextX = x;
        int nextY = y;

        switch (type)
        {
        case 'S':
            nextX = x;
            nextY = y;
            break;
        case 'L':
            nextX = y;
            nextY = -x;
            break;
        case 'R':
            nextX = -y;
            nextY = x;
            break;
        }
        nextPosX = pos % w + nextX;
        nextPosY = pos / w + nextY;
        if (nextPosX >= w) nextPosX = 0;
        else if (nextPosX < 0) nextPosX = w - 1;
        if (nextPosY >= h) nextPosY = 0;
        else if (nextPosY < 0) nextPosY = h - 1;

        mynode n = mynode(nextPosY * w + nextPosX, nextX, nextY);
        return n;

    }

};



int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };


vector<int> Q_20240119_0201::solutionQ10(vector<string> grid) {
    vector<int> answer;
    unordered_set<string> set;

    int width = grid[0].size();
    int height = grid.size();

    for (int start = 0; start < height * width; start++) {
        for (int k = 0; k < 4; k++) {
            mynode currNode = mynode(start, dir[k][0], dir[k][1]);
            if (set.count(currNode.GetString()) > 0) {
                continue;
            }
            int result = 0;
            while (set.count(currNode.GetString()) == 0) {
                result += 1;
                int w = currNode.pos % width;
                int h = currNode.pos / width;
                set.insert(currNode.GetString());
                currNode = currNode.GetNextNode(grid[h][w], width, height);
            }
            answer.push_back(result);
        }
    }
    sort(answer.begin(), answer.end());




    return answer;
}

/*
2024 KAKAO WINTER INTERNSHIP
도넛과 막대 그래프

도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프들이 있습니다. 
이 그래프들은 1개 이상의 정점과, 정점들을 연결하는 단방향 간선으로 이루어져 있습니다.

크기가 n인 도넛 모양 그래프는 n개의 정점과 n개의 간선이 있습니다. 
도넛 모양 그래프의 아무 한 정점에서 출발해 이용한 적 없는 간선을 계속 따라가면 나머지 n-1개의 정점들을 한 번씩 방문한 뒤 원래 출발했던 정점으로 돌아오게 됩니다.
도넛 모양 그래프의 형태는 다음과 같습니다.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/dbf6ff18-1f05-46c2-8b62-7c39e831d1c6/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio.png

크기가 n인 막대 모양 그래프는 n개의 정점과 n-1개의 간선이 있습니다. 
막대 모양 그래프는 임의의 한 정점에서 출발해 간선을 계속 따라가면 나머지 n-1개의 정점을 한 번씩 방문하게 되는 정점이 단 하나 존재합니다. 
막대 모양 그래프의 형태는 다음과 같습니다.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/85e3e66c-bba0-4da3-9552-c467dfe5baf4/%E1%84%83%E1%85%A9%E1%84%82%E1%85%A5%E1%86%BA%E1%84%80%E1%85%AA%E1%84%86%E1%85%A1%E1%86%A8%E1%84%83%E1%85%A22.png
크기가 n인 8자 모양 그래프는 2n+1개의 정점과 2n+2개의 간선이 있습니다. 
8자 모양 그래프는 크기가 동일한 2개의 도넛 모양 그래프에서 정점을 하나씩 골라 결합시킨 형태의 그래프입니다.
8자 모양 그래프의 형태는 다음과 같습니다.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/868f2c14-8521-4c94-a2f0-1e11708aa76a/8%E1%84%8C%E1%85%A1%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%84%91%E1%85%B3.drawio.png

도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프가 여러 개 있습니다. 
이 그래프들과 무관한 정점을 하나 생성한 뒤, 각 도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 임의의 정점 하나로 향하는 간선들을 연결했습니다.
그 후 각 정점에 서로 다른 번호를 매겼습니다.
이때 당신은 그래프의 간선 정보가 주어지면 생성한 정점의 번호와 
정점을 생성하기 전 도넛 모양 그래프의 수,
막대 모양 그래프의 수,
8자 모양 그래프의 수를 구해야 합니다.

그래프의 간선 정보를 담은 2차원 정수 배열 edges가 매개변수로 주어집니다.
이때, 생성한 정점의 번호, 
도넛 모양 그래프의 수, 
막대 모양 그래프의 수, 
8자 모양 그래프의 수를 순서대로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
*/