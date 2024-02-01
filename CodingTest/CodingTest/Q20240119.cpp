#include "header.h"

Q_20240119_0201::Q_20240119_0201() {

}

/*
* 
* �ڵ� ���� Ʈ���̴�
������ �� ����

boolean ���� x1, x2, x3, x4�� �Ű������� �־��� ��, ������ ���� true/false�� return �ϴ� solution �Լ��� �ۼ��� �ּ���.

(x1 �� x2) �� (x3 �� x4)
*/

bool solution(bool x1, bool x2, bool x3, bool x4) {
    return (x1 || x2) && (x3 || x4);
}
/*
�ڵ� ���� Ʈ���̴�
�ֻ��� ���� 3

1���� 6���� ���ڰ� ���� �ֻ����� �� �� �ֽ��ϴ�. �� �ֻ����� ������ �� ���� ���ڿ� ���� ������ ���� ������ ����ϴ�.

�� �ֻ������� ���� ���ڰ� ��� p�� ���ٸ� 1111 �� p���� ����ϴ�.
�� �ֻ������� ���� ���ڰ� p�� ���� ������ �ٸ� �ֻ������� ���� ���ڰ� q(p �� q)��� (10 �� p + q)^2 ���� ����ϴ�.
�ֻ����� �� ���� ���� ���� ������, ���� ���ڸ� ���� p, q(p �� q)��� �Ѵٸ� (p + q) �� |p - q|���� ����ϴ�.
��� �� �ֻ������� ���� ���ڰ� p�� ���� ������ �� �ֻ������� ���� ���ڰ� ���� p�� �ٸ� q, r(q �� r)�̶�� q �� r���� ����ϴ�.
�� �ֻ����� ���� ���ڰ� ��� �ٸ��ٸ� ���� ���� �� ���� ���� ���� ��ŭ�� ������ ����ϴ�.
�� �ֻ����� ������ �� ���� ���ڰ� ���� �Ű����� a, b, c, d�� �־��� ��, ��� ������ return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
���� �̾� �ٿ� ���ڿ� �����

���ڿ� my_string�� ���� �迭 index_list�� �Ű������� �־����ϴ�.
my_string�� index_list�� ���ҵ鿡 �ش��ϴ� �ε����� ���ڵ��� ������� �̾� ���� ���ڿ��� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
9�� ���� ������

���� �ƴ� ������ 9�� ���� �������� �� ������ �� �ڸ� ������ ���� 9�� ���� �������� ���� ���� �˷��� �ֽ��ϴ�.
�� ����� �̿��Ͽ� ���� �ƴ� ������ ���ڿ� number�� �־��� ��, �� ������ 9�� ���� �������� return �ϴ� solution �Լ��� �ۼ����ּ���.
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
* �ڵ� ���� Ʈ���̴�
���ڿ� ���� �� ������

���ڿ� my_string�� ������ ���� �迭 queries�� �Ű������� �־����ϴ�. 
queries�� ���Ҵ� [s, e] ���·�, my_string�� �ε��� s���� �ε��� e������ ��������� �ǹ��Դϴ�.
my_string�� queries�� ����� ������� ó���� ���� ���ڿ��� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
�迭 ����� 5

���ڿ� �迭 intStrs�� ���� k, s, l�� �־����ϴ�. intStrs�� ���Ҵ� ���ڷ� �̷���� �ֽ��ϴ�.
�迭 intStrs�� �� ���Ҹ��� s�� �ε������� �����ϴ� ���� l¥�� �κ� ���ڿ��� �߶� ������ ��ȯ�մϴ�. 
�̶� ��ȯ�� �������� k���� ū ������ ���� �迭�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.
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
* �ڵ� ���� Ʈ���̴�
�κ� ���ڿ� �̾� �ٿ� ���ڿ� �����

���̰� ���� ���ڿ� �迭 my_strings�� ������ ���� �迭 parts�� �Ű������� �־����ϴ�.
parts[i]�� [s, e] ���·�, my_string[i]�� �ε��� s���� �ε��� e������ �κ� ���ڿ��� �ǹ��մϴ�.
�� my_strings�� ������ parts�� �ش��ϴ� �κ� ���ڿ��� ������� �̾� ���� ���ڿ��� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
���ڿ��� ���� n����

���ڿ� my_string�� ���� n�� �Ű������� �־��� ��, my_string�� ���� n���ڷ� �̷���� ���ڿ��� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
���̻� �迭

� ���ڿ��� ���ؼ� ���̻�� Ư�� �ε������� �����ϴ� ���ڿ��� �ǹ��մϴ�. ���� ���, "banana"�� ��� ���̻�� "banana", "anana", "nana", "ana", "na", "a"�Դϴ�.
���ڿ� my_string�� �Ű������� �־��� ��, my_string�� ��� ���̻縦 ���������� ������ ���ڿ� �迭�� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
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
�ڵ� ���� Ʈ���̴�
���̻����� Ȯ���ϱ�

� ���ڿ��� ���ؼ� ���̻�� Ư�� �ε������� �����ϴ� ���ڿ��� �ǹ��մϴ�. ���� ���, "banana"�� ��� ���̻�� "banana", "anana", "nana", "ana", "na", "a"�Դϴ�.
���ڿ� my_string�� is_suffix�� �־��� ��, is_suffix�� my_string�� ���̻��� 1��, �ƴϸ� 0�� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
*/

int Q_20240119_0201::solutionQ09(string my_string, string is_suffix) {

    int index = my_string.size() - is_suffix.size();
    if (index < 0) return 0;

    return my_string.substr(index).find(is_suffix) == -1 ? 0 : 1;
}



/*
���� �ڵ� ç���� ����3
���� ��� ����Ŭ
�� ĭ���� S, L, �Ǵ� R�� ���� �ִ� ���ڰ� �ֽ��ϴ�. ����� �� ���ڿ��� ���� ����� �մϴ�. �� ������ �� ĭ���� ������ ���� Ư���� ������ �ֽ��ϴ�.

���� "S"�� ���� ĭ�� ������ ���, �����մϴ�.
���� "L"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� "R"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� ������ ���� �Ѿ ���, �ݴ��� ������ �ٽ� ���ƿɴϴ�. ���� ���, ���� 1�࿡�� ���� �پ��� �������� �̵��� ���, ���� ���� �ݴ��� �� ������ �ٽ� ���ƿɴϴ�.
����� �� ���� ������ ���� �̵��� �� �ִ� ��� ����Ŭ�� �� �� �ְ�, �� ����Ŭ�� ���̰� ������ �˰� �ͽ��ϴ�. ��� ����Ŭ�̶�, ���� �̵��ϴ� ��ȯ ��θ� �ǹ��մϴ�.

���� ���, ���� �׸��� ���� ["SL","LR"]���� 1�� 1������ 2�� 1�� �������� ���� �� ���, �ش� ���� �̵��ϴ� ��� ����Ŭ�� ǥ���� ���Դϴ�.

https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f3c02c50-f82e-45d0-b633-ad3ecadba316/ex1.png

�� ���ڿ��� ���̰� 16�� ����Ŭ 1���� ������, �ٸ� ����Ŭ�� �������� �ʽ��ϴ�.

������ ������ ��Ÿ���� 1���� ���ڿ� �迭 grid�� �Ű������� �־����ϴ�. �־��� ���ڸ� ���� ��������� ���� ��� ����Ŭ�� ��� ���̵��� �迭�� ��� ������������ �����Ͽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.

grid	    result
["SL","LR"]	[16]
["S"]	    [1,1,1,1]
["R","R"]	[4,4]
*/


//��ǲ�� ������ 
//�ƿ�ǲ�� ���;���

//���� ������ �� ����, ��ġ �� ����
//�� ��ǲ + ���� ��ġ �� ����
//�ƿ� ǲ = ���� ��ǲ+���� ��ġ�� ����

//���� ��ġ���� 4������ ��� �˻��ؾ��Ѵ�.

//������ ��ġ�� ���� input�� 
//x,y -> x,y
//x,y -> y,x
//x,y -> -y,-x
//�� 3���� �������� ������

//�� ������ ���� map�� �����Ͱ�(node) �ִ� �� �˻�
//�ִٸ� �װ� ������ �ϼ��� ��������

//���� �����Ͱ� ���ٸ� ������ �˻��Ѵ�.

//������ �˻��ϰ� �����͸� �����Ѵ�.

//��� �׸��忡 ���ؼ� �ش� �˻縦 �����ϰ� �������� ������������ ����



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
���Ӱ� ���� �׷���

���� ��� �׷���, ���� ��� �׷���, 8�� ��� �׷������� �ֽ��ϴ�. 
�� �׷������� 1�� �̻��� ������, �������� �����ϴ� �ܹ��� �������� �̷���� �ֽ��ϴ�.

ũ�Ⱑ n�� ���� ��� �׷����� n���� ������ n���� ������ �ֽ��ϴ�. 
���� ��� �׷����� �ƹ� �� �������� ����� �̿��� �� ���� ������ ��� ���󰡸� ������ n-1���� �������� �� ���� �湮�� �� ���� ����ߴ� �������� ���ƿ��� �˴ϴ�.
���� ��� �׷����� ���´� ������ �����ϴ�.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/dbf6ff18-1f05-46c2-8b62-7c39e831d1c6/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio.png

ũ�Ⱑ n�� ���� ��� �׷����� n���� ������ n-1���� ������ �ֽ��ϴ�. 
���� ��� �׷����� ������ �� �������� ����� ������ ��� ���󰡸� ������ n-1���� ������ �� ���� �湮�ϰ� �Ǵ� ������ �� �ϳ� �����մϴ�. 
���� ��� �׷����� ���´� ������ �����ϴ�.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/85e3e66c-bba0-4da3-9552-c467dfe5baf4/%E1%84%83%E1%85%A9%E1%84%82%E1%85%A5%E1%86%BA%E1%84%80%E1%85%AA%E1%84%86%E1%85%A1%E1%86%A8%E1%84%83%E1%85%A22.png
ũ�Ⱑ n�� 8�� ��� �׷����� 2n+1���� ������ 2n+2���� ������ �ֽ��ϴ�. 
8�� ��� �׷����� ũ�Ⱑ ������ 2���� ���� ��� �׷������� ������ �ϳ��� ��� ���ս�Ų ������ �׷����Դϴ�.
8�� ��� �׷����� ���´� ������ �����ϴ�.
https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/868f2c14-8521-4c94-a2f0-1e11708aa76a/8%E1%84%8C%E1%85%A1%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%84%91%E1%85%B3.drawio.png

���� ��� �׷���, ���� ��� �׷���, 8�� ��� �׷����� ���� �� �ֽ��ϴ�. 
�� �׷������ ������ ������ �ϳ� ������ ��, �� ���� ��� �׷���, ���� ��� �׷���, 8�� ��� �׷����� ������ ���� �ϳ��� ���ϴ� �������� �����߽��ϴ�.
�� �� �� ������ ���� �ٸ� ��ȣ�� �Ű���ϴ�.
�̶� ����� �׷����� ���� ������ �־����� ������ ������ ��ȣ�� 
������ �����ϱ� �� ���� ��� �׷����� ��,
���� ��� �׷����� ��,
8�� ��� �׷����� ���� ���ؾ� �մϴ�.

�׷����� ���� ������ ���� 2���� ���� �迭 edges�� �Ű������� �־����ϴ�.
�̶�, ������ ������ ��ȣ, 
���� ��� �׷����� ��, 
���� ��� �׷����� ��, 
8�� ��� �׷����� ���� ������� 1���� ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.
*/