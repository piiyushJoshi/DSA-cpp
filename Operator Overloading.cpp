#include<iostream>
using namespace std;

class overloading{
    private:
    int a,b;
    public:
    overloading(){}
    overloading(int x,int y){
        a = x;
        b = y;
    }
    void display(){
        cout<<"Values of x,y are: "<<a<<" "<<b<<endl;
    }
    overloading operator + (overloading o){
        overloading obj;
        obj.a = a+o.a;
        obj.b = b+o.b;
        return obj;
    }
    overloading operator - (overloading o){
        overloading obj;
        obj.a = a-o.a;
        obj.b = b-o.b;
        return obj;
    }
};

int main(){
    overloading o1(3,5),o2(5,3),o3,o4;
    o1.display();
    o2.display();
    o3 = o1+o2;
    o4 = o1-o2;
    o3.display();
    o4.display();
    
    return 0;
}
