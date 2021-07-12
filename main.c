#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void f1 (void);
void f2 (void);
void f3 (void);
void f4 (void);
void f5 (void);
void f6 (void);
void f7 (void);
void f8 (void);
void f9 (void);
void f10 (void);
void f11 (void);
void f12 (void);


void mainmenu();

void read_books_file(void);
void read_members_file(void);
void read_borrows_file(void);

void write_books_file(void);
void write_members_file(void);
void write_borrows_file(void);

int search_books_isbn(void);
int search_books_title(void);
int search_books_author(void);
int search_books_category(void);


typedef struct
{
    char isbn[20];
    char title[50];
    char author[50];
    char category[50];
    int copies;
} Book;

typedef struct
{
    int id;
    char name[50];
    int no;
    char st[50];
    char city [50];
    char phone[50];

} Members;

typedef struct
{
    int day,month,year;
} date;

typedef struct
{
    char isbn[20];
    int id;
    date issus,due,ret;
} Borrow;


Book B[100];
Members M[100];
Borrow Bor[100];

int nB,nM,nBor;


int main()
{

    read_books_file();

    read_members_file();
    read_borrows_file();

    mainmenu();


    return 0;
}


void mainmenu()
{
    int choice,SEARCH_FLAG=1;

    while(SEARCH_FLAG)
    {


        system("cls");

        printf("\n\n********** Menu ***********\n\n");
        printf("1.Add books\n");
        printf("2.Search for a book\n");
        printf("3.Edit no of copies\n");
        printf("4.Delete book\n");
        printf("5.New member\n");
        printf("6.Borrowbook\n");
        printf("7.Return book\n");
        printf("8.remove member\n");
        printf("9.admin\n");
        printf("10.admin1\n");
        printf("11.Exit without saving\n");
        printf("12.Saving\n");

        printf("-------------------------------------\n\n");

        time_t currentTime;
        time(&currentTime);
        printf("%s\n",ctime(&currentTime));
        struct tm *myTime=localtime(&currentTime);

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)

        {
        case 1:
            f1();
            break;
        case 2:
            f2();
            break;
        case 3:
            f3();
            break;
        case 4:
            f4();
            break;
        case 5:
            f5();
            break;
        case 6:
            f6();
            break ;
        case 7 :
            f7();
            break ;
        case 8:
            f8();
            break;

        case 11:
        {

            f11();

            break;
        }
        case 12:

            f12();
            break;
        default:

            mainmenu();

        }
    }

}



void f1(void)
{

    system("cls");
    printf("\n************ Add book **************\n");

    getchar();

    printf("Enter the book isbn: ");
    gets(B[nB].isbn);


    printf("Enter the book title: ");
    gets(B[nB].title);

    fflush(stdin);


    printf("Enter the book author: ");
    gets(B[nB].author);

    printf("Enter the book category: ");
    gets(B[nB].category);

    printf("Enter the book copies: ");
    scanf("%d",&B[nB].copies);

    nB++;

}






void f2(void)
{


    char a,b,c,d;
    int choice;



    system("Cls");

    printf("\n********** Search menu ***********\n");
    printf("1. by isbn\n");
    printf("2. by title\n");
    printf("3.  by author\n");
    printf("4.by category\n");
    printf("5. back to main\n");

    printf("-------------------------------------\n\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {

    case 1:
        // by isbn
        a= search_books_isbn();

        break;

    case 2:
        // by title
        b=  search_books_title();

        break;

    case 3:
        // by author
        c= search_books_author();


        break;
    case 4:
        d=  search_books_category();
        break;

    case 5:
        // back


        getchar();
        break;



        printf("press a");
        getchar();
    }
}

int search_books_isbn()
{
    char key[50];
    int i,location=-1,x;

    fflush(stdin);
    printf("Enter the book isbn: ");
    gets(key);

    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].isbn);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("isbn is not found\n");
    else
        printf(" %s %s %s %s %d\n",B[location].isbn,B[location].title,B[location].author,B[location].category,B[location].copies);

    printf("Enter to back\n");
    getchar();
}
/*void f6(void)

{      system("cls");
printf("*&*&*&*&*&*&*&borrowbooks&*&*&*&*&*&*&\n");
time_t tm tm= *localtime(&t);
printf("enter id ");
fflush(stdin);
scanf("%d",&bor[nbpr].id);
for(i=0;i<nm,i++)
{
    if(M[i].id==bor[nbor].id&&M[mcount]<=3)
    {
        flag=1;
        break ;
    }
    if(flag==0)
    {
        printf("member cant borrow : ! ");
        fflush(stdin)
       getchar();
       mainmenu();

    }
    else
    printf("borrower %s enter isbn of book :",M[i].name)
    fflush(stdin)
    scanf{"%s",br[n3].isbn};
    for(j=0;j<(n1);j++)
    {
        if(strcmp(books[j].isbn,br[n3].isbn)==0)
            flag=1
            break;
    }
    else
    br[n3].dbrrow.day=tm.tm_mday ;
        br[n3].dbrrow.month=(tm.tm_mon+1);;
           br[n3].dbrrow.year=(tm.tm_year+1900);
           printf("the borrowing date ");
           printf("%d/%d%/%d",br[n3].dbrrow.day, br[n3].dbrrow.month, br[n3].dbrrow.year)
            do scanf("%d\%d%d",br[n3].dduereturn.year<br[n3].dduereturn.month}
            while[br[n3].dduereturn.year<br[n3].dreturn.day,&br[n3].dreturn.month,&br[n3].dreturn.year]
            printf("done")
                     n3++
                     m[i].mboount++
                     books[j].copies--;
                     book[j].bcount++;






}*/


int search_books_title()
{
    char key[50];
    int i,location=-1,x;

    fflush(stdin);
    printf("Enter the book title: ");
    gets(key);
    // search for the book by title
    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].title);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("title is not found\n");
    else
        printf(" %s %s %s %s %d\n",B[location].isbn,B[location].title,B[location].author,B[location].category,B[location].copies);

    printf("Enter to back\n");
    getchar();

}

int search_books_author()
{
    char key[50];
    int i,location=-1,x;

    fflush(stdin);
    printf("Enter the book author: ");
    gets(key);
    // search for the book by title
    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].author);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("author is not found\n");
    else
        printf(" %s %s %s %s %d\n",B[location].isbn,B[location].title,B[location].author,B[location].category,B[location].copies);

    printf("Enter to back\n");
    getchar();
}

int search_books_category()
{
    char key[50];
    int i,location=-1,x;

    fflush(stdin);
    printf("Enter the book category: ");
    gets(key);
    // search for the book by title
    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].category);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("category is not found\n");
    else
        printf(" %s %s %s %s %d\n",B[location].isbn,B[location].title,B[location].author,B[location].category,B[location].copies);

    printf("Enter to back\n");
    getchar();
}



void f3 (void)
{
    char key[50];
    int i,location=-1,x,nc=0;

    system("cls");
    printf("\n************ Add a new copies **************\n");
    getchar();

    printf("Enter the book isbn: ");
    gets(key);
    // search for the book by title
    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].isbn);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("isbn is not found\n");
    else
    {
        printf("Enter no of copies: ");
        scanf("%d",&nc);
        //check if not negative
        if(nc>0);
        B[location].copies+=nc;

    }

}

void f4(void)   // delete
{
    char key[50];
    int i,location=-1,x;

    system("cls");
    printf("\n************ Delete Book **************\n");
    getchar();

    printf("Enter the book isbn: ");
    gets(key);
    // search for the book by title
    for(i=0; i<=nB; i++)
    {
        x= strcmp(key,B[i].isbn);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("isbn is not found\n");
    else      //  copy the last in location
    {
        strcpy(B[location].isbn,B[nB-1].isbn);
        strcpy(B[location].title,B[nB-1].title);
        strcpy(B[location].author,B[nB-1].author);
        strcpy(B[location].category,B[nB-1].category);
        B[location].copies=B[nB-1].copies;

    }

    nB--;


}

void f5(void)
{
    //new member
    system("cls");
    printf("\n************ Add a new member **************\n");

    getchar();

    printf("Enter the member id: ");
    scanf("%d",&M[nM].id);
    getchar();

    printf("Enter the member name: ");
    gets(M[nM].name);

    printf("Enter the member no: ");
    scanf("%d",&M[nM].no);
    fflush(stdin);

    printf("Enter the member street: ");
    gets(M[nM].st);

    printf("Enter the member city: ");
    gets(M[nM].city);

    printf("Enter the member phone: ");
    gets(M[nM].phone);

    nM++;

}

void f8(void)
{
    char key[50];
    int i,location=-1,x;

    system("cls");
    printf("\n************ Remove member **************\n");
    getchar();

    printf("Enter the member name: ");
    gets(key);

    for(i=0; i<=nM; i++)
    {
        x= strcmp(key,M[i].name);


        if(x == 0)
        {
            location = i;
            break;
        }
    }

    if (location==-1)
        printf("name is not found\n");
    else      //  copy the last in location
    {
        M[location].id=M[nM-1].id;
        strcpy(M[location].name,M[nM-1].name);
        M[location].no=M[nM-1].no;
        strcpy(M[location].st,M[nM-1].st);
        strcpy(M[location].city,M[nM-1].city);
        strcpy(M[location].city,M[nM-1].phone);


    }

    nM--;


}

void write_books_file(void)
{
    system("cls");
    FILE *fp;
    int i;
    fp = fopen("Books.txt","wt");
    if  (fp==NULL)
    {
        printf("Error in opening Books.txt\n");
        exit(1);
    }
    fprintf(fp,"%d\n",nB);
    for(i=0; i<nB; i++)
    {
        fprintf(fp,"%s %s %s %s %d\n",B[i].isbn,B[i].title,B[i].author,B[i].category,B[i].copies);
    }
    fclose(fp);
}


void write_borrows_file(void)
{
    FILE *fp;
    int i;
    fp = fopen("Borrows.txt","wt");
    if  (fp==NULL)
    {
        printf("Error in opening Borrows.txt\n");
        exit(1);
    }
    fprintf(fp,"%d\n",nBor);
    for(i=0; i<nBor; i++)
    {
        fprintf(fp,"%s %d\n",Bor[i].isbn,Bor[i].id);
    }
    fclose(fp);
}

void write_members_file(void)
{
    FILE *fp;
    int i;
    fp = fopen("Members.txt","wt");
    if  (fp==NULL)
    {
        printf("Error in opening Members.txt\n");
        exit(1);
    }
    fprintf(fp,"%d\n",nM);
    for(i=0; i<nM; i++)
    {
        fprintf(fp,"%d %s %d %s %s %s\n",M[i].id,M[i].name,M[i].no,M[i].st,M[i].city,M[i].phone);
    }
    fclose(fp);
}

void read_books_file(void)
{
    FILE *fp;
    int i;
    fp = fopen("Books.txt","rt");
    if  (fp==NULL)
    {
        printf("Error in opening Books.txt\n");
        exit(1);
    }

    fscanf(fp,"%d",&nB);
    for(i=0; i<nB; i++)
    {
        fscanf(fp,"%s %s %s %s %d\n",B[i].isbn,B[i].title,B[i].author,B[i].category,&B[i].copies);
    }
    fclose(fp);
}
void read_members_file(void)
{

    FILE *fp;
    int i;
    fp = fopen("Members.txt","rt");
    if  (fp==NULL)
    {
        printf("Error in opening Members.txt\n");
        exit(1);
    }
    fscanf(fp,"%d",&nM);
    for(i=0; i<nM; i++)
    {
        fscanf(fp,"%d %s %d %s %s %s\n",&M[i].id,M[i].name,&M[i].no,M[i].st,M[i].city,M[i].phone);
    }

    fclose(fp);

}


void read_borrows_file(void)
{
    FILE *fp;
    int i;
    fp = fopen("Borrows.txt","rt");
    if  (fp==NULL)
    {
        printf("Error in opening Borrows.txt\n");
        exit(1);
    }
    fprintf(fp,"%d\n",nBor);
    for(i=0; i<nBor; i++)
    {
        fscanf(fp,"%s %d\n",Bor[i].isbn,&Bor[i].id);
    }
    fclose(fp);

}

void f11(void)
{
    system("cls");
    exit(0);
}

void f12(void)   // saving
{
    system("cls");

    write_books_file();
    write_members_file();
    write_borrows_file();

    printf("save done.");
    getch();

    exit(0);

}
void f6(void)


{
    time_t t = time(NULL);   //Some variables for time XD
    struct tm tm = *localtime(&t);
    int i,j,flagbook=0,flagmember=0;
    char y,temp[20];
    int tempid;

    printf("Enter User ID and ISBN of book \n");
    printf("Book ISBN : ");
    fflush(stdin);
    scanf("%s",temp);    //Scanning Book ISBN
    printf("User ID   : ");
    fflush(stdin);
    scanf("%d",&tempid);  //Scanning User id
    for(i=0; i<nB; i++)
    {
        if(strcmp(B[i].isbn,temp)==0)
        {
            flagbook=1;
            break;
        }
    }  //Searching book
    for(j=0; j<nM; j++)
    {
        if (M[j].id==tempid)
        {
            flagmember=1;
            break;
        }
    }  //Searching user id
    if(flagbook==1) //book found
    {
        if(flagmember==1) //id found
        {
            if(nBor<3) //if member borrowed more than 3 books
            {
                if(B[i].copies>0)   // if there are no available copies
                {
                    printf("Date Borrowed : %d/%d/%d\n",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900); //Date right now
                    printf("Write *num:1*  : ");
                    fflush(stdin);
                    scanf("%c",&y);
                    if(y=='1')
                    {
                        //B[b].date_borrowed.day=tm.tm_mday;
                        //B[b].date_borrowed.month=tm.tm_mon+1;
                        //B[b].date_borrowed.year=tm.tm_year+1900;
                        printf("you should return it  at :%d/%d/%d",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1901 );
                        //B[b].date_returened.day=0;
                        //B[b].date_returened.month=0;
                        // B[b].date_returened.year=0;
                        strcpy(Bor[nBor].isbn,B[i].isbn);
                        Bor[nBor].id =M[j].id ;
                        B[i].copies--;
                        nBor++;
                    }
                    else printf("\nReturning to main menu\n");
                }
                else printf("\nThere are no available copies right now\n");
            }
            else printf("\nUser has already the maximum Number of borrowings\n");
        }
        else printf("\nUser ID was not found\n");
    }
    else printf("\nBook ISBN was not found\n");
    printf("\nPress any key to Continue\n");
    fflush(stdin);
    getchar();
}

void f7(void)
{
    time_t t = time(NULL);   //Some variables for time XD
    struct tm tm = *localtime(&t);
    int i,j,flagbook=0,flagmember=0;
    char temp[20];
    int tempid;
        char key[20];
    int k,location=-1,x;
    printf("please inter isbn  you would return it and your id  : \n");
    printf("Book ISBN : ");
    fflush(stdin);
    gets(temp)  ;  //Scanning Book ISBN
    printf("User ID   : ");
    fflush(stdin);
    scanf("%d",&tempid);  //Scanning User id
    for(i=0; i<nBor; i++)
    {
        if(strcmp(Bor[i].isbn,temp)==0)
        {
            flagbook=1;
            break;
        }
    }  //Searching book
    for(j=0; j<nBor; j++)
    {
        if (Bor[j].id==tempid)
        {

            flagmember=1;
            break;
        }
    }  //Searching user id
    if(flagbook==1) //book found
    {
        if(flagmember==1) //id found
        {strcpy(key,Bor[i].isbn);
            for(k=0; k<=nB; k++)
    {
        x= strcmp(key,B[k].isbn);


        if(x == 0)
        {
            location = k;
             B[k].copies++;
             nBor--;
            break;

        }
    }



        }
        else printf("\nUser ID was not found\n");
    }
    else printf("\nBook ISBN was not found\n");
    printf("\nPress any key to Continue\n");
    fflush(stdin);
    getchar();
}







