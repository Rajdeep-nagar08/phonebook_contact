#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    
 char number[11];
 char name[30];
struct node *next;
       
};

    
    void insert();
    void sort();
    void deletecontact(char n[20]);
    int searchbyname(char p[20],int x);
    int searchbynumber(char no[30],int x);
   
    void display();
    void update(char ch[10]);
    struct node* head=NULL;
                    
int main()
{
    char n[30];
    char name[30];
    char number[11];
    char ans='y';
    int ch,a;
    int stop=0;
    printf("Hi! WELCOME TO PHONEBOOK!!!!!!\n\n");
    do
    {
printf("\nWHICH OPERATION YOU WANTS TO PERFORM???");
printf("\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) SEARCH BY NAME\n6) SEARCH BY NUMBER\n7) EXIT\n\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
    case 1:
    display();
   break;
    
    case 2:
    insert();
    sort();
    break;
    
    case 3:
        printf("\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n");
        scanf("%s",n);
    update(n);
    sort();
    break;
    
    case 4:
    printf("\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n");
    scanf("%s",name);
    deletecontact(name);
    break;
    
    case 5:
        printf("ENTER THE NAME TO BE SEARCHED\n");
        scanf("%s",name);
        searchbyname(name,0);
        break;
   case 6:
        printf("ENTER THE NUMBER TO BE SEARCHED\n");
        scanf("%s",number);
        searchbynumber(number,0);
   break;
   case 7:
        stop=1;
    break;
    }
    
    if(stop==1){
    printf("\n\nTHANK YOU! HAVE A NICE DAY");
     break;
    }
    
    printf("\n\nDO YOU WANT TO CONTINUE OPERATIONS(y/n)?????????");
    scanf("%s",&ans);
}
while(ans=='y');
}
 

void insert()
{    struct node* ptr=NULL;
        char num[11];
        char nam[30];
    char ans;
    
      do
        {
    printf("ENTER NAME      :");
    scanf("%s",nam);
    
    if(searchbyname(nam,1)==1){
        printf("NAME ALREADY EXIST !");
         break;
    }
    printf("ENTER NUMBER    :");
    scanf("%s",num);
    if(searchbynumber(num,1)==1){
        printf("NUMBER ALREADY EXIST !");
        break;
    }
    
   if(strlen(num)!=10){
   while(1)
    {
    printf("ENTER VALID NUMBER  :");
    scanf("%s",num);
    if(strlen(num)==10)
    break;
    }
   }
   
    struct node* temp=(struct node*)malloc(sizeof(struct node));
   strcpy(temp->name,nam);
   strcpy(temp->number,num);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
       temp->next=ptr;
       head=temp;
    }
    
	    printf("DO YOU WANT TO CONTINUE INSERTING?????????(y/n)");
    scanf("%s",&ans);
}
while(ans=='y');

}


void display()
{  struct node* ptr=NULL;
    ptr=head;
    if(head==NULL){
        printf("\nYOUR PHONE BOOK IS EMPTEY");
        return;
    }
    
	while(ptr!=NULL)
	{
			printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
			ptr=ptr->next;
	}
}

   
    
    void deletecontact(char s[20])
    {    struct node* ptr=NULL;
        int c=0;
        ptr=head;
        if(head==NULL){
        printf("\nYour Phone book is empty");
        return;
        }
        
        if(head->next==NULL){
            if(strcmp(s,head->name)==0){
        head=NULL;
        printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        return;
        }
        else{
           printf("YOUR ENTERED NAME IS NOT IN THE LIST...");
           return;
        }
       }
        
        struct node* temp=NULL;
        
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            temp=ptr;
            ptr=ptr->next;
        }
        
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            temp->next=ptr->next;
           free(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(ptr==head)
        {
            head=head->next;
            free(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(ptr->next==NULL)
        {
            temp->next=NULL;
            free(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(c==2)
        {
            printf("YOUR ENTERED NAME IS NOT IN THE LIST...");
        }
    }

    int searchbyname(char na[10],int x)
    {  int found=0;
        struct node* ptr=NULL;
        ptr=head;
        char nm[20];
        char nu[11];
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                found=1;
                strcpy(nm,ptr->name);
                strcpy(nu,ptr->number);
                break;
                
            }
            ptr=ptr->next;
        }
        if(found==0){
            if(x==0)
           printf ( " Not found ");
        return 0;
        }
        else{
            if(x==0){
            printf("NAME FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
            }
           return 1;
        }
    }
    
    
     int searchbynumber(char num[20],int x)
    {
        int found=0;
        struct node* ptr=NULL;
        ptr=head;
        char nm[20];
        char nu[11];
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                found=1;
                strcpy(nm,ptr->name);
                strcpy(nu,ptr->number);
                break;
                
            }
            ptr=ptr->next;
        }
        if(found==0){
            if(x==0)
           printf ( " Not found ");
        return 0;
        }
        else{
            if(x==0){
            printf("NAME FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
            }
           return 1;
        }
    }
    
    
    
    void update(char n[20])
    {   struct node* ptr=NULL;
        
        
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                
                do
                {
                    printf("\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:
                    printf("ENTER NEW-NAME=");
                    scanf("%s",ptr->name);
                    break;
                    case 2:
                    printf("ENTER NEW PHONE-NUMBER?");
                    scanf("%s",ptr->number);
                    while(strlen(ptr->number)!=10)
    {
    printf("ENTER VALID NUMBER  :");
    scanf("%s",ptr->number);
    }
                    break;
                }
                printf("DO YOU WANT TO CONTINUE UPDATING(y/n)?");
                scanf("%s",&ans);
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
    
    
    
        void sort()
    {
        struct node *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }
     
    }
