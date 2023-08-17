bool isPossible(vector<int> &arr, int mid, int m, int &numStudentReq)
{
    long long sm = 0;
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] > mid)
            return false;
        if (sm + arr[i] <= mid)
        {
            sm += arr[i];
            i++;
        }
        else
        {
            numStudentReq++;
            sm = 0;
        }
    }
    return numStudentReq <= m;
}
int findPages(vector<int> &arr, int n, int m)
{
    // sort(arr.begin(), arr.end());
    if (m > n)
    {
        return -1;
    }
    int s = 0;
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += arr[i];
    }
    long long lo = 0, hi = sm, ans = -1;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        int numStudentReq = 1;
        if (isPossible(arr, mid, m, numStudentReq))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans ;
}
