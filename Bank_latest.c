#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Bank Account structure - listnode

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////      User Account    ///////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
typedef struct acc
{
    char fullname[200];
    char address[100];
    char nationalID[20];
    int age;
    long long int accID;
    char guardian[200];
    char guardNID[20];
    char status[20];
    int balance;
    char password[6];
    struct acc *Next;

} Account;
// create list
typedef struct list
{
    int size;
    Account *head;

} List;

static long long int ids = 1000000000;

// functions
void voidInit(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

void createAccount(int index, List *pl)
{

    Account *new = (Account *)malloc(sizeof(Account));
    // Account *q;

    printf("Enter Full Name: \n");
    gets(new->fullname);

    printf("Enter Address: \n");
    gets(new->address);

    char tempNID[20];

    printf("Enter National ID : \n");
    gets(tempNID);

    while (strlen(tempNID) < 14)
    {
        printf("INVALID National ID !!! \n");
        printf("Enter National ID : \n");
        gets(tempNID);
    }

    strcpy(new->nationalID, tempNID);

    printf("Enter Age: \n");
    scanf(" %d", &new->age);
    fflush(stdin);

    if (new->age < 21)
    {
        printf("You must have a guardian: \nEnter guardian fullname");
        gets(new->guardian);

        printf("Enter guardian national ID: \n");

        gets(tempNID);

        while (strlen(tempNID) < 14)
        {
            printf("INVALID National ID !!! \n");
            printf("Enter National ID : \n");
            gets(tempNID);
        }
        strcpy(new->guardNID, tempNID);
    }

    strcpy(new->status, "Active");

    printf("Enter balance: \n");
    scanf(" %d", &new->balance);
    fflush(stdin);
    fflush(stdout);

    ids += 1;
    new->accID = ids;

    printf("The account ID: %lld \n", new->accID);

    // generate password
    char tmpPass[6];
    int r;

    for (int i = 0; i < 6; i++)
    {
        r = rand() % 10;
        tmpPass[i] = r + '0';
    }

    strcpy(new->password, tmpPass);

    printf("The password for account is: %s \n", new->password);

    new->Next = NULL;

    if (pl->head == NULL)
    {
        new->Next = pl->head;
        pl->head = new;
    }
    else
    {
        Account *q;

        q = pl->head;

        while (q->Next != NULL)
        {
            q = q->Next;
        }

        q->Next = new;
    }
    pl->size++;
}

// Search Function
Account *searchAccount(List *pl, long long int sid)
{
    Account *tmp = pl->head;

    while (tmp != NULL)
    {
        if (tmp->accID == sid)
        {
            return tmp;
        }

        tmp = tmp->Next;
    }

    printf("Account Not Found\n");
    return NULL;
}

void changeStatus(List *pl, long long int id)
{
    Account *a = searchAccount(pl, id);
    int num;
    bool op = true;
    int yn;

    while (op)
    {
        printf("Enter the status for the account:\n");
        printf("1 - Active:\n");
        printf("2 - Restricted:\n");
        printf("3 - Closed:\n");
        scanf("%d", &num);
        fflush(stdin);
        fflush(stdout);

        if (num == 1)
        {
            strcpy(a->status, "Active");
        }
        else if (num == 2)
        {
            strcpy(a->status, "Restricted");
        }
        else if (num == 3)
        {
            strcpy(a->status, "Closed");
        }
        else
        {
            printf("WRONG CHOICE\n");
        }

        printf("\nDo you want to try again?\n");
        printf("1 - YES?\n");
        printf("2 - NO\n");

        scanf("%d", &yn);
        fflush(stdin);
        fflush(stdout);

        if (yn == 2)
        {
            op = false;
        }
    }
}

void getCash(List *pl, long long int id)
{
    Account *a = searchAccount(pl, id);
    int amt;
    int yn;
    bool op = true;

    printf("enter the cash amount you want:\n");
    scanf("%d", &amt);
    fflush(stdin);
    fflush(stdout);

    while (op)
    {
        if (amt <= a->balance)
        {
            a->balance -= amt;
            printf("\nAfter withdraw %d:\n", a->balance);
        }
        else
        {
            printf("the amount entered is more than balance....\n");
        }

        printf("\nDo you want to try again?\n");
        printf("1 - YES?\n");
        printf("2 - NO\n");

        scanf("%d", &yn);

        if (yn == 2)
        {
            op = false;
        }
    }
}

void deposit(List *pl, long long int id)
{
    Account *a = searchAccount(pl, id);
    int amt;
    int yn;
    bool op = true;

    printf("enter the cash amount to deposit:\n");
    scanf("%d", &amt);
    fflush(stdin);
    fflush(stdout);

    while (op)
    {
        if (amt > 0)
        {
            a->balance += amt;
            printf("\nAfter Deposit %d:\n", a->balance);
        }

        printf("\nDo you want to Deposit again?\n");
        printf("1 - YES?\n");
        printf("2 - NO\n");

        scanf("%d", &yn);
        fflush(stdin);
        fflush(stdout);

        if (yn == 2)
        {
            op = false;
        }
    }
}

void makeTrans(List *pl, long long int id)
{
    Account *a = searchAccount(pl, id);
    long long int a2ID;
    int amt;
    int yn;
    bool op = true;

    printf("Enter ID of account transferred to:\n");
    scanf("%lld", &a2ID);
    fflush(stdin);
    fflush(stdout);

    Account *a2 = searchAccount(pl, a2ID);

    while (op)
    {
        printf("\nEnter the amount you want to transfer:\n");
        scanf("%d", &amt);

        if (amt <= a->balance && strcmp(a->status, "Active") == 0 && strcmp(a2->status, "Active") == 0)
        {
            printf("\nStatus1 %s:\n", a->status);
            printf("\nStatus2 %s:\n", a2->status);

            printf("\nCurrent Balance of sender %d:\n", a->balance);
            printf("\nCurrent Balance of reciever %d:\n", a2->balance);

            // operation
            a->balance -= amt;
            a2->balance += amt;

            printf("After Transaction - Balance of sender %d:\n", a->balance);
            printf("After Transaction - of reciever %d:\n", a2->balance);
        }
        else
        {
            printf("There isn't enough money or one or both of account are not Active\n");
            printf("Status of sender %s:\n", a->status);
            printf("Status of reciever %s:\n", a2->status);
        }

        printf("\nDo you want to try again?\n");
        printf("1 - YES?\n");
        printf("2 - NO\n");

        scanf("%d", &yn);
        fflush(stdin);
        fflush(stdout);

        if (yn == 2)
        {
            op = false;
        }
    }
}

void changePass(List *pl, long long int id)
{

    Account *a = searchAccount(pl, id);
    char curr[100];
    int updated[100];

    printf("Enter your current password: \n");
    gets(curr);
    fflush(stdin);
    fflush(stdout);

    if (strcmp(a->password, curr) == 0)
    {
        printf("Enter new password: \n");
        gets(a->password);
        fflush(stdin);
        fflush(stdout);
        printf("You have changed your password successfully!!: \n");
    }
}



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////      Admin Account    //////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
typedef struct AdminAcc
{
    char fullname[200];
    char address[100];
    char nationalID[20];
    int age;
    long long int accID;
    char password[6];
    struct AdminAcc *Next;
} AdminAccount;

typedef struct list2
{
    int size;
    AdminAccount *head;
} List2;


static long long int ids2 = 1000000000;


void voidInit_add(List2 *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

void createAccount_admin(int index, List2 *pl)
{
    AdminAccount *new = (AdminAccount *)malloc(sizeof(AdminAccount));
    // Account *q;

    printf("Enter Full Name: \n");
    gets(new->fullname);

    printf("Enter Address: \n");
    gets(new->address);

    char tempNID[20];

    printf("Enter National ID : \n");
    gets(tempNID);

    
    strcpy(new->nationalID, tempNID);

    printf("Enter Age: \n");
    scanf(" %d", &new->age);
    fflush(stdin);
    fflush(stdout);

    ids2 += 1;
    new->accID = ids2;

    printf("The account ID: %lld \n", new->accID);

    // generate password
    char tmpPass[6];
    int r;

    for (int i = 0; i < 6; i++)
    {
        r = rand() % 10;
        tmpPass[i] = r + '0';
    }

    strcpy(new->password, tmpPass);

    printf("The password for account is: %s \n", new->password);

    new->Next = NULL;

    if (pl->head == NULL)
    {
        new->Next = pl->head;
        pl->head = new;
    }
    else
    {
        AdminAccount *q;

        q = pl->head;

        while (q->Next != NULL)
        {
            q = q->Next;
        }

        q->Next = new;
    }
    pl->size++;
}

// Search Function
AdminAccount *searchAccount_admin(List2 *pl, long long int sid)
{
    AdminAccount *tmp = pl->head;

    while (tmp != NULL)
    {
        if (tmp->accID == sid)
        {
            return tmp;
        }

        tmp = tmp->Next;
    }

    printf("Account Not Found\n");
    return NULL;
}




int main()
{
    long long int id;
    // initialize
    List UserAccounts;
    voidInit(&UserAccounts);
    List2 AdminAccounts;
    voidInit_add(&AdminAccounts);

    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;

    bool operate_Full = true;
    bool operate_Admin = true;
    bool operate_user = true;

    while (operate_Full)
    {
        operate_Admin = true;
        operate_user = true;
        //////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////   Login Window  /////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////
        printf("\n");
        printf("Welcome to Login Window:\n");
        printf("who are You?:\n");
        printf("A-Admin\n");
        printf("B-User\n");
        printf("C-Exit\n");
        scanf("%c", &m1);
        fflush(stdin);
        fflush(stdout);

        switch (m1)
        {
        //////////////////////////////////////////////////////////////////////////////////////////
        case 'A':
            //////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////   Admin Window  /////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////
            while (operate_Admin)
            {
                // login as admin
                printf("\n");
                printf("Welcome to admin main menu:\n");
                printf("a - Login:\n");
                printf("b - Create account:\n");
                printf("c - Exit:\n");
                scanf("%c", &m7);
                fflush(stdin);
                fflush(stdout);
                if (m7 == 'a')
                {
                    printf("Enter the ID of your account:\n");
                    scanf("%d", &id);
                    fflush(stdin);
                    fflush(stdout);
                    char usrpass1[6];
                    printf("Enter your account password:\n");
                    gets(usrpass1);
                    fflush(stdin);
                    fflush(stdout);
                    AdminAccount *searched1 = searchAccount_admin(&AdminAccounts, id);

                    if (searched1 == NULL || strcmp(searched1->password, usrpass1) != 0)
                    {
                        printf("ACCOUNT DOESNT EXIST OR WRONG PASSWORD\n");
                        continue;
                    }
                }
                else if (m7 == 'b')
                {
                    createAccount_admin(AdminAccounts.size, &AdminAccounts);
                    continue;
                }
                else
                {
                    operate_user = false;
                    break;
                }
                printf("What do you want to do?:\n");
                printf("A-Create New Account\n");
                printf("B-Open Existing account\n");
                printf("C-Exit\n");
                scanf("%c", &m2);
                fflush(stdin);
                fflush(stdout);

                switch (m2)
                {
                case 'A':
                    // call create account
                    createAccount(UserAccounts.size, &UserAccounts);
                    break;
                case 'B':
                    printf("\n");
                    printf("Enter the ID of the account you want to control:\n");
                    scanf("%d", &id);
                    fflush(stdin);
                    fflush(stdout);
                    Account *searched = searchAccount(&UserAccounts, id);
                    if (searched == NULL)
                    {
                        break;
                    }
                    printf("What do you want to do?:\n");
                    printf("A-Make Transaction\n");
                    printf("B-Change account status\n");
                    printf("C-Get cash\n");
                    printf("D-Deposit in Account\n");
                    printf("E-Return to main menu\n");
                    printf("F-Exit\n");
                    scanf("%c", &m3);
                    fflush(stdin);
                    fflush(stdout);
                    switch (m3)
                    {
                    case 'A':
                        // call
                        makeTrans(&UserAccounts, id);
                        break;
                    case 'B':
                        // call
                        changeStatus(&UserAccounts, id);
                        break;
                    case 'C':
                        // call
                        getCash(&UserAccounts, id);
                        break;
                    case 'D':
                        // call
                        deposit(&UserAccounts, id);
                        break;
                    case 'E':
                        break;
                    case 'F':
                        operate_Admin = false;
                        break;
                    }
                    break;
                case 'C':
                    operate_Admin = false;
                    break;
                }
            }
        break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case 'B':
            //////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////   User Window  /////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////
            while (operate_user)
            {
                // login as user
                printf("\n");
                printf("Welcome to user menu:\n");
                printf("a - Login:\n");
                printf("b - Exit:\n");
                scanf("%c", &m6);
                fflush(stdin);
                fflush(stdout);
                if (m6 == 'a')
                {
                    printf("Enter the ID of your account:\n");
                    scanf("%d", &id);
                    fflush(stdin);
                    fflush(stdout);
                    char usrpass[6];
                    printf("Enter your account password:\n");
                    gets(usrpass);
                    fflush(stdin);
                    fflush(stdout);
                    Account *searched = searchAccount(&UserAccounts, id);

                    if (searched == NULL || strcmp(searched->password, usrpass) != 0)
                    {
                        printf("ACCOUNT DOESNT EXIST OR WRONG PASSWORD\n");
                        continue;
                    }
                }
                else
                {
                    operate_user = false;
                    continue;
                }
                
                printf("What do you want to do?:\n");

                printf("A-Make transaction\n");
                printf("B-change account password\n");
                printf("C-Get Cash\n");
                printf("D-Deposit in Account\n");
                printf("E-Return to main menu\n");
                printf("F-Exit\n");
                scanf("%c", &m4);
                fflush(stdin);
                fflush(stdout);
                switch (m4)
                {
                case 'A':
                    // call
                    makeTrans(&UserAccounts, id);
                    break;
                case 'B':
                    // call
                    changePass(&UserAccounts, id);
                    break;
                case 'C':
                    // call
                    getCash(&UserAccounts, id);
                    break;
                case 'D':
                    // call
                    deposit(&UserAccounts, id);
                    break;
                case 'E':
                    break;
                case 'F':
                    operate_user = false;
                    break;
                }
            }
            continue;
        //////////////////////////////////////////////////////////////////////////////////////////
        case 'C':
            //////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////   Exit  /////////////////////////////////////////
            //////////////////////////////////////////////////////////////////////////////////////
            operate_Full = false;
            break;
        }
    }

    return 0;
}