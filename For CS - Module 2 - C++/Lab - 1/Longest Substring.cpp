#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(const string &s)
{
    int start = 0, end = 0, ans = 0;

    unordered_set<char> charSet;

    while (end < s.length())
    {
        if (charSet.find(s[end]) == charSet.end())
        {
            charSet.insert(s[end]);
            end++;
            ans = max(ans, static_cast<int>(charSet.size()));
        }
        else
        {
            charSet.erase(s[start]);
            start++;
        }
    }

    return ans;
}

int main()
{
    string str;
    getline(cin, str);

    int ret = lengthOfLongestSubstring(str);
    cout << ret << endl;

    return 0;
}
