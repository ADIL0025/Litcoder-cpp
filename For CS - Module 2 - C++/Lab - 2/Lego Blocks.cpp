#include <iostream>
#include <vector>

const int MOD = 1000000007;
const int MAX_SIZE = 1000 + 1;
const int UNKNOWN = -1;

int allSolutions[MAX_SIZE][MAX_SIZE];
int solidSolutions[MAX_SIZE][MAX_SIZE];

void initializeArrays()
{
    for (int i = 1; i < MAX_SIZE; i++)
    {
        std::fill(allSolutions[i], allSolutions[i] + MAX_SIZE, UNKNOWN);
        std::fill(solidSolutions[i], solidSolutions[i] + MAX_SIZE, UNKNOWN);
    }
}

int getAllSolutions(const int height, const int width)
{
    if (allSolutions[height][width] != UNKNOWN)
    {
        return allSolutions[height][width];
    }

    long long count;
    if (width == 1)
    {
        count = 1;
    }
    else if (height == 1)
    {
        if (width <= 4)
        {
            count = 2 * getAllSolutions(1, width - 1);
        }
        else
        {
            count = 0;
            for (int i = 1; i <= 4; i++)
            {
                count += getAllSolutions(1, width - i);
                count %= MOD;
            }
        }
    }
    else
    {
        int oneRowSolutions = getAllSolutions(1, width);

        count = 1;
        for (int h = 0; h < height; h++)
        {
            count *= oneRowSolutions;
            count %= MOD;
        }
    }

    allSolutions[height][width] = static_cast<int>(count);
    return allSolutions[height][width];
}

int getSolidSolutions(const int height, const int width)
{
    if (solidSolutions[height][width] != UNKNOWN)
    {
        return solidSolutions[height][width];
    }

    long long count;
    if (width == 1)
    {
        count = 1;
    }
    else
    {
        count = getAllSolutions(height, width);
        for (int i = 1; i < width; i++)
        {
            long long a = getAllSolutions(height, i);
            long long b = getSolidSolutions(height, width - i);
            count -= (a * b) % MOD;
            if (count < 0)
            {
                count += MOD;
            }
        }
    }
    solidSolutions[height][width] = static_cast<int>(count);
    return solidSolutions[height][width];
}

int main()
{
    initializeArrays();

    int height, width;
    std::cin >> height >> width;

    std::cout << getSolidSolutions(height, width) << std::endl;

    return 0;
}
