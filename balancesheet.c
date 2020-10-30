#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double solv, per_building, per_property, per_bank_funds; 
int building, property, bank_funds, debit, percentage_b, percentage_p, percentage_cash, result; 
int equity, long_term_debt, short_term_debt, credit; 
int debit_side(int building, int property, int bank_funds);
int credit_side(int equity, int long_term_debt, int short_term_debt);
double solvency (double, double); 
void balance_result (int, int);
double percentage (int, int);  

int main ()
{

printf ("First insert all debit entries on balance sheet\n");
printf ("Balance sheet value of buildings: ");
scanf ("%d", &building);
printf ("Balance sheet value of property: ");
scanf ("%d", &property);
printf ("Balance sheet value of bank funds: ");
scanf ("%d", &bank_funds);
debit = debit_side(building, property, bank_funds);

printf("Now enter all credit entries on balance sheet\n");
printf("Total equity is: ");
scanf ("%d", &equity);
printf ("Balance sheet value of long term debt: ");
scanf ("%d", &long_term_debt);
printf ("Balance sheet value short term debt: ");
scanf ("%d", &short_term_debt);
credit = credit_side(equity, long_term_debt, short_term_debt);
solv = solvency (equity, credit);

printf ("\nTotal debit side balance sheet value is %d.             \n"   , debit);
printf ("Total credit side balance sheet value is %d.           \n", credit);
balance_result(debit, credit);
printf("Total solvency ratio for this company is %0.2lf%% \n ", solv);

printf ("\n Now calculating percentages of balance sheet items in relation to total balance sheet\n");

per_building = percentage (building, debit);
printf("Percentage of buildings in relation to balance sheet is %0.2lf\n", per_building); 

per_property = percentage (property, debit);
printf("Percentage of property in relation to balance sheet is %0.2lf\n", per_property); 

per_bank_funds = percentage (bank_funds, debit);
printf("Percentage of bank funds in relation to balance sheet is %0.2lf\n", per_bank_funds); 

printf ("\nPrinting debit side balance sheet pertcentages as follows: \n\n 1. Buildings \n 2. Property \n 3. Bank funds \n\n");


percentage_b = per_building / 10;
// printf ("%d", percentage_b); 
for (int i = percentage_b ; i > 0 ;i -- )
    {
        printf("X");
    }
printf ("\n");

percentage_p = per_property / 10;
for (int i = percentage_p ; i > 0 ;i -- )
    {
        printf("X");
    }
printf ("\n");

percentage_cash = per_bank_funds / 10;
for (int i = percentage_cash ; i > 0 ;i -- )
    {
        printf("X");
    }

printf ("\n");

}
int debit_side (int building, int property, int bank_funds)
{
int x = building + property + bank_funds;
return x;    
}

int credit_side(int equity, int long_term_debt, int short_term_debt)
{
int x = equity + long_term_debt + short_term_debt;
return x; 
}

double solvency (double equity, double credit)
{
double x = equity / credit * 100;
return x;
}

void balance_result(int debit, int credit)
{ 
if (debit == credit)
    {
    printf ("Looks like debit and credit are equal, nice job\n");
    } else {
       printf ("Looks like debit and credit are not equal, great job loser.\n");
    }
}

double percentage (int balance_sheet_item, int balance_sheet_total)
{
double x = ((double)balance_sheet_item / balance_sheet_total * 100);
return x;
} 