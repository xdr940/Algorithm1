#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h" 

void Save (R*head){
	
	printf("                  ���뱣���·����(1~60000)") ; 
	
	int number;
	
	int x;
	
	scanf(" %d",&number); 
 	
 	FILE *fp = fopen("new_roads.data","w");// �����������Ϣ�������ļ��ڣ�������Ϊ������ �������ļ� 
 	
 	while(x!=number){
 		
 		number=fwrite(head,sizeof(R),1,fp);  //д�����ݾ���aStu������飬ÿ���ṹ�Ŀռ����sizeof��stu������number����д��fpȥ 
 		
 		x++; 
 		
	 }
		fclose(fp);
	
		printf("                \n������ɣ��ļ�����new_roads.data\n") ; 
	
	
}
