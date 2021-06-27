//
//  main.c
//  ACP_J
//
//  Created by Shivam Aditya on 03/11/20.
//


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define fee 500
#define fee1 2000
#define samepatient 250
int keyupdate_ = 0; // Normal Patient Indexing
int keyupdate1_ = 0; // Emergency Patient Indexing
int keyupdate2_ = 0;


struct node{
    int age;
    char sex[10];
    int key; // Index
    char bloodgroup[3];
    char name[50];
    char date[15];
    char phonenumber[15];
    char category[25];
    struct node *link; // Address of next node
};


struct node *start1 = NULL; // head for emergency patients
struct node *start = NULL; // head for normal patients


// Function to create Newnode
struct node *createnode(){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    return p;
};

void save_record(int option, int index){
    struct node *p;
    FILE *fp;
    if (option == 1){
        p = start;
        while(p->key != index){
            p = p->link;
        }
        fp = fopen("/Users/shivamaditya/Desktop/Records.txt","a");
        fprintf(fp,"%s \n%s \n%s \n%d \n%s \n%s \n%s \n\n",p->date,p->name,p->sex,p->age,p->bloodgroup,p->phonenumber,p->category);
        fclose(fp);
    }
    if (option == 2) {
        p = start1;
        while (p->key != index) {
            p = p->link;
        }
        fp = fopen("/Users/shivamaditya/Desktop/Records.txt","a");
        fprintf(fp,"%s \n%s \n%s \n%d \n%s \n%s \n%s \n\n",p->date,p->name,p->sex,p->age,p->bloodgroup,p->phonenumber,p->category);
        fclose(fp);
    }
    printf("------------\n");
    printf("choose another option\n");
}


void insertnormalpatient_(){
    int option;
    struct node *temp = createnode();
    keyupdate_++;
    temp->key = keyupdate_;
    temp->link = NULL; // initialize
    printf("Enter your name, sex, bloodgroup and age : ");
    scanf("%s%s%s%d",temp->name,temp->sex,temp->bloodgroup,&temp->age);
    printf("enter the date\n");
    scanf("%s",temp->date);
    printf("enter you phone number\n");
    scanf("%s",temp->phonenumber);
    FILE *fp;
    char c;
    fp = fopen("/Users/shivamaditya/Desktop/Normal_Menu.txt","r");
    c = fgetc(fp);
    while (c != EOF){
        printf ("%c", c);
        c = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    printf("choose your problem\n");
    scanf("%d",&option);
    if(option==1)
    strcpy(temp->category,"opthalmologist");
    if (option==2)
    strcpy(temp->category,"orthopaedician");
    if (option==3)
    strcpy(temp->category,"paediatrician");
    if (option==4)
    strcpy(temp->category,"urologist");
    if (option==5)
    strcpy(temp->category,"dermatologist");
    if (option==6)
    strcpy(temp->category,"radiologist");
    if (option==7)
    strcpy(temp->category,"pathologist");
    if (option==8)
    strcpy(temp->category,"pulmonologist");
    
    if(start == NULL)
    start = temp;
    
    else{
        struct node *t = start;
        // traversing to last node
        while(t->link != NULL){
            t = t->link;
        }
        t->link = temp; // Attaching newnode to the end
    }
    printf("------------\n");
    printf("choose another option\n");
}




void insertemergencypatient_()
{
    int option1;
    struct node *temp=createnode();
    keyupdate1_++; // Indexing
    temp->key=keyupdate1_;
    temp->link=NULL;
    printf("enter your name,sex bloodgroup and age : \n");
    scanf("%s%s%s%d",temp->name,temp->sex,temp->bloodgroup,&temp->age);
    printf("enter the date\n");
    scanf("%s",temp->date);
    printf("enter your phone number\n");
    scanf("%s",temp->phonenumber);
    FILE *fp;
    char c;
    fp = fopen("/Users/shivamaditya/Desktop/Emergency_Menu.txt","r");
    c = fgetc(fp);
    while (c != EOF){
        printf ("%c", c);
        c = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    printf("choose the option");
    scanf("%d",&option1);
    if(option1==1)
    strcpy(temp->category,"general surgeon");
    if(option1==2)
    strcpy(temp->category,"cardilogist");
    if(option1==3)
    strcpy(temp->category,"gynacologist");
    
    if(start1==NULL)
    start1=temp;
    
    else{
        struct node *t=start1;
        while(t->link!=NULL){
            t=t->link;
        }
        t->link=temp;
    }
    
    printf("------------\n");
    printf("choose another option\n");
}






void printemergencypatientdetails() {
    int i=1;
    struct node *t=start1;
    while(t!=NULL){
        printf("%d.>",i);
        printf("%s\n",t->name);
        printf(" %s\n",t->sex);
        printf(" %d\n",t->age);
        printf(" %s\n",t->bloodgroup);
        printf(" %s\n",t->date);
        printf(" %s\n",t->phonenumber);
        printf(" ------------");
        t=t->link;
        i++;
    }
    printf("------------\n");
    printf("choose another option\n");
}




void printnormalpatientdetails_() {
    int i=1;
    struct node *t=start;
    while(t!=NULL) {
        printf("%d.>",i);
        printf("%s\n",t->name);
        printf(" %s\n",t->sex);
        printf(" %d\n",t->age);
        printf(" %s\n",t->bloodgroup);
        printf(" %s\n",t->date);
        printf(" %s\n",t->phonenumber);
        t=t->link;
        i++;
    }
    printf(" ------------\n");
    printf("choose another option\n");
}





void diagnoseexistedpatient_(int k) { // normal Patients only
    struct node *t=start;
    while(t!=NULL) {
        if(t->key==k) {
            keyupdate2_--; //**************************************************
            printf("Member existed\n");
            printf("------------\n");
            printf("choose another option\n");
            break;
        }
        else {
            t=t->link;
        }
    }
}




void totalfee() {
    int a = ((keyupdate2_*samepatient) + (keyupdate_*fee) + (keyupdate1_*fee1));
    printf("total fees :%d\n",a);
    printf("------------\n");
    printf("choose another option\n");
}




void totalpatient() {
    int a = keyupdate1_ + keyupdate_ + keyupdate2_;
    printf("total number of patients :%d\n",a);
    printf("------------\n");
    printf("choose another option\n");
}




int main() {
    int i,j,k;
    FILE *fp;
    char c;
    fp = fopen("/Users/shivamaditya/Desktop/Menu.txt","r");
    c = fgetc(fp);
    while (c != EOF){
        printf ("%c", c);
        c = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    while(1) {
        scanf("%d",&j);
        switch(j) {
            case 1:
             insertnormalpatient_();
             break;
            case 2:
             insertemergencypatient_();
             break;
            case 3:
             printnormalpatientdetails_();
             break;
            case 4:
             printemergencypatientdetails();
             break;
            case 5:
             printf("enter the key number");
             scanf("%d",&k);
             diagnoseexistedpatient_(k);
             break;
            case 6:
             totalfee();
             break;
            case 7:
             totalpatient();
             break;
            case 8:
             exit(0);
             break;
            case 9:
                printf("1.Normal Patient\n");
                printf("2.Emergency Patient\n");
                printf("Option : ");
                scanf("%d",&i);
                printf("Index : ");
                scanf("%d",&k);
                save_record(i, k);
                break;
        }
    }
    return 0;
}
