#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void OwnerLogin();
void CustomerLogin();
void Create(char[],int a);
void TakingInput();
void menu();

int serial=1;
int total=0;
char name1[50],
address1[500],email1[25],phone1[15];
struct node
{
	int serial;
	int price;
	char name[40];
	struct node *next;
};
struct node*head=NULL,*temp;
int main()
{
	int n,operation;
	printf("\n1.Owner login\n2.Customer login\n>> ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			OwnerLogin();
			printf("\033[1;32m");
    	 	printf("\n1.Menu Creation\n2.Menu Item Deletion\n3.Menu Item Updation\n4.exit");
    	 	printf("\n\nWhich operation do you wanna do ? : ");
    	 	scanf("%d",&operation);
    	 	switch(operation)
    	 	{
    	 		case 1:
    	 			TakingInput();
    	 			OwnerLogin();
    	 			break;
				case 2:
					DeleteItem();
					break;
				case 3:
					UpdateItem();
					break;
				default:
					printf("\nPlease enter correct option ");
					    	 			
			 }
			break;
		case 2:
			CustomerLogin();
			break;
		default:
			printf("\n please select correct option!!!!!!");
			main();
			
	}
	
	
	return 0;
}

void OwnerLogin()
{
	printf("\033[0;32m");
	char name2[100];
    char email2[25];
    char phone2[15];
    char password2[25];
    printf("\nenter your name : ");
    fflush(stdin);
    gets(name2);
    printf("\nenter your phone number : ");
    fflush(stdin);
    gets(phone2);
    printf("\nenter your email : ");
    fflush(stdin);
    gets(email2);
    printf("\nenter your password : ");
    fflush(stdin);
    gets(password2);
    printf("\n\aYOU HAVE LOGIN TO THE DELIVERY SYSTEM SUCCESSFULLY\n");
}

void CustomerLogin()
{
	printf("\033[0;34m");
	char name[100];
    char address[500];
    char email[25];
    char phone[15];
    char password[25];
    printf("\nenter your name : ");
    fflush(stdin);
	gets(name);
    printf("\nenter your full address : ");
    fflush(stdin);
    gets(address);
    printf("\nenter your phone number : ");
    fflush(stdin);
    gets(phone);
    printf("\nenter your email : ");
    fflush(stdin);
    gets(email);
    printf("\nenter your password : ");
    fflush(stdin);
    gets(password);
    strcpy(name1,name);
    strcpy(address1,address);
    strcpy(email1,email);
    strcpy(phone1,phone);
}
//Function For Taking Name of The Items
void TakingInput()
{
	printf("\033[0;35m");
	char name[50];
	int price;
	printf("\nenter the item name : ");
	fflush(stdin);
	gets(name);
	printf("\nenter the price : ");
	scanf("%d",&price);
	Create(name,price);
}

//Function For the creation Of The Menu

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
	}

}

void DeleteItem()
{	
	int item;
	char newItem[50];
	int price1;
	struct node *t;
	printf("\n Menu items are --> ");
	menu();
	printf("\n Enter which item You wanna Delete : ");
	scanf("%d",&item);
	t=head;
	while(t->next!=item-1)
	{
		t=t->next;
	}
	printf("%d\t%d\t%s",t->price,t->serial,t->name);
	
	
}

void UpdateItem(){
	
}
void menu()
{	
	printf("\033[0;32m");
	struct node *temp1;
		temp1=head;
		if(temp1==NULL)
		printf("\nMenu Is Empty !!!!!");
	while(temp1!=NULL)
	{
		printf("\n%d\t%s\t\t\t%d",temp1->serial,temp1->name,temp1->price);
		temp1=temp1->next;

	}
}

