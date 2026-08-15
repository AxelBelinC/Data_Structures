#include <iostream>
#include <limits>

using namespace std;

long long factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main(){
    int n, r;
    long long permutation, combination;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Now, enter the value of r (only works for r = 2): ";
    cin >> r;

    if(n < 0 || r < 0 || r > n){
        cout << endl << "Invalid input. Please ensure that n and r are positive numbers and that r is less than or equal to n " << endl;
        return 1;
    }

    permutation = factorial(n)/factorial(n - r);
    combination = factorial(n)/(factorial(n - r) * factorial(r));
    cout << endl << "Permutation (" << n << "P" << r << "): " << permutation;
    cout << endl << "Combination (" << n << "C" << r << "): " << combination << endl;

    cout << endl << "Permutation's table (" << permutation<< "):" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (i != j){
                cout << i << "," << j << endl;
            }
        }
    }

    cout << endl << "Combination's table (" << combination <<"):" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (i < j){
                cout << i << "," << j << endl;
            }
        }
    }

    cout << endl << "Press enter to exit." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}