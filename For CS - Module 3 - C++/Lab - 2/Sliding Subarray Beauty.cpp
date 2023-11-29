#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <memory>

std::vector<int> slidingSubarrayBeauty(const std::vector<int> &arr, int k, int n)
{
    std::vector<int> result;

    for (int i = 0; i <= arr.size() - k; i++)
    {
        std::vector<int> subarray(arr.begin() + i, arr.begin() + i + k);
        std::sort(subarray.begin(), subarray.end());
        result.push_back(subarray[n - 1]);
    }

    return result;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    std::unique_ptr<std::vector<int>> arr = std::make_unique<std::vector<int>>();
    int num;
    while (iss >> num)
    {
        arr->push_back(num);
    }

    int k, n;
    std::cin >> k >> n;

    std::vector<int> result = slidingSubarrayBeauty(*arr, k, n);
    for (int beauty : result)
    {
        std::cout << beauty << " ";
    }

    return 0;
}
