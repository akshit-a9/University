/*Consider a simple customer billing system. In this system the customer records will be stored 
within an array of structures. Each record will be stored as an individual structure (array 
element) containing the following details:
customer name, street, city, contact details, account number, account type, old balance, current 
payment, new balance, and payment date.
The payment date is a structure with following members: month, day, and year in mm/dd/yyyy 
format.
The overall strategy is to enter customer record into the computer, updating it as soon as it is 
entered to reflect current payments. All the updated records will then be displayed , along with 
the current status of each account. 
The account status will depend on the following details:
a) If the current payment is greater than zero but less than 10 % of the old_balance 
balance, the account will be OVERDUE.
b) If the current payment is equal to zero and old_balance balance is greater than zero, the 
account will be DELINQUENT.
c) Otherwise, the account will be CURRENT ACCOUNT.
Write a C program for the customer billing system*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct payment_date
{
    int month;
    int day;
    int year;
}p;

struct customer
{
    char customer_name[50];
    char street[50];
    char city[15];
    int contact_details;
    char account_number;
    float old_balance;
    float current_payment;
    float new_balance;
    char account_type[50];
}c;

int main()
{
    scanf("%s\n%s\n%s\n%d\n%s\n%f\n%f\n%d\n%d\n%d\n", &c.customer_name, &c.street, &c.city, &c.contact_details, &c.account_type, &c.old_balance, &c.current_payment, &p.month, &p.day, &p.year);
    c.new_balance = c.old_balance - c.current_payment;
    char account_type[50];

    if(c.current_payment > 0 && c.current_payment < (0.1 * c.old_balance)) c.account_type[] = "OVERDUE";
    else if(c.current_payment == 0 && c.old_balance > 0) c.account_type[] = "DELINQUENT";
         else c.account_type[] = "CURRENT ACCOUNT";
    
    printf("%s\n%s\n%s\n%d\n%s\n%s%.2f\n%0.2d\n%0.002d\n%.04d\n", c.customer_name, c.street, c.city, c.contact_details, c.accountnumber, c.account_type, c.oldbalance, c.current_payment, p.month, p.day, p.year, c.new_balance = c.old_balance - c.current_payment;
    printf("%.2f", c.new_balance);
}