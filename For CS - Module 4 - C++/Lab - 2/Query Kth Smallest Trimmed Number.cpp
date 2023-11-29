#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<int> kthSmallestTrimmedNumber(const std::vector<std::string> &nums, const std::vector<std::pair<int, int>> &queries)
{
    std::vector<int> answer;

    for (const auto &query : queries)
    {
        int position = query.first;
        int trimLength = query.second;
        std::vector<int> trimmedNums;

        for (const std::string &num : nums)
        {
            int trimmed = std::stoi(num.substr(num.length() - std::min<size_t>(num.length(), static_cast<size_t>(trimLength))));
            trimmedNums.push_back(trimmed);
        }

        std::vector<int> sortedNums = trimmedNums;
        std::sort(sortedNums.begin(), sortedNums.end());

        int kthSmallest = (position <= sortedNums.size()) ? sortedNums[position - 1] : -1;
        int kthSmallestIndex = (kthSmallest != -1) ? std::find(trimmedNums.begin(), trimmedNums.end(), kthSmallest) - trimmedNums.begin() : -1;
        answer.push_back(kthSmallestIndex);
    }

    return answer;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    std::vector<std::string> nums;
    std::string num;
    while (iss >> num)
    {
        nums.push_back(num);
    }

    int queriesCount;
    std::cin >> queriesCount;

    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < queriesCount; i++)
    {
        int position, trimLength;
        std::cin >> position >> trimLength;
        queries.push_back({position, trimLength});
    }

    std::vector<int> result = kthSmallestTrimmedNumber(nums, queries);

    for (int res : result)
    {
        std::cout << res << " ";
    }

    return 0;
}
