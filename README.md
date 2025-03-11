    Simple Tax Calculator in C++
    
    Overview

This is a basic C++ program that calculates federal taxes based on user input. It determines the Adjusted Gross Income (AGI), applicable deductions, taxable income, and the federal tax owed or refunded.

    Features

Accepts user input for wages, taxable interest, unemployment compensation, filing status, and tax withheld.

Calculates AGI and applies standard deductions based on filing status (Single or Married).

Computes federal tax using a progressive tax bracket system.

Determines whether the user owes taxes or is eligible for a refund.

    How to Use

Compile the program using a C++ compiler.

Run the program and enter the following values when prompted:

Wages

Taxable interest

Unemployment compensation

Filing status (1 for Single, 2 for Married)

Tax withheld

The program will output the AGI, deduction amount, taxable income, calculated federal tax, and whether a refund or payment is due.

Compilation & Execution

To compile and run the program:

 g++ -o tax_calculator tax_calculator.cpp -lm
 ./tax_calculator

    Code Structure

AGI Calculation: Adds wages, taxable interest, and unemployment compensation.

Deduction Handling: Applies appropriate deductions based on filing status.

Tax Calculation: Uses tax brackets to compute federal tax owed.

Refund or Due Amount: Compares tax withheld with tax owed and determines the outcome.

    Dependencies

Standard C++ libraries (iostream, iomanip, string, cmath)
