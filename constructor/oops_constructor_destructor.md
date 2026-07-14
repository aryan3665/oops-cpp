# OOP in C++ Notes

## 1. What is OOP?

OOP (Object Oriented Programming) is a programming style where we create
**classes** and **objects**.

### Advantages

-   Code Reusability
-   Easy Maintenance
-   Security
-   Real-world modeling

------------------------------------------------------------------------

# 2. Class

A class is a blueprint.

``` cpp
class Student
{
public:
    int age;
};
```

------------------------------------------------------------------------

# 3. Object

Object is an instance of a class.

``` cpp
Student s1;
```

------------------------------------------------------------------------

# 4. Constructor

A constructor is a special function that runs automatically when an
object is created.

Rules: - Same name as class - No return type - Automatically called

``` cpp
class Student
{
public:
    Student()
    {
        cout<<"Constructor\n";
    }
};
```

Parameterized constructor:

``` cpp
class Student
{
public:
    int age;

    Student(int a)
    {
        age=a;
    }
};
```

------------------------------------------------------------------------

# 5. Destructor

Destructor runs automatically when an object is destroyed.

Rules: - Name starts with `~` - No parameters - Only one destructor

``` cpp
class Student
{
public:
    ~Student()
    {
        cout<<"Destructor\n";
    }
};
```

Use: - Free dynamic memory - Close files - Cleanup resources

------------------------------------------------------------------------

# 6. Static Memory Allocation

Memory allocated automatically.

``` cpp
int x=10;
Student s1;
```

Features: - Fast - Automatically destroyed

------------------------------------------------------------------------

# 7. Dynamic Memory Allocation

Memory allocated using `new`.

``` cpp
int *ptr=new int;
*ptr=10;

delete ptr;
```

Always free memory using `delete`.

------------------------------------------------------------------------

# 8. Stack vs Heap

## Stack

-   Automatic memory
-   Faster
-   Auto deleted

## Heap

-   Dynamic memory
-   Slower
-   Must use delete

------------------------------------------------------------------------

# 9. Shallow Copy

Only pointer address is copied.

``` cpp
Student s2=s1;
```

Problem: - Shared memory - Double delete - Unexpected changes

------------------------------------------------------------------------

# 10. Deep Copy

Allocate new memory and copy actual data.

``` cpp
Student(Student &obj)
{
    ptr=new int;
    *ptr=*obj.ptr;
}
```

Benefits: - Independent objects - Safe memory management

------------------------------------------------------------------------

# Quick Revision

-   Class = Blueprint
-   Object = Real instance
-   Constructor = Initialization
-   Destructor = Cleanup
-   Static Memory = Stack
-   Dynamic Memory = Heap
-   Shallow Copy = Address copy
-   Deep Copy = Data copy

------------------------------------------------------------------------

# Next Topics

-   Encapsulation
-   Inheritance
-   Polymorphism
-   Abstraction
