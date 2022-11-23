#include <stdio.h>		
#include <string.h>
#include <unistd.h>		// Unix standard functions
#include <fcntl.h>		// File control funcitons
#include <errno.h>		// Error number definitions
#include <termios.h>	// POSIX terminal control definitions
#include "RS232Comm.h"

int main() {
	int fd2; 										// file descriptors 
	int readin, readinTot = 0;						// Bytes read from Rx port
	char buffer[140];								// read buffer
	char* bufptr;									// buffer ponter
	while(1){
	// Open and configure ports
	fd2 = openPort(PORT2);							// Port to read from (Rx)
	configPort(fd2);								// Apply settings

	// Read data from Rx port
	bufptr = buffer; 
	// Read characters into our string buffer until get a carriage return \r or new line \n
	while((readin = read(fd2, bufptr, buffer + sizeof(buffer) - bufptr - 1)) > 0) {
		bufptr += readin;
		readinTot += readin;
		if (bufptr[-1] == '\n' || bufptr[-1] == '\r') break;
	} 
	*bufptr = '\0';		// Null terminate the string so we can printf() it

	printf("\nTotal bytes read: %d\n", readinTot);
	printf("\nReceived message: %s\n", buffer);
	}
	// Close the port(s) 
	close(fd2);
	return(0);
}
