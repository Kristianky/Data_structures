#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class My_String{
    private:
       char *data;
       int lenght;
    public:
       My_String() {data = new char[] {"WELCOME"};for (int i{1};data[i]!='\0';i++){lenght = i + 1;}}
           ~My_String(){delete [] data;}
       int get_lenght(){return lenght;}
       void change_to_upper();
       void change_to_lower();
       void display();
       void reverse();
       void reverse2();
};

void My_String::change_to_lower(){
    
    for (int i{0};data[i]!='\0';i++){
       data[i] = data[i] + 32;
    }
}

void My_String::change_to_upper(){
    
    for (int i{0};data[i]!='\0';i++){
       data[i] = data[i] - 32;
    }
}

void My_String::display(){
    for (int i{0};data[i]!='\0';i++){
        std::cout<<data[i];
    }
    std::cout<<"\n";
}
void My_String::reverse(){
    char *temp;
    int size_temp = lenght;
    temp = new char[size_temp];
    temp[size_temp] = '\0';
    size_temp--;
    for (int i{0};data[i]!='\0';i++,size_temp--){
        temp[size_temp] = data[i];
    }
    data = temp;
    delete[] temp;
}

void My_String::reverse2(){
    int i{},j{lenght-1};
    char t;
    for (i = 0;i < j;i++,j--){
        t=data[j];
        data[j]=data[i];
        data[i]=t;
    }
}
#endif