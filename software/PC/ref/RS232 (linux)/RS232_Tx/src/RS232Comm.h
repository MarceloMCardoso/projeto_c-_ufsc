#define BIT_RATE B9600								// See Table 4 in Source 1 for options

const char PORT1[] = "/dev/ttyUSB0";  //COM6          //"/dev/ttyUSB0";				// determine the USB port names from terminal using $ dmesg | grep tty 
const char PORT2[] = "/dev/ttyUSB1";  //COM7          //"/dev/ttyUSB1";

// Function prototypes  
int openPort(const char* port);                     // Opens port and returns file descriptor 
void configPort(int fd);                            // Configures port settings
