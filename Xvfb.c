#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>

// memo
//uint32_t fb_size = 1024 * 768 * 4 + 0xa0 + (12 * 256)
float depth = 24.0; //1024 x 768 x "24"
int fb_size;

void* init_xvfb(){

	char *filename = "Xvfb_screen0";
	FILE *fp;

	if((fp = fopen(filename, "r"))==NULL){
		puts("open error");
		puts("please check if \"Xvfb_screen0\" exists in current directory");
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	fb_size = ftell(fp);
	fclose(fp);

	// mmap Xvfb framebuffer
	int fd;
	if((fd = open(filename, O_RDWR)) < 0){
		puts("open error");
		exit(0);
	}
	void *addr = mmap(NULL, fb_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);


	//https://samy.pl/packet/MISC/tru64/usr/include/X11/XWDFile.h
	//big endian...??
	uint8_t header_size = ((uint8_t*)addr)[3];

	// 256 ... 0x00 ~ 0xff
	uint32_t offset = header_size + 256 * (uint32_t)(16 * (depth/32.0));

	// fb1 is a start address of framebuffer
	uint8_t *fb1 = ((uint8_t*)addr + offset);

	return fb1;
}


