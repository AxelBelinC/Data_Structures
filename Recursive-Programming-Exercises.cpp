/* | 08/06/2026 || 08/06/2026 |
Axel Armando Belin Castorena - 355651
Intelligent Computing Engineering 2°A - UAA
Program objective: Using a menu, implement decimal-to-binary and binary-to-decimal conversions, as well as printing the divisors of a number.
*/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void DecitoBin(double decimal);
void Integer(int num);
void FractionalPart(double fraction, int precision);
void BintoDeci(string binary);
int IntegerBin(const string& bin, size_t index, int accumulator);
double FractionBin(const string& bin, size_t index, double pow);
void Divisors(int number);
void Rdivisors(int n, int actualDivisor);

int main(){
    int op, number;
    string binary = "";
    double decimal = 0;

    do{
        cout << "=================MENU=================" << endl;
        cout << "[1]. Decimal to Binary" << endl;
        cout << "[2]. Binary to Decimal" << endl;
        cout << "[3]. Divisors of a number" << endl;
        cout << "[0]. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Enter an option: ";
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls || clear");

        switch (op){
            case 1:
                cout << "Please enter the decimal number: ";
                cin >> decimal;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Binary: ";
                DecitoBin(decimal);
            break;
            case 2:
                cout << "Please ente the binary number: ";
                cin >> binary;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                BintoDeci(binary);
                cout << endl;
            break;
            case 3:
                cout << "Please enter an integer number: ";
                cin >> number;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                Divisors(number);
                break;
            break;
            default:
                cout << "Please enter a valid option." << endl;
            break;
        }

        if (op!=0){
            cout << endl << "Press any key to continue...";
            cin.get();
        }

        system("cls || clear");

    }while(op !=0);

    return 0;
}

void Integer(int num){ //recursive function (reverse order)
    if (num > 0){
        Integer(num / 2); //recursion first
        cout << num % 2; //print after
    }
}

void FractionalPart(double fraction, int precision){ //recursive function (normal order)
    if (fraction == 0.0 || precision == 0){
        return;
    }

    double multiplication = fraction * 2.0;
    int bit = static_cast<int>(multiplication); //we obtain the 1 or the 0.

    cout << bit; //first print

    FractionalPart(multiplication - bit, precision - 1); //then recursion
}


void DecitoBin(double decimal){ //combine both parts

    int num = static_cast<int>(decimal);
    double fraction = decimal - num;

    if (num == 0){
        cout << 0;
    } else{
        Integer(num);
    }

    if (fraction > 0.0){
        cout << "."; //decimal point

        FractionalPart(fraction, 5); //precision limit (example: 5 decimals)
    }
}

int IntegerBin(const string& bin, size_t index, int accumulator){ //index declared as size_t cause the comparison with a .length()
    if (index == bin.length()){ //end of the string
        return accumulator;
    }

    accumulator = accumulator * 2 + (bin[index] - '0'); //multiply the accumulated value by 2 and add the current bit.
    return IntegerBin(bin, index + 1, accumulator);
}

double FractionBin(const string& bin, size_t index, double pow){
    if (index == bin.length()){
        return 0.0;
    }

    double value = (bin[index] - '0') * pow; //calulate the value of the current bit
    //add the current value and make the recursive call with half the current power (example: 0.5 → 0.25).
    return value + FractionBin(bin, index + 1, pow / 2.0);
}

void BintoDeci(string binary){
    string IntegerPart = "";
    string FractionPart = "";

    size_t Posicion = binary.find('.'); //search a decimal point on the string

    if (Posicion != string::npos){
        //separate the string in two parts with "substr"
        IntegerPart = binary.substr(0, Posicion);
        FractionPart = binary.substr(Posicion + 1);
    } else{
        IntegerPart = binary;
    }

    //validation for only 1s and 0s
    for (char c : IntegerPart + FractionPart) {
        if (c != '0' && c != '1') {
            cout << "Error: Invalid binary number." << endl;
            return;
        }
    }

    //calculate both values
    int IntegerValue = 0;
    if (!IntegerPart.empty()) {
        IntegerValue = IntegerBin(IntegerPart, 0, 0);
    }
    double FractionalValue = 0.0;
    if(!FractionPart.empty()){
        FractionalValue = FractionBin(FractionPart, 0, 0.5); // 0.5 = 2^-1
    }

    //merge both strings and show the result
    double Result = IntegerValue + FractionalValue;
    cout << "Decimal: " << Result << endl;
}

void Rdivisors(int n, int actualDivisor){
    if (actualDivisor > n){  //when the divisor is bigger than the number means that there's no divisors left
        return;
    }

    if (n % actualDivisor == 0){ //check if the division is exact
        cout << "[" << actualDivisor << "]" << endl;
    }

    //call to the recursive function
    Rdivisors(n,actualDivisor + 1 );
}

void Divisors(int number){
    if (number <= 0){
        cout << "Please enter a positive integer number." << endl;
        return;
    }

    cout << "Divisors of " << number << ":" << endl;

    Rdivisors(number, 1); //start the recursive function and the first divisor is 1
}