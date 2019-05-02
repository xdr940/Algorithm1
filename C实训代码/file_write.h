
void Write(R *head){
	
		/*------------------打印链表---------------------------*/
	
	printf("                  要不要打印读取的数据?\n");
	printf("                  1.打印\n");
	printf("                  2.不打印\n");
	printf("                  ");

		int s;
		
		scanf("%d",&s);	
	
		if(s==1){
								R *pst ;
						
						 for(pst=head;pst;pst=pst->next){ /*链表打印*/
						 	
						 	
						 	
						 	
						 	printf("linkid= %d ; ",pst->linkid);
						 	
						 	printf("roadnameflag= %d ; ",pst->roadnameflag); 
						 	
							printf("brunch= %d ;",pst->brunch); 
							 
							printf("dispclass= %d ;",pst->dispclass);
									
									if (pst->roadnameflag){
										printf("roadname= %s ;",pst->name);
										
									} 	
								 	else{
								 		printf("roadname= 0 ;");
									 }
								 		
							 
						 	printf("\n");	
						 }
			
		}else{
			
			
			printf("                          \n"); 
			
			
		}
		
}
