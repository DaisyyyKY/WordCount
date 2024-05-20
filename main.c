#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int main() {
	int words = 0;//单词数
	int single = 0;//字符数
	FILE* file;//文档指针
	char buffer[MAX];//缓存取得的MAX字符
	int length = 0;//buffer中一次取得的字符长度 
	 
	file = fopen("D:\\study\\wordcount\\words.txt", "r");//读取文件，"r"：只读 
	if(file == NULL) {//如果读取失败 
		printf("cannot open!");
		return 0;
	} 
	while(!feof(file)){//feof判断是否读取完毕
	 	if(fgets(buffer, MAX, file) != NULL) {
	 		length = strlen(buffer);
			int i;
			for(i = 0; i < length - 1; i++) {//length-1去掉最后的一个位置 
				if(buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '.' || buffer[i] == '\n') {
					words++;
				}
				single++;
			}	
		}
	} 
	
	fclose(file);//关闭当前文件流 
	printf("总单词数：%d\n", words);
	printf("总字符数：%d", single);
} 
