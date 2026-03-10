/*
  @file Exercise1_Ellis.cpp
  @author Elijah Ellis
  @date 2026-03-09
  @brief This program validates UPC-A barcodes by calculating and verifying
  the UPC-A check digit using the official algorithm. The program allows
  the user to test multiple UPC codes without restarting.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//the four functions below get the numbers for the barcode
int calcfirstnumber() {
    int firstnumber;
    cout << "Enter first number of the barcode: ";
    cin >> firstnumber;
    return firstnumber;
}

int calclastnumber() {
    int lastnumber;
    cout << "Enter last number of the barcode: ";
    cin >> lastnumber;
    return lastnumber;
}

int calcproductnumber() {
    int productnumber;
    cout << "Enter product number of the barcode: ";
    cin >> productnumber;
    return productnumber;
}

int calcmanufacturenumber() {
    int manunumber;
    cout << "Enter manufacturer number of the barcode: ";
    cin >> manunumber;
    return manunumber;
}

//checks wheather or not the barcode is valid
void printBarcode(string Num, bool isValid) {
    if (isValid == true) {
        cout << "The UPC code " << Num << " is valid." << endl;

        cin.ignore();
        cin.clear();
    }
    else {
        cout << "This UPC code is INVALID." << endl;

        cin.ignore();
        cin.clear();
    }
}
/*
    This calculates wheather if the barcode is valid or not
    It first puts the numbers in through and puts them into a string
    then it will add the sum of all the even and odd positions. 
    it will multiply the odd positions by 3 and modulo the sum of the evens by 10
    then it will add both into one total
    Finally, it will go through a couple of checks to see if the total is equal to the last number
    if so, then the barcode is valid
*/
void CalcBarCode(int first, int last, int manu, int product) {
    bool isValid = false;
    int oddtotal = 0, eventotal = 0, total, digitCheck;
    vector<int> Nums = { first, manu, product };
    string Num;

    for (int num : Nums) { 
        Num += to_string(num);
    }

    for (int i = 0; i < Num.size(); i += 2) { 
        oddtotal += (Num.at(i) - '0');
    }
    oddtotal = oddtotal * 3;

    for (int i = 1; i < Num.size(); i += 2) { 
        eventotal += (Num.at(i) - '0');
    }

    total = oddtotal + eventotal;
    total = total % 10;

    if (total > 0) {
        digitCheck = 10 - total;
    }
    if (total == 0) {
        digitCheck = 0;
    }

    if (digitCheck == last) { 
        isValid = true;
    }

    Num += to_string(last); 

    printBarcode(Num, isValid);
}

/*
    Gets the values for the barcode
    can repeat by typing 'y' and break by typing 'n'
*/

void getBarcode() {
    char again;
    int first, last, manu, product;

    cout << "Do you have a UPC-number to test? (y/n): ";
    cin >> again;

    while (again != 'n') {
        if (std::tolower(again) == 'y') {
            int first = calcfirstnumber();

            int last = calclastnumber();

            int manu = calcmanufacturenumber();

            int product = calcproductnumber();

            CalcBarCode(first, last, manu, product);
        }
        else if (std::tolower(again) == 'n') {
            cout << "Understood!" << endl;
        }
        else {
            std::cout << "Invalid input. Please enter 'y' (\"yes\") or 'n' (\"no\") to proceed." << std::endl << std::endl;
            std::cin.ignore();
            std::cin.clear();
        }
        }
}


//gets the getBarcode function.
int main() {
    getBarcode();

    cout << "Thank you for your input" << endl;
}