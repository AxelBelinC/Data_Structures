#include <iostream>
#include <limits>

using namespace std;

long long permutation(int n, int r){ //(n)*(n-1)*...*(n-r+1)
    long long result = 1;
    for(int i = 0; i < r; i++){
        result *= (n - i);
    }
    return result;
}

long long combination(int n, int r){
    if(r > n - r){
        r = n - r; //Optimization C(n, r) = C(n, n-r)
    }
    long long result = 1;
    for(int i = 1; i <= r; i++){
        result = result * (n - i + 1) / i;
    }
    return result;
}

void Permutation_Generator(int n, int r, int position, int boxes[], bool used[], long long& counter){
    if(position == r){
        counter++;
        cout << counter << "\t";

        for(int i = 0; i < r; i++){
            cout << boxes[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            boxes[position] = i;
            used[i] = true;
            Permutation_Generator(n, r, position + 1, boxes, used, counter);
            used[i] = false;
        }
    }
}

void Combination_Generator(int n, int r, int position, int boxes[], int start, long long& counter){
    if(position == r){
        counter++;
        cout << counter << "\t";
        for(int i = 0; i < r; i++){
            cout << boxes[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = start; i <= n; i++){
        boxes[position] = i;
        Combination_Generator(n, r, position + 1, boxes, i + 1, counter);
    }
}

int main(){
    int n, r;

    do{
        cout << "=================PERMUTATION AND COMBINATION CALCULATOR=================" << endl;
        cout << "Enter the value of n: ";
        cin >> n;
        cout << "Now, enter the value of r: ";
        cin >> r;

        if(n < 0 || r < 0 || r > n){
            cout << endl << "Invalid input. Please ensure that n and r are positive numbers and that r is less than or equal to n " << endl; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls || clear");
        }
        
    }while(n < 0 || r < 0 || r > n);


    cout << endl << "Permutation (" << n << "P" << r << "): " << permutation(n, r);
    cout << endl << "Combination (" << n << "C" << r << "): " << combination(n, r) << endl;

    cout << endl << "==================PERMUTATION GENERATION=================" << endl;
    cout << "No.\tPermutation" << endl;
    int boxes[101];
    long long counter = 0;
    bool used[101] = {false};
    Permutation_Generator(n, r, 0, boxes, used, counter);

    cout << endl << "==================COMBINATION GENERATION=================" << endl;
    cout << "No.\tCombination" << endl;
    int boxes_c[101];
    long long counter_c = 0;
    Combination_Generator(n, r, 0, boxes_c, 1, counter_c);

    cout << endl << "Press enter to exit." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}