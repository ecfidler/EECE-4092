#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

unsigned int address; //32-bit
int pageNumber;
int offset;

int main(int argc, char *argv[])
{

	if (argc != 2) {
		printf("Incorrect number of parameters");
		return -1;
	}

	address = strtoul(argv[1], NULL, 10); //string to unsigned int

    if (address == 0) {
        printf("invalid address: 0 or non-integer");
		return -1;
    }

    printf("The address %i contains:",address); //prints address

	
}

// input 32-bit virtual address with a 4-KB page size.
// output the page number and offset for the given address.

// example:
// ./a.out 19986
// Your program would output:
// The address 19986 contains:
// page number = 4
// offset = 3602
