/*************************************************************************
	> File Name: 333.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Oct 2018 12:00:10 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class Person{

protected:
    string color ;
    string country ;
    string name ;
    int age ;
    string hobby ;
    string sex ;
    string identity ;
public:
    void do_what(){

        cout<<"The student is introducing himself!"<<endl ;
    }
    void introduce(){
    
        cout<<"An "<<sex<<" skin color is "<<color<<"  coming!"<<"he said"<<endl ;
        cout<<"hello ,my name is "<<name<<endl ;
        cout<<"I'm from  "<<country<<endl ;
        cout<< "My age is "<<age<<endl ;
        cout<<"Now my identity is  "<<endl ;
        cout<<"my hobby is  "<<hobby<<endl ;
    }
};

class Student : public Person{ 

private :
    string zhiwei ;
    string hobby ;
public :
    void endIntroduce(){
    
        cout<<"The student introduced end!"<<endl ;
    }

    Student(){
        cout<< "Input skin color:"<<"";
         getline(cin , color);
        cout<< "Input country:"<<"";
         getline(cin,country);
          cout<<"input name:"<<"";
          getline(cin,name);
    cout<<"Input age:"<<"";
    cin>>age;
    getchar();
    cout<<"Input sex"<<"" ;
    getline(cin,sex);
    cout<<"Input identity:"<<"";
    getline(cin,identity);
    cout<<"Input zhiwei:"<<"";
    getline(cin,zhiwei);
    cout<<"Input hobby:"<<"";
    getline(cin,hobby);
    }
};

void do_what(){

    cout<<"The student is introducing himself!"<<endl ;
}

void endIntroduce(){
    
    cout<<"The student introduced end!"<<endl ;
}


int main(){

    Student changke ;
    changke.do_what();
    changke.introduce();
    changke.endIntroduce();
}
