#include <iostream>
#include <stack>

int clumsy(int n)
{
    std::stack<int> stack;
    stack.push(n);

    int idx = 0;
    for (int i = n - 1; i > 0; --i)
    {
        if (idx % 4 == 0)
        {
            stack.push(stack.top() * i);
        }
        else if (idx % 4 == 1)
        {
            stack.push(stack.top() / i);
        }
        else if (idx % 4 == 2)
        {
            stack.push(i);
        }
        else
        {
            stack.push(-i);
        }
        ++idx;
    }

    int result = 0;
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;
}

int main()
{
    int n;
    std::cin >> n;

    int result = clumsy(n);
    std::cout << result << std::endl;

    return 0;
}
