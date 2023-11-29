#include <iostream>
#include <vector>

int mixTheArray(int n, std::vector<std::vector<int>> &queries)
{
    std::vector<int> array(n, 0);

    for (const auto &query : queries)
    {
        int start = query[0];
        int end = query[1];
        int value = query[2];
        array[start - 1] += value;
        if (end < n)
        {
            array[end] -= value;
        }
    }

    int max_value = array[0];
    int current_value = array[0];

    for (int i = 1; i < n; i++)
    {
        current_value += array[i];
        max_value = std::max(max_value, current_value);
    }

    return max_value;
}

int main()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> queries(q, std::vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> queries[i][j];
        }
    }

    int result = mixTheArray(n, queries);
    std::cout << result << std::endl;

    return 0;
}
