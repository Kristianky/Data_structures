#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class My_String{
    private:
       char *data;
       int lenght;
    public:
       My_String() {data = new char[] {"WELCOME"};for (int i{0};data[i]!='\0';i++){lenght = i;}}
           ~My_String(){delete [] data;}
       int get_lenght(){return lenght;}
       void change_to_upper();
       void change_to_lower();
       void display();
};

void My_String::change_to_lower(){
    
    for (int i{0};data[i]!='\0';i++){
       data[i] = data[i] + 32;
    }
}

void My_String::display(){
    for (int i{0};data[i]!='\0';i++){
        std::cout<<data[i];
    }
    std::cout<<"\n";
}
#endif