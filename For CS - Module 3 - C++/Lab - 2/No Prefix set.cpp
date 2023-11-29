#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream> 

std::string isGoodPassword(const std::vector<std::string> &passwords)
{
    std::vector<std::string> sortedPasswords = passwords;
    std::sort(sortedPasswords.begin(), sortedPasswords.end());

    for (size_t i = 0; i < sortedPasswords.size() - 1; i++)
    {
        if (sortedPasswords[i + 1].compare(0, sortedPasswords[i].length(), sortedPasswords[i]) == 0)
        {
            return "BAD PASSWORD";
        }
    }
    return "GOOD PASSWORD";
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    std::vector<std::string> passwords;
    std::string password;
    while (iss >> password)
    {
        passwords.push_back(password);
    }

    std::string result = isGoodPassword(passwords);
    std::cout << result << std::endl;

    return 0;
}
