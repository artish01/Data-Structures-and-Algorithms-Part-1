#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> v1;

    // v1.push_back(12);
    // v1.push_back(342);
    // v1.push_back(1);

    // cout<<v1.at(0)<<endl;
    // cout<<v1.at(1)<<endl;
    // cout<<v1.at(2)<<endl;

    //                                 v1.pop_back();
    //                                 // v1.pop_back();
    //                                 // v1.pop_back();

    //                                 v1[0] = 2; // this will give error as if i  pop all the elements
    //                                             // we can use array only for update of element not for insert
    // cout<<"Size-> "<<v1.size()<<endl;
    // cout<<"Element at 1 -> "<<v1.at(1)<<endl;

    // // for(int i=0; i<v1.size(); i++)
    // // {
    // //     cout<<v1.at(i)<<endl;
    // // }

    // for(int i:v1)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // cout<<"Front element "<<v1.front()<<endl;
    // cout<<"Back element "<<v1.back()<<endl;

    vector<int> v1;
    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1.push_back(12);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1.push_back(21);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1.push_back(14);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1.push_back(4);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1.push_back(40);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    v1[5] = 221; // can be use for update only

    v1.push_back(1);

    cout << "Size = " << v1.size() << endl;
    cout << "capacity = " << v1.capacity() << endl;

    // v1.push_back(410);

    // cout << "Size = " << v1.size() << endl;
    // cout << "capacity = " << v1.capacity() << endl;

    for (int i : v1)
    {
        cout << i <<" ";
    }
    cout << endl;

    cout << "Element at 5 index : " << v1.at(5) << endl;
    cout << "Front " << v1.front() << endl;
    cout << "back " << v1.back() << endl;

    // cout<<v1.at(8);
    cout<<v1[8]; // array will print garbage value if the index is under capacity but  at function will terminate;

    return 0;
}