


R *Sort  (R*head){

    
    R *hh,*pr,*p,*pp,*ppr,*temp,*ph;
    hh=head;

    int min;
    int flag=1; //�Ƿ���ͷһ�εĽڵ�
    ph=head;
     printf("                         ������,���Ժ�...\n"); 
     printf("\n") ;
    while(head!=NULL)
    {
        
    
            min=head->linkid ;        
            p=head;
            pr=p;           
            ppr=pr;
            pp=p;
         /*
           �ź�˳�������Ϊͷ�ڵ�hh��ͷ��ÿ�ζ���h�ڵ㿪ͷ��
           ����ð�ݳ���ֵ��С�Ľڵ㣬�ӵ�hh����ͷ������β����
           
         */

            //��ʼð��
             
            while(p!=NULL)
            {
                if(p->linkid <min) //�ҳ� �ڵ�ֵ������С�Ľڵ�
                {    
                    ppr=pr;   //��С�ڵ�ĸ��ڵ�
                    pp=p;     //��С�ڵ�
                    min=p->linkid ;  //�ڵ����С��ֵ
                }
                pr=p;
                p=p->next;
            }        

           /*
             �ҵ�h�ڵ�֮����ֵ��С�Ľڵ㣬 pp�������С�ڵ�
             pprΪpp�������ڵ�
           */

            if(ppr==pp)
            {            
                head=pp;
                ph->next=head;
                if(flag==1)  //�ڻ�δ����ͷ�ڵ�ʱ���Ƚ���ͷ�ڵ㣬hh�����ͷ�ڵ�
                {
                   hh=head;flag=0; //ͷ�ڵ�h֮ǰ�Ľڵ㶼���Ѿ�����С�����˳���ź�˳��Ľڵ㣬
                }    
            }else
            {    
                /*
                 �����С�ڵ㲻��ͷ�ڵ�p�ĺ����ڵ�Ļ�
                 �Ͱ�ͷ�ڵ�h����С��ֵ�ڵ�һ�
                */
                if(head!=ppr)
                {
                    /*
                      �����ڵ� h��pp
                      �õ������Ľڵ�������ڵ�ph��ppr
                    */
                temp=head->next;
                ppr->next=head;
                head->next=pp->next;            
                pp->next=temp;                                       
                head=pp;

                if(flag==1){hh=head;flag=0;}
                else
                {
                  ph->next=head;
                }

                }else
                {  /*
                     �����С�ڵ�p��ͷ�ڵ�h�ĺ����ڵ�Ļ�
                     ���������ڵ�
                   */
                    head->next=pp->next;
                    pp->next=head;
                    head=pp;
                    if(flag==1){hh=head;flag=0;}
                    else{
                        ph->next=pp;
                    }
                }            
                
                
           }    

        ph=head;//phΪͷ�ڵ�h�ƶ�ʱ�������ڵ�
        head=head->next;
    }

    

   

     			
    
    printf("                         �������\n"); 
    printf("\n");
    head=hh;
     return head;
	 
} 
