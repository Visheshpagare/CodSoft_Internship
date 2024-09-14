#include <iostream>
using namespace std;
#include <vector>
#include <string>

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add a task\n";
    cout << "2. View tasks\n";
    cout << "3. Mark task as completed\n";
    cout << "4. Remove a task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, taskDescription);
    tasks.push_back(Task(taskDescription));
    cout << "Task added!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" 
                  << (tasks[i].isCompleted ? "Completed" : "Pending")
                  << "] " << tasks[i].description << "\n";
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
