#include <iostream>
using namespace std;

void doSth(unsigned int x){
    cout << "Value is: " << x << endl;
}

int main(){
    int num;
    num = INT_MAX;
    unsigned int u_num;
    u_num = num*2;

    std::cout << num << std::endl;
    {
        num +=1;
        cout << num << endl;
    }

    std::cout << u_num << std::endl;
    for (int i = 0; i < 2; i++)
    {
        u_num +=1;
        cout << u_num << endl;
    }

    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';


    //Automatic convertion to unsigned after math operation
    signed int num3 = 0;
    cout << num3 - unsigned(1) << endl;
    //Automatic convertion after comparison signed(-1) become unsigned 4294967295
    if(signed(-1) > unsigned(1)){
        cout << "Whaaaat? How -1 > 1 ?!" << endl;
    }

/*
    void doSth(unsigned int x){
        cout << "Value is: " << x << endl;
    }
*/
    //Output is 4294967295 (automatically converted to parameter data type - unsigned)
    doSth(-1);
    return 0;
}