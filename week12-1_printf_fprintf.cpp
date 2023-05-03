/// 要能夠寫檔案
#include <stdio.h>

int main()
{///檔案指標 fout = 開檔案("檔名","用甚麼程式");
    FILE * fout = fopen("file.txt","w");///w:write
    printf("Hello World\n");
    fprintf(fout,"Hello World在檔案裡\n");
}
