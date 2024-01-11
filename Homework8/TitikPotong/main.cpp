#include <iostream>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

const double xMin = 10.0;
const double xMax = 50.0;
const double yMin = 10.0;
const double yMax = 50.0;

int computeOutCode(double x, double y) {
    int code = INSIDE;
    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;

    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;

    return code;
}

void cohenSutherland(double x1, double y1, double x2, double y2) {
    int outcode1 = computeOutCode(x1, y1);
    int outcode2 = computeOutCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outcode1 | outcode2)) {
            accept = true;
            break;
        }
        else if (outcode1 & outcode2) {
            break;
        }

        else {
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            double x, y;
            if (outcodeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (outcodeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (outcodeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (outcodeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutCode(x2, y2);
            }
        }
    }

    if (accept) {
        cout << "Garispotong pada (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")" << endl;
    } else {
        cout << "Garis di luar window" << endl;
    }
}

int main() {
    double x1 = 5.0, y1 = 15.0;
    double x2 = 60.0, y2 = 35.0;

    cout << "Titik awal (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")" << endl;

    cohenSutherland(x1, y1, x2, y2);

    return 0;
}
