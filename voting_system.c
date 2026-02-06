#include<stdio.h>
#include<string.h>
struct candidate{
	char name[20];
	int id;
	int votes;
};
void setup();
void vote();
void result();
struct candidate c[5];
int voted[100];
int vote_count=0;
int main(){
	int choice;
	setup();
	printf("____voting pole____\n");
	do{
		printf("1.cast vote\n 2.result\n 3.exit\n");
		printf("## enter your choice from given menu\n");
		scanf("%d",&choice);
	switch(choice){
		case 1: vote();
		break;
		case 2: 
		result();
		break;
		case 3: printf("____thank you for voting____\n");
		break;
		default: printf("** enter the valid choice\n");
	}
}
	while(choice!=3);
	return 0;
}
void setup(){
c[0].id=1;
c[1].id=2;
c[2].id=3;
c[3].id=4;
c[4].id=5;
strcpy(c[0].name,"Dhruv");
strcpy(c[1].name,"Rahul");
strcpy(c[2].name,"Sahil");
strcpy(c[3].name,"Deepanshu");
strcpy(c[4].name,"Mayank");
c[0].votes=c[1].votes=c[2].votes=0;
}
int i;
void vote(){
int voter_id;
int found=0; 
int choice;
printf("## enter your voter id card number\n");
scanf("%d",&voter_id);
for(i=0;i<vote_count;i++){
	if(voted[i]==voter_id){
		printf("** duplicate vote\n **");
		return ;
	}
}
for(i=0;i<5;i++){
	printf("\n %d. %s\n",c[i].id,c[i].name);
	
}
printf("## enter a number\n");
scanf("%d",&choice);
for(i=0;i<5;i++){
	if(c[i].id==choice){
		c[i].votes++;
		voted[vote_count++]=voter_id;
		found=1;
		break;
	}
} 
if(found==0){ 
printf("**--invalid candidate\n--**");
}
}
void result(){
	int i;
	for(i=0;i<5;i++){
		printf("%s ",c[i].name);
		printf("%d ",c[i].votes);
		printf("\n");
	}
}