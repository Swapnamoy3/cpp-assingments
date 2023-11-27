/*
Implement a class template for 1D array. Elements may be any basic data type. Provision to find maximum element, sum of the elements must be there.
*/

#include<iostream>

using namespace std;

template <class T>
class array{
    T* arr;
    int mx_size;
public:
    array(int size){
        mx_size=size;
        arr = new T[mx_size];
    }

    T& operator [](int i){
        if(i<0 || i>=mx_size) throw i;
        else {
            return arr[i];
        }
    }

    T sum(){
        T ans;
        for(int i=0;i<mx_size;i++){
            ans+=arr[i];
        }
        return ans;
    }

    T max_Element(){
        T ans=arr[0];
        for(int i=0;i<mx_size;i++){
            ans= max(ans,arr[i]);
        }
        return ans;
    }
};



int main() {
    try {
        int n;
        cout << "Enter the size of the integer array: ";
        cin >> n;

        // Create an array of integers
        array<int> intArray(n);

        // Input elements
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i << ": ";
            cin >> intArray[i];
        }

        // Find and print the maximum element
        int maxInt = intArray.max_Element();
    cout << "Maximum element in the integer array: " << maxInt << endl;
    } catch (int index) {
        cout << "Index " << index << " is out of bounds." << endl;
    }

    return 0;
}