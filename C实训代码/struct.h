#ifndef   YOUR_HEADER
#define  YOUR_HEADER
#include <stdlib.h>
#define  LEN   50
struct  roads{
	
	
	int linkid;
		
	int roadnameflag;
	
	int brunch;
	
	int dispclass; 
	
	char name[LEN];
	 
	 struct roads *next; 
};

typedef  struct roads R;


  R* head= (R*)malloc(sizeof(R)); 



#endif

	
	
	
			
				 
				 
				 
