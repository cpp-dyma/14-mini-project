#include "crud.h"
#include <iostream>

void createTask(std::vector<Task> &tasks_list)
{
    Task new_task{};

    std::cout << "Quelle description voulez-vous donner à votre tâche ?\n";
    std::cin.ignore();
    std::getline(std::cin, new_task.description);


    std::cout<<"Quelle est la date attendue (au format jj/mm/aaaa ) ?\n";
    //TODO : regex
    std::cin>>new_task.dueDate;

    tasks_list.push_back(new_task);
    std::cout << "Tâche ajoutée avec succès !\n";
}

void printTask(const Task& task, int task_index)
{
    std::cout << "Tâche #"<<task_index+1<<"\n";
    std::cout << "Description: " << task.description << "\n";
    std::cout << "Date d'échéance: " << task.dueDate << "\n";
    std::cout << "Statut: " << (task.checked ? "Terminée" : "En cours") << "\n";
}

void markTaskAsChecked(std::vector<Task> &tasks_list)
{
    std::cout<<"Quelle tâche voulez-vous marquer comme terminée (indiquez son #) : ";
    auto task_nb{-1};
    std::cin>>task_nb;
    task_nb--;
    if(tasks_list.size()>task_nb && task_nb>=0){
        tasks_list[task_nb].checked = true;
    } else {
        std::cerr << "Le numéro de tâche indiqué est invalide...\n";
    }
}

void updateTask(std::vector<Task> &tasks_list)
{
    std::cout<<"Quelle tâche voulez-vous mettre à jour (indiquez son #) : ";
    auto task_nb{-1};
    std::cin>>task_nb;
    task_nb--;

    if(tasks_list.size()>task_nb && task_nb>=0){
        std::string description{}, due_date{};
        std::cout<<"Saisir la description (ou laisser vide pour conserver la description actuelle) : ";
        std::cin.ignore();
        std::getline(std::cin, description);
        if(!description.empty()){
            tasks_list[task_nb].description = description;
        }

        std::cout<<"Saisir la date attendue (ou laisser vide pour conserver la date actuelle) : ";
        std::cin.ignore();
        std::getline(std::cin, due_date);
        //TODO : regex
        if(!due_date.empty()){
            tasks_list[task_nb].dueDate = due_date;
        }


    } else {
        std::cerr << "Le numéro de tâche indiqué est invalide...\n";
    }
    
}

void deleteTask(std::vector<Task> &tasks_list)
{
    std::cout<<"Quelle tâche voulez-vous supprimer (indiquez son #) : ";
    auto task_nb{-1};
    std::cin>>task_nb;
    task_nb--;
    if(tasks_list.size()>task_nb && task_nb>=0){
        tasks_list.erase(tasks_list.begin()+task_nb);
    } else {
        std::cerr << "Le numéro de tâche indiqué est invalide...\n";
    }
}
