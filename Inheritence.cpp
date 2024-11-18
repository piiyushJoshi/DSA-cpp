#include<iostream>
using namespace std;

class fruit{
    public:
    int no_fruits;
    fruit(int a = 0){
        no_fruits = a;
    }
    void print_data(){
        cout<<"Number of fruits in the basket is: "<<no_fruits<<endl;
    }
};
class mango;                     //forward declaration
class apple : public fruit{
    private:
    int no_apples;
    public:
    apple(int a = 0){
        no_apples = a;
    }
    void print_data(){
        cout<<"Number of apples in the basket is: "<<no_apples<<endl;
    }
    friend int add(apple o1,mango o2);
};
class mango : public fruit{
    private:
    int no_mangoes;
    public:
    mango(int a = 0){
        no_mangoes = a;
    }
    void print_data(){
        cout<<"Number of mangoes in the basket is: "<<no_mangoes<<endl;
    }
    friend int add(apple o1,mango o2);
};

int add(apple o1,mango o2){
    fruit f1;
    f1.no_fruits = o1.no_apples + o2.no_mangoes;
    return f1.no_fruits;
}

int main(){
    int a,b;
    cout<<"Enter the number of apples: ";
    cin>>a;
    cout<<"Enter he number of mangoes: ";
    cin>>b;
    apple a1(a);
    mango m1(b);
    fruit f1(add(a1,m1));
    a1.print_data();
    m1.print_data();
    f1.print_data();
    return 0;
}
