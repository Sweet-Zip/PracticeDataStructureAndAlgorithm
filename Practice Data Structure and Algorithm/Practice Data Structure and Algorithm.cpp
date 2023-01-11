#include <iostream>
#include <vector>
using namespace std;

void FindEvenAndODD() {
    int N;
    cout << "Enter Number: "; cin >> N;
    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            cout << i << " is even number.\n";
        }
        else {
            cout << i << " is odd number.\n";
        }
    }
}

void CalculateTax() {
    double hourWork[4], rate, overTime, weeklyPay[4], tax, monthlyPay = 0, overTimePay[4], LBP, totalHourWork = 0;
    double exchangeRate;
    cout << "Enter pay rate per hour: "; cin >> rate;
    cout << "Enter money exchange rate from Riel to Dollar: "; cin >> exchangeRate;
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Enter work hours in week" << i + 1 << " : "; cin >> hourWork[i];
        if (hourWork[i] <= 40) {
            weeklyPay[i] = rate * hourWork[i];
            cout << "Total pay in week " << i + 1 << " is " << weeklyPay[i] << endl << endl;
        }
        else {
            overTime = hourWork[i] - 40;
            overTimePay[i] = 1.5 * overTime * rate;
            weeklyPay[i] = (rate * 40) + (overTimePay[i]);
            cout << endl;
            cout << "Over Time pay in week " << i + 1 << " is " << overTimePay[i] << endl;
            cout << "Total pay in week " << i + 1 << " is " << weeklyPay[i] << endl << endl;
        }
    }
    for (int i : weeklyPay) {
        monthlyPay = monthlyPay + i;
    }
    if (monthlyPay < 1500001 / exchangeRate) {
        tax = 0;
        LBP = 0;
    }
    else if (monthlyPay > 1500001 / exchangeRate and monthlyPay < 2000001 / exchangeRate) {
        tax = 5;
        LBP = 75000 / exchangeRate;
    }
    else if (monthlyPay > 2000001 / exchangeRate and monthlyPay < 8500001 / exchangeRate) {
        tax = 10;
        LBP = 175000 / exchangeRate;
    }
    else if (monthlyPay > 8500001 / exchangeRate and monthlyPay < 12500001 / exchangeRate) {
        tax = 15;
        LBP = 600000 / exchangeRate;
    }
    else if (monthlyPay > 12500001 / exchangeRate) {
        tax = 20;
        LBP = 1225000 / exchangeRate;
    }
    cout << "Total monthly pay is " << monthlyPay << endl;
    cout << "Total tax is " << tax << endl;
    cout << "Total Salary after tax is " << monthlyPay - (((monthlyPay * tax) / 100) - LBP) << endl;
}

int main()
{
    //int age[10], count = 0;
    ////string name;
    //while (count < 10) {
    //    //cout << "Enter Your Name: "; cin >> name;
    //    cout << "Enter Your Age: "; cin >> age[count];
    //    
    //    //cout << name << " is " << age << endl;
    //    count++;
    //}
    //for (int x : age)
    //{
    //    cout << x << endl;
    //}

    //int num1;
    //double price;
    //int i = 0, j;
    //double total = 0;
    //int item;
    //cout << "Select Item: " << endl;
    //do
    //{
    //    j = i;
    //    cout << "1: Coca 2000\n";
    //    cout << "2: Oichi 2500\n";
    //    cout << "0 exit\n";
    //    cin >> num1;
    //    if (num1 == 0)
    //        break;
    //    switch (num1)
    //    {
    //    case 1:
    //        price = 2000;
    //        total = total + price;
    //    case 2:
    //        price = 2500;
    //        total = total + price;
    //    case 0:
    //        break;
    //    default:
    //        break;
    //    }
    //    //num.push_back(num1);
    //    i++;
    //} while (num1 != 0);
    //
    //
    //cout << "Sub Total = " << total << endl;
    //double discount;
    //cout << "Enter discount in %: "; cin >> discount;
    //double totaldis = total - ((total * discount) / 100);
    //cout << "Total = " << totaldis;

    int option;
    do
    {
        cout << "Choose Option\n1: Find Even and Odd Number\n2: Calculate Cambodia Tax\nSelect from 1-2 (0 to exit the program): ";
        cin >> option;
        if (option == 1) {
            FindEvenAndODD();
        } else if (option == 2) {
            CalculateTax();
        }
    } while (option != 0);
    return 0;
}

