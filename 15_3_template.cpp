#include "iostream"
using namespace std;

template <typename T, typename V>

class temp
{
    // int x;
    // int y;

    // T x;
    // V y;

    T x;  // if same data of both then both T if different then one T and one Y
    V y;

public:
    void setx(T x)
    {
        this->x = x;
    }
    T getx()
    {
        return x;
    }

    void sety(V y)
    {

        this->y = y;
    }
    V gety()
    {
        return y;
    }
};

int main()
{
    // temp p;
    // p.setx(4);
    // cout<<p.getx()<<endl;

    // p.sety(7);
    // cout<<p.gety()<<endl;

    // using template

    // temp<int,float> p1;

    // p1.setx(3);
    // cout<<p1.getx()<<endl;

    // p1.sety(13.654);
    // cout<<p1.gety()<<endl;

    temp<temp<int, float>, float> t1;

    t1.sety(12.1);

    temp<int, float> t2;

    t2.setx(232);
    t2.sety(32); 

    t1.setx(t2);

    cout<<t1.getx().getx()<<endl;
    cout<<t1.getx().gety()<<endl;
    cout << t1.gety() << endl;
    


   


    return 0;
}