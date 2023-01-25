#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define max 10

void mang();
void new_item();
void update1();
void access();
void login();
void signup();
void add();
void display(FILE *);
void search();
void update();
void bill();

char res;
int ch,i;
FILE *fp,*fp1,*fp2;
struct product
{
    int ID;
    char pdN[10];
    char brand[10];
    char user[10];
    char pword[10];
    float cost;
}pd[max];
int main()
{
    printf("\n***************************************************\n\n\t\tWELCOME TO\t\n\tCOSMETIC PRODUCT MANAGEMENT SYSTEM\t\n\n***************************************************");
    do
    {
        printf("\n\n\tAre you-\n============================================\n1.DATA MANAGER\t\t\t2.CUSTOMER\t\n");
        printf("\nEnter your choice:\t");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            mang();
            break;

        case 2:
            access();
    
            do
            {
                printf("\n1.READ PRODUCT LIST:\n2.ADD PRODUCT:\n3.DISPLAY PRODUCT LIST\n4.SEARCH PRODUCTS:\n5.UPDATE PRODUCT LIST:\n6.TOTAL BILL:\n------------------------------------------------------------\n");
                printf("\nEnter your choice:\t");
                scanf("%d",&ch);

                switch (ch)
                {
                    case 1:
                        fp1 = fopen("prod_list.txt","r");
                        display(fp1);
                        break;
                
                    case 2:
                        add();
                        break;
                    
                    case 3:
                        fp2 = fopen("My_list.txt","r");
                        display(fp2);
                        break;

                    case 4:
                        search();
                        break;

                    case 5:
                        update();
                        break;

                    case 6:
                        bill();
                        break;
                    
                    default:
                        exit(0);
                }
                printf("\n\nwant to cont.......(y/n)----->");
                scanf(" %c",&res);
            } while (res=='y');
            break;

        default:
            exit(0);
        }

        printf("\n\nGO to Main Menu----->(y/n)");
        scanf(" %c",&res);
    }while(res == 'y');
    return 0;
}

void mang()
{   do
    {
    printf("\n\n1.WANT TO ADD NEW PRODUCT:\n2.WANT TO DISPLAY WHOLE PRODUCT LIST:\n3.WANT TO UPDATE THE PRICE OF PRODUCT:\n\n");
    printf("Enter your choice------->");
    scanf("%d",&ch);
    
    switch (ch)
    {
    case 1:
        new_item();
        break;

    case 2:
        fp1 = fopen("prod_list.txt","r");
        display(fp1);
        break;

    case 3:
        update1();
        break;
    
    default:
        break;
    }    
    printf("\n\nwant to cont.......(y/n)----->");
    scanf(" %c",&res);
    } while (res=='y');
    
}

void new_item()
{
    char name[10],bnd[10];
    int id;
    float cost;
    fp = fopen("prod_list.txt","a");
    if(fp == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        printf("\nEnter product Name------>");
        scanf("%s",&name);
        printf("\nEnter product Brand------>");
        scanf("%s",&bnd);
        printf("\nEnter product ID------>");
        scanf("%d",&id);
        printf("\nEnter product cost------>");
        scanf("%f",&cost);
        fprintf(fp,"%s\t%s\t%d\t%.2f\t\n",name,bnd,id,cost);
        fclose(fp);

    }
}

void update1()
{
    FILE *tfp1;
    fp1 = fopen("prod_list.txt","r");
    tfp1 = fopen("temp.txt", "w"); 
        if(fp == NULL && fp1 ==NULL)
    {
            printf("\n\t\tFile opening error");
            exit(0);
    }
    else
    {
        i=0;
        int flag =0,id;
        float ct;
        printf("\n\t\t\tEnter ID you want to be updated:\t");
        scanf("%d",&id);
        while(fscanf(fp1, "%s\t%s\t%d\t%f\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            if(pd[i].ID==id)
            {
                printf("\n\t\t\tEnter new Cost----->");
                scanf("%f",&ct);

                fprintf(tfp1,"%s\t%s\t%d\t%f\n", pd[i].pdN,pd[i].brand,pd[i].ID,ct);

                printf("\n\nRecord updated");
                flag =1;
            }
            else
                fprintf(tfp1,"%s\t%s\t%d\t%f\n", pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
            i++;
        }
        if(flag==0)
            printf("\n\t\tRECORD not found");
        fclose(fp1);
        fclose (tfp1);
        fp1 = fopen("prod_list.txt","w");
        tfp1 = fopen("temp.txt", "r");
        if(fp1 == NULL && tfp1 ==NULL)
        {
            printf("\n\t\tFile opening error");
            exit(0);
        }
        else
        {
            i=0;
                while(fscanf(tfp1,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
                {
                    fprintf(fp1,"%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
                    i++;
                }
            fclose(fp);
            fclose (fp1);
        }
    }
}

void access()
{
    printf("\n1.Sign Up\t\t2.Login\n");
    printf("\nEnter your choice:\t");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        signup();
        break;

    case 2:
        login();
        break;
    
    default:
        exit(0);
    }
}

void signup()
{
    printf("\n\t\tCREATE YOUR NEW USER ID AND PASSWORD\t\n\t(User ID and Password must be less than 10 characters)\t\n---------------------------------------------------------------------------\n");
    fp = fopen("login.txt","a+");
    if(fp == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        printf("\nCreate New User ID:\t");
        scanf(" %s",pd[i].user);
        printf("Create Strong Password:\t");
        scanf(" %s",pd[i].pword);
        printf("Confirm Password:\t");
        scanf(" %s",pd[i].pword);
        fprintf(fp,"%s\n%s\n",pd[i].user,pd[i].pword);
        printf("\n\n\tSIGNED IN SUCCESSFULLY>>>>\t\n\n");
        fclose(fp);
    }
}

void login()
{
    int flg=0;
    char usN[11],psw[11],ch;
    printf("\n\t======================= LOGIN =======================\t\n");
    printf("\n\tEnter your User ID:\t");
    scanf(" %s",&usN);
    printf("\n\tEnter Password:\t\t");
    i=0;
    while((ch = getch()) != 13)
    {
        psw[i] = ch;
        i++;
        printf("*");
    }
    psw[i] = '\0';
    
    fp = fopen("login.txt","r");
    if(fp == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        while(fscanf(fp,"\n%s\n%s\n",pd[i].user,pd[i].pword)!=EOF)
        {
            if(strcmp(usN,pd[i].user)==0 && strcmp(psw,pd[i].pword)==0)
            {
                printf("\n\n\tLOGIN IS SUCESSFULLY>>>>>>>>>>\t\n\n");
                flg=1;
            } 
            i++;
        }
        if(flg==0)
        {
            printf("\n\t!! INVALID USER ID OR PASSWORD !!\t\n");
            printf("\nWant to Sign Up(y/n):\n");
            scanf(" %c",&res);
            if(res=='y')
            {
                signup();
            }
            else
                login();
        }
    }
}

void add()
{
    i=0;
    printf("\nEnter Product ID----->\t");
    int id,flg=0;
    scanf("%d",&id);
    fp1 = fopen("prod_list.txt","r");
    fp2 = fopen("My_list.txt","a");
    if(fp1!=NULL && fp2!=NULL)
    {
        while(fscanf(fp1,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            if(id == pd[i].ID)
            {   
                fprintf(fp2,"%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
                flg=1;
            }
            i++;
        }
        if(flg==0)
            printf("ID not Found.\n");
    }
    else
    {
        printf("\n\nFile opening Error");
        exit(0);
    }
    fclose(fp1);
    fclose(fp2);
}

void display(FILE *fp2)
{
    if(fp2 == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        i=0;
        printf("\n________________________________________________\nProduct \tBrand\tID\tPrice\t\n________________________________________________\n");
        while(fscanf(fp2,"%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            printf("%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
            i++;
        }
        fclose(fp2);
    }
}

void search()
{
    int id;
    fp1 = fopen("prod_list.txt","r");
    if(fp1 == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        printf("\n\nEnter the Product ID----->\t");
        scanf("%d",&id);
        int flg=0;
        i=0;
        while(fscanf(fp1,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            if(id == pd[i].ID)
            {   
                printf("product Found is>>>>>>>>\n%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
                flg=1;
                break;
            }
            i++;
        }
        if(flg==0)
            printf("ID not Found.\n");
    }
    fclose(fp1);
}

void update()
{
    int id,id1,flg=0;
    i=0;
    FILE *tfp2;
    fp2 = fopen("My_list.txt","r");
    tfp2 = fopen("tempMy_list.txt","a+");
    fp1 = fopen("prod_list.txt","r");
    if(fp2 == NULL && tfp2 == NULL && fp1 == NULL)
    {
        printf("File opening Error.");
        exit(0);
    }
    else
    {
        printf("\n\nEnter the Product ID you want to be update----->\t");
        scanf("%d",&id);
        while(fscanf(fp2,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            if(id == pd[i].ID)
            {     
                int j=0;
                printf("Entar New ID:----->");
                scanf("%d",&id1);
                while(fscanf(fp1,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[j].pdN,pd[j].brand,&pd[j].ID,&pd[j].cost)!=EOF)
                {
                    if(id1 == pd[j].ID)
                    {   
                        fprintf(tfp2,"%s\t%s\t%d\t%.2f\n",pd[j].pdN,pd[j].brand,pd[j].ID,pd[j].cost);
                        flg=1;
                        break;
                    }
                    j++;
                }
                if(flg==0)
                    printf("ID not Found.\n");
            }
            else
                fprintf(tfp2,"%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
            i++;
        }
        if(flg==0)
            printf("ID not Found.\n");
        fclose(fp2);
        fclose(tfp2);
        fclose(fp1);

        fp2 = fopen("My_list.txt","w+");
        tfp2 = fopen("tempMy_list.txt","r");
        if(fp2 == NULL && tfp2 == NULL)
        {
            printf("File opening Error.");
            exit(0);
        }
        else
        {
            i=0;
            while(fscanf(tfp2,"\n%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
            {
                fprintf(fp2,"%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
                i++;
            }
            fclose(fp2);
            fclose(tfp2);
        }
    }
}

void bill() 
{
    i=0;
    float sum=0;
    fp2 = fopen("My_list.txt","r");
    if(fp2 == NULL)
    {
        printf("\n\t\tFile opening error");
        exit(0);
    }
    else
    {
        i=0;
        printf("\n________________________________________________\nProduct \tBrand\tID\tPrice\t\n________________________________________________\n");
        while(fscanf(fp2,"%s\t\t%s\t\t%d\t\t%f\t\t\n",pd[i].pdN,pd[i].brand,&pd[i].ID,&pd[i].cost)!=EOF)
        {
            printf("%s\t%s\t%d\t%.2f\n",pd[i].pdN,pd[i].brand,pd[i].ID,pd[i].cost);
            sum=sum+pd[i].cost;
            i++;
        }
    }
    printf("\n\t\t\tTotal=%.2f",sum);
    fclose(fp2);
}