#include <stdio.h>

int main(void){
	int ary[] = {8, 98 , 9, 29, 2, 3, 5, 0, 9};
	int *ary_ptr = &ary[0];
	int i;
	for(i=0;i<9;++i){ printf("%d\n",ary[i]);}
	
	printf("-----\n");
	for(i=0;i<9;++i){
		*ary_ptr = 0;
		++ary_ptr;
	}
	
	for(i=0;i<9;++i){ printf("%d\n",ary[i]);}

	return(0);
}
