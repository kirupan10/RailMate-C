/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char T_username[255];
void Bugs();
void NewBugs();
void BugsView();

int main()
{
    Bugs();
    return 0;
}

void Bugs()
{
    int BugsOption;

    printf("\n");
    printf("\t\t\t----------------------[ # ] Bugs reports  ---------------------------\n");
    printf("\t\t\t-------------------- Hello [ %s ] -----------------\n\n", T_username);
    printf("\t\t\t-------------------[ 1 ] Report Bugs ---------------------------\n");
    printf("\t\t\t-------------------[ 2 ] View Bugs-----------------------------------\n");
    printf("\t\t\t-------------------[ 3 ] Main menu ------------------------------\n");
    printf("\t\t\t-------------------[ 4 ] Exit -----------------------------------\n\n");

    printf("\t\t\tFeature Option: ");
    scanf("%d", &BugsOption);

    switch (BugsOption)
    {
    case 1:
        NewBugs();
        break;
    case 2:
        BugsView();
        break;
    case 3:
        // Features_Services();
        break;
    case 4:
        exit(0);
        break;

    default:
        break;
    }
}

void NewBugs()
{
    char content[3000], c;
    int index = 0;

    char heading[3000], c1;
    int index1 = 0;

    char mailaddress[3000], c2;
    int index2 = 0;

    int no = 1;

    // Time
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));

    char *filename = "bugs.txt";
    FILE *BugsFile = fopen(filename, "a");

    if (BugsFile == NULL)
    {
        printf("Error: could not open file %s", filename);
        exit(0);
    }
    else
    {
        printf("Enter Mail Address( press ';' to end input)\n");
        while ((c2 = getchar()) != ';')
        {
            mailaddress[index2++] = c2;
        }
        mailaddress[index2] = '\0';

        printf("Enter the heading( press ';' to end input)\n");
        while ((c1 = getchar()) != ';')
        {
            heading[index1++] = c1;
        }
        heading[index1] = '\0';

        printf("Enter the content( press ';' to end input)\n");
        while ((c = getchar()) != ';')
        {
            content[index++] = c;
        }
        content[index] = '\0';

        fprintf(BugsFile, "Mail support no. %d \n\tRequesting person name: %s \nMail address: %s \nHeading: %s \nContent: %s \n\tTime: %s", no, T_username, mailaddress, heading, content, asctime(timeinfo));
        fprintf(BugsFile, "---------------------------------------------------------------\n\n\n");

        fclose(BugsFile);

        char yesorno[20];
        printf("Do you want to continue...? [Type 'yes' or 'no']");
        scanf("%s", yesorno);
        int value, value1;
        value = strcmp(yesorno, "yes");
        value1 = strcmp(yesorno, "no");
        if (value == 0)
        {
            // Features_Services();
        }
        else if (value1 == 0)
        {
            printf("System exits\n");
            exit(0);
        }
        else
        {
            printf("Wrong input...\n System goes to mainmenu page...\n");
            // Features_Services();
        }
    }
}

void BugsView()
{
    char *filename = "bugs.txt";
    FILE *ViewBugFile = fopen(filename, "r");

    if (ViewBugFile == NULL)
    {
        printf("Error: could not open file %s", filename);
        exit(0);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(ViewBugFile)) != EOF)
        putchar(ch);

    char *x[] = {"ab", "bc", "cd"};
    char *s = "kirupan";
    int len = sizeof(x) / sizeof(x[0]);
    int i;

    for (i = 0; i < len; ++i)
    {
        if (!strcmp(x[i], s))
        {
            // Do your stuff
        }
    }
    // close the file
    fclose(ViewBugFile);

    char yesorno[20];
    printf("Do you want to continue...? [Type 'yes' or 'no']");
    scanf("%s", yesorno);
    int value, value1;
    value = strcmp(yesorno, "yes");
    value1 = strcmp(yesorno, "no");
    if (value == 0)
    {
        printf("Wrong input...\n System goes to mainmenu page...\n");
        // Features_Services();
    }
    else if (value1 == 0)
    {
        printf("System exits\n");
        exit(0);
    }
    else
    {
        printf("Wrong input...\n System goes to mainmenu page...\n");
        // Features_Services();
    }
}