#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

class students
{
    public:
    string name;
    int age;
    bool gender;

    // Costructors:::
//Paramaterised:
    students(string a,int b)
    {
        name = a;
        age = b;
        // cout<<"This is an example of a paramtersied constructor.."<<endl;
        // prininfo();
    }
//Default construcor:
    students();

//Copy constructor...
    students(students &a)
    {
        cout<<"copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }


//Operator overloading...
    bool operator == (students &a)
    {
        if (name == a.name && gender == a.gender && age == a.age)
        {
            return true;
        }
    }


    void prininfo()
    {
        cout<<"Name"<<"=";
        cout<<name<<endl;
        cout<<"Age"<<"=";
        cout<<age<<endl;
        cout<<"Gender"<<"=";
        cout<<gender<<endl;
    }
};

signed main()
{
    students pig("Sudarshan",18);
    students huo("Ritesh",20);
    students iop = pig;
    iop.prininfo();
    (pig == huo)? cout<<"YES"<<endl:cout<<"NO"<<endl;
}
