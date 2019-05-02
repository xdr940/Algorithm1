#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"
 


 R* Read(R*head){
	FILE *fp;
	


	if((fp=fopen("GTBL.dat","rb"))==NULL){
		printf("can't open file");
		exit(1);
	}
   	
	   
	 char road[50];
  	 char temp_name[50];
  	 
  	 int id_temp; 
  	 
  	 char trans[50];
  	 
  	 int size;
  	 int name_size;
  	 
  	 
  	 	
  	   short *p;
  	   int   *q;
  	   
	   int j=0;
	   int i=0; 
	   
	   
  	
  	int x=0x80;
  	
  	int y=0x70;   /*第四部分提前定义需要的常量*/
  
  	int z=0x0f;
  	
  	
  	char temp_roadnameflag;
  	char temp_brunch;
  	char temp_dispclass;
	  
	   
 
	R* pnew=NULL;
	R* prear=NULL;
	
    while(!feof(fp)){
    	
    	fread(&road,sizeof(char)*2,1,fp);
		 
		    	{/*一部分 总 size*/
					trans[0]=road[1];
					trans[1]=road[0];
					 
					p=(short*)&trans[0] ;
			
				              	size=*p;
				}	
    	
		fread(&road,sizeof(char)*(size-2),1,fp);
			 
			 	{/*二部分 id号*/ 
	
			trans[0]=road[5-2];
			trans[1]=road[4-2];
			trans[2]=road[3-2];
			trans[3]=road[2-2];
				
			q=(int*)trans;
		              	id_temp=*q;
	
			}		
	
		
		
	
	
		
	
		{/*三部分  路名字 size*/ 
			trans[0]=road[7-2];
			trans[1]=road[6-2];
		
		
	           	p=(short *)trans;
		
		            name_size=*p;
		
			
			
     	  }              	
		
		
		{
		/*四部分 道路信息情报*/ 
		temp_roadnameflag=(x&road[11])>>7;
	   
		
		temp_brunch=(y&road[11-2])>>4;
	

	    temp_dispclass=z&road[11-2];
	
		

		} 
		
		
		
		
		
		
		{/*五部分 路名字*/ 
			
			
			
		for(i=0,j=16-2;j<size;i++,j++){
			
			
			temp_name[i]=road[j];
			
		}
			
				
			
		}
		
		
			
			
	/*------------------------------------把信息传到链表去-----------------------------*/
			
 
			
	         /*结点生成部分*/
		
		pnew=(R*)malloc(sizeof(R));/* 生成结点，再让p指向他*/
		
	
		
		pnew->linkid=id_temp; 	/*一。道路id 赋值*/
		 
	
	    pnew->roadnameflag= temp_roadnameflag;
	
		pnew->brunch=temp_brunch;              /*第二三四部分的道路信息*/
		
		pnew->dispclass=temp_dispclass;
	
		
		for(i=0,j=0;j<size;i++,j++){  /*五。道路名称赋值*/ 
			
			pnew->name[i]=temp_name[j];
			
		}      
		
		
		                     
				 if(prear==NULL){ 
				 	head=prear=pnew;
				 } 
		
		prear->next=pnew;  /* 让新生成的结点末尾指向空*/
		
		prear=pnew; 
		
		

	}
	
	
		
	prear->next=NULL;	
	
	
	
	
	
	

	
	
	

	
		return head;	
	
	
} 
	
	
	  
	

