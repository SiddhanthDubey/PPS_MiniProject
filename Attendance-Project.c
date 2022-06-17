/**
 * Title		:	Attendance Management System using C file Handling and pointers
 * Author		:	Siddhanth
 * Date			:	03-06-2022
 */
#include<stdio.h> 						//using also to remove files
#include<string.h> 					 	//using to compare strings and concating
#include<time.h>  						//using to generate time
#include<conio.h>						//using to make the screen hold
#include<dirent.h>  					//using for directory
#define esc 27
#define EOL '\n'

int main()
{
	int x=00,y=00;   					//initializing variables for counter
	char id_ag[]="RA2111003010022";			//faculties id

	char pw_ag[]="ss";					//faculties pass

	char subjcode1[]="18PYB";			//subject code

	char subjc1[100];					//taking subject code from user

	char temp_id[9];					//accepting id and pass from users
	char temp_pw[10];

	char chx;
	x1:printf("Enter  Your Credentials\n");
	printf("Login ID =>");
	scanf("%s",temp_id);
	printf("Password =>");
	scanf("%s",temp_pw);

	char ch,ch2,ch3,ch4,ch5,ch6,ch7,ch8,l1;				//assigning the character value to these variables that getch() is returning

	FILE *fp2;											//Creating a file structure pointer

	int a=(strcmp(id_ag,temp_id));						//Comparing two strings id
	if(a==0)											//if returning true
	{

		int p1=(strcmp(pw_ag,temp_pw));					//comparing two strings password
		if(p1==0)										//if returning true
		{
			printf("\nWelcome Siddhanth!!!\n");
			label2:printf("\nPress q to search for records\nPress n to create new record\nPress z to delete any records\nPress x to Logout\n");
			label1:ch2=getch();
			if (ch2=='q')					//if user enters q i.e. for reading
			do{
			{

				DIR *d;
				struct dirent *dir;
				d=opendir("..//DSUMini/Faculty/Sidhanth/");		//opening directory of speicified path
				if(d)
				{
					printf("\nTotal records In ur Database are as follows\n");
					while((dir=readdir(d))!=NULL)
					{
						printf("%s\n", dir->d_name);			//displaying each files present in that directory
					}
					closedir(d);
				}
				char filename[50];
				char c1[]="..//DSUMini/Faculty/Siddhanth/";				//path of the faculty database

				printf("\nEnter the date and time in the following format DD-MM-YYYY-HH-AM/PM\nExample: 21-08-2017-08-AM To open any specific records\n");

				scanf("%s",filename);									//time and date
				strcat(c1,filename);									//concat path and time and date and storing in c1
				char c2[]=".txt";
				strcat(c1,c2);											//concat c1 with .txt and storing in c1

				fp2=fopen(c1,"r");										//opening file in read mode

					if(fp2==NULL)
					{
					printf("\nNo such records found plz try again\npress b to go back or any key to contiue\n");	//if no records found
					ch7=getch();
					if(ch7=='b')
					{
						goto label2;									//when pressed b going back to main menu
					}
					}

				else
				{
					ch2=fgetc(fp2);										//when file found and reading full files
					while(ch2!=EOF)
					{
                            putchar(ch2);						//same as printf function
							ch2=fgetc(fp2);


					}
					fclose(fp2);
					label3:printf("\nPress b to go back to main menu or press e to Logout\n");
				ch3=getch();
				if(ch3=='b')
				{
					goto label2;			//going back to main menu when pressed b
				}
				else if(ch3=='e')
				{
					goto x1;				//if pressed e then logout going back to login credential phase
				}
				else
				{
					printf("\nPlease select only above mentioned option\n");
					goto label3;				//if any unwanted key pressed again repeating procedure from asking user to press b or e
				}

				}

			}
		}while(fp2==NULL);
			else if(ch2=='n')
			{
			//if user is creating a new record
			label81:printf("\nEnter the COURSECODE (ALL In Caps)\n");
			scanf("%s",subjc1);			//accepting coursecode

			int c=(strcmp(subjcode1,subjc1));		//comparing user course code with valid course code
			if(c==0)								//if returns true
			{
			time_t raw;
			labelitr:time(&raw);

			struct tm *time_ptr;
			time_ptr=localtime(&raw);				//declaring and using structure of time

			char date[50];
			strftime(date,50,"%d-%m-%Y-%I-%M-%S-%p",time_ptr);		//formatting the time and storing in an array with cuurent date,month,year,hour(24 hour format),minutes,seconds,am/pm
			char date11[50];
			strftime(date11,50,"%d-%m-%Y-%I-%p",time_ptr);			//formatting the time and storing in an array with cuurent date,month,year,hour(24 hour format),am/pm
			char date1[50];
			strftime(date1,50,"%d-%m-%Y",time_ptr);					//formatting the time and storing in an array with cuurent date,month,year
			char time1[50];
			strftime(time1,50,"%I:%M:%p",time_ptr);					//formatting the time and storing in an array with cuurent hour(24 hour format),minutes,seconds,am/pm
			char d1[]="..//DSUMini/Faculty/Siddhanth/temp";			//path of temporary directory
			char c1[]="..//DSUMini/Faculty/Siddhanth/temp/";			//path of temporary directory to access that file
			char c11[]="..//DSUMini/Faculty/Siddhanth/";				//path of database
			strcat(c1,date);										//concatinating temporary dir path with the first strftime
			strcat(c11,date11);										//concat permanent database path with 2nd strftime
			//puts(c1);
			char c2[]=".txt";
			char c22[]=".txt";
			strcat(c1,c2);
			strcat(c11,c22);										//concat with the above mentioned path with .txt to get complete .txt file
			//puts(c1);

			char p;
			char present[]="\tPresent";
			char absent[]="\tAbsent";								//declaring string with empty array for present and absent


			FILE *fp1;
			fp1=fopen("..//DSUMini/Stud_Db.txt","r");				//creating a file ptr and opening the specified path file in read mode


			mkdir(d1);												//making a temp directory

			FILE *fp;
			fp=fopen(c1,"a+");									//making a file ptr and opening a temp file with read and append mode
			ch=fgetc(fp1);


			fprintf(fp,"Subject-Name=SOMETHING\t\tCOURSECODE=%s\tSubject-Incharge=Siddhanth\n",subjc1);

			printf("\nPress p for present and a for absent\n");
			while(ch!=EOF)
			{
					if(ch==EOL)
					do
					{
					p=getch();
					}while(p!='p'&&p!='a');


					if(p=='p')
					{
					while(ch!=EOF)
					{
						if(ch==EOL)
						x++;
						if(ch==EOL)
						fprintf(fp,"\t\t%s",present);
						if(ch==EOL)
						printf(present);
						break;
					}
					}
					else if(p=='a')
					{
					while(ch!=EOF)
					{
						if(ch==EOL)
						y++;
						if(ch==EOL)
						fprintf(fp,"\t\t%s",absent);
						if(ch==EOL)
						printf(absent);
						break;
					}
					}
					fputc(ch, fp);

						putchar(ch);
					ch = fgetc(fp1);

			}

			printf("\nTotal number of student Present\t%d\ton %s at %s",x,date1,time1);
			printf("\nTotal number of student Absent \t%d\ton %s at %s",y,date1,time1);
			fprintf(fp,"\nTotal number of student Present\t%d\ton %s at %s",x,date1,time1);
			fprintf(fp,"\nTotal number of student Absent \t%d\ton %s at %s",y,date1,time1);

			x=00,y=00;
			fclose(fp);
			fclose(fp1);
			labelitrl1:printf("\nPress y to commit or n to update the record\n");
			l1=getch();
			if(l1=='y')
			{
			fp=fopen(c1,"r");
			FILE *fp5;
			fp5=fopen(c11,"w");
			ch=fgetc(fp);
			while(ch!=EOF)
			{
				fputc(ch,fp5);
				ch=fgetc(fp);
			}
			fclose(fp);
			fclose(fp5);
			remove(c1);
			}
			else if(l1=='n')
			{
				remove(c1);
				goto labelitr;
			}
			else
			{
				printf("\nPlease select only above mentioned option\n");
					goto labelitrl1;
			}
				rmdir(d1);
				label4:printf("\nPress b to go back to main menu or press e to Logout\n");
				ch4=getch();
				if(ch4=='b')
				{
					goto label2;
				}
				else if(ch4=='e')
				{
					goto x1;
				}
				else
				{
					printf("\nPlease select only above mentioned option\n");
					goto label4;
				}
			}
			else
			{
				printf("Invalid Subject Code , plz enter subject code in caps\n or it may be possible the subject is taken by other faculty\nTry Again");
				goto label81;
			}

		}
			else if(ch2=='z')
			{

				do{
				DIR *d;
				struct dirent *dir;
				d=opendir("..//DSUMini/Faculty/Siddhanth/");
				if(d)
				{
					printf("\nTotal records are in ur database\n");
					while((dir=readdir(d))!=NULL)
					{
						printf("%s\n", dir->d_name);
					}
					closedir(d);

				}
				char filename[50];
				int f;
				char c1[]="..//DSUMini/Faculty/Siddhanth/";
				printf("\nEnter the date and time in the following format DD-MM-YYYY-HH-AM/PM\nExample: 21-08-2017-08-AM To delete any specific records\n");
				scanf("%s",filename);
				strcat(c1,filename);
				char c2[]=".txt";
				strcat(c1,c2);
				strcat(filename,c2);
				FILE *fp2;
				fp2=fopen(c1,"r");

				if(fp2==NULL)
				{
					printf("\nNo such records found plz try again\npress b to go back or any key to contiue\n");
					ch6=getch();
					if(ch6=='b')
					{
						goto label2;
					}
				}
			fclose(fp2);

			if(fp2!=NULL)
			{
			printf("Are You Sure You really want to delete %s \nRecord/File From the database",filename);
				label5:printf("\nThe recovery isn't possible after deletion Press y to confirm or b to go back ");
				ch5=getch();
				if(ch5=='y')
				{
				f=remove(c1);

				if(f==0)
				{
					printf("\n%s Record/File deted successfully\npress b to go back or press any key to continue",filename);
					ch8=getch();
					if(ch8=='b')
					{
						goto label2;
					}
				}
				else
				{
					printf("Unable to delete file");
					perror("Error");
				}



				}


			else
			{
				if(ch5=='b')
				{
					goto label2;
				}
				else
				{
					printf("\nPlease select only above mentioned option\n");
					goto label5;
				}


			}
			}

			}while(fp2!=NULL);
			}

			else if(ch2=='x')
			{
				goto x1;
			}

			else
			{
				printf("\nPlease select only the above option mentioned\n");
				goto label1;
			}

		}

		else
		{
			printf("\nInvalid Password\nPress Escape to exit\nPress any key to try again\n");
			chx=getch();
			if(chx==esc)
			{
				return 0;
			}
			else
			{
				goto x1;
			}
		}
	}

			}
