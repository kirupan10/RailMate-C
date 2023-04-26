#include <stdio.h>
#include <string.h>

void ViewUser(char userName[]);
int Loginuser();

int CreateUser(void)
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;

    // integer variable
    int value;

    // character variable
    char userName[255];
    char PassWord[255];
    char PassWordC[255];
    char NameOfUser[255];

    char AccountCreateOption = 'N';

    // Get username from user and create a new file name as user's username
    printf("Welcome to TRS-Application...!!");
    printf("\tUsername: ");
    scanf("%s", userName);

    // open the file in write mode
    inputf = fopen(userName, "w");

    if (inputf != NULL)
    {
        // printf("File created successfully!\n");
    }
    else
    {
        printf("There are no exicting user...\n");
        printf("do you want to create an account..?\n Y/N");
        scanf("%c", &AccountCreateOption);

        if (AccountCreateOption == 'Y')
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            return -1;
        }
    }

    char id[255] = "TRS_UR_001";

    // get customer detail
    printf("\tEnter name: ");
    scanf("%s", &NameOfUser);

    printf("\tEnter your password: ");
    scanf("%s", &PassWord);

    printf("\tAgain Password: ");
    scanf("%s", &PassWordC);

    value = strcmp(PassWord, PassWordC);
    if (value == 0)
    {
        fprintf(inputf, "%s %s %s %s\n", id, userName, NameOfUser, PassWord);
    }

    else
    {
        printf("\tPasswords doesn't match...\n");

        printf("\tEnter your password: ");
        scanf("%s", &PassWord);

        printf("\tAgain Password: ");
        scanf("%s", &PassWordC);
        value = strcmp(PassWord, PassWordC);
        if (value == 0)
        {
            fprintf(inputf, "%s %s %s %s\n", id, userName, NameOfUser, PassWord);
        }
        else
        {
            printf("Passwords doesn't match...\n");
            printf("Try again later...\n");
            return -1;
        }
    }

    // close connection
    fclose(inputf);

    ViewUser(userName);
    return 0;
}

void ViewUser(char userName[])
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;
    // reading section

    char r_username[255];
    char r_Name[255];
    char r_Password[255];
    char r_userID[255];

    // open file for reading
    inputf = fopen(userName, "r");

    // display detail
    printf("\nCustomer Details:\n");
    fscanf(inputf, "%s %s %s %[^\n]s", r_userID, &r_username, &r_Name, &r_Password);
    printf("\tUserID: %s\n", r_userID);
    printf("\tUsername: %s\n", r_username);
    printf("\tName: %s\n", r_Name);
    printf("\tPassword: %s\n", r_Password);

    printf("\nEnd of file.\n");

    // close connection
    fclose(inputf);
}

int main()
{
    // creating a FILE variable
    /// FILE *inputf;
    FILE *inputf;

    char l_username[255];
    char l_name[255];
    char l_userID[255];
    char l_Password[255];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;

    printf("Enter your username: ");
    scanf("%s", &l_username);

    inputf = fopen(l_username, "r");

    if (inputf != NULL)
    {
        // display detail
        printf("\nCustomer Details:\n");
        fscanf(inputf, "%s %s %s %[^\n]s", l_userID, &l_username, &l_name, &l_Password);
        // printf("\tUserID: %s\n", r_userID);
        // printf("\tUsername: %s\n", r_username);
        printf("\t Hello %s\n", l_name);
        // printf("\tPassword: %s\n", l_Password);

        printf("Enter your password: ");
        scanf("%s", &PassWordFromUser);

        value = strcmp(l_Password, PassWordFromUser);
        if (value == 0)
        {
            printf("You have successfully loggedin");
        }
        else
        {
            printf("your password is wrong...\n");
            printf("try again...\n");

            printf("Enter your password: ");
            scanf("%s", &PassWordFromUser);

            value = strcmp(l_Password, PassWordFromUser);
            if (value == 0)
            {
                printf("You have successfully loggedin");
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        printf("There are no exicting user...\n");
        printf("do you want to create an account..? [ Y / N ] : ");
        scanf("%s", &AccountCreateOption);

        if (AccountCreateOption == 'Y')
        {
            CreateUser();
        }
        else
        {
            // exit status for OS that an error occured
            printf("Terminating....\n");
            return -1;
        }
    }
}
