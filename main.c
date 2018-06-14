#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>

extern int fb_size;

void* init_xvfb();

int main(){

	uint8_t *fb1 = (uint8_t*)init_xvfb();

	// draw test
	int i;
	for(i=0; i<0x5000; i++){
		fb1[i] = 0xff;
	}
	for(i=0x5000; i<0xa000; i++){
		fb1[i] = 0xaa;
	}
	for(i=0xa000; i<0xe000; i++){
		fb1[i] = 0x55;
	}


	munmap(fb1, fb_size);
}


