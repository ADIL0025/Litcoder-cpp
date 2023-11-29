#include <iostream>
#include <stack>
#include <sstream>

class SimpleTextEditor
{
private:
    static std::string text;
    static std::stack<std::string> operations;

public:
    SimpleTextEditor()
    {
        text = "";
    }

    static void insert(const std::string &value)
    {
        text += value;
        operations.push("1 " + value);
    }

    static void remove(int value)
    {
        int start = std::max(0, static_cast<int>(text.length()) - value);
        int end = text.length();
        operations.push("2 " + text.substr(start, end - start));
        text.erase(start, end - start);
    }

    static char get(int value)
    {
        char result = text[value - 1];
        operations.push("3 " + std::string(1, result));
        return result;
    }

    static void undo()
    {
        if (!operations.empty())
        {
            std::string lastOperation = operations.top();
            operations.pop();
            std::stringstream ss(lastOperation);
            int command;
            ss >> command;

            switch (command)
            {
            case 1:
            {
                std::string value;
                ss >> value;
                text.erase(text.length() - value.length());
                break;
            }
            case 2:
            {
                std::string deletedText;
                ss >> deletedText;
                text += deletedText;
                break;
            }
            case 3:
            {
                std::string result;
                ss >> result;
                // Undoing "get" operation doesn't need any action.
                break;
            }
            }
        }
    }
};

std::string SimpleTextEditor::text;
std::stack<std::string> SimpleTextEditor::operations;

int main()
{
    SimpleTextEditor editor;
    std::string input;
    getline(std::cin, input);

    std::stringstream inputStream(input);
    std::string command;
    while (getline(inputStream, command, ','))
    {
        std::stringstream commandStream(command);
        int type;
        commandStream >> type;

        switch (type)
        {
        case 1:
        {
            std::string value;
            commandStream >> value;
            SimpleTextEditor::insert(value);
            break;
        }
        case 2:
        {
            int value;
            commandStream >> value;
            SimpleTextEditor::remove(value);
            break;
        }
        case 3:
        {
            int value;
            commandStream >> value;
            std::cout << SimpleTextEditor::get(value) << std::endl;
            break;
        }
        case 4:
            SimpleTextEditor::undo();
            break;
        }
    }

    return 0;
}
