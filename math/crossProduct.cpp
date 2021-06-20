#include <bits/stdc++.h>
using namespace std;


struct P {
    long long x, y;
};
// subtraction to return a new 2-dimensional object
P operator- (const P &a, const P &b) {
    return P{b.x-a.x,b.y-a.y};
}
// override the operator * to find the value of the z-axis when taking the cross product in 2-dimensional space
long long operator* (const P &a, const P&b) {
    return a.x*b.y-a.y*b.x;
}

// This can be used to test if 3 points are collinear in 2-dimensional space

const bool isCollinear(const P &a, const P &b, const P &c) {
    return (b-a)*(c-a)==0;
}

// Also can check a point is on the boundary by using a bounding-box technique. 
const bool onBoundary(const P &a, const P &b, const P &c) {
    if (!isCollinear(a,b,c)) {
        return false;
    }
    return a.x>=min(b.x,c.x) && a.x<=max(b.x,c.x) && a.y>=min(b.y,c.y) && a.y<=max(b.y,c.y);
}

// A function to find if two line segments intersect by using the cross product.  
const bool isIntersection(P a, P b, P c, P d) {
    for (int rep = 0;rep<2;rep++) {
        bool s1 = (b-a)*(c-a)>0, s2 = (b-a)*(d-a)>0;
        if (s1==s2) {
            return false;
        }
        swap(a,c);
        swap(b,d);
    }
    return true;
}