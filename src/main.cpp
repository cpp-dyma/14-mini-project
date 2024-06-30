#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "file.h"

void printTasks(const std::vector<Task> tasks){

    std::cout<<"#########################################\n";
    // Afficher les tâches chargées
    for(auto i{0}; i<tasks.size(); i++){
        printTask(tasks[i], i);
        std::cout<<"##########\n";
    }
    std::cout<<"#########################################\n";
}

void printOptionsList(){
    using std::cout;

    cout<<"0 - Quitter\n";
    cout<<"1 - Créer une nouvelle tâche\n";
    cout<<"2 - Marquer une tâche comme terminée\n";
    cout<<"3 - Modifier une tâche\n";
    cout<<"4 - Supprimer une tâche\n";
}


int main() {
    //Régler le problème d'accent sur Windows
    //std::setlocale(LC_ALL, ".utf8");

    const std::string fileName = "tasks.csv";

    auto tasks {loadTasks(fileName)};

    auto choix_utilisateur{0};
    do{
        printTasks(tasks);
        printOptionsList();
        std::cout<<"Quel est votre choix : ";
        std::cin>>choix_utilisateur;

        switch (choix_utilisateur)
        {
        case 0:
            //Ne rien faire
            break;
        
        case 1:
            createTask(tasks);
            break;
        case 2:
        {
            markTaskAsChecked(tasks);
            break;
        }

        case 3:
            updateTask(tasks);
            break;

        case 4:
            deleteTask(tasks);
            break;

        default:
            break;
        }

    }while(choix_utilisateur!=0);    
    
    auto nb_tasks_saved = saveTasks(fileName, tasks);
    if(nb_tasks_saved>0){
        std::cout<<nb_tasks_saved<<" tâches sauvegardées avec succès dans le fichier "<<fileName;
    } else {
        std::cerr<<"L'enregistrement a échoué dans le fichier "<<fileName;
    }

    return 0;
}
