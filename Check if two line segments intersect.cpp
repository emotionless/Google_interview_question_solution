/*
Link: https://www.youtube.com/watch?v=bbTqI0oqL5U
Code from : https://gist.github.com/SuryaPratapK/4b632447abbc0e95f6e81da321b855fb
*/

#include <iostream>
#include <cmath>

using namespace std;
struct Point {
    int x, y;
};

bool isColinear(Point p, Point q, Point r) {
    return min(p.x, q.x) <= r.x && r.x <= max(p.x, q.x)
            && min(p.y, q.y) <= r.y && r.y <= max(p.y, q.y);
}


// 0 - co-linear
// 1 - clockwise
// 2 - anti-clockwise
int getOrientation(Point p, Point q, Point r) {
    int val = (p.x - r.x) * (q.y - r.y) - (q.x - r.x) * (p.y - r.y);
    if (val == 0) return 0;
    return val > 0? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int p2Orientation = getOrientation(p1, q1, p2);
    int q2Orientation = getOrientation(p1, q1, q2);
    int p1Orientation = getOrientation(p2, q2, p1);
    int q1Orientation = getOrientation(p2, q2, q1);
    if (p2Orientation != q2Orientation && p1Orientation != q1Orientation) return true;
    if (p2Orientation == 0 && isColinear(p1, q1, p2)) return true;
    else if (q2Orientation == 0 && isColinear(p1, q1, q2)) return true;
    else if (p1Orientation == 0 && isColinear(p2, q2, p1)) return true;
    else if (q1Orientation == 0 && isColinear(p2, q2, q1)) return true;
    return false;
}

int main() {
    struct Point p1 = {1, 1}, q1 = {10, 1};
	struct Point p2 = {1, 2}, q2 = {10, 2};

	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {10, 0}, q1 = {0, 10};
	p2 = {0, 0}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {-5, -5}, q1 = {0, 0};
	p2 = {1, 1}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {-5, -5}, q1 = {0, 0};
	p2 = {0, 0}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    return 0;
}


