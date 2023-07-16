#include <bits/stdc++.h>
using namespace std;
// Car Fleet(LeetCode)
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    map<int, double> carTrack;
    for (int i = 0; i < n; ++i)
    {
        carTrack[position[i]] = (double)(target - position[i]) / speed[i];
    }
    auto itr = --carTrack.end();
    int numFleet = 1;
    double slowestCar = (*itr).second;
    while (true)
    {
        if ((*itr).second > slowestCar)
        {
            slowestCar = (*itr).second;
            numFleet++;
        }
        if (itr == carTrack.begin())
        {
            break;
        }
        itr--;
    }

    return numFleet;
}
int main()
{
    vector<int> position = {0, 4, 2};
    vector<int> speed = {2, 1, 3};
    cout << carFleet(10, position, speed);
}
