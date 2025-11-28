#include "system.hpp"
#include <iostream>

int main() {

    //=================== CREATE DEPARTMENT ===================
    Department dep;

    std::cout << "===== EMPLOYEE PAYROLL & TEAM STRUCTURE SYSTEM =====\n\n";

    //=================== CREATE EMPLOYEES ====================
    Senior* s1 = new Senior("Aram", 12, 7);    // Project Manager
    Senior* s2 = new Senior("Meri", 9, 5);     // Another Senior

    Middle* m1 = new Middle("Karen", 6, 4, s1);
    Middle* m2 = new Middle("Sona", 5, 3, s2);

    Junior* j1 = new Junior("Davit", 2, 2, m1);
    Junior* j2 = new Junior("Ani", 1, 1, m2);

    Intern* i1 = new Intern("Narek", 1, 1, j1);
    Intern* i2 = new Intern("Lilit", 0, 1, j2);

    //=================== CONNECT SUBORDINATES ====================
    s1->add_subord(m1);
    s1->add_subord(j1);
    s1->add_subord(i1);

    s2->add_subord(m2);
    s2->add_subord(j2);
    s2->add_subord(i2);

    

    //=================== ADD TO DEPARTMENT ====================
    dep.add_employs(s1);
    dep.add_employs(s2);
    dep.add_employs(m1);
    dep.add_employs(m2);
    dep.add_employs(j1);
    dep.add_employs(j2);
    dep.add_employs(i1);
    dep.add_employs(i2);

    //=================== PRINT FULL DEPARTMENT INFO ====================
    std::cout << "\n===== FULL DEPARTMENT INFORMATION =====\n\n";
    dep.print_info();

    //=================== PRINT TOTAL PAYROLL ====================
    std::cout << "\n===== TOTAL DEPARTMENT MONTHLY SALARY =====\n";
    dep.calculate_all_salari();
    std::cout << "===========================================\n";

    std::cout << "\nSystem finished successfully.\n";

    return 0;
}
