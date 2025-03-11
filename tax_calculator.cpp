#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    const int MAX_AGI = 120000;
    const int SINGLE = 12000;
    const int MARRIED = 24000;
    // Declare the variables
    int wages, taxable_interest, unemployment_compensation, status, tax_withheld;

    // Take inputs
    cin >> wages >> taxable_interest >> unemployment_compensation >> status >> tax_withheld;
    int AGI = wages + taxable_interest + unemployment_compensation;
    cout << "AGI: $" << AGI << endl;

    if (AGI > MAX_AGI)
    {
        cout << "Error: Income too high to use this form" << endl;
        return 0;
    }

    int deduction = 0;
    // Deduction based on filing status
    if (status == 1)
    {
        deduction = SINGLE; // Single
    }
    else if (status == 2)
    {
        deduction = MARRIED; // Married
    }
    else
    {
        status = 1;
        deduction = SINGLE; // Default to single if input is invalid
    }

    int taxable_income = AGI - deduction;
    if (taxable_income < 0)
    {
        taxable_income = 0;
    }

    cout << "Deduction: $" << deduction << endl;
    cout << "Taxable income: $" << taxable_income << endl;

    // Define tax variables based on taxable income and filing status
    double federal_tax = 0.0;

    if (status == 1) // Single filer
    {
        if (taxable_income <= 10000)
        {
            federal_tax = taxable_income * 0.10;
        }
        else if (taxable_income > 10000 && taxable_income <= 40000)
        {
            federal_tax = 1000 + (taxable_income - 10000) * 0.12;
        }
        else if (taxable_income > 40000 && taxable_income <= 85000)
        {
            federal_tax = 4600 + (taxable_income - 40000) * 0.22;
        }
        else
        {
            federal_tax = 14500 + (taxable_income - 85000) * 0.24;
        }
    }
    else if (status == 2) // Married filer
    {
        if (taxable_income <= 20000)
        {
            federal_tax = taxable_income * 0.10;
        }
        else if (taxable_income > 20000 && taxable_income <= 80000)
        {
            federal_tax = 2000 + (taxable_income - 20000) * 0.12;
        }
        else
        {
            federal_tax = 9200 + (taxable_income - 80000) * 0.22;
        }
    }

    // Round the federal tax to the nearest whole number
    federal_tax = round(federal_tax);

    // Output Federal tax with correct format
    cout << "Federal tax: $" << federal_tax << endl;


    // Tax refund 
    double tax_due_or_refund = federal_tax - tax_withheld;
    if (tax_due_or_refund < 0) // Refund if tax withheld is more than tax owed
    {
        cout << "Tax refund: $" << -tax_due_or_refund << endl;  // Refund is positive value
    }
    else // Amount due if tax withheld is less than tax owed
    {
        cout << "Taxes Owed: $" << tax_due_or_refund << endl;  // Tax due is positive value
    }

    return 0;
}
