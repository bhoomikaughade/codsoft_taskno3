#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << (tasks[i].isCompleted ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
            }
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].isCompleted = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    string taskDescription;
    int taskIndex;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // To consume the newline character after the integer input

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            getline(cin, taskDescription);
            toDoList.addTask(taskDescription);
            break;
        case 2:
            toDoList.viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> taskIndex;
            toDoList.markTaskAsCompleted(taskIndex);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> taskIndex;
            toDoList.removeTask(taskIndex);
            break;
        case 5:
            cout << "Exiting To-Do List Manager. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
