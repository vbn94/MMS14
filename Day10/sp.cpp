#include <iostream>
#include <memory>

using namespace std;

class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
 
    int area(){
        return length * breadth;
    }
};

template <class T>
class SmartPtr {
    T *ptr;
    public:
        explicit SmartPtr(T* p = NULL) {
             ptr = p;
         }
         ~SmartPtr(){
             delete ptr;
         }
         T& operator*(){
             return *ptr;
         }
         T* operator->(){
             return ptr;
         }
};

int main(){
    /*unique_ptr<Rectangle> p1(new Rectangle(10, 5));
    unique_ptr<Rectangle> p2;
    p2 = move(p1);
    cout << p2->area() << endl;*/
   /* shared_ptr<Rectangle> p1(new Rectangle(10, 5));
    shared_ptr<Rectangle> p2;
    p2 = p1;
    cout << p1->area() << endl;
    cout << p2->area() << endl
    cout << p2.use_count() << endl; */

    shared_ptr<Rectangle> sp(new Rectangle(10, 4));
    weak_ptr<Rectangle> wp;
    wp = sp;
    cout << sp->area() << endl;
    cout << sp.use_count() << endl;
    return 0;
}