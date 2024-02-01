#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>

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

    vector<vector<vector<int>>> q4_1;
    vector<string> q4_2;
    vector<int> q4_3;
    vector<string> q4_4;

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



class Q_20240116 {
public:
    Q_20240116();

    int solutionQ1(int a, int b);
    int solutionQ2(int a, int b);
    int solutionQ3(int a);
    int solutionQ4(string ineq, string eq, int n, int m);
    vector<string> solutionQ5(vector<string> players, vector<string> callings);
};

class Q_20240117 {
public:
    Q_20240117();

    string solutionQ1(string);
    int solutionQ2(int a, int d, vector<bool> included);
    int solutionQ3(int a, int, int);
    int solutionQ4(vector<int> num_list);
    int solutionQ5(vector<int> num_list);
};

class Q_20240118 {
public:
    Q_20240118();

    vector<int> solutionQ1(vector<int> num_list);
    int solutionQ2(int n, string control);
    string solutionQ3(vector<int> numLog);
    vector<int> solutionQ4(vector<int> arr, vector<vector<int>> queries);
    vector<int> solutionQ5(vector<int> arr, vector<vector<int>> queries);
    vector<int> solutionQ6(vector<int> arr, vector<vector<int>> queries);
    vector<int> solutionQ7(int l, int r);
    vector<int> solutionQ8(int start_num, int end_num);
    vector<int> solutionQ9(int n);
    vector<int> solutionQ10(vector<int> arr);
    vector<int> solutionQ11(vector<string> park, vector<string> routes);
    vector<int> solutionQ12(string today, vector<string> terms, vector<string> privacies);
};

class Q_20240119_0201 {
public:
    Q_20240119_0201();

    int solutionQ01(int a, int b, int c, int d);
    string solutionQ02(string my_string, vector<int> index_list);
    int solutionQ03(string number);
    string solutionQ04(string my_string, vector<vector<int>> queries);
    vector<int> solutionQ05(vector<string> intStrs, int k, int s, int l);
    string solutionQ06(vector<string> my_strings, vector<vector<int>> parts);
    string solutionQ07(string my_string, int n);
    vector<string> solutionQ08(string my_string);
    int solutionQ09(string my_string, string is_suffix);
    vector<int> solutionQ10(vector<string> grid);
};
