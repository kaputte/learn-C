#include <stdio.h>
#include <stdlib.h>

int main()
{
	char			name[100];	/* 使用するファイルの名前 */
	FILE			*in_file;	/* 入力用のファイル */

	printf("Name? ");
	fgets(name, sizeof(name), stdin);

	in_file = fopen(name, "r");
	if (in_file == NULL){
		fprintf(stderr, "Could not open file\n");
		exit(8);
	}
	printf("File found\n");
	fclose(in_file);
	return(0);
}
