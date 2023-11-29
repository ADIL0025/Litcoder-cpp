#include <iostream>
#include <string>

long maximumSubsequenceCount(const std::string &text, const std::string &pattern)
{
    long result = 0, first = 0, second = 0;

    for (char ch : text)
    {
        if (ch == pattern[1])
        {
            result += first;
            second++;
        }

        if (ch == pattern[0])
        {
            first++;
        }
    }

    return result + std::max(first, second);
}

int main()
{
    std::string a, b;
    getline(std::cin, a);
    getline(std::cin, b);

    long ret = maximumSubsequenceCount(a, b);
    std::cout << ret << std::endl;

    return 0;
}
