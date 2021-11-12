#include <bits/stdc++.h>
using namespace std;

/*
Let's do square root decomposition to find the sum of elements in a given range.  

This algorithm splits up the array into O(sqrt(n)) sized blocks and O(sqrt(n)) blocks.  
In O(n) time we preprocess the sums over each block.  

There are two types of queries:
1) The query completing overlaps each block in the [l,r] range query, in that case it is O(sqrt(n)) time 
to sum up all the blocks
2) The query does not overlap a block, in that case you iterate through the nonoverlapped portions in O(sqrt(n)). 
And sum up the rest of them. 

overlapped blocks + nonoverlapped blocks = O(sqrt(n))
*/

// Example of using square root decomposition to solve the dynamic range sum queries problem. 
struct Query {
    int l, r, id,k,u;
};

void dynamicRangeSumQueries(vector<long long>& a, vector<Query>& queries) {
    int n = a.size();
    const int BLOCK = int(ceil(sqrt(n))); // the ceiling of sqrt(n)
    vector<long long> b(BLOCK,0); // the block array
    for (int i = 0;i<n;i++) {
        b[i/BLOCK] += a[i];
    }
    for (Query &q : queries) {

        // first query of type 1 is an update query, updates value at position 
        if (q.id==1) {
            long long k = q.k, u = q.u;
            b[k/BLOCK] += u - a[k];
            a[k]=u;
        } else if (q.id==2) {
            long long l = q.l, r = q.r;
            long long sum = 0;
            long long c_l = l/BLOCK, c_r = r/BLOCK; // the block number of the query
            if (c_l==c_r) {
                for (long long i = l;i<=r;i++) {
                    sum += a[i];
                }
            } else {
                for (long long i = l, end = (c_l+1)*BLOCK;i<end;i++) {
                    sum += a[i];
                }
                for (long long i = c_l+1;i<=c_r-1;i++) {
                    sum += b[i];
                }
                for (long long i = c_r*BLOCK, end = r;i<=end;i++) {
                    sum += a[i];
                }
            }
            printf("%lld\n",sum);
        }
    }
}

// int main() {
//     long long n,q,x,y,z;
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     cin>>n>>q;
//     vector<long long> a(n,0);
//     for (long long i = 0;i<n;i++) {
//         cin>>x;
//         a[i]=x;
//     }
//     vector<Query> qs(q);
//     for (long long i = 0;i<q;i++) {
//         cin>>x>>y>>z;
//         qs[i].id=x;
//         if (x==1) {
//             qs[i].k=y-1;
//             qs[i].u=z;
//         } else {
//             qs[i].l = y-1;
//             qs[i].r = z-1;
//         }

//     }
//     dynamicRangeSumQueries(a,qs);
// }



/*
Mo's algorithm is a variation of the square root decomposition algorithm.
*/

void remove(idx); //TODO: remove value at idx from data structure
void add(idx); // TODO: add value at idx to data structure
int get_answer(); // TODO: extract the current answer of the data structure

const int BLOCK;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l/BLOCK, r)<make_pair(other.l/BLOCK, other.r);
    }
};

vector<int> mosAlgorithm(vector<Query> queries) {
    vector<int> answer(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0, cur_r = -1;
    // invariant: data structure will always reflect tha range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l>q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r<q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l<q.l) {}
            remove(cur_l);
            cur_l++;
        }
        while (cur_r>q.r) {}
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

// Example of using Mo's algorithm to solve the little elephant array problem from CF
// We want to store the frequency, cause want to store the answer for the number of elements
// that have a frequency equal to the value of the element in a range. 

int cnt;
int BLOCK;
const int N = 1e5+5;
vector<int> arr;
int freq[N];


struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l/BLOCK, r)<make_pair(other.l/BLOCK, other.r);
    }
};

void remove(int idx) {
    if (freq[arr[idx]] == arr[idx]+1) {
        cnt++;
    }
    if (freq[arr[idx]]-- == arr[idx]) {
        cnt--;
    }
}
void add(int idx) {
    if (freq[arr[idx]] == arr[idx]) {
        cnt--;
    }
    if (++freq[arr[idx]] == arr[idx]) {
        cnt++;
    }
}
int get_answer() {
    return cnt;
}

vector<int> mosAlgorithm(vector<Query>& queries) {
    vector<int> answer(queries.size(),0);
    sort(queries.begin(), queries.end());
    int cur_l = 0, cur_r = -1;
    // invariant: data structure will always reflect tha range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l>q.l) {
            cur_l--;
            if (arr[cur_l]>=N) {continue;}
            add(cur_l);
        }
        while (cur_r<q.r) {
            cur_r++;
            if (arr[cur_r]>=N) {continue;}
            add(cur_r);
        }
        while (cur_l<q.l) {
            if (arr[cur_l]>=N) {
                cur_l++;
                continue;
            }
            remove(cur_l);
            cur_l++;
        }
        while (cur_r>q.r) {
            if (arr[cur_r]>=N) {
                cur_r--;
                continue;
            }
            remove(cur_r);
            cur_r--;
        }
        answer[q.idx] = get_answer();
    }
    return answer;
}

// int main() {
//     int n,q,x,y;
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     cin>>n>>q;
//     BLOCK = int(ceil(sqrt(n)));
//     cnt = 0;
//     arr.resize(n);
//     for (int i = 0;i<n;i++) {
//         cin>>x;
//         arr[i]=x;
//     }
//     vector<Query> qs(q);
//     for (long long i = 0;i<q;i++) {
//         cin>>qs[i].l>>qs[i].r;
//         qs[i].idx = i;
//         qs[i].l--;
//         qs[i].r--;
//     }
//     vector<int> qres = mosAlgorithm(qs);
//     for (int &q : qres) {
//         cout<<q<<endl;
//     }
// }
