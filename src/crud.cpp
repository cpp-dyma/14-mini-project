#include "crud.h"
#include <iostream>
#include <regex>

void createTask(std::vector<Task> &tasks_list)
{
    Task new_task{};

    std::cout << "Quelle description voulez-vous donner à votre tâche ?\n";
    std::cin.ignore();
    std::getline(std::cin, new_task.description);

    const std::regex date_regex{R"(^(0?[1-9]|[12][0-9]|3[01])[\/](0?[1-9]|1[012])[\/\-]\d{4}$)"};
    auto date_valide{false};
    while(!date_valide) {
        std::cout<<"Quelle est la date attendue (au format jj/mm/aaaa ) ?\n";
        //^(0?[1-9]|[12][0-9]|3[01])[\/](0?[1-9]|1[012])[\/\-]\d{4}$
        std::cin>>new_task.dueDate;
        date_valide = std::regex_match(new_task.dueDate, date_regex);
        if(!date_valide){
            std::cerr<<"Date invalide ! Réessayez !\n";
        }
    }

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

        auto date_valide{false};
        const std::regex date_regex{R"(^(0?[1-9]|[12][0-9]|3[01])[\/](0?[1-9]|1[012])[\/\-]\d{4}$)"};
            
        while(!date_valide) {
            std::cout<<"Saisir la date attendue (ou laisser vide pour conserver la date actuelle) : ";
            //^(0?[1-9]|[12][0-9]|3[01])[\/](0?[1-9]|1[012])[\/\-]\d{4}$
            std::cin>>due_date;
            if(due_date.empty())
                break;

            date_valide = std::regex_match(due_date, date_regex);
            if(!date_valide){
                std::cerr<<"Date invalide ! Réessayez !\n";
            } else {
                tasks_list[task_nb].dueDate = due_date;
            }
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
