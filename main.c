#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int main() {
	int words = 0;//������
	int single = 0;//�ַ���
	FILE* file;//�ĵ�ָ��
	char buffer[MAX];//����ȡ�õ�MAX�ַ�
	int length = 0;//buffer��һ��ȡ�õ��ַ����� 
	 
	file = fopen("D:\\study\\wordcount\\words.txt", "r");//��ȡ�ļ���"r"��ֻ�� 
	if(file == NULL) {//�����ȡʧ�� 
		printf("cannot open!");
		return 0;
	} 
	while(!feof(file)){//feof�ж��Ƿ��ȡ���
	 	if(fgets(buffer, MAX, file) != NULL) {
	 		length = strlen(buffer);
			int i;
			for(i = 0; i < length - 1; i++) {//length-1ȥ������һ��λ�� 
				if(buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '.' || buffer[i] == '\n') {
					words++;
				}
				single++;
			}	
		}
	} 
	
	fclose(file);//�رյ�ǰ�ļ��� 
	printf("�ܵ�������%d\n", words);
	printf("���ַ�����%d", single);
} 
