#include "file_read.h"
#include "file_sort.h"
#include "file_search.h"
#include "file_delete.h"
#include "file_write.h"
#include "file_clear.h"
#include "file_save.h"





extern void Run(){
	while(1){
		
	    
	
		int i;    /*ѡ��*/
	  	printf("               ������ѡ��  ");
		 scanf("                   %d",&i);
		
	  	printf("\n");
 
		  	 

		  	
		  	
		  		if(i==0){
		  				printf("=====================================================\n");
		  				printf("================����================================\n");
						printf("=====================================================\n");   
		  				printf("\n");
		  				printf("\n");
		  				break;
		  		  	  		  
						 
						
					}
		  	
		  		else if(i==1){
		  			
		  				
						  head=Read(head);//��ȡ���� 
		  		  	    
					      Write(head);
					      
				  }
		  		 	
		  		else if(i==2){
		  		
		  			Sort(head);//������
					Write(head); 
		  		
					
				  }
				else if(i==3){
					Search(head);
				}
		  	
		  		else if(i==4){
		  			
		  			Delete(head) ;
		  			Write(head);
		  				
		  			
					
				  }else if(i==5){
				  
				   		Save(head);
				  } 
				 
		  	Clear();
		  	
		  	show_menu();
		  	
		  	
    }    
	
	
}
