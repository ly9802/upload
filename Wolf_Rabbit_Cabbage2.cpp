#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int aa[4], bb[4];
int solution[8];
int amount=0;
void Leave_bank_A(int,int);
bool judge(int oo[]){
    int i=0;
    bool flag=false;
    for(i=1;i<4;i++){
	if(oo[i]>0){flag=true;} 
    }

   return flag;
}
bool safe(int item,int tt[]){
    
    int i=0,j=0;
    bool flag=true;
    string name="";
    for(i=1;i<3;i++){
	for(j=i+1;j<4;j++){
	    if((i!=item)&&(j!=item)){
		if( fabs(tt[i]-tt[j])==1 ){
                   flag=false;
		   break;
		}
	    }
	}
	if(flag==false){break;}
    }
    
    return flag;
}
void print(int step3, int object, string direction){
    string cargo="";
    switch(object){
     case 3:cargo="Cabbage";break;
     case 4:cargo="Rabbit"; break;
     case 5:cargo="Wolf";break;
     default:cargo="Nothing";break;
    } 
    if (direction=="go"){
	cout<<"step "<<step3<<": side A " <<"--->"<<cargo<<" --->"<<" side B"<<endl;
    }
    else{
	cout<<"step "<<step3<<": side A " <<"<---"<<cargo<<" <---"<<" side B"<<endl;
    }
}
void output(int ss[])
{
    int i=0;
    string cargo="";
    for(i=1;i<8;i++){
	cargo="";
        switch(ss[i]){
           case 3:cargo="Cabbage";break;
           case 4:cargo="Rabbit"; break;
           case 5:cargo="Wolf";break;
           default:cargo="Nothing";break;
	} 
	if (i%2==0){
	    cout<<"step "<<i<<": side A " <<"<---"<<cargo<<" <---"<<" side B"<<endl;
	}
	else{
	    cout<<"step "<<i<<": side A " <<"--->"<<cargo<<" --->"<<" side B"<<endl;
	}
    }//end for loop
}
void Leave_bank_B(int step2,int lastcargo){
    
	
	if(safe(0,bb)==true){
	   //print(step2,0,"back");//bring nothing
	   solution[step2]=0;
           if(judge(aa)==true){
	       Leave_bank_A(step2+1,0);
	       
	       solution[step2]=0;
	   }
	   else{
	       
	       cout<<"end"<<endl;
	   }
	}
	else{
	    int i=0;
	    for(i=1;i<4;i++){
		if((bb[i]!=lastcargo)&&(bb[i]!=0)&&(safe(i,bb)==true)){
		    
		    aa[i]=bb[i];
		    
		    solution[step2]=bb[i];
		    bb[i]=bb[i]-bb[i];
		    if(judge(aa)==true){Leave_bank_A(step2+1,aa[i]);}
		    else{cout<<"end"<<endl;}
		    
		    solution[step2]=0;
		    bb[i]=aa[i];
		    aa[i]=0;
		}	
	    }//end for loop
	}
        
}
void Leave_bank_A(int step,int lastcargo){
      int i=0;
    
      for(i=1;i<4;i++){
	  if( (aa[i]!=lastcargo)&&(aa[i]!=0)&&(safe(i,aa)==true) ){
	      
             bb[i]=aa[i];
	     
	     solution[step]=aa[i];
	     aa[i]=aa[i]-aa[i];
	     if(judge(aa)==true){Leave_bank_B(step+1,bb[i]);}
	     else{
		 amount++;
		 cout<<"Solution "<<amount<<":"<<endl;
		 output(solution);
		 cout<<"end"<<endl;
	     }
	     
	     solution[step]=0;
	     aa[i]=bb[i];
	     bb[i]=0;
	     
	  }
      }//end for loop
    
}
void main(){
   int i=0;
   aa[0]=0;bb[0]=0;
   for(i=0;i<8;i++){solution[i]=0;}
   for(i=1;i<4;i++){
     aa[i]=i+2;
     bb[i]=0;
   }
   //cout<<safe(0,aa)<<endl;
   Leave_bank_A(1,0);
   //cout<<judge(aa)<<endl;
   //print(3, "go");
}