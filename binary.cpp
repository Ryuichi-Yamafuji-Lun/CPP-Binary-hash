//binary search implementation
#include <iostream>
#include <cmath>
using namespace std;

int binary_search(int array[],int n,int num){
    int left = 0;
    int right = n - 1;
    //search through array
    while(left <= right){
        //find mid length
        int mid = (left + right)/2;
        if(array[mid] < num){
            left = mid + 1;
        }
        else if(array[mid] > num){
            right = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(void){
    //array
    int array[] = {1,2,3,4};
    int num = 0;
    cout << "Key? ";
    cin >> num;
    int n = *(&array + 1) - array;
    int result = binary_search(array, n, num);
    if(result == -1) {
        cout << "element is not present";
    }
    else{
        cout << "Found (Step = " << result << ")" << endl;
    }
    return 0;
}