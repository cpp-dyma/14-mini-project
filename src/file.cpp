#include "file.h"
#include <fstream>
#include <iostream>

std::vector<Task> loadTasks(const string &fileName)
{
    std::vector<Task> tasks;
    std::ifstream file(fileName);
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            Task task;
            size_t pos = 0;
            pos = line.find(";");
            task.description = line.substr(0, pos);
            line.erase(0, pos + 1);
            
            pos = line.find(";");
            task.dueDate = line.substr(0, pos);
            line.erase(0, pos + 1);

            task.checked = line=="1" ? true : false;
            tasks.push_back(task);
        }
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier.\n";
    }
    return tasks;
}

int saveTasks(const std::string &fileName, const std::vector<Task> tasks)
{
    std::ofstream file(fileName, std::ios::trunc | std::ios::out);
    if (file) {
        auto nb_tasks_written{0};
        for(const Task task : tasks){
            file << task.description << ";" << task.dueDate << ";" << (task.checked ? "1" : "0") << "\n";
            nb_tasks_written++;
        }
        file.close();
        return nb_tasks_written;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier.\n";
        return 0;
    }
}
