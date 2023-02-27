#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void TakingInput();
void Create(char[],int a);
void Display();
void Order();
void login();
void OwnerLogin();
void CustomerLogin();
void menu();
void choice();
void by_food();
void by_hotel();
void payment();
void invoice();

int serial=1;
int total=0;
char name1[50],address1[500],email1[25],phone1[15];
struct node
{
	int serial;
	int price;
	char name[40];
	struct node *next;
};
struct node*head=NULL,*temp;

int main(){
	printf("\t\t\t|--------------------------------------------------------------------|\n");
    printf("\t\t\t|                  WELCOME TO THE DELIVERY SYSTEM                    |\n");
    printf("\t\t\t|--------------------------------------------------------------------|\n\n");
//    	 printf("\nGo to the Owner Login Page ->> ");
//    	 OwnerLogin();
//    	 printf("\nYOU LOGIN TO THE DELIVERY SYSTEM SUCCESSFULLY\n");
//    	 printf("\nPlease Insert Your Menu Items : ");
//    	 TakingInput();
//    	 printf("\nYou Have Successfully Inserted Your Menu Items ");
//	printf("\nGo to the Customer Login Page ->> ");
//    		CustomerLogin();
//    		printf("\nYOU LOGIN TO THE DELIVERY SYSTEM SUCCESSFULLY");
	login();	
	choice();
	return 0;
}
void login()
{
	int a;
	printf("\n1.Owner Login\n2.Customer Login\n3.Exit\n>> ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
		 printf("\nGo to the Owner Login Page ->> ");
    	 OwnerLogin();
    	 printf("\nYOU LOGIN TO THE DELIVERY SYSTEM SUCCESSFULLY\n");
    	 printf("\nPlease Insert Your Menu Items : ");
    	 TakingInput();
    	 printf("\nYou Have Successfully Inserted Your Menu Items ");
    	 break;
    	case 2:
    		printf("\nGo to the Customer Login Page ->> ");
    		CustomerLogin();
    		printf("\nYOU LOGIN TO THE DELIVERY SYSTEM SUCCESSFULLY");
    		
			
	}
}
void OwnerLogin()
{
	char name2[100];
//    char address[500];
    char email2[25];
    char phone2[15];
    char password2[25];
    printf("\nenter your name : ");
//    gets(name2);
	scanf("%s",&name2);
    printf("\nenter your phone number : ");
    gets(phone2);
    printf("\nenter your email : ");
    gets(email2);
    printf("\nenter your password : ");
    gets(password2);
}
void CustomerLogin()
{
	char name[100];
    char address[500];
    char email[25];
    char phone[15];
    char password[25];
    printf("\nenter your name : ");
    gets(name);
    printf("\nenter your full address : ");
    gets(address);
    printf("\nenter your phone number : ");
    gets(phone);
    printf("\nenter your email : ");
    gets(email);
    printf("\nenter your password : ");
    gets(password);
    strcpy(name1,name);
    strcpy(address1,address);
    strcpy(email1,email);
    strcpy(phone1,phone);
}
void TakingInput()
{
	char name[50];
	int price;
	printf("\nenter the item name : ");
	scanf("%s",&name);
//	gets(name);
	printf("\nenter the price : ");
	scanf("%d",&price);
	Create(name,price);
}
void Create(char name[50],int price)
{	int choice;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->serial=serial;
	strcpy(newnode->name,name);
	newnode->price=price;
	newnode->next=NULL;
	serial++;
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}	
	printf("\nWill You Wanna Add More Item (1 for yes 0 for no ) : ");
	scanf("%d",&choice);
	if(choice==1)
	{ 
		TakingInput();
	}
	else if(choice==0){
		return;
//		menu();
	}
	
}
void menu()
{	struct node *temp1;
	printf("\n <---- THIS IS OUR MENU ---->\n");
		temp1=head;
	while(temp1!=NULL)
	{
		printf("\n%d\t%s\t\t\t %d",temp1->serial,temp1->name,temp1->price);
		temp1=temp1->next;
		
	}	
}

void Order()
{	struct node *temp2;
	int Item,NumItem,Bill,ch;
	printf("\n Please Select Your Order : ");
	scanf("%d",&Item);
	temp2=head;
	while(temp2->serial!=Item)
	{
		temp2=temp2->next;
	}
	printf("\n How many %s do you want : ",temp2->name);
	scanf("%d",&NumItem);
	Bill=temp2->price*NumItem;
	printf("\nYour Bill For %d no of %s is : %d ",NumItem,temp2->name,Bill);
	total=total+Bill;
	printf("\nDo You Wanna Oder More(1 for yes 0 for no) : ");
	scanf("%d",&ch);
	if(ch==1)
	{
		Order();
	}
	else if(ch==0)
	{
		return;
	}
	
}
void choice()
{
	int n;
	printf("\n\nWe provide two type of order ---> \n1.By Hotel\n2.By Food\n3.Exit\n");
    printf("\nENTER YOUR CHOICE--> ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
            by_hotel();
            break;
    case 2:
            by_food();
            break;
    case 3:
    		exit(1);
    		break;
    default:
            printf("\nplease press the right key ");
            main();
        	break;
    }
}

void by_hotel()
{
    int n,choic;
    printf("\n1.Hotel Shreyan\n2.Tasty\n3.Tris Planet\n4.Lets Eat\n5.Dhakeshwari Resturant\n6.Exit");
    printf("\nENTER YOUR CHOICE--> ");
    scanf("%d",&choic);
    switch(choic)
    {
    	case 1:
    		printf("\n<---------THIS IS OUR MENU--------->\n\n");
    		menu();
    		Order();
    		break;
    	case 2:
			printf("\n<---------THIS IS OUR MENU--------->\n\n");

    		menu();
    		Order();
    		break;
    	case 3:
    		printf("\n<---------THIS IS OUR MENU--------->\n\n");
    		menu();
    		Order();
    		break;
    	case 4:
    		printf("\n<---------THIS IS OUR MENU--------->\n\n");
    		menu();
    		Order();
    		break;
    	case 5:
    		printf("\n<---------THIS IS OUR MENU--------->\n\n");
    		menu();
    		Order();
    		break;
		case 6:
				printf("\nTHANK YOU FOR VISITING US \n");
				exit(1);
				break;
    	default:
    		printf("\nPLEASE ENTER THE CORRECT CHOICE\n");
    		by_hotel();
    		break;
    		
    			
	}
	printf("\nGO TO THE PAYMENT GATEWAY(press 1 ) ->> ");
	scanf("%d",&n);
	if(n==1)
	payment();
  
}
void by_food()
{
   	int n;
    printf("\n<-----------THIS IS OUR MENU----------->\n\n");
   	menu();
   	Order();
	printf("\n\nGO TO THE PAYMENT GATEWAY(press 1 ) ->> ");
	scanf("%d",&n);
	if(n==1)
	payment();
}

void payment()
{	
	int n,a;
	printf("\n1.ONLINE PAYMENT\n2.CASH ON DELIVERY\n");
	printf("ENTER YOUR CHOICE--> ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\n1.PAYTM\n2.PHONEPAY\n3.GPAY\n4.CARD PAY\n");
			printf("ENTER YOUR CHOICE--> ");
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					printf("\nTHANK YOU !!!!!!! YOU WILL GET YOUR DELICIOUS FOOD JUST AFTER 30-40 MINUTES \n\n");
					break;
				case 2:
					printf("\nTHANK YOU !!!!!!! YOU WILL GET YOUR DELICIOUS FOOD JUST AFTER 30-40 MINUTES \n\n");
					break;
				case 3:
					printf("\nTHANK YOU !!!!!!! YOU WILL GET YOUR DELICIOUS FOOD JUST AFTER 30-40 MINUTES \n\n");
					break;
				case 4:				
					printf("\nTHANK YOU !!!!!!! YOU WILL GET YOUR DELICIOUS FOOD JUST AFTER 30-40 MINUTES \n\n");
					break;
				default:
					printf("PLEASE SELECT THE CORRECT OPTION\n");
					payment();
					break;
			}
			break;
		case 2:
			printf("\nTHANK YOU !!!!!!! YOU WILL GET YOUR DELICIOUS FOOD JUST AFTER 30-40 MINUTES \n\n");
			break;
		default:
			printf("PLEASE SELECT THE CORRECT OPTION\n");
					payment();
					break;

			
	}
	int c;
	printf("WOULD YOU WANT TO GENERATE YOUR INVOICE ?(press 1 for yes 0 for no)--> ");
	scanf("%d",&c);
	if(c==1)
	{
		invoice();
	}
}

void invoice()
{	int total2;
	printf("\n\n\t|---------------------------------------------------------------------|\n");
    printf("\t\t			 YOUR INVOICE				 \n");
    printf("\t|---------------------------------------------------------------------|\n\n");
	printf("\nName: %s\n",name1);
	printf("Address: %s\n",address1);
	printf("Phone: %s\n",phone1);
	printf("Email: %s\n",email1);
	int gst;
	gst=total+total*.18;
	total2=gst;
	printf("\nYOUR TOTAL BILL IS--> %d (including 18 percent GST)\n",total2);
	
}




