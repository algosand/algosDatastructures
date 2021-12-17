#include <bits/stdc++.h>
using namespace std;

/*
An excellent method to create an array of tokens from a string that is space separated
*/
vector<string> getTokenArray(string &s) {
    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> tokens(begin,end);
    return tokens;
}  

/*
A more general version of the function above. 
A method to create an array of strings from a string with a specific delimiter, this one
uses delimiter delim
*/
vector<string> getArray(string &str, char delim) {
  vector<string> nodes;
  stringstream ss(str);
  string tmp;
  while (getline(ss, tmp, delim)) {
    if (tmp.empty()) {continue;}
    nodes.push_back(tmp);
  }
  return nodes;
}

/*
This returns a array datastructure using vectors in C++ to 
convert an input string with some form of delimiter into and array datastructure
*/
vector<int> getArray(string &str, char delim) {
  vector<int> nodes;
  stringstream ss(str);
  string tmp;
  while (getline(ss, tmp, delim)) {
    if (tmp.empty()) {continue;}
    nodes.push_back(stoi(tmp));
  }
  return nodes;
}
/*
This is returning a vector of char. 
*/
vector<char> getArrayChar(string &str, char delim) {
  vector<char> nodes;
  int n = str.size();
  for (int i = 0;i<n;i++) {
    if (str[i]==delim) {continue;}
    nodes.push_back(str[i]);
  }
  return nodes;
}

/*

*/


/*
count leading tabs in a string
*/
int countTabs(string& str) {
    int count = 0;
    int n = str.size();
    for (int i = 0;i<n;i++) {
        if (str[i]!='\t') {break;}
        count++;
    }
    return count;
}