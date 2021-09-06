#include <bits/stdc++.h>
using namespace std;
/*
This creates the coordinates structure or point struct, that can be used to perform
*/
struct P {
    long long x, y;
    void init() {
        cin>>x>>y;
    }
    void operator-=(const P &b) {
        x-=b.x;
        y-=b.y;
    }
    P operator-(const P &b) const {
        return P{x-b.x, y-b.y};
    }
    // cross product magnitude along the z-coordinate
    long long operator*(const P &b) const {
        return x*b.y-y*b.x;
    }
    bool operator<(const P &b) const {
        return make_pair(x,y)<make_pair(b.x,b.y);
    }
    long long triangle(const P &b, const P &c) const {
        return (b-*this)*(c-*this);
    }
};
/*
Graham's scan algorithm in O(nlogn)
*/
vector<P> convexHull(int N) {
    vector<P> points(N);
    for (int i = 0;i<N;i++) {
        P p;
        p.init();
        points[i]=p;
    }
    sort(points.begin(),points.end());
    vector<P> hull;
    for (int rep=0;rep<2;rep++) {
        const int S = hull.size();
        for (P c: points) {
            while (hull.size() - S >= 2) {
                P a = hull.end()[-2];
                P b = hull.end()[-1];
                if (a.triangle(b,c)<=0) {
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(c);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    return hull;
}

int main() {
    int N;
    cin>>N;
    vector<P> hull = convexHull(N);
}
/*
Another implementation of grahams scan for when you are using vector<int> for the points. and you need
to consider straight lines of length 1->3 also.  
*/
// cross product value of the z component, for vector (b-a)X(c-a)
int triangle(vector<int> &a, vector<int> &b, vector<int> &c) {
    int x1 = b[0]-a[0], x2 = c[0]-a[0], y1 = b[1]-a[1], y2=c[1]-a[1];
    return x1*y2-x2*y1;
}
vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n= trees.size();
    if (n<2) {
        return trees;
    }
    sort(trees.begin(),trees.end());
    vector<vector<int>> hull;
    // does two scans one for the upper and the lower, 
    // So it checks that upper are clockwise, and lower is counterclockwise.
    // But it is more than that by reversing you are actually checking lower is clockwise so the same logic applies by doing this.
    for (int rep = 0;rep<2;rep++) {
        const int S = hull.size();
        for (int i = 0;i<n;i++) {
            while (hull.size()-S>=2 && triangle(hull.end()[-2], hull.end()[-1], trees[i])<0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        hull.pop_back();
        reverse(trees.begin(),trees.end());  // reverse for checking the lower set of points. 
    }
    set<pair<int,int>> st; // remove duplicate points because you can have a straight line
    for (vector<int> &v : hull) {
        st.insert({v[0], v[1]});
    }
    vector<vector<int>> hullPoints;
    for (auto p : st) {
        hullPoints.push_back({p.first, p.second});
    }
    return hullPoints;
}

/*
Jarvis algorithm, 
The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) and we keep wrapping points in counterclockwise direction. The big question is, given a point p as current point, how to find the next point in output? The idea is to use orientation() here. Next point is selected as the point that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, we have “orientation(p, q, r) = counterclockwise”. Following is the detailed algorithm.
1) Initialize p as leftmost point. 
2) Do following while we don’t come back to the first (or leftmost) point. 
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r. To find this, we simply initialize q as next point, then we traverse through all points. For any point i, if i is more counterclockwise, i.e., orientation(p, i, q) is counterclockwise, then we update q as i. Our final value of q is going to be the most counterclockwise point. 
…..b) next[p] = q (Store q as next of p in the output convex hull). 
…..c) p = q (Set p as q for next iteration).
*/

// cross product value of the z component, for vector (b-a)X(c-a)
int triangle(vector<int> &a, vector<int> &b, vector<int> &c) {
    int x1 = b[0]-a[0], x2 = c[0]-a[0], y1 = b[1]-a[1], y2=c[1]-a[1];
    return x1*y2-x2*y1;
}

/*
This example of jarvis algorithm uses just a vector<int> of size 2 for representing the points.  And it just returns all the points
that make up the convex hull in any order. 
*/
vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n= trees.size();
    if (n<=3) {
        return trees;
    }
    sort(trees.begin(),trees.end());
    vector<vector<int>> hull;
    auto distance = [&](const auto & a, const auto &b) {
        int deltax = a[0]-b[0], deltay=a[1]-b[1];
        return deltax*deltax+deltay*deltay;
    };
    int i = 0;
    unordered_set<int> uniquePoints;
    uniquePoints.insert(i);
    while (true) {
        int next = (i+1)%n;
        vector<int> collinear;
        for (int j = 0;j<n;j++) {
            if (i==j) {continue;}
            int crossProduct = triangle(trees[i], trees[j], trees[next]);
            if (crossProduct<0) {
                next = j;
                collinear.clear();
            } else if (crossProduct==0) {
                if (distance(trees[i], trees[next])<distance(trees[i],trees[j])) {
                    collinear.push_back(next);
                    next = j;
                } else {
                    collinear.push_back(j);
                }
            }
        }
        for (int &j : collinear) {
            uniquePoints.insert(j);
        }
        if (next==0) {break;}
        uniquePoints.insert(next);
        i=next;
    }
    for (auto &i : uniquePoints) {
        hull.push_back(trees[i]);
    }
    return hull;
}