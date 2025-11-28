#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <vector>
#include <string>
class Employee;
class Middle;
class Senior;

enum class Role {
    noname, QA, Designer, DevOps, Software_Engineer,
    Security_Specialist, Project_Manager
};

class Department {
    private:
        std::vector<Employee*> employs;
    
        
    public:
//functions    
        void add_employs( Employee* emp);
        void calculate_all_salari();
        void clean_up();
        void print_info();
//dtor
        ~Department() {
            clean_up();
        }    
};

class Employee {

    protected:
        std::string name; 
        int years;
        int N_projects;
        Role role;
        double salari;

    public:
//ctor    
        Employee():name("no name"), years{0}, N_projects{0}, role{Role::noname} {}
        Employee(std::string name, int years = 0, int n_projects = 0, Role r = Role::noname, double _salari = 0.0)
        :name{name}, years{years}, N_projects{n_projects}, role{r}, salari{_salari} {}
    
    public:
//functiions
        virtual double calculate_salari();
        double bonus_project();
        virtual void print_info();
        void get_name()const{ std::cout<<name; }
//dtor
        virtual ~Employee()= default;
};


class Intern:public Employee  {

    private:
        Employee* mentor;

    public:
//ctor    
        Intern():Employee(),mentor(nullptr) {}
        Intern(std::string name, int years = 0, int N_projects = 0, Employee* _mentor = nullptr)
        :Employee(name, years, N_projects, Role::Software_Engineer, 1000), mentor(_mentor)  {}   
    public:
//funtions    
        virtual double calculate_salari()override;
        virtual void print_info() override;
//dtor
        virtual ~Intern() = default; 
};

class Junior:public Employee {
    private:
        Employee* T_lead;
    public:
//ctor    
        Junior():Employee(), T_lead(nullptr) {}
        Junior(std::string name , int years = 0, int N_projects = 0, Employee* t_lead = nullptr )
        :Employee(name, years, N_projects, Role::Designer, 1300), T_lead(t_lead)  {}  
    public:
//funtions
        virtual double calculate_salari() override;
        virtual void print_info() override;
//dtor
        virtual ~Junior()= default;

};
class Middle:public Employee {
    private:
        Employee* T_lead;
    public:
//ctor    
        Middle():Employee(), T_lead(nullptr) {}
        Middle(std::string name, int years = 0, int N_projects = 0 , Employee* t_lead = nullptr)
        :Employee(name, years, N_projects, Role::Security_Specialist, 2000), T_lead(t_lead){}   
    public:
//functions        
        virtual double calculate_salari() override;
        virtual void print_info() override;
//dtor
        virtual ~Middle()= default;


};


class Senior:public Employee {

    private:
        std::vector<Employee*> subord;
    public:
//ctor
        Senior():Employee(), subord() {}
        Senior(std::string name, int years = 0, int N_projects = 0)
        :Employee(name, years, N_projects, Role::Project_Manager, 3000), subord() {}
       
    public:
//functions       
        void add_subord(Employee* sub);
        virtual double calculate_salari() override;
        void get_sub_name()const;
        virtual void print_info() override;     
//destructor     
        virtual ~Senior() = default;               
        
};


#endif