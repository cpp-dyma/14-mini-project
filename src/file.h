#ifndef __FILE_H__
#define __FILE_H__

#include <vector>
#include <string>
#include "crud.h"

using std::string;


std::vector<Task> loadTasks(const string& fileName);

int saveTasks(const std::string& fileName, const std::vector<Task>);

#endif