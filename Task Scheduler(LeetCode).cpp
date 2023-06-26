#include <bits/stdc++.h>
using namespace std;
// Task Scheduler(LeetCode)
int leastInterval(vector<char> &tasks, int n)
{
    int totalTime = 0;
    unordered_map<char, int> freqTrack;
    for (auto ch : tasks)
    {
        freqTrack[ch]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto pr : freqTrack)
    {
        pq.push({pr.second, pr.first});
    }
    while (pq.size() > 0)
    {
        int cpuTime = n + 1;
        vector<pair<int, char>> temp;
        while (!pq.empty() && cpuTime)
        {
            auto pr = pq.top();
            pq.pop();
            int freq = pr.first;
            if (--freq)
            {
                temp.push_back({freq, pr.second});
            }
            cpuTime--;
            totalTime++;
        }
        for (auto pr : temp)
        {
            pq.push(pr);
        }
        if (pq.empty())
            break;
        totalTime += cpuTime;
    }
    return totalTime;
}
