
R *Delete(R *head)
{
	int x;
	printf("                  ������Ҫɾ��·��ID\n"); 
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
	   printf("                  ɾ�����\n");
	   printf("\n"); 
		return head;
	
	
}


