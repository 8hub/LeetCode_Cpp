#include <iostream>
#include <algorithm>

using namespace std;
int b_search(int l, int r, int array[], int target){
    int mid = 0;
    while (l <= r){
        mid = l + (r - l)/2;
        if(array[mid] > target){
            r = mid - 1;
        }
        else if(array[mid] < target){
            l = mid + 1;
        }
        else return mid;
    }
    return -1;
}

int main(){
    int array[7]{5,2,3,1,1,10,4};
    // for(auto a:array){
    //     cout << a << endl;
    // }
    sort(array, array+6);
    cout << b_search(0, 6, array, 1) << endl;
    cout << b_search(0, 6, array, 3) << endl;
    cout << b_search(0, 6, array, 10) << endl;
    cout << b_search(0, 6, array, 0) << endl;
    cout << b_search(0, 6, array, 11) << endl;
    return 0;
}