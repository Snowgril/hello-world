#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------*/
/*                      二进制文件的读操作                       */
/*---------------------------------------------------------------*/

int main(int argc,char* argv[])
{
    FILE* fid;
    unsigned long count=0;
    char buff[25];       //接收字符的缓冲区
    if(argc != 2)       //没有带参数运行程序或者带一个以上参数运行程序
    {
        printf("Usage: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fid = fopen(argv[1],"r")) == NULL)
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(fid,0,SEEK_SET);  //将文件的位置指示符移动到文件开始处
    fread(buff,1,25,fid);    //从fid中读取4个元素，每个元素占一个字节，保存到buff中
    while(count<25)
        {
        printf("%x ",buff[count]);
        count++;
        }
    fclose(fid);
    printf("\n");
    return 0;
}
