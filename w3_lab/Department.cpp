#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }
    Department::Department() {
        name = nullptr;
        projects = nullptr;
        num_of_projects = 0;
        budget = 15345.99;
    }
    void Department::updateName(const char* newname) {
        if (strlen(newname) > 0) {
            delete[]name;
            name = new char[strlen(newname) + 1];
            strcpy(name, newname);
        }
    }
    void Department::updateBudget(double change) {
        budget += change;
    }
    bool Department::addProject(Project& newproject) {
        int i=0;
        if (totalexpenses() + newproject.m_cost > budget) {
            return false;
        }
        
        Project* temp = new Project[num_of_projects + 1];
        for (i = 0; i < num_of_projects; i++) {
            temp[i] = projects[i];
        }
        temp[num_of_projects] = newproject;
        num_of_projects++;
        delete[] projects;
        projects = nullptr;
        projects = new Project[num_of_projects];
        for (i = 0; i < num_of_projects; i++) {
            projects[i] = temp[i];
        }
        delete[] temp;
        temp = nullptr;
        return true;
    }
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project* Department::fetchProjects() const {
        return projects;
    }
    int Department::fetchNumProjects() const {
        return num_of_projects;
    }
    double Department::fetchBudget()const {
        return budget;
    }
    char* Department::fetchName()const {
        return name;
    }
    double Department::totalexpenses() {
        int i = 0;
        double total = 0;
        for (i = 0; i < num_of_projects; i++) {
            total += projects[i].m_cost;
        }
        return total;
    }

    double Department::remainingBudget() {
        return budget - totalexpenses();
        }

    void Department::clearDepartment() {
        delete[]name;
        delete[]projects;
        num_of_projects = 15345.99;

        }

  

}