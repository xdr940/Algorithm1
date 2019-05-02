#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h" 

void Save (R*head){
	
	printf("                  输入保存道路数量(1~60000)") ; 
	
	int number;
	
	int x;
	
	scanf(" %d",&number); 
 	
 	FILE *fp = fopen("new_roads.data","w");// 打算把输入信息保存在文件内，初步定为二进制 ，创建文件 
 	
 	while(x!=number){
 		
 		number=fwrite(head,sizeof(R),1,fp);  //写的内容就是aStu这个数组，每个结构的空间就是sizeof（stu），有number个，写到fp去 
 		
 		x++; 
 		
	 }
		fclose(fp);
	
		printf("                \n保存完成，文件名：new_roads.data\n") ; 
	
	
}
