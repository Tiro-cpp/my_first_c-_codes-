#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "system.hpp"


//=======DEPARTMENT========
void Department::add_employs( Employee* emp ) {
    employs.push_back(emp);
    
}
void Department::print_info() {
    for(size_t i{0}; i < employs.size(); ++i) {
        employs[i]->print_info();
        std::cout<<"==================\n";
    }
}
void  Department::clean_up() {
    for(size_t i{0}; i < employs.size(); ++i) {
        delete employs[i];
    }
    employs.clear(); 
}

        
void Department::calculate_all_salari() {
    int all_money =0;
    for(size_t i{0}; i < employs.size(); ++i) {
        all_money += employs[i]->calculate_salari();
    }
    std::cout << "\nTOTAL SALARY BUDGET: " << all_money << " $\n";
    std::cout << "===============================\n";
}
//===========EMPLOYEE===========
double Employee::bonus_project() {
    int bonus =0;
    bonus += N_projects * 50;
    bonus += years * 100;
    return  bonus;
}


double Employee::calculate_salari() {
    switch(role) {
        case Role::Designer: salari = 1000;
        break;
        case Role::DevOps: salari = 1200;
        break;
        case Role::Software_Engineer: salari = 1300;
        break;
        case Role::Security_Specialist: salari = 1400;
        break;
        case Role::Project_Manager: salari = 1500;
        break;
        case Role::QA: salari = 1100;
        break;

        default:  
        break;
    }      
    return salari;
}
void Employee::print_info() {
    std::cout << "name is: " << name << std::endl;
    std::cout << N_projects << "-projects" << "\n" << years << "  year work experience" << std::endl;   
    switch(role) {
        case Role::QA: std::cout << "the role is QA"; break;
        case Role::Designer: std::cout << "the role is Designer"; break;
        case Role::DevOps: std::cout << "the role is DevOps"; break;
        case Role::Project_Manager: std::cout << "the role is Project Manager"; break;
        case Role::Software_Engineer: std::cout << "the role is Software ingener"; break;
        case Role::Security_Specialist:  std::cout << "the role is Security Specialist";break;
        default: break;
    }  
    std::cout<<std::endl;
}
//===============INTERN=================
double Intern::calculate_salari() {
    return Employee::calculate_salari();

}

void Intern::print_info() {
    Employee::print_info();
    std::cout << "your salary is " << calculate_salari() << "$"<< std::endl;
}

//=============JUNIOR=========================
double Junior::calculate_salari() {
    salari = Employee::calculate_salari();
    return salari;
}


void Junior::print_info() {
    Employee::print_info();
    std::cout<<"team lead is  ";
    T_lead->get_name();
    std::cout<< "\n";
    std::cout << "your salary is " << calculate_salari() << "$"<< std::endl;
}

//==========MIDDLE===================
double Middle::calculate_salari() {
    salari = Employee::calculate_salari();
    salari += bonus_project();
    return salari;
} 


void Middle::print_info() {
    Employee::print_info();
    std::cout<<"team lead is  ";
    T_lead->get_name();
    std::cout<< "\n";
   
}
//===============SENIOR======================
void Senior::add_subord(Employee* sub) {
    subord.push_back(sub);
 }

double Senior::calculate_salari() {
    salari = Employee::calculate_salari();
    salari += bonus_project();
    salari += subord.size() * 50;
    return salari;
} 

void Senior::get_sub_name()const {
    std::cout << "Subordinates: ";

    for(size_t i{0}; i < subord.size(); ++i){
        subord[i]->get_name();
        std::cout<<", ";
    }
    std::cout<<"\n";
}
void Senior::print_info() {
    Employee::print_info();
    get_sub_name();
    std::cout << "your salary is " << calculate_salari() << "$"<< std::endl;
}



