#include<stdio.h>
#include <time.h>
int main(){
int pass,g=10;
char a,id;
printf("\t \t \t \t**Welcome to the Drug Test**\n ");
printf("\n");
printf("Please Enter User id\n");
scanf("%s",&a);
printf("Welcome,%s\n" );
time_t t;
    time(&t);
    printf("The login time is %s\n",ctime(&t));

	printf("\nInput the password: ");
	scanf("%d",&pass);

	if (pass==4431)
	{
		printf("Correct password");
    }
    else
    {
       printf("Incorrect password, try Agnain");
	}
	printf("\n");
   }





