#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Task { string description; bool completed; };

void addTask(vector<Task>& tasks, const string& desc) {
    tasks.push_back({desc, false});
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) { cout << "No tasks available.\n"; return; }
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Remove Task\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number 1-5.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        if (choice == 1) {
            string desc;
            cout << "Enter task description: ";
            getline(cin, desc);
            addTask(tasks, desc);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            if (tasks.empty()) { cout << "No tasks to mark.\n"; continue; }
            viewTasks(tasks);
            cout << "Enter the task number to mark completed: ";
            int idx;
            if (!(cin >> idx)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                continue;
            }
            if (idx < 1 || idx > (int)tasks.size()) {
                cout << "Invalid task number!\n";
            } else {
                tasks[idx - 1].completed = true;
                cout << "Task marked as completed!\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice == 4) {
            if (tasks.empty()) { cout << "No tasks to remove.\n"; continue; }
            viewTasks(tasks);
            cout << "Enter the task number to remove: ";
            int idx;
            if (!(cin >> idx)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                continue;
            }
            if (idx < 1 || idx > (int)tasks.size()) {
                cout << "Invalid task number!\n";
            } else {
                tasks.erase(tasks.begin() + (idx - 1));
                cout << "Task removed successfully!\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice == 5) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
