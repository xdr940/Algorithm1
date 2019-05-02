
void Search(R *head){
   int x;
   printf("                  请输入查找路的ID\n");
   printf("\n");
   printf("                  ");
   
   scanf("%d",&x);
   printf("\n");
   R *p,*q;
   for(p=head;p!=NULL;p=p->next)/*检索结点*/
    {
      	if(p->linkid==x)
             break;  
	} 
    if(p!=NULL) 
	{
		printf("                  查询结果如下：\n"); 
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



