#pragma once

#include <new>
#include <cassert> // дл€ assert
#include <iostream>
#include <typeinfo>
#include <exception>
#include<string>
#include <conio.h>
#include <algorithm>
#include <regex>

#include "Employee.h"
//#include "Administrator.h"
#include "StackErr.h"

using namespace std;
#include <iomanip> // дл€ setw
inline std::string enter_datee(std::istream& in) {
    string i;
    int flags;
    do {
        try {
            flags = 0;
            std::cout << "Enter date... ";
            in >> i;
            if (!std::cin || std::cin.peek() != '\n') {
                throw 1;
            }
            //regex_search()
            static std::regex rgx{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))" };
            smatch res;
            if (regex_search(i, res, rgx))
            {
                for (int j = 0; j < i.size(); j++) {
                    if (i[0] == '3' && i[1] == '1' && i[3]=='0' && i[4] == '2')
                    {
                        throw 1;
                        
                        
                    }
                    else if (i[0] == '3' && i[1] == '0' && i[3] == '0' && i[4] == '2')
                    {
                        throw 1;
                    }
                }
                return i;
                /*d.day = std::stoi(res[1]);
                d.month = std::stoi(res[2]);
                d.year = std::stoi(res[3]);*/
                //return true;
            }
            else {
                throw 1;
            }
            //return false;
            /*if (i < min || i > max) {
                throw 'a';
            }*/
        }
        catch (int) {
            flags = 1;
            std::cout << "It's not a (type) date!!!\n\n";
            std::cin.clear(0);
            rewind(stdin);
        }
        catch (char) {
            flags = 1;
            std::cout << "Out of range.\n\n";
            std::cin.clear(0);
            rewind(stdin);
        }
    } while (flags);
    return i;
}

inline int* string_IntMas(std::string date)
{
    int* res = new int[3];
        char st[] = { date[0] , date[1] };
        string day = string(st);
        int day1 = std::stoi(day);
        char st1[] = { date[3] , date[4] };
        string month = string(st1);
        int month1 = std::stoi(month);
        char st2[] = { date[6] , date[7],date[8] , date[9] };
        string year = string(st2);
        int year1 = std::stoi(year);
        res[0] = day1;
        res[1] = month1;
        res[2] = year1;
    return res;
}

 inline std::string enter_chars(std::istream& in) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // ¬вод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    ////////

    std::string s;
    int flags;
    std::string letters = "абвгдеЄжзийклмнопрстуфхцчшщъыьэю€";
    do {
        try {
            flags = 0;
            rewind(stdin);
            std::cout << "Enter the letters... ";
            getline(in, s);
            //std::transform(s.begin(), s.end(), s.begin(), tolower);
            //in >> s;			
            for (int i = 0; i < s.length(); i++)
            {
                for (int il = 0; il < letters.length(); il++)
                {
                    if (s[i] != letters[il])
                    {
                        if (il == letters.length() - 1)
                        {
                            if (!isalpha(s[i]) && s[i] != ' ' && s[i] != '-')
                                throw 1; break; break;
                        }
                    }
                    else break;
                }
            }
        }
        catch (int) {
            flags = 1;
            std::cout << "It's not a letters!!!\n\n";
            std::cin.clear(0);
            rewind(stdin);
        }
    } while (flags);
    return s;
}


template <typename T>
class Stack
{
public:
    T* stackPtr;                      // указатель на стек
     int size=100;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека

    Stack(int maxSize) : size(maxSize)
    {
        try {
            stackPtr = new T[size]; // выделить пам€ть под стек
        }
        catch (bad_alloc ex)
        {
            cout << "Exeption " << ex.what();
            cout << "size= " << size << endl;
        }
        top = 0; // инициализируем текущий элемент нулем;
    }

    Stack() {
        top = 0;
        //stackPtr = NULL;
        stackPtr = new T[size];
    }
    Stack(T i) {
        top = 0;
        //stackPtr = NULL;
        stackPtr = new T[size];
        push(i);
    }

     int getTop() const
    {
        return top;
    }

    ~Stack()
    {
        delete[] stackPtr; // удал€ем стек
    }

   friend ostream& operator<<(ostream& out, Stack<T>& obj)
    {
        out << std::right << std::setw(22) << "full name" << std::right << std::setw(25) << "department number" << std::right << ::setw(20) << "position" << std::right << ::setw(22) << "start date of work" << endl;
        for (int ix = obj.top - 1; ix >= 0; ix--)
        {
            out << "|" << obj.stackPtr[ix] << endl;
        }
        return out;
    }

    void checkEmpty(int s)
    {
        char str[] = "The stack is empty!";
        if (s == 0)
            throw StackErr(str);
    }

    void checkSize(int s)
    {
        char str[] = "The stack is already full!";
        if (s == size)
            throw StackErr(str);
    }

    bool checkEnter(T e, char* S)
    {
        const char* temp = "0123456789-+";
        char str[] = "Invalid input!";
        for (int i = 0; i < strlen(S); i++) {
            if (!strchr(temp, S[i])) throw StackErr(str); return false;
        }
        return true;
    }

     void push(T elem)
    {
        try {
            checkSize(getTop());
        }
        catch (StackErr ss)
        {
            cout << "Warning -  ";
            ss.show();
            return;
        }
        stackPtr[top++] = elem;// помещаем элемент в стек
    }

     T pop()
    {
        try {
            checkEmpty(top);
        }
        catch (StackErr st)
        {
            cout << "Warning -  ";
            st.show();
            T t;
            return t;
        }
        return stackPtr[--top];  // удал€ем элемент из стека
    }

     void clearStack()
     {
         for (int ix = top - 1; ix >= 0; ix--)
         {

            /* try {
                 checkEmpty(top);
             }
             catch (StackErr st)
             {
                 cout << "Warning -  ";
                 st.show();
                 T t;
                 //return t;
             }*/
            // return 
                 stackPtr[--top];
         }
     }

     
     const T& search(int nom, string date) const
    {
         int kol = 0;
        for (int ix = top - 1; ix >= 0; ix--)
        {
            if (stackPtr[ix].getDepNum(stackPtr[ix]) == nom)
            {
                cout << "found" << endl;
                kol++;
               // return stackPtr[ix];
                break;
            }
        }
        if (kol==0)
        {
            cout << "not found" << endl;
        }
        
        /*for (int j = 0; j < date.size(); j++) {
            char st[]={ date[0] , date[1] }; 
            string day = string(st);
            int day1=std::stoi(day);
            char st1[] = { date[3] , date[4] };
            string month = string(st1);
            int month1 = std::stoi(month);
            char st2[] = { date[6] , date[7],date[8] , date[9] };
            string year = string(st2);
            int year1 = std::stoi(year);
        }*/
        int* masDate = string_IntMas(date);

        for (int ix = top - 1; ix >= 0; ix--)
        {
            if (stackPtr[ix].getDepNum(stackPtr[ix]) == nom)
            {

                /*****************************************/
                string d=stackPtr[ix].getStartDateOfWork();
                int* masFindDate= string_IntMas(d);
                if (masFindDate[2] < masDate[2])
                {
                    cout << stackPtr[ix];
                }
                else
                {
                    if (masFindDate[2] == masDate[2])
                    {
                        if (masFindDate[1] < masDate[1])
                        {
                            cout << stackPtr[ix];
                        }
                        else
                        {
                            if (masFindDate[1] == masDate[1])
                            {
                                if (masFindDate[0] <= masDate[0])
                                {
                                    cout << stackPtr[ix];
                                }
                            }
                        }
                        // else if(masFindDate[1] > masDate[1])
                    }
                }
                /*****************************************/
              // cout << stackPtr[ix];
            }
        }
        T t;
        return t;
    }

     void editing(string name)
     {
         int kol = 0;
         for (int ix = top - 1; ix >= 0; ix--)
         {
             if (stackPtr[ix].getFullName() == name)
             {
                 kol++;
                 int ch = 0;
                 cout << "1 - full name \n2 - department number \n3 - position \n4 - start date of work \n5 - exit\n";
                 cout << "Enter choice: ";
                 cin >> ch;
                 switch (ch) {
                 case 1:
                 { cout << "Enter name:" << endl;
                 string name = enter_chars(std::cin);
                 stackPtr[ix].updateFullName(name);
                 }
                     break;
                 case 2:
                 {
                     cout << "Enter department number:" << endl;
                     int num = 0;
                     cin >> num;
                     stackPtr[ix].updateDepartmentNumber(num);
                 }
                     break;
                 case 3:
                 {  cout << "Enter position:" << endl;
                 string pos = enter_chars(std::cin);
                 stackPtr[ix].updatePosition(pos);
                 }
                     break;
                 case 4:
                 {
                     cout << "Enter start date of work:" << endl;
                     
                     string start = enter_datee(std::cin);              //!!!!!!!!!!!!!!!!!!!!!!!!!!!
                     stackPtr[ix].updatestartDateOfWork(start);
                 }
                     break;
                 case 5:
                     break;
                 }
                 //cout << "Enter name" << endl;
                // string name = enter_chars(std::cin);
                // stackPtr[ix].updateFullName(name);
                //// cout << "found" << endl;
                // return stackPtr[ix];
                // break;
             }
         }
         if (kol == 0) {
             cout << "not found!!!" << endl;
         }
         

     }
    // вывод стека на экран
   
    void printStack()
    {
        std::cout << std::right << std::setw(22) << "full name" << std::right << std::setw(25) << "department number" << std::right << ::setw(20) << "position" << std::right << ::setw(22) << "start date of work" << endl;
        for (int ix = top - 1; ix >= 0; ix--)
            cout << "|" << stackPtr[ix] << endl;
    }


    //вернуть указатель на стек (дл€ конструктора копировани€)
    
     T*getPtr() const
    {
        return stackPtr;
    }

   
     void sortStack()
    {
        for (int i = 1; i < top; i++)
            for (int j = i; j > 0 && stackPtr[j - 1].getDepNum(stackPtr[j - 1]) < stackPtr[j].getDepNum(stackPtr[j]); j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(stackPtr[j - 1], stackPtr[j]);
    }

   
     void sortStackB()
    {
        for (int i = 1; i < top; i++)
            for (int j = i; j > 0 && stackPtr[j - 1].getDepNum(stackPtr[j - 1]) > stackPtr[j].getDepNum(stackPtr[j]); j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(stackPtr[j - 1], stackPtr[j]);
    }

     void PrintInFail(string file_name)
     {
         if (size != 0)
         {
           for (int ix = top - 1; ix >= 0; ix--)
             {
                 stackPtr[ix].fillFile(file_name);
             }
         }
     }
};