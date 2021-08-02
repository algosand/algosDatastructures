#include <bits/stdc++.h>
using namespace std;
/*
The sequence is the following, and it follows a formula which I believe is called 
cardanos formula, it is related to solving a cubic equation. 
0, 12, 60, 168, 360, 660, 1092, 1680, 2448, 3420, 4620, 6072, 7800, 
9828, 12180, 14880, 17952, 21420, 25308, 29640, 34440, 39732, 45540, 
51888, 58800, 66300, 74412, 83160, 92568, 102660, 113460, 124992, 137280, 
150348, 164220, 178920, 194472, 210900, 228228
*/
void cardano() {
    long long apples = 0, i;
    for (i=1000;apples<1e15;i++) {
        apples = 2*i*(i+1)*(2*i+1);
    }
}

int main() {
    cardano();
}