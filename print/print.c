/*********************************************
 * Program: Print
 *
 * Purpose:
 * 		Output files formated
 *
 * Usage: 
 * 		print [options] file(s)
 *
 * Options:
 * 		-v			verbose mode
 * 		-o<file>	Output to a file
 * 					(Defualt=print.out)
 * 		-l<lines>	Specify lines/pages
 * 					(Default=66).
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int verbose = 0;
char *out_file = "print.out";
char *program_name;	/* For error */
int line_max = 66;

/*********************************************
 * do_file	-- Dummy routine for file
 *
 * Parameter
 * 	   name	-- Output filename
 *********************************************/
void do_file(char *name)
{
	printf("Verbose %d Lines %d Input %s Output %s\n",
		verbose, line_max, name, out_file);
}
/*********************************************
 * usage	-- Output program usage to user,
 * 			   and exit program.
 *********************************************/
void usage(void)
{
	fprintf(stderr, "Usage is %s [options] [file-list]\n",
			program_name);
	fprintf(stderr, "	-v			verbose\n");
	fprintf(stderr, "	-l<number>	Number of lines\n");
	fprintf(stderr, "	-o<name>	Set output filename\n");
	exit(8);
}

int main(int argc, char *argv[])
{
	/* Save the program name to use after */
	program_name = argv[0];

	/*
	 *	Loop for some options:
	 *		when all arguments are processed, 
	 *		or there are arguments without hyphen,
	 *		loop will break.
	 */

	while ((argc > 1) && (argv[1][0] == '-')){
		/*
		 *	argv[1][1] is letter of options
		 */
		switch (argv[1][1]){
			/*
			 * -v verbose mode
			 */
			case 'v':
				verbose = 1;
				break;
			/*
			 * -o<name> output file
			 *  [0] is hyphen
			 *  [1] is "o"
			 *  from [2] row names.
			 */
			case 'o':
				line_max = atoi(&argv[1][2]);
				break;
			/*
			 * -l<number>	specify max lines
			 */
			case 'l':
				line_max = atoi(&argv[1][2]);
				break;
			default:
				fprintf(stderr, "Bad option %s\n", argv[1]);
				usage();
		}
		/*
		 * move next argument
		 * minus 1
		 */
		++argv;
		--argc;
	}
	
	if (argc == 1){
		do_file("print.in");
	}else{
		while (argc > 1){
			do_file(argv[1]);
			++argv;
			--argc;
		}
	}
	return(0);
}
