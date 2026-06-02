/* | 01/06/2026 || 01/06/2026 |
Axel Armando Belin Castorena - 355651 | Brandon Alejandro Herrera Rodriguez - 243519
Intelligent Computing Engineering 2°A - UAA
Program objective: Show the QuickSort and Bubble Sort sorting methods.
*/

#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <chrono> //take the exact time

using namespace std;
using namespace chrono;

//Function prototypes using pass-by-reference
void VectorMaker(vector<int> &Original, const int size);
void ShowVector(vector<int> &Original);
double BubbleSort(vector<int> &Bubble);
double QuickSortMain(vector<int> &Quick);
void QuickSort(vector<int> &arr, int low, int high, bool ascending);
int partition(vector<int> &arr, int low, int high, bool ascending);
void CompareTimes(double timeBubble, double timeQuick);

int main (){
    int op;

    //variables for the vector
    const int size = 10000;
    vector<int> Original(size);
    bool vectorGenerated = false;

    double timeBubble = 0.0;
    double timeQuick = 0.0;

    cout << "==============QUICKSORT AND BUBBLE SORT ALGORITHMS==============" << endl;
    do{
        cout << endl << "===============MENU===============" << endl;
        cout << "[1]. Generate Vector" << endl;
        cout << "[2]. Show Vector" << endl;
        cout << "[3]. Bubble Sort" << endl;
        cout << "[4]. QuickSort" << endl;
        cout << "[5]. Compare times" << endl;
        cout << "[6]. Clean Vector" << endl;
        cout << "[0]. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Enter an option: ";
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls || clear");

        switch (op){
            case 1:
                VectorMaker(Original, size);
                vectorGenerated = true;
            break;
            case 2:
                if (vectorGenerated) ShowVector(Original);
                else cout << "First you have to generate the vector." << endl;
            break;
            case 3:
                if (vectorGenerated) {
                    vector<int> Bubble = Original; //copy the generated vector
                    timeBubble = BubbleSort(Bubble);
                } else {
                    cout << "First you have to generate the vector." << endl;
                }
            break;
            case 4:
                if (vectorGenerated) {
                    vector<int> Quick = Original; 
                    timeQuick = QuickSortMain(Quick); //call to the main function QuickSort
                } else {
                    cout << "First you have to generate the vector." << endl;
                }
            break;
            case 5:
                if (timeBubble > 0.0 && timeQuick > 0.0) {
                    CompareTimes(timeBubble, timeQuick);
                } else {
                    cout << "You must execute both methods before comparing." << endl;
                }
            break;
            case 6:
                fill(Original.begin(), Original.end(), 0); //clean the vector filled it with zeros
                timeBubble = 0.0;
                timeQuick = 0.0;
                vectorGenerated = false;
                cout << "Vector cleaned and times successfully reset." << endl;
            break;
            default:
                cout << "Please enter a valid option." << endl;
            break;
        }

        if (op != 0){
            cout << endl << "Please enter any key to return. ";
            cin.get();
        }
        system("cls || clear");
    } while (op != 0);
    
    return 0;
}

void VectorMaker(vector<int> &Original, const int size){
    srand(time(0)); //change the elements each time

    for (int i = 0;  i < size; i++){ //Vector generated with 10,000 random elements between 1 and 50,000
        Original[i] = rand() % 1000 + 1; 
    }

    cout << "Vector of " << size << " random elements generated." << endl;
}

void ShowVector(vector<int> &Original){
    cout << "Vector elements:" << endl;
    for (size_t i = 0; i < Original.size(); i++){
        cout << i + 1 << ": " <<  Original[i] << endl;
    }
}

double BubbleSort(vector<int> &Bubble){
    int x;
    cout << "===========Sorting Vector using Bubble Sort===========" << endl;
    cout << "Choose [1] for ascending order and [2] for descending order: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls || clear");

    auto start = high_resolution_clock::now();

    switch (x){
        case 1: //ascending
            for (size_t i = 0; i < Bubble.size() - 1; i++){ 
                for (size_t j = 0; j < Bubble.size() - i - 1; j++){
                    if (Bubble[j] > Bubble[j + 1]){
                        swap(Bubble[j], Bubble[j + 1]); //exchange the value between the two elements
                    }
                }
            }
            ShowVector(Bubble);
        break;
        case 2: //descending
            for (size_t i = 0; i < Bubble.size() - 1; i++){
                for (size_t j = 0; j < Bubble.size() - i - 1; j++){
                    if (Bubble[j] < Bubble[j + 1]){
                        swap(Bubble[j], Bubble[j + 1]);
                    }
                }
            }
            ShowVector(Bubble);
        break;
        default:
            cout << "Please choose a valid option." << endl;
            return 0.0;
        break;
    }

    auto end = high_resolution_clock::now();
    duration<double, milli> ExecutionTime = end - start;

    cout << endl << "Bubble Sort finished in: " << ExecutionTime.count() << "ms" << endl;

    return ExecutionTime.count(); //return the milliseconds it took for later comparisons.
}

double QuickSortMain(vector<int> &Quick) {
    int order;
    cout << "=========== QUICKSORT ===========" << endl;
    cout << "Choose [1] for ascending order and [2] for descending order: ";
    cin >> order;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls || clear");

    bool ascending = (order == 1);

    auto start = high_resolution_clock::now();

    //call to the recursive function
    QuickSort(Quick, 0, Quick.size() - 1, ascending);

    auto end = high_resolution_clock::now();
    duration<double, milli> ExecutionTime = end - start;

    ShowVector(Quick);
    cout << endl << "QuickSort finished in: " << ExecutionTime.count() << "ms" << endl;

    return ExecutionTime.count();
}

void QuickSort(vector<int> &arr, int low, int high, bool ascending) {
    if (low < high) {
        //pi is the partition index, arr[pi] is already in the correct place
        int pi = partition(arr, low, high, ascending);

        //sort the elements recursively before and after the partition
        QuickSort(arr, low, pi - 1, ascending);
        QuickSort(arr, pi + 1, high, ascending);
    }
}

//vector segmenting with a "pivote"
int partition(vector<int> &arr, int low, int high, bool ascending) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (ascending) {
            // Ascending
            if (arr[j] < pivot) {
                i++; 
                swap(arr[i], arr[j]);
            }
        } else {
            // Descending
            if (arr[j] > pivot) {
                i++; 
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//compare the two methods
void CompareTimes(double timeBubble, double timeQuick) {
    cout << "================ SORTING TIME COMPARISON =====================" << endl;
    cout << "Bubble Sort Method: " << timeBubble << " ms" << endl;
    cout << "QuickSort Method:   " << timeQuick << " ms" << endl;
    cout << "==============================================================" << endl;

    if (timeQuick < timeBubble) {
        cout << endl << "QuickSort was " << (timeBubble / timeQuick) << " times more faster than Bubble Sort." << endl;
    } else if (timeBubble < timeQuick) {
        cout << endl << "Bubble Sort was the fastest." << endl;
    } else {
        cout << endl << "Both methods had the same execution time." << endl;
    }
}