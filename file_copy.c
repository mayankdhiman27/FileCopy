#include<stdio.h>
#include<stdlib.h>
//Function cat, which concatenates the file chars to stdout
void cat(FILE * fp3,FILE *fp4){
int c;
while((c=getc(fp3))!=EOF){
putc(c,fp4);
}
}

//driver code
int main(int argc,char *argv[]){
FILE *fp,*fp1;
char *p=argv[0];
if(argc==1){			//no agruments
//cat(stdin,stdout);
printf("Please retry with proper filename");
}
else{
while(--argc>0){
if((fp=fopen(*++argv,"rb"))==NULL){
fprintf(stderr,"%s: Can't open file %s\n",p,*argv);		//stderr file contains error for stdout. first %s points to program file and later one 									//points to argv[1],i.e input file
exit(1);
}
else{
fp1=fopen("/home/dmayank/Documents/client/abc.c","wb");
cat(fp,fp1);
fclose(fp);
}
}
}
exit(0);
}
