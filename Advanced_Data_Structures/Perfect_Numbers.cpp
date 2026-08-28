#include<iostream>

using namespace std;

int main(){
    int n = 0, count = 0;
    long long ac, consecutive = 2;
    cout << "Enter the number of perfect numbers you want to find: ";
    cin >> n;

    while(count<n){
        ac = 0;
        for(long long i = 1; i < consecutive; i++){
            if(consecutive % i == 0){
                ac = ac + i;
            }
        }
        if(ac == consecutive){
            count++;
            cout << consecutive << " is a perfect number." << endl;
        }
        consecutive++;
    }
    return 0;
}