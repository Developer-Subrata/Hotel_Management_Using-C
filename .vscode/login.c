#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
   void admin();
   void servic();
   void features();
   void cheack();
   void rent();
   void book();
   void back();
		   void delet();
		   void request();
		   void update();
		   void Back();
		   void view();
		   void db_room();
		   void ggg();
                    void reg();
                    void login();
                    void ext();
   
  struct book        /////////book file
     {
      char ph[10],fn[10],ln[10],vill[25],po[25],ps[25],dist[25],mail[25],date[10],pin[6],adr[12];
      int rn,day;
     }bk;
struct update
   {
    char floar[10],toilet[10],n_f_ac[10],heater[5];
    int r_no,n_bed,window,gate;
   }rd;

                             struct studen
                                 {
                                 char f_name[15],l_name[15],dob[10],uid[25];
                                 }std1;

FILE *bf;  ///book file
FILE *uf;
FILE *dp;  ///
FILE *dp1;   ////delele booked room
FILE *rf;
//////////////////////main block////////////////////////////////////
void main()
 { system("CLS");//clrscr();
 int c;
 //textcolor(GREEN+BLINK);
 printf("                              *---WeLcOmE---*");
 //textcolor(RED);
  printf("\n\t\t");
  printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
  printf("\n\t\t           |                  |           ");
  printf("\n\t\t           *     STR HOTEL    *           ");
  printf("\n\t\t           |                  |           ");
  printf("\n");
  printf("\t\t");
  printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
  printf("\n________________________________________________________________________________\n");
  printf("                       (1).ADMIN            (2).SERVICE\n");
  printf("\n                      (3).FEATURES         (4).EXIT\n");
  while(1)
  {
  scanf("%d",&c);
  switch(c)
     {
      case 1: admin();
		break;
      case 2: servic();
		break;
      case 3: features();
		break;
      case 4: exit(0);
		break;
      default: printf("Chose correct option");
     }
  getch();
  }
 }
////////////////////////////main menu block////////////////////////


void admin()
    { system("CLS");//clrscr();
   
   char ch1;
     printf("\n                        ......Press 'L' For Login......\n");
     printf("                       ......Press 'R' For Register.....\n");
     printf("                        .......Press 'E' For Exit......\n");
     scanf("%c",&ch1);
     if('R'==toupper(ch1))
       {
	reg();
       }
    else if('L'==toupper(ch1))
      {
       login();
      }
    else if('E'==toupper(ch1))
      {
       exit(0);
      }
    else
      {
       printf("!!!!...Please Enter Correct Choice...!!!!");
      }
   }

 void ext()
   {
    exit(0);
   }

void reg()
  {
   rf=fopen("ssssss.dat","a");
   printf("\nEnter Your First Name    :  ");
   scanf("%s",std1.f_name);
   printf("\nEnter Your Last Name     :  ");
   scanf("%s",std1.l_name);
   printf("\nEnter Your Date_Of_Birth :  ");
   scanf("%s",std1.dob);
   printf("\nEnter Your User ID       :  ");
   scanf("%s",std1.uid);
   fwrite(&std1,sizeof(std1),1,rf);
   fclose(rf);
   printf("\nYour User  ID Is = %s",std1.uid);
   printf("\nYour PassWord Is = %s",std1.dob);
   printf("\n                Press any Key to continue........");
   getch();
   system("CLS");
   login();
  }

  void login()
     {    
      char userid[25],pass[10];
      rf=fopen("ssssss.dat","r");
   printf("\nEnter Your User ID    :  ");
   scanf("%s",userid);
   printf("\nEnter Your PassWord   :  ");
   scanf("%s",pass);
   rewind(rf);
   fread(&std1,sizeof(std1),1,rf);
	   while(!feof(rf))
	   {
	    if(strcmp(userid,std1.uid)==0&&strcmp(pass,std1.dob)==0)
	      {
	       printf("\nlogin succesful......");
      ////////////////////////////////////////////////  
      system("CLS");
    int v1;
  printf("\n________________________________________________________________________________\n");
  printf("                     (1).COUSTOMER DETAILS           (2).UPDATE_FEATURES\n");
  printf("\n                   (3).DELETE ROOM                 (4).BACK\n");
  printf("\n                   (5). VIEW ROOM LIST             (6). DELETE BOOKED ROOM\n");
   while(1)
    {
       scanf("%d",&v1);
      switch(v1)
       {
      case 1: request();
		break;
      case 2: update();
		break;
      case 3: delet();
		break;
      case 4: back();
		break;
      case 5: view();
		break;
      case 6: db_room();
		break;
      default: printf("Chose correct option....");
    }
  }
           getch();
	       exit(0);
	      }
	   fread(&std1,sizeof(std1),1,rf);
	  }
      fclose(rf);
	       printf("               ____________INVALID USER_ID & PASSWORD___________");
	       printf("\n\nPress ~1~ For New Registration.....");
	       printf("\nPress ~any key~ For Exit.....");
	       printf("\nPress ~5~ For TryAgain....");
	   int zze;
        scanf("%d",&zze);
     switch (zze)
          {
          case 1: reg();
                 break;
          case 5: login();
                 break; 
          default: ext();
                  break;
          }
     }  
	    /* if(zz==1)
	      {
	       reg();
	      }
        if(zz==5)
		{
		 login();
		}
	     if(zz!=1&&zz!=5)
	      {
	       ext();
	      }*/
	   
/////////////////////////////////////////////////////////////
void db_room() /////////////delete booked room
  { system("CLS");//clrscr();
   int d7,flag1=0;
    bf=fopen("book.dat","r");
    dp1=fopen("delet1.dat","w");
    printf("\nWhich Room You Want To Delet?  Enter Room Number:  ");
    scanf("%d",&d7);
    rewind(bf);
    fread(&bk,sizeof(bk),1,bf);
     while(!feof(bf))
       {
	if(bk.rn==d7)
	 {
	  printf("\nRecord Deleted!\n");
	  flag1=1;
	 }
	 else
	  {
	fwrite(&bk,sizeof(bk),1,dp1);
	  }
     fread(&bk,sizeof(bk),1,bf);
	}
    fclose(bf);
    fclose(dp1);
    remove("book.dat");
    rename("delet1.dat","book.dat");
    if(flag1==0)
      {
       printf("File Does Not Existing!!!");
      }
   printf("\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
   int v0;
   scanf("%d",&v0);
   if(v0==0)
     {
      admin();
     }
   else
    {
     db_room();
    }
  }
		  ///////////
 void request()     /////////////COUSTOMER DETAILS////
   { system("CLS");//clrscr();
    int g;
  bf=fopen("book.dat","r");
  rewind(bf);
  fread(&bk,sizeof(bk),1,bf);
  while(!feof(bf))
    {
      printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
     printf("\n                     --  %s %s --\n",bk.fn,bk.ln);
     printf("\nBooked Room no      : => %d",bk.rn);
     printf("\nVillage Name        : => %s",bk.vill);
     printf("\nPost Office Name    : => %s",bk.po);
     printf("\nPolice Station Name : => %s",bk.ps);
     printf("\nDistrict Name       : => %s",bk.dist);
     printf("\nArea Pin Code       : => %s",bk.pin);
     printf("\nMobile Number       : => %s",bk.ph);
     printf("\nMAIL Id             : => %s",bk.mail);
     printf("\nAaddher Number      : => %s",bk.adr);
     printf("\nBooking Date        : => %s",bk.date);
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
    fread(&bk,sizeof(bk),1,bf);
    }
     fclose(bf);
     printf("\n\nPRESS '1' FOR CONFORM  =>          ");
       scanf("%d",&g);
     if(g==1)
	{
	 ggg();
	}
      else
       {
	request();
       }
   printf("\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
    int v3;
   scanf("%d",&v3);
    if(v3==0)
     {
      admin();
     }
    else
     {
     request();
     }
   }
void ggg()
 {
  system("CLS");//clrscr();
 }
////////////////////////////UPDATE/////////////////////////////////
void update()
  { system("CLS");//clrscr();
       char ch='Y';
    uf=fopen("features.dat","a");
    while(toupper(ch)=='Y')
      {
	printf("\nEnter room details as well as features\n");
	printf("Enter Room Floar                         =>  ");
	  scanf("%s",rd.floar);
    printf("Enter Room Number                      => ");
	 scanf("%d",&rd.r_no);
    fflush(stdin);
    printf("How Many Bed Available In This Room ?  => ");
	 scanf("%d",&rd.n_bed);
    fflush(stdin);
    printf("How Many AC or FAN In This Room ?      => ");
	scanf("%s",rd.n_f_ac);
    fflush(stdin);
    printf("How Many Window In This Room ?         => ");
	scanf("%d",&rd.window);
    fflush(stdin);
    printf("How Many Gate In This Room ?           => ");
	scanf("%d",&rd.gate);
    fflush(stdin);
    printf("Is Available Heater In The Room ?      => ");
       scanf("%s",rd.heater);
    fflush(stdin);
    printf("Is Available Toilet In The Room ?      => ");
       scanf("%s",rd.toilet);
       fflush(stdin);
       fwrite(&rd,sizeof(rd),1,uf);
       printf("                            Do You Want To Add More Room.....?\n                                    'YES or NO'");
       ch=getche();
       }
     fclose(uf);
     printf("\n\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
   int v4;
   scanf("%d",&v4);
   if(v4==0)
     {
      admin();
     }
   else
    {
     update();
    }
  }
//////////////////////////////////
void delet()
  { system("CLS");//clrscr();
    int de,flag=0;
    uf=fopen("features.dat","r");
    dp=fopen("delet.dat","w");
    printf("\nWhich Room You Want To Delet?  Enter Room Number:  ");
    scanf("%d",&de);
    rewind(uf);
    fread(&rd,sizeof(rd),1,uf);
      while(!feof(uf))
       {
	if(rd.r_no==de)
	 {
	  printf("\nRecord Deleted!\n");
	  flag=1;
	 }
	 else
	  {
	fwrite(&rd,sizeof(rd),1,dp);
	  }
	fread(&rd,sizeof(rd),1,uf);
       }
    fclose(uf);
    fclose(dp);
    remove("features.dat");
    rename("delet.dat","features.dat");
    if(flag==0)
      {
       printf("File Does Not Existing!!!");
      }
   printf("\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
   int v2;
   scanf("%d",&v2);
   if(v2==0)
     {
      admin();
     }
   else
    {
     delet();
    }
  }
 void view()
   { system("CLS");//clrscr();
    uf=fopen("features.dat","r");
    rewind(uf);
    fread(&rd,sizeof(rd),1,uf);
    printf("                            ------ROOM DETAILS------\n");
    printf("                                ~**************~        \n\n ");
    printf("FLOAR  *  R_NO  *  BED  *  FAN & AC   *  HEATER  *  WINDOW  *   GATE  *  TOILET\n");
    printf("--------------------------------------------------------------------------------\n");
    while(!feof(uf))
       {
    printf("%s         %d       %d       %s         %s        %d         %d        %s\n",rd.floar,rd.r_no,rd.n_bed,rd.n_f_ac,rd.heater,rd.window,rd.gate,rd.toilet);
       fread(&rd,sizeof(rd),1,uf);
       }
     fclose(uf);
 bf=fopen("book.dat","r");
  rewind(bf);
  fread(&bk,sizeof(bk),1,bf);
  while(!feof(bf))
    {
     printf("\nBooked Room no      : => %d",bk.rn);
   fread(&bk,sizeof(bk),1,bf);
    }
  fclose(bf);
      int v22;
  printf("\n\nEnter '0' For Back\n\n");
  scanf("%d",&v22);
   if(v22==0)
     {
      admin();
     }
   else
    {
     view();
    }
   }
void back()
  { system("CLS");//clrscr();
   main();
  }
	       /////////////service//////////////
void servic()
    { system("CLS");//clrscr(); 
    int v;
  printf("\n\n________________________________________________________________________________\n");
  printf("                     (1).CHEACK ABILITY            (2).BOOK ROOM\n");
  printf("\n                     (3).CHEACK RENT FOR ROOM        (4).BACK\n");
    while(1)
    {
       scanf("%d",&v);
      switch(v)
       {
      case 1: cheack();
		break;
      case 2: book();
		break;
      case 3: rent();
		break;
      case 4: Back();
		break;
      default: printf("Chose correct option....");
       }
     }
   }
		 ////
void cheack()
  { system("CLS");//clrscr();
      uf=fopen("features.dat","r");
    rewind(uf);
    fread(&rd,sizeof(rd),1,uf);
    printf("                            ------ROOM DETAILS------\n");
    printf("                                ~**************~        \n\n ");
    printf("FLOAR  *  R_NO  *  BED  *  FAN & AC   *  HEATER  *  WINDOW  *   GATE  *  TOILET\n");
    printf("--------------------------------------------------------------------------------\n");
    while(!feof(uf))
       {
    printf("%s         %d       %d       %s         %s        %d         %d        %s\n",rd.floar,rd.r_no,rd.n_bed,rd.n_f_ac,rd.heater,rd.window,rd.gate,rd.toilet);
       fread(&rd,sizeof(rd),1,uf);
       }
     fclose(uf);
  bf=fopen("book.dat","r");
  rewind(bf);
  fread(&bk,sizeof(bk),1,bf);
  while(!feof(bf))
    {
     printf("\nBooked Room no      : => %d",bk.rn);
   fread(&bk,sizeof(bk),1,bf);
    }
  fclose(bf);

    printf("\n\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
    int v5;
      scanf("%d",&v5);
   if(v5==0)
     {
      servic();
     }
   else
    {
     cheack();
    }
  }
     /////
void book()
  {  system("CLS");//clrscr();
  int re=599,re1;
   char ch='Y';
   bf=fopen("book.dat","a");
      while(toupper(ch)=='Y')
      {
     printf("Enter Room no                  : => ");
     scanf("%d",&bk.rn);
       fflush(stdin);
    uf=fopen("features.dat","r");
    rewind(uf);
    fread(&rd,sizeof(rd),1,uf);
    while(!feof(uf))
       {
	 if(bk.rn==rd.r_no)
	   {
     printf("Enter First Name               : => ");
     scanf("%s",bk.fn);
       fflush(stdin);
     printf("Enter Last Name                : => ");
     scanf("%s",bk.ln);
       fflush(stdin);
     printf("Enter Your Village Name        : => ");
     scanf("%s",bk.vill);
      fflush(stdin);
     printf("Enter Your Post Office Name    : => ");
     scanf("%s",bk.po);
      fflush(stdin);
     printf("Enter Your Police Station Name : => ");
     scanf("%s",bk.ps);
      fflush(stdin);
     printf("Enter Your District Name       : => ");
     scanf("%s",bk.dist);
      fflush(stdin);
     printf("Enter Your Area Pin Code       : => ");
     scanf("%s",bk.pin);
      fflush(stdin);
     printf("Enter Your Mobile Number       : => ");
     scanf("%s",bk.ph);
      fflush(stdin);
     printf("Enter Your MAIL Id             : => ");
     scanf("%s",bk.mail);
      fflush(stdin);
     printf("Enter Your Aaddher Number      : => ");
     scanf("%s",bk.adr);
      fflush(stdin);
     printf("How Many Days You Want To Book?: => ");
     scanf("%d",&bk.day);
      fflush(stdin);
     printf("Enter Booking Date             : => ");
     scanf("%s",bk.date);
      fflush(stdin);
     fwrite(&bk,sizeof(bk),1,bf);
    rewind(uf);
    fread(&rd,sizeof(rd),1,uf);
	   re1=bk.day*re;
       printf("\nYour Have To Pay Rs. %d \n\nPress Enter 3 Times For Payments\n",re1);
       getch();
       getch();
       getch();
       printf("\n                               Room Book Successfully\n\n");
       printf("                            Are You Want To Book More ROOM.....?\n                                    'YES or NO'");
	   }
	 else
	  {
	   printf("This Room is not Availabe Now\nPlease Cheack Ability First & Book again\n");
	   getch();
	   servic();
	  }
       fread(&rd,sizeof(rd),1,uf);
       }
     fclose(uf);
       ch=getche();
      }
    fclose(bf);
     printf("\n\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
    int v6;
    scanf("%d",&v6);
    if(v6==0)
     {
      servic();
     }
   else
    {
     book();
    }
  }
		     ///////
void rent()
  { system("CLS");//clrscr();
     printf("coming soon..............");
     printf("\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
     int v7;
   scanf("%d",&v7);
   if(v7==0)
     {
      servic();
     }
   else
    {
     rent();
    }
  }
		   /////////
void Back()
  { system("CLS");//clrscr();
      main();
  }
///////////////////////features////////////////////////////////////
  void features()
    { system("CLS");//clrscr();
     printf("coming soon .............");
      printf("\n                        *~~PRESS '0' TO BACK FROM HERE*~~\n");
       int v8;
     scanf("%d",&v8);
      if(v8==0)
       {
	main();
       }
     else
       {
	features();
       }
     }