class Solution {
public:
    int maximumSwap(int num) {
        if(num<=10) return num;
          string numString = to_string(num);
  string maxString = numString;
  for (int i = 0; i < numString.size(); ++i)
  {
    for (int j = i + 1; j < numString.size(); ++j)
    {
      string temp = numString;
      swap(temp[i], temp[j]);
      maxString = max(maxString, temp);
    }
  }
  return stoi(maxString);
    }
};
