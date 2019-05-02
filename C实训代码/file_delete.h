
R *Delete(R *head)
{
	int x;
	printf("                  请输入要删除路的ID\n"); 
	printf("                  ");
	scanf("%d",&x);
	R *p,*q;
	for(p=head,q=NULL;p!=NULL;q=p,p=p->next) 
	{
	   if(p->linkid==x)	
	   break;
	  
	}
	 if(p!=NULL)
	   {
	   	 if(q==NULL)
	   	 head=p->next;
	   	 else
	   	 q->next=p->next;
	   	 free(p);
		 
	   }
	   printf("\n");
	   printf("                  删除完成\n");
	   printf("\n"); 
		return head;
	
	
}


