#include <stdio.h>
#include <stdlib.h>
#include <G:\ITI materials\intro_programming\MyLibrary.h>
#define NormalPen 0X07
#define HighlightedPen 0X70

///2. Employee with Dynamic Allocation and Highlight Menu (allow the user to specify the size of array at runtime).
///------------------------------------------------------------------------------------

struct Employee {
    int id;
    char name[20];
    int salary;
    int bonus;
    int deduction;
};

struct Employee AddNewEmployee(char name[20],int id,int salary,int bonus,int deduction){
    struct Employee e;
    strcpy(e.name,name);
    e.id = id;
    e.salary = salary;
    e.bonus = bonus;
    e.deduction = deduction;
    return e;
}

void DisplayEmployee(struct Employee e,int i){
    printf("\nEmployee %d name : %s ",i+1 ,e.name);
    printf("\nEmployee %d ID : %d ",i+1 ,e.id);
    printf("\nEmployee %d net salary : %d ",i+1 , e.salary + e.bonus - e.deduction);
}


int main()
{

    int i, cur = 0, Flag = 0,n=0,len;
    char menu[6][15] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};
    char ch,c;
    printf("---------- please enter how many Employees you will enter data for them : ----------\n");
    scanf("%d",&len);
    struct Employee* e;
    e = malloc(len * sizeof(struct Employee));
    while(Flag == 0)
    {
        clrscr();
        for(i=0; i<6; i++)
        {
            gotoxy(40, 5 + i*3);
            if(cur == i)
                textattr(HighlightedPen);
            else
                textattr(NormalPen);
            printf("%s", menu[i]);
        }

        ch = getch();

        switch(ch)
        {
        case 0:         ///Extended key
        case -32:
        case 224:

            c = getch();

            switch(c)
            {
                case 72: ///UP
                    cur--;
                    if(cur < 0)
                        cur=5;
                    textattr(NormalPen);
                    printf("");
                    break;

                case 80: ///Down
                    cur++;
                    if(cur > 5)
                        cur=0;
                    textattr(NormalPen);
                    printf("");
                    break;

                case 71: ///Home
                    cur = 0;
                    break;
                case 79: ///End
                    cur = 2;
                    break;

            }

        break; ///break of Extended keys case

        case 9:  ///Tab
            cur++;
            if(cur > 2)
                cur=0;
            break;

        case 13: ///Enter
            if(cur == 0)
            {

                int len,id,salary,bonus,deduction;
                char name[20];
                clrscr();
                gotoxy(40, 5);
                printf("\n ...... New ......");
                printf("\n---------- please enter Employee data : ----------\n");
                printf("\nEmployee %d name : ",n+1);
                scanf("%s",name);
                printf("\nEmployee %d ID :",n+1);
                scanf("%d",&id);
                printf("\nEmployee %d salary : ",n+1);
                scanf("%d",&salary);
                printf("\nEmployee %d bonus : ",n+1);
                scanf("%d",&bonus);
                printf("\nEmployee %d deduction : ",n+1);
                scanf("%d",&deduction);
                e[n] = AddNewEmployee(name,id,salary,bonus,deduction);
                n++;
                printf("\n Enter any character to view a menu again : ");
                ch = getche();
            }
            else if (cur == 1)
            {
                int index;
                clrscr();
                gotoxy(40, 10);
                printf("\n ...... Display ......");
                printf("\n Enter Employee index : ");
                scanf("%d",&index);
                DisplayEmployee(e[index],index);
                printf("\n Enter any character to view a menu again : ");
                ch = getche();
            }
            else if (cur == 2)
            {
                int j;
                clrscr();
                gotoxy(40, 10);
                printf("\n ...... Display All......");
                printf("\n---------- print All Employees data : ----------");
                for(j=0;j<n;j++){
                    DisplayEmployee(e[j],j);
                }
                printf("\n Enter any character to view a menu again : ");
                ch = getche();
            }
            else if (cur == 3)
            {
                int index,j;
                clrscr();
                gotoxy(40, 10);
                printf("\n ...... Delete ......");
                printf("\n Enter Employee index : ");
                scanf("%d",&index);
                for (j = index; j <= n ; j++)
                {
                e[j] = e[j + 1];
               }
                n--;
                printf("\n Enter any character to view a menu again : ");
                ch = getche();
            }
            else if (cur == 4)
            {
                clrscr();
                gotoxy(40, 10);
                printf("\n ...... Delete All ......");
                n=0;
                printf("\n Enter any character to view a menu again : ");
                ch = getche();
            }
            else if (cur == 5)
            {
                clrscr();
                gotoxy(40, 10);
                textattr(NormalPen);
                printf("");
                printf("\n ...... Exit ......");
                Flag = 1;
            }
        break;

        case 27: ///Esc
            Flag = 1;
        break;

        }
    }

    return 0;
}
