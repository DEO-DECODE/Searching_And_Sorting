bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second > p2.second;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
  
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> jobs;
        int maxDeadLine = 0;
        for (int i = 0; i < n; ++i)
        {
            jobs.push_back({arr[i].dead, arr[i].profit});
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }
        sort(jobs.begin(), jobs.end(), cmp);
        int lastWorkingDay = -1;
        vector<int> schedule(maxDeadLine + 1, -1);
        int i = 0, profitEarned = 0, jobsDone = 0;
        while (i < n)
        {
            int profit = jobs[i].second;
            int currDeadLine = jobs[i].first;
            for (int day = currDeadLine; day >= 1; day--)
            {
                if (schedule[day] == -1)
                {
                    schedule[day] = 1;
                    profitEarned += profit;
                    jobsDone++;
                    break;
                }
            }
            i++;
        }
        return {jobsDone, profitEarned};
    }
};
