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




// Agar **Constructor** samajh aa gaya hai, to ab **Deep Copy** aur **Shallow Copy** samajhna bahut important hai. Ye C++ ke **sabse important interview topics** me se ek hai.

// Main assume kar raha hoon ki tumhe **pointer bhi properly nahi aata**, isliye bilkul basic se samjhaunga.

// ---

// # Sabse Pehle Copy Constructor Yaad Karo

// Maan lo ek object hai.

// ```cpp
// Student s1("Rahul");
// ```

// Ab hum likhte hain

// ```cpp
// Student s2 = s1;
// ```

// Yaha kya hua?

// **s1 ki copy bana di gayi.**

// Question ye hai:

// **Copy kaise hui?**

// Do tarike hain.

// 1. Shallow Copy
// 2. Deep Copy

// ---

// # Memory Samjho

// Suppose class hai

// ```cpp
// class Student
// {
// public:

//     string name;
//     int age;
// };
// ```

// Object

// ```cpp
// Student s1;
// ```

// Memory

// ```
// s1

// +----------------+
// | name           |
// +----------------+
// | age            |
// +----------------+
// ```

// Ab

// ```cpp
// Student s2 = s1;
// ```

// To

// ```
// s1                    s2

// +---------+          +---------+
// | Rahul   |          | Rahul   |
// +---------+          +---------+
// | 20      |          | 20      |
// +---------+          +---------+
// ```

// Yaha koi problem nahi hai.

// Kyuki

// * string
// * int

// simple variables hain.

// ---

// # Problem Kab Aati Hai?

// Jab Pointer use karte hain.

// Example

// ```cpp
// class Student
// {
// public:

//     int *marks;
// };
// ```

// Ab constructor me

// ```cpp
// marks = new int;
// ```

// Likha.

// Yani memory heap me bani.

// Diagram

// ```
// Object

// +---------+
// | marks --|------------+
// +---------+            |
//                        |
//                        V
//                   +---------+
//                   | 95      |
//                   +---------+
// ```

// Pointer sirf address store karta hai.

// ---

// # Ab Copy Karte Hain

// ```cpp
// Student s1;
// Student s2 = s1;
// ```

// Default Copy Constructor kya karega?

// Sirf address copy karega.

// Diagram

// ```
//           Heap

//         +--------+
//         | 95     |
//         +--------+
//            ^
//            |
// +---------+|      +---------+
// | marks --+------>| marks --+
// +---------+       +---------+

//  s1               s2
// ```

// Notice

// Dono pointer same address ko point kar rahe hain.

// Ye hi

// # Shallow Copy

// ---

// # Shallow Copy Definition

// **Shallow Copy me sirf pointer ka address copy hota hai, actual data copy nahi hota.**

// Isliye

// ```
// s1.marks
// ```

// Aur

// ```
// s2.marks
// ```

// Dono same memory use karte hain.

// ---

// # Shallow Copy Example

// ```cpp
// #include<iostream>
// using namespace std;

// class Student
// {
// public:

//     int *marks;

//     // Constructor
//     Student()
//     {
//         // Heap par memory allocate kar rahe hain
//         marks = new int;

//         *marks = 90;
//     }
// };

// int main()
// {
//     Student s1;

//     // Default copy constructor -> shallow copy
//     Student s2 = s1;

//     cout << *s1.marks << endl;
//     cout << *s2.marks << endl;

//     return 0;
// }
// ```

// Output

// ```
// 90
// 90
// ```

// Abhi tak sab sahi lag raha hai.

// ---

// # Ab Value Change Karte Hain

// ```cpp
// *s2.marks = 50;
// ```

// Code

// ```cpp
// Student s1;

// Student s2 = s1;

// *s2.marks = 50;

// cout << *s1.marks << endl;
// cout << *s2.marks << endl;
// ```

// Output

// ```
// 50
// 50
// ```

// Question

// Humne

// ```
// s2
// ```

// Badla tha.

// Fir

// ```
// s1
// ```

// Kyu change ho gaya?

// Kyuki

// Dono same memory ko point kar rahe hain.

// Diagram

// ```
// Heap

// +--------+
// | 50     |
// +--------+
//    ^
//    |
// +--+---+
// |      |
// |      |
// s1     s2
// ```

// ---

// # Sabse Badi Problem

// Destructor

// ```cpp
// ~Student()
// {
//     delete marks;
// }
// ```

// Maan lo

// ```
// s1
// ```

// Destroy hua.

// Memory delete.

// Ab

// ```
// s2
// ```

// Destroy hua.

// Fir

// ```cpp
// delete marks;
// ```

// Same memory dubara delete.

// Isko kehte hain

// **Double Deletion**

// Result

// ❌ Program crash

// ---

// # Isi Problem Ko Solve Karta Hai

// # Deep Copy

// ---

// Deep Copy me

// Address copy nahi hota.

// Data copy hota hai.

// Diagram

// ```
// Heap

// +--------+        +--------+
// | 90     |        | 90     |
// +--------+        +--------+
//      ^                ^
//      |                |

//    s1              s2
// ```

// Ab dono ki alag memory hai.

// ---

// # Deep Copy Constructor

// ```cpp
// #include<iostream>
// using namespace std;

// class Student
// {
// public:

//     int *marks;

//     // Constructor
//     Student(int value)
//     {
//         // Heap par nayi memory allocate kar rahe hain
//         marks = new int;

//         *marks = value;
//     }

//     // Deep Copy Constructor
//     Student(Student &obj)
//     {
//         // Nayi memory allocate kar rahe hain
//         marks = new int;

//         // Original object ka data copy kar rahe hain
//         *marks = *(obj.marks);
//     }

//     // Destructor
//     ~Student()
//     {
//         // Heap memory free kar rahe hain
//         delete marks;
//     }
// };

// int main()
// {
//     Student s1(90);

//     // Deep copy constructor call hoga
//     Student s2 = s1;

//     // Sirf s2 ki value change kar rahe hain
//     *s2.marks = 50;

//     cout << *s1.marks << endl;
//     cout << *s2.marks << endl;

//     return 0;
// }
// ```

// Output

// ```
// 90
// 50
// ```

// Ab

// ```
// s1
// ```

// Change nahi hua.

// Kyuki

// Alag memory hai.

// ---

// # Memory Diagram

// Before Copy

// ```
// s1

// +--------+
// |marks --|--------+
// +--------+        |
//                   |
//                   V
//              +--------+
//              | 90     |
//              +--------+
// ```

// After Deep Copy

// ```
// s1                    s2

// +--------+          +--------+
// |marks --|---+      |marks --|---+
// +--------+   |      +--------+   |
//              |                   |
//              V                   V

//         +--------+         +--------+
//         | 90     |         | 90     |
//         +--------+         +--------+
// ```

// ---

// # Shallow Copy vs Deep Copy

// | Shallow Copy                                                         | Deep Copy                                   |
// | -------------------------------------------------------------------- | ------------------------------------------- |
// | Address copy hota hai                                                | Data copy hota hai                          |
// | Same memory share hoti hai                                           | Alag memory hoti hai                        |
// | Ek object change karo to dusra bhi change hota hai                   | Dusra object affect nahi hota               |
// | Double delete ka risk hota hai                                       | Safe hota hai                               |
// | Default copy constructor yahi karta hai (pointer members ke case me) | Hume khud copy constructor likhna padta hai |

// ---

// # Real-Life Example

// Suppose tumhare paas ek **house key** hai.

// ### Shallow Copy

// Ek hi ghar ki **duplicate key** bana di.

// ```
// Rahul -----> House

// Aman ------> Same House
// ```

// Dono same house me ja rahe hain.

// Ek andar sofa hata de.

// Dusra bhi wahi badla hua sofa dekhega.

// Yani resource same hai.

// ---

// ### Deep Copy

// Builder ne ek aur same design ka ghar bana diya.

// ```
// Rahul -----> House 1

// Aman ------> House 2
// ```

// Ab Rahul apna ghar paint kare.

// Aman ka ghar nahi badlega.

// ---

// # Rule of Three (Interview Point)

// Agar tumhari class me **pointer** hai aur tum:

// * Constructor likh rahe ho
// * Copy Constructor likh rahe ho
// * Destructor likh rahe ho

// To in teeno ko sahi tarah implement karna zaroori hota hai. Isse C++ me **Rule of Three** kehte hain. Agar deep copy ki zarurat ho aur tum default copy constructor par bharosa kar lo, to shallow copy, shared memory aur double deletion jaise bugs aa sakte hain.

// ## Yaad Rakhne Ki Trick

// * **Shallow = Share** → Same memory share hoti hai.
// * **Deep = Duplicate** → Nayi memory banti hai aur data duplicate hota hai.

// **Interview me agar koi pooche "Shallow copy aur Deep copy me kya difference hai?" to ek line ka best answer hai:**

// > **Shallow copy pointer ka sirf address copy karti hai, jabki Deep copy nayi memory allocate karke actual data copy karti hai. Isliye Deep copy independent aur safe hoti hai, jabki Shallow copy shared memory aur double deletion jaisi problems create kar sakti hai.**
