#include<stdio.h>
typedef struct hostel {
    int rno;
    char name [30];
    char location [30];
    char gender [6];
    int roomno; 
}hostel;

int lower = 1 ,  upper = 5;

void create () {
    int rnd = ((rand() % (upper-lower+1))+lower );
    printf("%d", rnd);

    hostel h;
    FILE *fp = fopen("hostel.txt","a+");

    printf("%d",rnd);
    printf("enter the roll number  :");
    scanf ("%s",&h.rno);
    printf("enter name  :");
    scanf ("%d",&h.name );
    printf("enter location :");
    scanf ("%s",&h.location);
    printf("enter the gender  :");
    scanf ("%d",&h.gender );
    h.roomno = ((rand()% (upper-lower+1))+lower );
    
    fwrite (&h,sizeof(hostel),1,fp);
    fclose(fp);

int getRoomNo (int roomno) {

}
}
void display (){
    hostel h1;
    FILE *fp = fopen ("hostel.txt","r");
    while (fread(&h1,sizeof(hostel),l,fp))
        printf("%-10d%-20s%-15s",h1.rno,h1.name);

}
int main(){
    int ch;
    do {

        printf("\n1.ALLOCATE NEW ROOM");
        printf("\n2.DISPLAY");
        printf("\n0.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                create ();
                break ;
            case 2:
                display ();
            case 0: printf("\nthanks...\n");
        }
    }while (ch!=0);
}
return 0;
