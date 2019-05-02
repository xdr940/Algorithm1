


R *Sort  (R*head){

    
    R *hh,*pr,*p,*pp,*ppr,*temp,*ph;
    hh=head;

    int min;
    int flag=1; //是否是头一次的节点
    ph=head;
     printf("                         排序中,请稍后...\n"); 
     printf("\n") ;
    while(head!=NULL)
    {
        
    
            min=head->linkid ;        
            p=head;
            pr=p;           
            ppr=pr;
            pp=p;
         /*
           排好顺序的链表为头节点hh开头，每次都从h节点开头的
           链表冒泡出数值最小的节点，接到hh链表开头的链表尾部。
           
         */

            //开始冒泡
             
            while(p!=NULL)
            {
                if(p->linkid <min) //找出 节点值数据最小的节点
                {    
                    ppr=pr;   //最小节点的父节点
                    pp=p;     //最小节点
                    min=p->linkid ;  //节点的最小数值
                }
                pr=p;
                p=p->next;
            }        

           /*
             找到h节点之后，数值最小的节点， pp代表该最小节点
             ppr为pp的先驱节点
           */

            if(ppr==pp)
            {            
                head=pp;
                ph->next=head;
                if(flag==1)  //在还未建立头节点时，先建立头节点，hh代表该头节点
                {
                   hh=head;flag=0; //头节点h之前的节点都是已经按从小到达的顺序排好顺序的节点，
                }    
            }else
            {    
                /*
                 如果最小节点不是头节点p的后驱节点的话
                 就把头节点h和最小数值节点兑换
                */
                if(head!=ppr)
                {
                    /*
                      交换节点 h和pp
                      用到两个的节点的先驱节点ph和ppr
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
                     如果最小节点p是头节点h的后驱节点的话
                     调换两个节点
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

        ph=head;//ph为头节点h移动时的先驱节点
        head=head->next;
    }

    

   

     			
    
    printf("                         排序完成\n"); 
    printf("\n");
    head=hh;
     return head;
	 
} 
