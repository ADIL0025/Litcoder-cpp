#include <iostream>

void egyptianFraction(int numerator, int denominator)
{
    if (numerator <= 0 || denominator <= 0)
    {
        return;
    }

    std::cout << (denominator / numerator + 1) << std::endl;
    int remainderNumerator = numerator * (denominator / numerator + 1) - denominator;
    int remainderDenominator = denominator * (denominator / numerator + 1);

    while (remainderNumerator != 0)
    {
        int nextDenominator = (remainderDenominator + remainderNumerator - 1) / remainderNumerator;
        std::cout << nextDenominator << std::endl;

        remainderNumerator = remainderNumerator * nextDenominator - remainderDenominator;
        remainderDenominator = remainderDenominator * nextDenominator;
    }
}

int main()
{
    int numerator, denominator;
    std::cin >> numerator >> denominator;

    egyptianFraction(numerator, denominator);

    return 0;
}
