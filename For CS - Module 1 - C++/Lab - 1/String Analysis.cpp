#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void analyzeEmailComposition(const std::string &email)
{
    int totalCharacters = email.length();
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int symbolCount = 0;

    for (char c : email)
    {
        if (std::isupper(c))
        {
            uppercaseCount++;
        }
        else if (std::islower(c))
        {
            lowercaseCount++;
        }
        else if (std::isdigit(c))
        {
            digitCount++;
        }
        else
        {
            symbolCount++;
        }
    }

    double uppercasePercentage = (uppercaseCount * 100.0) / totalCharacters;
    double lowercasePercentage = (lowercaseCount * 100.0) / totalCharacters;
    double digitPercentage = (digitCount * 100.0) / totalCharacters;
    double symbolPercentage = (symbolCount * 100.0) / totalCharacters;

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << uppercasePercentage << "%" << lowercasePercentage << "%" << digitPercentage << "%" << symbolPercentage << "%" << std::endl;
}

int main()
{
    std::string email;
    std::getline(std::cin, email);
    analyzeEmailComposition(email);

    return 0;
}
