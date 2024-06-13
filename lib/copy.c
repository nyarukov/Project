#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    if (argc!=3)
    {
        printf("./x.exe\t <form> <to>\r\n");
    }
    FILE *fp1 = fopen(argv[1],"r");
    if(fp1==NULL){
        exit(1);
    }
    FILE *fp2 = fopen(argv[2],"w");
    if(fp2==NULL){
        exit(2);
    }
    char fbuffer[1024]={0};
    size_t size;
    while (1)
    {
        size=fread(fbuffer,1,sizeof(fbuffer)-1,fp1);
        if(size>0){
            fwrite(fbuffer,1,size,fp2);
            continue;
        }
        break;
    }
    
    return 0;
}