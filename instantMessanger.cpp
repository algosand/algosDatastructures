#include <bits/stdc++.h>
using namespace std;
/*
Instant Messanger from codeforces, with the following queries:
login
logout
add_friend
del_friend
count_online_friends   
*/

int n, m, q,u,v,o;
const int BLOCK = 500;
vector<int> numOnlineFriends;
unordered_set<int> heavy;
vector<unordered_set<int>> g;
vector<bool> online;
void connect(int u, int v) {
    if (g[u].size()<BLOCK) {
        numOnlineFriends[v] += online[u];
    }
    g[u].insert(v);
    if (g[u].size()==BLOCK) {
        for (auto v : g[u]) {
            numOnlineFriends[v] -= online[u];
        }
        heavy.insert(u);
    }
}
void update(int u, int x) {
    online[u]=x;
    if (g[u].size()<BLOCK) {
        for (auto v:g[u]) {
            numOnlineFriends[v] += (x==0?-1:1);
        }
    }
}
void disconnect(int u, int v) {
    if (g[u].size()<BLOCK) {
        numOnlineFriends[v] -= online[u];
    }
    g[u].erase(v);
    // downgraded to a light node
    if (g[u].size()==BLOCK-1) {
        for (auto v : g[u]) {
            numOnlineFriends[v] += online[u];
        }
        heavy.erase(u);
    }
}
int countOnlineFriends(int u) {
    int ans = numOnlineFriends[u];
    for (auto v:heavy) {
        if (g[u].find(v)!=g[u].end()) {
            ans += numOnlineFriends[v];
        }
    }
    return ans;
}

int main() {
    cin>>n>>m>>q;
    numOnlineFriends.assign(n+1,0);
    g.assign(n+1,unordered_set<int>());
    // use square root decomposition to solve queries in O(1) time
    // n is the number of users
    // m is the number of friends
    // q is the number of queries
    // u is the user id
    // v is the friend id
    // o is the number of online friends
    // use a vector of vectors to store the friends of each user
    // use light and heavy nodes
    // use a vector of ints to store the number of friends of each user
    online.assign(n+1,false);
    cin>>o;
    for (int i = 0;i<o;i++) {
        cin>>u;
        online[u]=true;
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        connect(u,v);
        connect(v,u);
    }
    for (int i = 0;i<q;i++) {
        char query;
        cin>>query;
        // user u logins
        if (query=='O') {
            cin>>u;
            update(u,1);
        }
        else if (query=='F') {
            cin>>u;
            update(u,0);
        }
        else if (query=='A') {
            cin>>u>>v;
            connect(u,v);
            connect(v,u);
        }
        else if (query=='D') {
            cin>>u>>v;
            disconnect(u,v);
            disconnect(v,u);
        }
        // count number of online friends of user u
        else if (query=='C') {
            cin>>u;
            cout<<countOnlineFriends(u)<<endl;
        }
    }

}