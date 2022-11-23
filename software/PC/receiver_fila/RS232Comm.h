#define BIT_RATE B9600

const char PORT1[] = "/dev/ttyUSB0";
const char PORT2[] = "/dev/ttyUSB0";

// Function prototypes  
int openPort(const char* port);
void configPort(int fd);
