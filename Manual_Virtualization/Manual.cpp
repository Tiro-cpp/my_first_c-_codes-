#include <iostream>
#include "Manual.hpp" 
 
void Virtualizable::registerVirtual(const std::string name, FnPtr fn){
        funcs.push_back(fn);
        names.push_back(name);

}
void Virtualizable::callVirtual(const std::string name){
        
        for (size_t i = 0; i < names.size(); ++i) {
            if (names[i] == name) {
                FnPtr f = funcs[i];
                (this->*f)();       
            return ;
        }
        
        }   
}     