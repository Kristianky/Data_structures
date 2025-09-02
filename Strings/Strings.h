#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class My_String
{
private:
    char *data;
    int lenght;

public:
    My_String()
    {
        data = new char[]{"WELCOME"};
        for (int i{1}; data[i] != '\0'; i++)
        {
            lenght = i + 1;
        }
    }
    ~My_String() { delete[] data; }
    int get_lenght() { return lenght; }
    void change_to_upper();
    void change_to_lower();
    void display() const;
    void reverse();
    void reverse2();
    bool operator==(const My_String &LHS) const;
    bool is_palindrome() const;
    void Check_Dublicate_Hash_Table() const;      // pouziva hash table cize array long int a porovnava to cez ascii code
    void Check_Duplicate_Bitwise() const;         // kontroluje pismena ci sa opakuju pouzivanim bit tabuliek
    bool is_anagram(const std::string RHS) const; // ci su tam tie iste pismena ale vsetky napr medical == decimal
    void Combinations(int k);
    int permutation(int k);
};

void My_String::change_to_lower()
{

    for (int i{0}; data[i] != '\0'; i++)
    {
        data[i] = data[i] + 32;
    }
}

void My_String::change_to_upper()
{

    for (int i{0}; data[i] != '\0'; i++)
    {
        data[i] = data[i] - 32;
    }
}

void My_String::display() const
{
    for (int i{0}; data[i] != '\0'; i++)
    {
        std::cout << data[i];
    }
    std::cout << "\n";
}
void My_String::reverse()
{
    char *temp;
    int size_temp = lenght;
    temp = new char[size_temp];
    temp[size_temp] = '\0';
    size_temp--;
    for (int i{0}; data[i] != '\0'; i++, size_temp--)
    {
        temp[size_temp] = data[i];
    }
    data = temp;
    delete[] temp;
}

void My_String::reverse2()
{
    int i{}, j{lenght - 1};
    char t;
    for (i = 0; i < j; i++, j--)
    {
        t = data[j];
        data[j] = data[i];
        data[i] = t;
    }
}

bool My_String::operator==(const My_String &LHS) const
{
    int i, j;
    for (i = 0, j = 0; data[i] != '\0' && LHS.data[j] != '\0'; i++, j++)
    {
        if (data[i] != LHS.data[j])
        {
            return false;
        }
        
    }
    return true;
}
bool My_String::is_palindrome() const
{
    for (int i{}, j{lenght}; i < j; i++, j--)
    {
        if (data[i] != data[j])
        {
            return false;
        }
    }
    return true;
}
void My_String::Check_Dublicate_Hash_Table() const
{
    int table[25];
    for (int i{}; i < 51; i++)
    {
        table[i] = 0;
    }
    for (int i{}; data[i] != '\0'; i++)
    {
        table[data[i] - 65]++;
    }
    for (int i{}; data[i] != '\0'; i++)
    {
        table[data[i] - 72]++;
    }
    for (int i{}; table[i] < 51; i++)
    {
        if (table[i] > 1)
        {
            std::cout << "Letter: " << i + 65 << " is there: " << table[i] << " times.";
        }
    }
}
void My_String::Check_Duplicate_Bitwise() const
{
    long int table{0}, x{0};
    for (int i{}; data[i] != '\0'; i++)
    {
        x = 1;
        x = x << (data[i] - 97);
        if ((x & table) > 0)
        {
            std::cout << data[i] << " is duplicate!!";
        }
        else
        {
            table = table || x;
        }
    }
}
bool My_String::is_anagram(const std::string RHS) const
{
    int Hash_Table[26];
    for (int i{}; i < 26; i++)
    {
        Hash_Table[i] = 0;
    }
    for (int i{}; data[i] != '\0'; i++)
    {
        Hash_Table[data[i] - 97]++;
    }
    for (int i{}; RHS[i] != '\0'; i++)
    {
        Hash_Table[data[i] - 97]--;
    }
    for (int i{}; i < 26; i++)
    {
        if (Hash_Table[i] != 0)
        {
            return false;
        }
    }
     return true;
}
void My_String::Combinations(int k){
    static char *Table;
    static int *I;
    int index {};
    Table = new char[lenght];
    I = new int [lenght];
    Table[lenght] = '\0';
    for (int i{};i < lenght;i++){
        I[i] = 0;
    }
    for (index = 0;data[index] != '\0';index++){
        if (data[k]=='\0'){
            Table[k] = '\0';
            std::cout<<Table[k];
        }
        else{
            for(index = 0;data[index] != '\0';index++){
                if (I == 0){
                    Table[k] = data[index];
                    I[index] = 1;
                    Combinations(k + index);
                    I[index] = 0;
                }
            }
        }
    }
}
int My_String::permutation(int k){
    static int *Number_Of_Pemutation = new int[lenght];
    static char *Perm_Table;
    int i{};
    Perm_Table = new char[lenght];
    if (data[k]=='\0'){
        for (int j{};Perm_Table[j]!='\0';j++){
            std::cout<<Perm_Table[j]<<" ";
        }
    }
    else {
        for (i=0;data[i]!='\0';i++){
            if(Number_Of_Pemutation[i]==0){
                Perm_Table[k]=data[i];
                Number_Of_Pemutation[i] = 1;
                permutation(k + 1);
                Number_Of_Pemutation[i] = 0;    
            }
        }
    }
}
#endif