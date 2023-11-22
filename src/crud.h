#ifndef __CRUD_H__
#define __CRUD_H__

#include <string>
#include <vector>

struct Task {
    std::string description;
    std::string dueDate;
    bool        checked;
};

void createTask(std::vector<Task> &tasks_list);

void printTask(const Task& task, int task_index);

void markTaskAsChecked(std::vector<Task> &tasks_list);

void updateTask(std::vector<Task> &tasks_list);

void deleteTask(std::vector<Task> &tasks_list);


#endif