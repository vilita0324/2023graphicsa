/// �n����g�ɮ�
#include <stdio.h>

int main()
{///�ɮ׫��� fout = �}�ɮ�("�ɦW","�άƻ�{��");
    FILE * fout = fopen("file.txt","w");///w:write
    printf("Hello World\n");
    fprintf(fout,"Hello World�b�ɮ׸�\n");
}
