#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void ddaLine(int x1, int y1, int x2, int y2, vector<pair<int, int>>& linePoints)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_increment = dx / (float) steps;
    float y_increment = dy / (float) steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        linePoints.push_back(make_pair(round(x), round(y)));
        x += x_increment;
        y += y_increment;
    }
}

int main()
{
    vector<pair<int, int>> line1Points;
    ddaLine(4, 10, 15, 4, line1Points);

    vector<pair<int, int>> line2Points;
    ddaLine(14, 10, 2, 8, line2Points);

    vector<pair<int, int>> line3Points;
    ddaLine(14, 2, 2, 10, line3Points);

    cout << "No 1: A(4, 10) B(15, 4)\n";
    for (const auto& point : line1Points)
    {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;

    cout << "No 2: A(14, 10) B(2, 8)\n";
    for (const auto& point : line2Points)
    {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;

    cout << "No 3: A(14, 2) B(2, 10)\n";
    for (const auto& point : line3Points)
    {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;

    return 0;
}
