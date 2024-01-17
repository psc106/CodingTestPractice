#include "header.h"

Q_20240116::Q_20240116() {

}

/*
* 두 수의 연산값 비교하기
* 코딩 기초 트레이닝

연산 ⊕는 두 정수에 대한 연산으로 두 정수를 붙여서 쓴 값을 반환합니다. 예를 들면 다음과 같습니다.

12 ⊕ 3 = 123
3 ⊕ 12 = 312
양의 정수 a와 b가 주어졌을 때, a ⊕ b와 2 * a * b 중 더 큰 값을 return하는 solution 함수를 완성해 주세요.

단, a ⊕ b와 2 * a * b가 같으면 a ⊕ b를 return 합니다.
*/
int Q_20240116::solutionQ1(int a, int b) {
    int data1 = 2 * a * b;
    int data2 = stoi(to_string(a)+ to_string(b));
    return data1 > data2 ? data1 : data2;
}

/*
* 코딩 기초 트레이닝
n의 배수

정수 num과 n이 매개 변수로 주어질 때, num이 n의 배수이면 1을 return n의 배수가 아니라면 0을 return하도록 solution 함수를 완성해주세요.
*/
int Q_20240116::solutionQ2(int num, int n) {
    return num % n == 0;
}

/*
* 코딩 기초 트레이닝
홀짝에 따라 다른 값 반환하기

양의 정수 n이 매개변수로 주어질 때, 
n이 홀수라면 n 이하의 홀수인 모든 양의 정수의 합을 return 하고
n이 짝수라면 n 이하의 짝수인 모든 양의 정수의 제곱의 합을 return 하는 
solution 함수를 작성해 주세요.
*/

int Q_20240116::solutionQ3(int n) {

    if (n % 2 == 1) {
        return (n + (n / 2) * (n / 2));
    }
    else {
        int even = 0;
        for (int i = 2; i <= n; i += 2) {
            even += i * i;
        }
        return even;
    }
}

/*
* 코딩 기초 트레이닝
조건 문자열

문자열에 따라 다음과 같이 두 수의 크기를 비교하려고 합니다.

두 수가 n과 m이라면
">", "=" : n >= m
"<", "=" : n <= m
">", "!" : n > m
"<", "!" : n < m
두 문자열 ineq와 eq가 주어집니다.
ineq는 "<"와 ">"중 하나고, eq는 "="와 "!"중 하나입니다. 
그리고 두 정수 n과 m이 주어질 때,
n과 m이 ineq와 eq의 조건에 맞으면 1을 아니면 0을 return하도록 solution 함수를 완성해주세요.
*/
int Q_20240116::solutionQ4(string ineq, string eq, int n, int m) {

    int l = n, r = m;
    if (ineq[0] == '>') {
        l = m, r = n;
    }

    bool equal = (n == m);
    bool result = (l < r);

    if (eq[0] == '=') {
        result = result || equal;
    }

    return result;
}


/*
* 연습문제
달리기 경주

얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다. 
예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때, 
해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다.
즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와 
해설진이 부른 이름을 담은 문자열 배열 callings가 매개변수로 주어질 때, 
경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.

players	callings	result
["mumu", "soe", "poe", "kai", "mine"]	["kai", "kai", "mine", "mine"]	["mumu", "kai", "mine", "soe", "poe"]

*/



vector<string> Q_20240116::solutionQ5(vector<string> players, vector<string> callings) {
    std::unordered_map<string, int> playerToOrder;
    std::unordered_map<int, string> ordersToPlayer;

    vector<string> result;

    for (int i = 0; i < players.size(); i++) {
        playerToOrder.insert({ players[i],i });
        ordersToPlayer.insert({ i,players[i] });
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int currOrder = playerToOrder[callings[i]];
        playerToOrder.erase(callings[i]);
        ordersToPlayer.erase(currOrder);

        string prePlayer = ordersToPlayer[currOrder-1];
        playerToOrder.erase(prePlayer);
        ordersToPlayer.erase(currOrder-1);

        playerToOrder.insert({ callings[i], currOrder - 1 });
        ordersToPlayer.insert({ currOrder - 1, callings[i] });
        playerToOrder.insert({ prePlayer,currOrder });
        ordersToPlayer.insert({ currOrder, prePlayer });

    }

    for (int i = 0; i < players.size(); i++) {
        result.push_back(ordersToPlayer[i]);
    }

    return result;
}