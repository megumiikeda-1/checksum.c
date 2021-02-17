/********************************/
/* Program Name: checksum       */
/* Author: Megumi Ikeda         */
/* Date: 2/15/21                */
/********************************/
/* Description:                 */
/* Validation Checks: all input values under max_int */
/* Enhancements: N/A            */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;
  byte checksum;
  byte complement;
  byte quotient;
  byte remainder;
  int checksum_value = 5;
  int retval;
  byte header[count];

  retval = read(STDIN_FILENO, (void *) &header, 10);

  for (int i = 0; i < count; i++) {
	  if (i > max_int) {
		  fprintf(stderr, "Error Detected!\n");
		  void exit(int status);
	  }
	  if (i == checksum_value) {
		  checksum = header[i];
		  header[i] = 0;
	  }
	  sum += header[i];
  }

  quotient = sum / (max_int + 1);
  remainder  = sum % (max_int + 1 );
  sum = quotient + remainder;
  complement = max_int - sum;

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n");
    return 1;
  }
  return 0;
}
