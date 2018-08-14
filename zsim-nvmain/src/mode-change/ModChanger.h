#ifndef MOD_CHANGER_H
#define MOD_CHANGER_H

#include"common/global_const.h"
#include "galloc.h"
class ModChanger : public GlobAlloc {
public:
	ModChanger(): pointi(0),pointmod(0),addrback(0),flag(0),newstep(0){
		step=new Address[MAXBUFFER] ();
		times=new int[MAXBUFFER] ();
	}
	~ModChanger(){
		delete []step;
		delete []times;
	}
	void LRU(Address newstep,uint64_t mod){
	    int minpoint=1<<30,mintimes=1<<30;
	    for(int i=0;i<MAXBUFFER;i++){
		    if(mintimes>=times[i]&&(!mod||i!=pointmod)){
			    mintimes=times[i];
			    minpoint=i;
		    }
	    }
	    times[minpoint]=2;
	    step[minpoint]=newstep;
	    pointi=minpoint;
    }
	void access (Address addr){
		newstep=addrback>addr?addrback-addr:addr-addrback;
        addrback=addr;
        flag=0;
        for(int i=0;i<MAXBUFFER;i++){
       	 if(newstep==step[i]&&times[i]!=0){
       		times[i]+=2;
            pointi=i;
            flag=1;
         }
         else{
            times[i]-=1;
            times[i]=times[i]<0?0:times[i];
         }
        }
    }
    int domodchange(uint64_t mod){
    	if(flag==0)
           LRU(newstep,mod);
        else{
       	   if(mod==0){
       	   	if(times[pointi]>=CHANGE){
       	   		pointmod=pointi;
       	   		return 1;
       	   	 }
       	   }
       	   else{
       	   	 if(times[pointmod]>CHANGE)times[pointmod]=CHANGE;
       	   	 else if(times[pointmod]<=0){
       	   		if(times[pointi]>=CHANGE){
       	   			times[pointi]=CHANGE;
       	   			pointmod=pointi;
       	   			return 1;
       	   		}
       	   		else {
       	   			return 0;
       	   		}
       	   	 }
       	   }
        }
        return mod;
    }
private:
	Address*step;
    int*times;
    Address addrback,newstep,mod;
    int pointi,pointmod,flag;
};
#endif

