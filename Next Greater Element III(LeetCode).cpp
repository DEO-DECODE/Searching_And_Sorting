class Solution {
public:
    int nextGreaterElement(int n) {
    vector<int> number;
    while (n > 0)
    {
        number.push_back(n % 10);
        n = n / 10;
    }
    reverse(number.begin(), number.end());

    int sz = number.size();
    int j = sz - 1;
    while (j > 0 && (number[j] <= number[j - 1]))
    {
        j--;
    }
    if (j == 0)
        return -1;
    int digAtind = number[j - 1];
    int k = sz - 1;
    while (k > j && number[k] <= digAtind)
    {
        k--;
    }
    number[j - 1] = number[k];
    number[k] = digAtind;
    sort(number.begin() + j, number.end());
    // for (auto dig : number)
    // {
    //     cout << dig << " ";
    // }
    long long ans = 0;
    for (auto dig : number)
    {
        ans = (ans * 10) + dig;
    }

    // cout << endl;
    return ans > INT_MAX ? -1 : ans;
    }
};
