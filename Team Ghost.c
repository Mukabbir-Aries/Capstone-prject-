#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dirent.h>
//Mukabbir//
struct dirent* entity;
struct user {
    char email[50];
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50],email[50];
	FILE *fp,*fptr;
	int opt,choice,opt2;
	int pass;
	float amount,anc;
	char cont = 'y';

	        printf("\t \t \t \t**Welcome to the Ancient Crypto**\n ");
            printf("\n");
            printf("Warning !!!!!  \tThis page is Coder Protected press that password to continue\n");
            printf("\nInput the password: ");
            scanf("%d",&pass);
    {
     	                     if (pass==2424)
	                  {
		              printf("Correct password,\n");
		              printf("\t  \t \t \t  **Welcome,Team Ghost**\n");

                      }
                       else
                        {
                       printf("Password incorrect Restart the Program\n");
                       _Exit(0);


    }


time_t t;
    time(&t);
    printf("The login time is %s\n",ctime(&t));
	printf("\nPlease Check List As You Desired");
	printf("\n\n1.Register your account");
	printf("\n2.Login to your account");
	printf("\n3.Account List of Anc\n");
	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt==3){
	printf("All file's Are\n");
                 DIR *d;
         struct dirent *dir;
         d = opendir(".");
     {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name );
    }
    closedir(d);
    }
	}
	 else if(opt == 1){
		printf("\nEnter your ANC User Id:\t");
		scanf("%s",user.ac);
		printf("Enter your Email:\t");
		scanf("%s",user.email);
		printf("Enter your New Password:\t");
		scanf("%s",user.password);
		user.balance=0;
		stpcpy(filename,user.email);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered ANC Account\n");
		}
	}
	else if(opt == 2){
		printf("\nEmail.:\t");
		scanf("%s",email);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(email,".dat"),"r");
		if(fp == NULL)
            printf("Email Not Registered Yet In Anc");

		else{
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				printf("\n\tWelcome %s\n",user.email);
				time_t t;
                time(&t);
                printf("The login time is %s\n",ctime(&t));
				printf("\n1.Anc Dashboard");
				printf("\n2.Invest");
				printf("\n3.Anc withdraw");
				printf("\n4.Transfer Anc To  Anc User");
				printf("\n5.Changing password Of Anc");
				printf("\n6.Transfer money in Bkash\n\n");
                scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your current Balance is in %.1f taka\n",user.balance);
						printf("Your Current Balance is %.2f ANC\n",user.balance/100);
						break;

					case 2:
						printf("Enter Amount to Invest:\t");
						scanf("%f",&amount);
						user.balance += amount;
						user.balance=amount;
						fp = fopen(email,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0)
                                                printf("\n\nYou have Invested taka.%.2f\n",amount);
						printf("In The amount is %.2f Anc\n",amount/100);
						fclose(fp);
						break;


					case 3:
						printf("Enter withdraw amount Must Be in Anc:\t");
						scanf("%f",&amount);
						if(amount*100>user.balance)
                                                printf("\nSorry insufficeint Anc");
						else {
                                                user.balance -= amount*100;
						fp = fopen(email,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0)
                                                printf("\n\nYou have withdrawn %.1f Anc",amount);
                                                printf("\n\nYou have withdrawn %.1f taka\n",amount*100);
						fclose(fp);
						}
						break;

					case 4:
						printf("Please enter the Email to trasnfer balance:\t");
						scanf("%s",email);
						printf("Enter the amount to transfer in Anc:\t");
						scanf("%f",&amount);
						if(amount*100 > user.balance)
                                                printf("\nSorry insufficent Ancient Coin");
						else {
							fptr = fopen(strcat(email,".dat"),"r");
							if(fptr==NULL) printf("Sorry this email is not registered yet in Anc Server");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);

								usr.balance += amount*100;

								fptr = fopen(email,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
								    printf("Loading......Please Wait\n");
                                                                    printf("Your trasfer is completed. You have trasnfered %.1f Anc to %s \n",amount,usr.email);
									printf("Your have transfered %.1f Taka to %s \n",amount*100,usr.email);
									fclose(fptr);
									user.balance -= amount*100;
									strcpy(filename,user.email);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.email);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");

					case 6 :
					    printf("Welcome to Bkash Withdraw\n");
                                            printf("Please enter the Bkash Number to trasnfer balance:\t");
						scanf("%s",phone);
						printf("Please Type Your Email to Confirm\n");
						scanf("%s",email);
						printf("Enter the amount to transfer in Taka:\t");
						scanf("%f",&amount);
						if(amount > user.balance)
                                           printf("\nSorry insufficent balance");
						 {
							fptr = fopen(strcat(email,".dat"),"r");
							if(fptr==NULL) printf("Sorry this email is not registered yet in Anc Server");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);

								usr.balance += amount;

								fptr = fopen(phone,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
								    printf("Loading......Please Wait\n");
                                          printf("Your trasfer is completed. You have trasnfered %.1f taka\n",amount,usr.email);
									fclose(fptr);
									user.balance -= amount-20;
									strcpy(filename,user.email);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;

				}
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
				}

			else {
				printf("Invalid password");
			}
		}
		printf("\n\n***Thank you for Being with Ancient Crypto***\n\n");
	}

	return 0;
}
}

