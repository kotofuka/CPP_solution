#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
    Point() {
        cout << "Initialize Point" << endl;
        x = 0;
        y = 0;
    };
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

struct Segment {
    Point begin, end;

    double GetLen() const {
        return sqrt(pow(begin.x - end.x, 2) + pow(begin.y - end.y, 2));
    }
};

class Triangle {
private:
    double a, b, c;
public:
    Triangle(Point p, Point q, Point t) {
        a = Segment{ p, q }.GetLen();
        b = Segment{ q, t }.GetLen();
        c = Segment{t, p}.GetLen();
    }

    constexpr double Perimtr() const {
        return a + b + c;
    }
    
    constexpr double Perimtr2() const {
        return Perimtr() / 2;
    }
    
    double GetSq() const {
        return sqrt(Perimtr2() * (Perimtr2() - a) * (Perimtr2() - b) * (Perimtr2() - c));
    }
};


int main()
{
    Point p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    Triangle t = {p[0], p[1], p[2]};
    Segment seg;
    cout << t.GetSq();
    //cin >> seg.begin.x >> seg.begin.y >> seg.end.x >> seg.end.y;
    //cout << seg.GetLen() << endl;
    //cout << b.x << " " << b.y << endl;
}
