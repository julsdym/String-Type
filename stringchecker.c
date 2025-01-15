#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * check to see if an IEEE 754 string
 * is normalized, denormalized, or is a special case. 
 */
int main(int argc, char** argv){
	if(argc != 2 ){
		printf("invalid format\n");
		return EXIT_FAILURE;
	}
	int test=0;
	char* number = argv[1];
	st:
	if(number[test]==NULL) goto next;
	if(number[test] != '0' && number[test] != '1'){
	printf("invalid format\n");
		return EXIT_FAILURE;
	}
	test++;
	goto st;
	
	next:
	int length = strlen(argv[1]);
	
	if(length!= 16){
		printf("must be 16 bits\n");
		return EXIT_FAILURE;
	}
	
	
	unsigned long int ie = strtoul(number, NULL, 2);
	unsigned int exp = (ie >> 10) & 0x1F; //5 bits
	unsigned int frac = ie & 0x3FF; //10 bits 

	
	if(exp==0){
		if(frac ==0) goto denormalized;
		goto special;
	}
	if(exp==31){
		goto special;
	}
	
	normalized:
	printf( "This value is normalized\n");
	goto end;
	
	denormalized:
	printf( "This value is denormalized\n");
	goto end;
	
	special:
	printf( "This value is a special case\n");
	goto end;
	
	end:
return EXIT_SUCCESS;
}
