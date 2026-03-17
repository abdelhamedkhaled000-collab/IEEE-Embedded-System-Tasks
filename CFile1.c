#include <stdio.h>
#include <avr/io.h>

unsigned char ToggleBit(unsigned char rege, int bit) {
	return rege ^ (1 << bit);
}

int main() {
	unsigned char my_port = 7;
	
	my_port = ToggleBit(my_port, 2);
	
	return 0;
}