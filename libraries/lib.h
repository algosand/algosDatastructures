#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <regex>
#include <set>
#include <chrono>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mxl INT64_MAX
#define mnl INT64_MIN
#define mx INT32_MAX
#define mn INT32_MIN
#define endl '\n'
using namespace std;
using namespace std::chrono;

ll mod(ll a, ll b)
{
    return (a % b + b) % b;
}

// Printing vectors vvvvvvvvvvvvv
template <class T>
void printVec(vector<T> vec)
{
    cout << "[";
    for (auto val : vec)
    {
        cout << val << ",";
    }
    cout << "]" << endl;
}
template <class T>
void print2DVec(vector<vector<T>> &M)
{
    cout << "[" << endl;
    for (vector<T> row : M)
    {
        cout << "[";
        for (auto val : row)
        {
            cout << val << ",";
        }
        cout << "]," << endl;
    }
    cout << "]" << endl;
}

template <class T>
void print3DVec(vector<vector<vector<T>>> &vec)
{
    cout << '[';
    for (auto ve : vec)
    {
        cout << '[';
        for (auto v : ve)
        {
            cout << '[';
            for (auto &val : v)
            {
                cout << val << ',';
            }
            cout << ']' << endl;
            ;
        }
        cout << ']' << endl;
    }
    cout << ']' << endl;
}
// Printing vectors ^^^^^^^^^^^
void printArray(int arr[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}
template <class T>
void printMap(T mp)
{
    cout << "{";
    for (auto &v : mp)
    {
        cout << "{" << v.first << "," << v.second << "},";
    }
    cout << "}" << endl;
}

// template <class T>
// void printMapVec(T )

template <class T>
void printMapSet(T mp)
{
    cout << "{";
    for (auto v : mp)
    {
        cout << "[" << v.first << ":";
        for (auto u : v.second)
        {
            cout << u << ",";
        }
        cout << "],";
    }
    cout << "}" << endl;
}

// Printing out a set in nice format.
template <class T>
void printSet(T st)
{
    cout << "{";
    for (auto v : st)
    {
        cout << v << ",";
    }
    cout << "}" << endl;
}

template <class T>
void printNameElem(string name, T a)
{
    cout << name << ": " << a << endl;
}

template <class T>
void printElem(T a)
{
    cout << a << endl;
}

struct p3
{
    int i, j, k;

    bool operator==(const p3 &p) const
    {
        return this->i == p.i && this->j == p.j && this->k == p.k;
    }
};

struct hashFunc
{
    template <class T>
    size_t operator()(const T &p) const
    {
        auto hash1 = hash<T>()(p.i);
        auto hash2 = hash<T>()(p.j);
        auto hash3 = hash<T>()(p.k);
        return hash1 ^ hash2 ^ hash3;
    }
};

string makeString(vector<int> A)
{
    stringstream ss;
    for (int i = 0; i < A.size(); i++)
    {
        if (i != 0)
        {
            ss << " ";
        }
        ss << A[i];
    }
    return ss.str();
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

template <class T1, class T2>
void printPair(pair<T1, T2> p)
{
    cout << "{" << p.first << "," << p.second << "}" << endl;
}
template <class T1, class T2>
void printSetPair(unordered_set<pair<T1, T2>, hash_pair> s)
{
    cout << "{";
    for (auto p : s)
    {
        cout << "{" << p.first << "," << p.second << "},";
    }
    cout << "}" << endl;
}

template <class T1, class T2>
void printMapPair(unordered_map<pair<T1, T2>, pair<T1, T2>, hash_pair> mp)
{
    cout << "{";
    for (auto p : mp)
    {
        cout << "{" << p.first.first << "," << p.first.second << ": " << p.second.first << "," << p.second.second << "},";
    }
    cout << "}" << endl;
}

template <class T1, class T2>
void printPQ(priority_queue<pair<T1, T2>> &pq)
{
    T1 x;
    T2 y;
    while (!pq.empty())
    {
        tie(x, y) = pq.top();
        printf("x=%d,y=%s\n", x, y);
        pq.pop();
    }
}

// Prints vector of pairs
template <class T1, class T2>
void printPairVec(vector<pair<T1, T2>> &p)
{
    cout << "[";
    for (auto &[x, y] : p)
    {
        cout << "(" << x << "," << y << "),";
    }
    cout << "]" << endl;
}

template <class T>
void output(int t, T out)
{
    cout << "Case #" << t << ": " << out << endl;
}

int column(vector<vector<int>> &matrix, vector<vector<int>> &target, int n, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != target[i][j])
        {
            return 1;
        }
    }
    return 0;
}
int solve(vector<vector<int>> &matrix, vector<vector<int>> &target)
{
    int n, m, cnt = 0;
    n = matrix.size();
    m = matrix[0].size();
    sort(matrix.begin(), matrix.end());
    sort(target.begin(), target.end());

    for (int j = 0; j < m; j++)
    {
        if (column(matrix, target, n, j))
        {
            cnt++;
            for (int i = 0; i < n; i++)
                matrix[i][j] ^= 1;
        }
        sort(matrix.begin(), matrix.end());
        if (column(matrix, target, n, j))
        {
            return -1;
        }
    }
    return cnt;
}

const string IMPOSSIBLE = "IMPOSSIBLE";

// Algorithms

// Euclidean algorithm to compute greatest common denominator
template <class T>
T gcd(T a, T b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}