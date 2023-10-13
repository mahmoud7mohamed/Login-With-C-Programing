
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BACKSPACE 8

struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
};

void takeInput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0; 
}

char generateUsername(char email[50],char username[50]){
	//abc123@gmail.com   ->>  abc123
    for(int i=0; i<strlen(email); i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

void takePassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BACKSPACE){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}


int main(){
	system("color 0b"); // color off the background and font color 
	FILE *fp;
	int opt,usrFound = 0;
	struct user user;
	char password2[50];
	
    char username[50],pword[50];
    struct user usr;

	printf("\n\t\t\t\t----------Welcome to authentication system---------");
	printf("\nPlease choose number of operation");
	printf("\n>> 1.Signup");
	printf("\n>> 2.Login");
	printf("\n>> 3.Exit");
	
	printf("\n\nYour choice:\t");
	scanf("%d", &opt);
	fgetc(stdin);
	
	switch(opt){
		case 1:
			system("cls");
			printf("\nEnter your full name:\t");
			takeInput(user.fullName);
			printf("Enter your email:\t");
			takeInput(user.email);
			printf("Enter your contact no:\t");
			takeInput(user.phone);
			printf("Enter your password:\t");
			takePassword(user.password);
			printf("\nConfirm your password:\t");
			takePassword(password2);
			
			if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0) printf("\n\nUser registration success, Your username is %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nPassword do not matched");
				Beep(750,300);
			}
		break;
		
		case 2:
			printf("\nEnter your username:\t");
			takeInput(username);
			printf("Enter your password:\t");
			takePassword(pword);
			
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){
						system("cls");
						printf("\n\t\t\t\t\t\tWelcome %s",usr.fullName);
						printf("\n\n|Full Name:\t%s",usr.fullName);
						printf("\n|Email:\t\t%s",usr.email);
						printf("\n|Username:\t%s",usr.username);
						printf("\n|Contact no.:\t%s",usr.phone);	
					}
					else {
						printf("\n\nInvalid Password!");
						Beep(800,300);
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			break;
			
		case 3:
			printf("\t\t\t( Bye Bye )");
			return 0;		
	}
	
	return 0;
}

