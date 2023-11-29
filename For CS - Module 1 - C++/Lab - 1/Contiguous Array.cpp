#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int findMaxLength(std::vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    for (int &num : nums)
    {
        if (num == 0)
        {
            num = -1;
        }
    }

    int sum = 0;
    int max = 0;

    std::unordered_map<int, int> map;
    map[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (map.find(sum) != map.end())
        {
            int last = map[sum];
            max = std::max(max, i - last);
        }
        else
        {
            map[sum] = i;
        }
    }

    return max;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> numbers;

    int num;
    while (iss >> num)
    {
        numbers.push_back(num);
    }

    std::cout << findMaxLength(numbers) << std::endl;

    return 0;
}
