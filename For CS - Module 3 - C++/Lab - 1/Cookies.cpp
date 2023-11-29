#include <iostream>
#include <vector>
#include <queue>

int cookies(std::vector<int> &candies, int targetSweetness)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int candy : candies)
    {
        minHeap.push(candy);
    }

    int steps = 0;

    while (!minHeap.empty() && minHeap.top() < targetSweetness)
    {
        int leastSweet = minHeap.top();
        minHeap.pop();

        if (!minHeap.empty())
        {
            int secondLeastSweet = minHeap.top();
            minHeap.pop();

            int combinedSweetness = leastSweet + 2 * secondLeastSweet;
            minHeap.push(combinedSweetness);
            steps++;
        }
        else
        {

            break;
        }
    }

    return steps;
}

int main()
{
    int targetSweetness;
    std::cin >> targetSweetness;

    int n;
    std::cin >> n;

    std::vector<int> candies(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> candies[i];
    }

    int result = cookies(candies, targetSweetness);
    std::cout << result << std::endl;

    return 0;
}
