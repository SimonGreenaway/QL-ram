#include <stdio.h>
#include <stdlib.h>

#define SIZE 4096

#define FRAMES ((unsigned short *)163886)

char d[SIZE];

unsigned int test(char *m)
{
	unsigned short t=*FRAMES;
	unsigned int i,j;

	for(i=0;i<1000;i++)
	{
		//memcpy(m,m+SIZE/2,SIZE/2);
		bzero(m,SIZE);
	}

	return *FRAMES-t;

}

int main(int argc,char *argv)
{
	unsigned int j;
	unsigned char i[SIZE];
	static char z[SIZE];

	FILE *f=fopen("flp1_ram_out","w");

	printf("test function at %d\n",(unsigned int)test);
	fprintf(f,"test function at %d\n",(unsigned int)test);
	printf("main function at %d\n",(unsigned int)main);
	fprintf(f,"main function at %d\n",(unsigned int)main);
	printf("local var\t%d\t%c %d\n",(unsigned int)&i,&i>=65536*4?'H':'L',test(&i));
	fprintf(f,"local var\t%d\t%c %d\n",(unsigned int)&i,&i>=65536*4?'H':'L',test(&i));
	printf("static var\t%d\t%c %d\n",(unsigned int)&z,&z>=65536*4?'H':'L',test(&z));
	fprintf(f,"static var\t%d\t%c %d\n",(unsigned int)&z,&z>=65536*4?'H':'L',test(&z));
	fprintf(f,"global var\t%d\t%c %d\n",(unsigned int)&d,&d>=65536*4?'H':'L',test(&d));

	for(j=0;j<1024;j++)
	{
		unsigned int t;
		char *mem=(char *)malloc(SIZE);

		if(mem==NULL) break;

		t=test(mem);

		printf("%d\t%d\t%c %d\n",j,(unsigned int)mem,mem>=65536*4?'H':'L',t);
		fprintf(f,"%d\t%d\t%c %d\n",j,(unsigned int)mem,mem>=65536*4?'H':'L',t);
	}

	fclose(f);
}
