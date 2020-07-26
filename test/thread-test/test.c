#include <stdio.h>
#include <stdlib.h>
#include <linux/delay.h>


int main(int argc,char *argv[])
{	
	printf("Enter main... argc:%d,first arg:%s.\n",argc,argv[0]);
	
	char words[]="first day!";
	printf("What do you want to say:%s\n",words);
	return 0;
}

