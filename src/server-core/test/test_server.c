//#include "../include/storage.h"
//#include "../include/server.h"
#include <stdio.h>
#include <unistd.h>

static int failures = 0;

static void test_server() {
	// test server()
	
}


int main(void) {
	test_server();

	if (failures > 0) {
	  fprintf(stderr, "\n%d test(s) failed.\n", failures);
	  return 1;
	}

	puts("\nAll test passed.");
	return 0;
}