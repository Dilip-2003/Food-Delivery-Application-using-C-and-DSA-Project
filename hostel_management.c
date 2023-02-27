#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void application_hostel();
void student_data();
void eligible();
struct node{
	int serial;
//	int room_no;
	char name[50];
	char address[100];
	int distance;
	char gender[20];
	struct node *next;
};
struct node1{
	int roomNo;
	int serial;
	char name[50];
	char address[100];
	int distance;
	char gender[10];
	struct node *next;
	
};
struct node *head=NULL,*temp;
int serial=1,serial2=1;;
int main()
{	
	printf("\033[1;31m");
	printf("\nInput the applied students data :\n\n ");
	application_hostel();
	printf("\n Applied Students are : \n\n");
	printf("\n\nserial\t\tname\t\taddress\t\tgender\t\tdistance\n");
	student_data();
	eligible();
	return 0;
}

void application_hostel(){
	printf("\033[0;32m");
	int choice,rno,dis;
	char name1[50],address1[100],gender1[10];
	fflush(stdin);
	printf("\nenter the name : ");
	gets(name1);
	fflush(stdin);
	printf("\nenter the address : ");
	gets(address1);
	fflush(stdin);
	printf("\nenter the gender : ");
	gets(gender1);
	fflush(stdin);
	printf("\nenter the distance(in Km) : ");
	scanf("%d",&dis);
	
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->serial=serial;
	strcpy(newnode->name,name1);
	strcpy(newnode->address,address1);
	strcpy(newnode->gender,gender1);
	newnode->distance=dis;
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
	printf("\nWill You Wanna Add More Students (1 for yes 0 for no ) : ");
	scanf("%d",&choice);
	if(choice==1)
	{
		application_hostel();
	}
	else if(choice==0){
		return;
	}


}
void student_data()
{	printf("\033[0;35m");
	struct node *temp1;
		temp1=head;
	while(temp1!=NULL)
	{	
		printf("\n\n%d\t%s\t%s\t%s\t%d",temp1->serial,temp1->name,temp1->address,temp1->gender,temp1->distance);
		temp1=temp1->next;

	}
}

void eligible()
{	printf("\033[0;35m");
	fflush(stdin);
	struct node *temp2;
	struct node1 *temp3,*temp4,*head1=NULL;
	int roomNo;
	temp2=head;
	while(temp2!=NULL)
	{
		if(temp2->distance > 100)
		{	
			printf("\n\n\nenter the room no for %s ",temp2->name);
			scanf("%d",&roomNo);
			temp3=(struct node1*)malloc(sizeof(struct node1));
			temp3->roomNo=roomNo;
			temp3->serial=serial2;
			strcpy(temp3->name,temp2->name);
			strcpy(temp3->address,temp2->address);
			strcpy(temp3->gender,temp2->gender);
			temp3->distance=temp2->distance;
			temp3->next=NULL;
			serial2++;
			if(head1==NULL)
			{
				temp4=head1=temp3;
			}
			else{
			temp4->next=temp3;
			temp4=temp3;
		}
		fflush(stdin);	
		}
		temp2=temp2->next;
	}
	
	printf("\n\n<------eligible students are-------> \n");
	while(head1!=NULL)
	{
		printf("\n\n%d\t%d\t%s\t%s\t%s\t%d",head1->roomNo,head1->serial,head1->name,head1->address,head1->gender,head1->distance);
		head1=head1->next;		
	}
	fflush(stdin);
}
