//Name: YI-CHENG, LIU (uniquename: liuyiche)
//Date: 19/09/2022
//Purpose: Calculation of interest regarding initial balance and duration

#include<iostream>

using namespace std;

//calculate the interest of one month according to the balance amount
bool accrueOneMonthsInterest(double &balanceAmt, 
                             const bool doPrintEachMonth);
//calculate the total interest and final balnace based on initial balance
bool accrueInterest(double &balanceAmt, 
                    const int numMonths, 
                    const int doPrintInfo);

#ifdef ANDREW_TEST  
#include "andrewTest.h"  
#else

int main() {
    double balanceAmt = 0;
    int numMonths = 0;
    string showEachMonth;
    bool doPrintInfo;
    const string PRINT_OUT = "y";
    
    cout << "Enter the initial balance of the account: ";
    cin >> balanceAmt;
    cout << "Enter the number of months to accrue interest: ";
    cin >> numMonths;
    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    cin >> showEachMonth;

    doPrintInfo = showEachMonth.compare(PRINT_OUT);

    accrueInterest(balanceAmt, 
                   numMonths, 
                   doPrintInfo);
    return 0;
}
#endif

//calculate the interest of one month according to the balance amount
bool accrueOneMonthsInterest(double &balanceAmt, 
                             const bool doPrintEachMonth){  
    double rate = 0;
    double curInterest = 0;
    const double BALANCE_INITIAL = balanceAmt;
    const double BALANCE_REQUIRE = 0.00;
    const double BALANCE_LOW = 1000.00;
    const double BALANCE_STANDARD = 15000.00;
    const double RATE_INITIAL = 1.00;
    const double RATE_LOW = 0.0015;
    const double RATE_STANDARD = 0.00225;
    const double RATE_HIGH = 0.004;
    const bool DO_PRINT = 0;

    //error occur when balance amount is under minimum requirement
    if(balanceAmt < BALANCE_REQUIRE){
        cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
             << " but the value " << balanceAmt << " was provided!" << endl;
        cout << "Sorry, an error was detected.  "
             << "Unable to provide results!" << endl;
        return false;
    }

    //calculate balance when no error occurs
    else{
        //determine the interest rate
        if(balanceAmt < BALANCE_LOW){
            rate = RATE_LOW;
        }
        else if(balanceAmt >= BALANCE_STANDARD){
            rate = RATE_HIGH;
        }
        else if(balanceAmt >= BALANCE_LOW && balanceAmt < BALANCE_STANDARD){
            rate = RATE_STANDARD;
        }

        //calculate the balance
        curInterest = balanceAmt * rate;
        balanceAmt *= (RATE_INITIAL + rate);
        
        //print out the details
        if(doPrintEachMonth == DO_PRINT){
            cout << "Accruing interest for 1 month:" << endl;
            cout << "  Initial balance: " << BALANCE_INITIAL << endl;
            cout << "  Initial rate: " << rate << endl;
            cout << "  Interest accrued: " << curInterest << endl;
            cout << "  New balance: " << balanceAmt << endl;   
        }
        //do silently
        else{
            return true;
        }
    }
    return true;
};

//calculate the total interest and final balnace based on initial balance
bool accrueInterest(double &balanceAmt, 
                    const int numMonths, 
                    const int doPrintInfo) {
    const double INITIAL_BALANCE = balanceAmt;
    const int MONTH_REQUIRE = 0;

    //error occur when number of month is under minimum requirement
    if(numMonths <= MONTH_REQUIRE){
        cout << "ERROR in accrueInterest: "
             << "numMonths must be > 0, but the value " << numMonths 
             << " was provided!" << endl;
        cout << "Sorry, an error was detected.  "
             << "Unable to provide results!" << endl;
        return false;
    }

    //check whether error occurs in accrueOneMonthsInterest()
    else if(accrueOneMonthsInterest(balanceAmt, doPrintInfo) == false){
        return false;
    }

    //calculate and print out the final statement when no error occurs
    else{
        for(int i = 1; i < numMonths; i++){
            accrueOneMonthsInterest(balanceAmt, doPrintInfo);
        }
        cout << "Interest accrued for " 
             << numMonths << " months!" << endl;
        cout << endl;
        cout << "Initial balance: " 
             << INITIAL_BALANCE << endl;
        cout << "Total interest accrued: " 
             << balanceAmt - INITIAL_BALANCE << endl;
        cout << "Final balance: " 
             << balanceAmt << endl; 
        return true; 
    }
};