
void Search(R *head){
   int x;
   printf("                  ���������·��ID\n");
   printf("\n");
   printf("                  ");
   
   scanf("%d",&x);
   printf("\n");
   R *p,*q;
   for(p=head;p!=NULL;p=p->next)/*�������*/
    {
      	if(p->linkid==x)
             break;  
	} 
    if(p!=NULL) 
	{
		printf("                  ��ѯ������£�\n"); 
		printf("\n");
        printf("                  linkid= %d ; ",p->linkid);
						 	
		printf("roadnameflag= %d ; ",p->roadnameflag); 
						 	
		printf("brunch= %d ;",p->brunch);
		printf("\n") ;
							 
	    printf("                  dispclass= %d ;",p->dispclass);
									
		if (p->roadnameflag){
			printf("roadname = %s ;\n",p->name);
										
		} 	
		else{
			
			printf("roadname = 0 ;\n");
	    }
	} 
	else
	   printf("                  no this unit\n");
	   
	printf("\n");
}



