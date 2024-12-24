#include <iostream>
#include <cctype>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

class Task
{
    private:
    std::string m_description;
    bool m_completed;

    public:
    Task(std::string description, bool completed) : m_description{description}, m_completed{completed} {
        std::cout << "Task created" << std::endl;
    }

    std::string getDescription() const {
        return m_description;
    }

    bool isCompleted() const {
        return m_completed;
    }
};

void printTaskList(std::vector<Task> &tasks);

int main()
{
    #ifdef _WIN32
    SetConsoleTitleW(L"Task List");
    #endif
    
    char userChoice{};

    std::vector<Task> tasks;

    do
    {
        std::cout << "Enter your choice: " << std::endl;
        std::cout << "a - Add a task" << std::endl;
        std::cout << "d - Delete a task" << std::endl;
        std::cout << "l - List all tasks" << std::endl;
        std::cout << "q - Quit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> userChoice;

        switch (tolower(userChoice))
        {
        case 'a':
        {
            std::string taskDescription;
            std::cout << "Enter the task description: ";
            std::cin.ignore();
            std::getline(std::cin, taskDescription);

            Task newTask { taskDescription, false };

            tasks.push_back(newTask);

            break;
        }
        case 'd':
            printTaskList(tasks);
            std::cout << "Enter the index of the task to delete: ";
            int index;
            std::cin >> index;
            tasks.erase(tasks.begin() + index);
            printTaskList(tasks);
            break;
        case 'l':
            printTaskList(tasks);

            break;
        case 'q':
            std::cout << "Quitting" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (tolower(userChoice) != 'q');

    return 0;
}

void printTaskList(std::vector<Task> &tasks)
{
    for (const auto &task : tasks)
    {
        int index = &task - &tasks[0];
        std::cout << index << " - " << task.getDescription() << " (" << (task.isCompleted() ? "Completed" : "Not Completed") << ")" << std::endl;
    }
}
