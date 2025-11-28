#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <vector>
#include <string>
class Virtualizable;

class  Virtualizable {
    public:
    using FnPtr = void (Virtualizable::*)();
    
    protected:
    std::string typeName;
    std::vector<std::string> names;
    std::vector<FnPtr> funcs;
    
    public:
        Virtualizable(const std::string& typeName_, const std::string& name1, const std::string& name2, FnPtr foo, FnPtr bar)
        :typeName{typeName_} {
            registerVirtual( name1, foo);
            registerVirtual( name2, bar);
        }

    public:
        std::string get_typename() { return typeName; }        
        void callVirtual(const std::string name); 
        void registerVirtual(std:: string name, FnPtr fn);
};
class Base:public Virtualizable {
    public:
        Base(const std::string& typeId = "Base", const std::string& name1 = "foo", const std::string& name2 = "bar", 
        FnPtr foo = (FnPtr)&Base::foo , FnPtr bar = (FnPtr)&Base::foo):Virtualizable(typeId, name1, name2, foo, bar){}
    public:

        static std::string get_typename() { return "Base"; }  
        void foo() { std::cout << "base foo" << std::endl; }
        void bar() { std::cout << "base bar" << std::endl; }
    };

class Derived : public Base {
    public:
        Derived(FnPtr foo = (FnPtr)&Derived::foo, FnPtr bar = (FnPtr)&Derived::bar)
        :Base("Derived", "foo", "bar", foo, bar) {}
        
       static std::string get_typename() { return "Derived"; }  
       
       
       void foo() { std::cout << "Derived::foo\n"; }
       void bar() { std::cout << "Derived::bar\n"; }
};




template<typename T>
T* dinamicCast(Virtualizable* type) {

    if (type->get_typename() == T::get_typename()) return static_cast<T*>(type);
    
    return nullptr; 
}




#endif