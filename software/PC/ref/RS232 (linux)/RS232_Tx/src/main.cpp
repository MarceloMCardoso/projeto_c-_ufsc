#include <stdio.h>		
#include <string.h>
#include <unistd.h>		// Unix standard functions
#include <fcntl.h>		// File control funcitons
#include <errno.h>		// Error number definitions
#include <termios.h>	// POSIX terminal control definitions
#include "RS232Comm.h"

int main() {
	int fd1; 										// file descriptor
	int written;									// Bytes written to Tx port
	char message[] = "This is a test message\r";	// Test message - must end in \r (return)
	int messageSize = strlen(message);				// Test message size
	
	// Open and configure port
	fd1 = openPort(PORT1);							// Port to write to (Tx)
	configPort(fd1);								// Apply settings
	
	// Write data to a Tx port
	written = write(fd1, message, messageSize);
	if (written < 0) {
		fputs("write() of bytes failed!\n", stderr); 
	}
	printf("\nTotal message size: %d\n", messageSize);
	printf("\nTotal bytes written: %d\n", written);

	// give time to send before closing the port
	sleep(3);		// Wait before closing

	// Close the port(s)
	close(fd1); 
	return(0);
}
