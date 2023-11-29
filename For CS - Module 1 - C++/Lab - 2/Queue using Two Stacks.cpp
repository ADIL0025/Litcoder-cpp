#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void processQueries(const string &input)
{
    stringstream ss(input);
    stack<int> stack1;
    stack<int> stack2;

    string query;
    while (getline(ss, query, ','))
    {
        stringstream queryStream(query);
        int type;
        queryStream >> type;

        switch (type)
        {
        case 1:
        {
            int element;
            queryStream >> element;
            stack1.push(element);
            break;
        }
        case 2:
            if (stack2.empty())
            {
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            if (!stack2.empty())
            {
                stack2.pop();
            }
            break;
        case 3:
            if (stack2.empty())
            {
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            if (!stack2.empty())
            {
                cout << stack2.top() << endl;
            }
            break;
        }
    }
}

int main()
{
    string input;
    getline(cin, input);

    processQueries(input);

    return 0;
}
