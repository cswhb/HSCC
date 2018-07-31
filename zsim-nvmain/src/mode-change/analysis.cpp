#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <fstream>
#include<stdint.h>
#define MAXBUFFER 5
#define CHANGE 40
using namespace std;
void LRU(uint64_t* step,int* times,uint64_t& pointi,uint64_t newstep,uint64_t pointmod,int mod){
	int minpoint=1<<30,mintimes=1<<30;
	for(int i=0;i<MAXBUFFER;i++){
		if(mintimes>=times[i]&&(!mod||i!=pointmod)){
			mintimes=times[i];
			minpoint=i;
		}
	}
    //printf("%d %d\n",times[minpoint],step[minpoint]);
	times[minpoint]=2;
	step[minpoint]=newstep;
	pointi=minpoint;
}
int main(){
	ifstream infile;
    infile.open("zsim.log.0");
    //infile.open("test.txt");
    if(!infile) {
        cout<<"error"<<endl;
        return 0;
    }
    int i=0;
    uint64_t a;
    int mod=0;
    char buffer[100];
    uint64_t* step=new uint64_t[MAXBUFFER] ();
    int* times=new int[MAXBUFFER] ();
    int flag=0;
    uint64_t pointi=0,pointmod=0;
    uint64_t addr=0,loggg=0;
    uint64_t newstep=0;
    while (! infile.eof() )
    {
       infile.getline (buffer,100);
       sscanf(buffer,"[S 0] %llu",&a);
       newstep=a>addr?a-addr:addr-a;
       addr=a;
       loggg++;
       flag=0;
       for(i=0;i<MAXBUFFER;i++){
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
       if(flag==0)
           LRU(step,times,pointi,newstep,pointmod,mod);
       else{
       	   if(mod==0){
       	   	if(times[pointi]>=CHANGE){
       	   		mod=1;
       	   		printf("%llu,modchange to 1,loggg:%llu\n",step[pointi],loggg);
                loggg=0;
       	   		pointmod=pointi;
       	   	}
       	   }
       	   else{
       	   	if(times[pointmod]>CHANGE)times[pointmod]=CHANGE;
       	   	else if(times[pointmod]<=0){
       	   		if(times[pointi]>=CHANGE){
       	   			times[pointi]=CHANGE;
       	   			pointmod=pointi;
                    printf("%llu",step[pointi]);
       	   		}
       	   		else {
       	   			mod=0;
       	   			printf("modchange to 0,loggg:%llu\n",loggg);
                    loggg=0;
       	   		}
       	   	}
       	   }
       }
      // cout<<a<<endl;
    }
    infile.close();
	return 0;
}
