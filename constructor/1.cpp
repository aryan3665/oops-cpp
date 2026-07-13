// #include <iostream>
// using namespace std;

// class Student
// {
//     string name;
//     int age;

// public:
//     // Default Constructor
//     Student()
//     {
//         name = "Unknown";
//         age = 18;
//     }

//     void display()
//     {
//         cout << "Name : " << name << endl;
//         cout << "Age : " << age << endl;
//     }
// };

// int main()
// {
//     Student s;

//     s.display();

//     return 0;
// }



//parametrized
// #include <iostream>
// using namespace std;

// class Car
// {
//     string brand;
//     int price;

// public:
//     Car(string b, int p)
//     {
//         brand = b;
//         price = p;
//     }

//     void display()
//     {
//         cout << "Brand : " << brand << endl;
//         cout << "Price : " << price << endl;
//     }
// };

// int main()
// {
//     Car c("BMW", 6000000);

//     c.display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Rectangle
// {
//     int length;
//     int breadth;

// public:
//     Rectangle()
//     {
//         length = 1;
//         breadth = 1;
//     }

//     Rectangle(int l, int b)
//     {
//         length = l;
//         breadth = b;
//     }

//     void area()
//     {
//         cout << "Area = " << length * breadth << endl;
//     }
// };

// int main()
// {
//     Rectangle r1;

//     Rectangle r2(10, 5);

//     r1.area();

//     r2.area();

//     return 0;
// }

// copy constructor

#include <iostream>
using namespace std;

class Student
{
    string name;
    int age;

public:
    // Default Constructor
    Student()
    {
        name = "Unknown";
        age = 18;
    }

    Student(Student &s){
        name=s.name;
        age=s.age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }
};

int main()
{
    Student s1;

    cout<<"student 1:";
    s1.display();
    cout<<"---------------------------------------------------->"<<endl;
    Student s2(s1);
    cout << "student 2:";
    s2.display();

    


    return 0;
}
