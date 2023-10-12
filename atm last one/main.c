#include <stdio.h>
#include <stdlib.h>
// Function prototypes
void checkbal();
void accType();
void withdraw();
void deposit();
void first();

float read_bal, accbal, deAmount, wiAmount,readbal;
int language, AccNum, read_Accnum, pinnum, read_pin, accTypei, service, req, any;


void first ()
{
      printf("\033[1;32m"); // Set the text color to green
printf(
      "#     #  #####  ######  #    #    ######     #    #     # #    #\n"
      "##    # #     # #     # #   #     #     #   # #   ##    # #   #\n"
      "# #   # #       #     # #  #      #     #  #   #  # #   # #  #\n"
      "#  #  #  #####  #     # ###       ######  #     # #  #  # ###\n"
      "#   # #       # #     # #  #      #     # ####### #   # # #  #\n"
      "#    ## #     # #     # #   #     #     # #     # #    ## #   #\n"
      "#     #  #####  ######  #    #    ######  #     # #     # #    #\n");
printf("\033[0m"); // Reset the text color to normal

printf("\n\n\nEnter Your Account Number : ");
scanf("%d",&AccNum);
FILE*AccNumfile = fopen("ACCOUNT NUMBER.txt","r");
fscanf(AccNumfile, "%d", &read_Accnum);
fclose(AccNumfile); // Close the file after reading.
if (AccNum == read_Accnum)
    {
            printf("Enter your pin number: ");
            scanf("%d", &pinnum);
            FILE* Pinnumfile = fopen("PIN NUMBER.txt", "r");
            fscanf(Pinnumfile, "%d", &read_pin);
            fclose(Pinnumfile); // Close the file after reading.

            if (pinnum == read_pin)
            {
                accType();
            }
            else
            {
                printf("\033[91mWrong Pin number\033[0m\n");
            }
    }
    else
        {
            printf("\033[91mWrong Account number\033[0m\n");
        }




}
void accType()
{
    printf(" \e[0;33m 1 Current Account\t2 Saving Account\n \033[0m");
    scanf("%d", &accTypei);
    if (accTypei == 2)
        {
           printf(" \x1b[34m 1 Deposit\t2 Withdraw\t3 Check your balance\n \033[0m");

           scanf("%d", &service);
           switch (service)
           {
               case 1:
                  deposit();
                  break;
               case 2:
                  withdraw();
                  break;
               case 3:
                  Checkbal();
                  break;
               default:
                 printf("Wrong number\n");
          }
       }
    else if (accTypei == 1)
        {
          printf("\033[91mYou don't have Current Account\033[0m\n");
          printf("Do you need any service:\n1)Yes\t2)No\n");

         scanf("%d", &req);
         if (req == 1)
         {
            first();
         }
        else
            {
             printf("\033[95mThank you! Have a nice day!\n\033[0m");
            }
        }
        else
            {
               printf("Invalid account type\n");
            }
}
void deposit()
{
    FILE* balanceFile = fopen("BALANCE.txt", "r");
    fscanf(balanceFile, "%f", &read_bal);
    accbal = read_bal;
    printf("Enter the Deposit amount: ");
    scanf("%f", &deAmount);
    accbal = accbal + deAmount;
    FILE* newbal = fopen("NEW BALANCE.txt", "w");
    fprintf(newbal, "NEW ACCOUNT BALANCE = %f\n", accbal);
    fclose(newbal); // Close the file after writing.

    printf("successfully deposited Rs.%0.2f\n",deAmount);


    printf("Do you need any service:\n1)Yes\t2)No\n");
    scanf("%d", &any);
    switch (any)
     {
        case 1:
            first();
            break;
        default:
             printf("\033[95mThank you! Have a nice day!\n\033[0m");
            break;
    }
}
void withdraw()
{
    FILE* balanceFile = fopen("BALANCE.txt", "r");
    fscanf(balanceFile, "%f", &read_bal);
    accbal = read_bal;
    printf("Enter the Withdraw Amount: ");
    scanf("%f", &wiAmount);
    accbal = accbal - wiAmount;
    FILE* newbal = fopen("NEW BALANCE.txt", "w");
    fprintf(newbal, "NEW ACCOUNT BALANCE = %f\n", accbal);
    fclose(newbal); // Close the file after writing.

    printf("Successfully withdraw Rs %0.2f \n ",wiAmount);

    printf("Do you need any service:\n1)Yes\t2)No\n");
    scanf("%d",&service);

    if(service== 01 || service== 1)
    {
        first();
    }
    else
    {
        printf("\033[95mThank you! Have a nice day!\n\033[0m");
    }
}
void Checkbal()
{
    FILE *bal = fopen("BALANCE.txt","r");
    fscanf(bal,"%f",&readbal);
    accbal= readbal;
    printf("Your balance is Rs. %0.2f\n",accbal);

    printf("Do you need any service:\n1)Yes\t2)No\n");
    scanf("%d",&service);

    if(service== 01 || service== 1)
    {
        first();
    }
    else
    {
        printf("\033[95mThank you! Have a nice day!\n\033[0m");
    }
}

int main()
{
    first();

    return 0;
}
