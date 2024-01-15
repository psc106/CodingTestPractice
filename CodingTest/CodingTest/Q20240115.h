#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Q_20240115 {
public:
    vector<vector<string>> q1_1;
    vector<vector<string>> q1_2;

    vector<vector<int>> q2_1;
    vector<int> q2_2;
    vector<vector<vector<int>>> q2_3;

    vector<vector<vector<string>>> q3_1;
    vector<int> q3_2;
    vector<int> q3_3;

    Q_20240115();
    int solutionQ1(vector<string> friends, vector<string> gifts);
    void Result1();
    int solutionQ2(vector<int> bandage, int health, vector<vector<int>> attacks);
    void Result2();
    int solutionQ3(vector<vector<string>> board, int h, int w);
    void Result3();
    vector<vector<int>> solutionQ4(vector<vector<int>> data, string ext, int val_ext, string sort_by);
    void Result4();
}; 
