// CPP code to illustrate the pointer reinterpret
#include <iostream>
using namespace std;

class A {
public:
	void fun_a() {
		cout << " In class A\n";
	}
};

class B {
public:
	void fun_b() {
		cout << " In class B\n";
	}
};

int main()
{
   // creating object of class B
   B* x = new B();

   cout << "B - " << x;
   x->fun_b();

   // converting the pointer to object
   // referenced of class B to class A
   //reinterpret_cast only guarantees that if you cast a pointer to a different
//type, and then reinterpret_cast it back to the original type, you get the
//original value. So in the following:
   /*This code compiles, although it does not make much sense, since now new_a
points to an object of a totally unrelated and likely incompatible class.*/
//Dereferencing new_a is unsafe.

   //A* new_a = reinterpret_cast<A*>(x);

   /*this will give compile error as these are polymorphic classes. Plymorpic
classes require atleast one virtual function. atleast a virtual destructor
(anyway virtual destructor is needed in polymorphic classes to safely use
delete)*/
   //A* new_a = dynamic_cast<A*>(x);
   //The below statement has the same effect as the reinterpret_cast.
   //A* new_a = (A*) x;

   //cout << endl <<"A - " << new_a;
   // accessing the function of class A
   //new_a->fun_a();

   int a = 1;
   if(--a == 0)
	   printf("1\n");
   else
	   printf("2\n");
   return 0;
} 