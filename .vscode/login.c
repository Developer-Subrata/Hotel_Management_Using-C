#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 struct student
   {
    char f_name[15],l_name[15],dob[10],uid[25];
   }std;
   FILE *rf;
void reg();
void login();

  void main()
    {
    char ch;
     printf("        ......Press 'L' For Login......\n");
     printf("       ......Press 'R' For Register.....\n");
     printf("         ......Press 'E' For Exit......\n");
     scanf("%c",&ch);
     if('R'==toupper(ch))
       {
	reg();
       }
    else if('L'==toupper(ch))
      {
       login();
      }
    else if('E'==toupper(ch))
      {
       exit(0);
      }
    else
      {
       printf("!!!!...Please Enter Correct Choice...!!!!");
      }
   }
void reg()
  {
   rf=fopen("ssssss.dat","a");
   printf("\nEnter Your First Name    :  ");
   //gets(std.f_name);
   scanf("%s",std.f_name);
   printf("\nEnter Your Last Name     :  ");
  // gets(std.l_name);
   scanf("%s",std.l_name);
   printf("\nEnter Your Date_Of_Birth :  ");
  // gets(std.dob);
   scanf("%s",std.dob);
   printf("\nEnter Your User ID       :  ");
   //gets(std.uid);
   scanf("%s",std.uid);
   fwrite(&std,sizeof(std),1,rf);
   fclose(rf);
   printf("\nYour User  ID Is = %s",std.uid);
   printf("\nYour PassWord Is = %s",std.dob);
   printf("\n                Press any Key to continue........");
   getch();
   login();
  }

   void login()
     {
     char userid[25],pass[10];
      rf=fopen("ssssss.dat","r");
   printf("\nEnter Your User ID    :  ");
  // gets(userid);
   scanf("%s",userid);
   printf("\nEnter Your PassWord   :  ");
  // gets(pass);
   scanf("%s",pass);
   rewind(rf);
   fread(&std,sizeof(std),1,rf);
	 while(!feof(rf))
	 {
	    if(strcmp(userid,std.uid)==0&&strcmp(pass,std.dob)==0)
	      {
	       printf("\nlogin succesful.......");
	       getch();
	       exit(0);
	      }
	   fread(&std,sizeof(std),1,rf);
	  }
      fclose(rf);
	      {
	       printf("\nPress Enter For New Registration.....");
	       getch();
	       reg();
	      }
	exit(0);
	   }

