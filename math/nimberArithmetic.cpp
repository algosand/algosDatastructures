#include <bits/stdc++.h>
#include "gnuplot-iostream.h"
using namespace std;
int main() {
	Gnuplot gp;
	// Gnuplot vectors (i.e. arrows) require four columns: (x,y,dx,dy:)
	// std::vector<boost::tuple<double, double, double, double> > pts_A;

	// You can also use a separate container for each column, like so:
    vector<vector<int>> matrix(101, vector<int>(101,0));
    vector<int>
    for (int i = 0;i<101;i++) {
        for (int j = 0;j<101;j++) {
            matrix[i][j] = i^j;
        }
    }

	// Don't forget to put "\n" at the end of each line!
	gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
	// '-' means read from stdin.  The send1d() function sends data to
	// gnuplot's stdin.
	gp << "plot '-' with vectors title 'pts_A', "
		<< "'-' with vectors title 'pts_B'\n";
	gp.send2d(matrix);
	// gp.send1d(boost::make_tuple(pts_B_x, pts_B_y, pts_B_dx, pts_B_dy));
}