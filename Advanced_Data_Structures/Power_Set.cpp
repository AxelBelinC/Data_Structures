#include <iostream>

using namespace std;
 
int main()
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	cout << endl;

    if(n < 1 || n > 26){
        cout << "The number of elements must be between 1 and 26." << endl;
        return 1;
    }

    char letters[26];
    for(int i = 0; i < n; i++){
        letters[i] = 'A'  + i;
    }

    // operator "<<" moves n bits to the left of the number before the operator. (Bitwise Shift)
    int subsets = (1 << n); // number of subsets (2^n)

    cout << endl << "===============Power Set of " << n << " Elements===============" << endl;
    if (n == 0){
        cout << "{}" << endl;
        return 0;
    }

    for(int i = 0; i < subsets; i++){
        cout << "{";
        bool first = true;

        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                if(!first){
                    cout << ", ";
                }
                cout << letters[j];
                first = false;
            }
        }
        
        cout << "}";
        if(i < subsets - 1){
            cout << ", ";
        }

    }
    cout << endl;
    cout << "Total of subsets: " << subsets << endl;
    
	return 0;
}
 