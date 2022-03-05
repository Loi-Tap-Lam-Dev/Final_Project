#pragma once
#include <iostream>

using namespace std;

class Person
{
  private:
    string name;
    string address;
  public:
    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }
    void setName(string name)
    {
        
    }
    string getName()
    {
        return name;
    }
    void setAddress(string address)
    {
        
    }
    string getAddress()
    {
        return address;
    }
    virtual void display()
    {
        cout<<"name: "<<getName()<<endl;
        cout<<"address: "<<getAddress()<<endl;
    }
};