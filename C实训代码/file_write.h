
void Write(R *head){
	
		/*------------------��ӡ����---------------------------*/
	
	printf("                  Ҫ��Ҫ��ӡ��ȡ������?\n");
	printf("                  1.��ӡ\n");
	printf("                  2.����ӡ\n");
	printf("                  ");

		int s;
		
		scanf("%d",&s);	
	
		if(s==1){
								R *pst ;
						
						 for(pst=head;pst;pst=pst->next){ /*�����ӡ*/
						 	
						 	
						 	
						 	
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
