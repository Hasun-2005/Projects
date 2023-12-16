

/*compound_interest_Hasun.cpp*/
/*My program will calculate your yearly earnings using compound interest*/
/*The plan*/
/*1.Output the decorative messages*/
/*2.define capital as a floating point number and ask the user to enter the capital*/
/*3.define rate as a floating point number and ask the user to enter their rate*/
/*4.define years as an integer and ask the user to enter the number of year they want to invest for*/
/*5.loops through all the years and calculate the total amount interest and the user portfolio at the end of the year */
/*6.outputs a message of your choice related to the program */
#include <iostream>
/*Allows input and output libraries*/
using namespace std;
/*Uses the standard library to output stuff*/
int main(){
    cout << "*** welcome to your finance buddy***" << endl;
    cout << "* This program computes your  *" << endl;
    cout << "*Yearly earnings using compound  *" << endl;
    cout << "*          rate  *" <<endl;
    cout << "**************************************" << endl;
    cout << "* Program created by   *" << endl;
    cout << "*     Hasun Sayed      *" << endl;
    cout << "**************************************";
    float capital;
    /*Capital is being defined as a floating point number*/
    cout  << "Enter your capital:" << endl;
    /*Displays a message on a screen asking the user to enter their capital*/
    cin >> capital;
    /*The user is able to enter their capital*/
    float rate;
    /*the rate is being defined a floating point number */
    cout << "Enter the (%) interest rate:";
    /*Displays a message asking the user to enter their  interest rate */
    cin >> rate;
    /*Allows the user to enter their interest rate */
    int years;
    /*The number of years they want to save is defined as an integer*/
    cout << "How many years do you want to save for?";
    /*Displays a message asking the user how much they want to save*/

    cin >> years;
    /*Asks the user to enter the number of years*/
    for ( int i = 1; i <= years ;i++){
        /*Loops all the years as i is being incremented.*/
        float interest = (rate/100) * capital ;
        /*Calculates the interest using a formula*/
        capital = capital + interest;
        /*This outputs the capital and iterates over each loop*/
        cout << "Your interest for year " << i <<" is "<<interest << "\n";
        /*Outputs the interest rate and a message*/
        cout << "Your portfolio now has a value of" <<capital << "\n";
        /*Outputs the value of the users portfolio*/
    }
    cout << "This is your final portfolio";
}