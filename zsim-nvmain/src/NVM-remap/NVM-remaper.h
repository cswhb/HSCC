#include "COMMON.h"
using namespace std; 
class NVM_remaper{
	public:
		NVM_remaper(unsigned areaShift,unsigned limit):areaShift(areaShift),limit(limit),writetimes(0){
		    mapTable=(Address*)malloc(sizeof(Address)*(zinfo->memory_size/(1<<areaShift)));
		    writeTimes=(unsigned*)malloc(sizeof(unsigned)*(zinfo->memory_size/(1<<areaShift)));
		}
	    void SetLimit(unsigned limit){
	    	this->limit=limit;
		}
		Address Translate(Address inAddr,bool iswrite,bool &ischange,Address &fromAddr ,Address &toAddr){
			Address pa=(inAddr-bottom+start)%(top-bottom);
			pa= pa>=gap?pa+1:pa;
			if(iswrite){
				if(ischange=ChangeWrite(fromAddr ,toAddr)){
					if(pa==fromAddr){
						ischange=false;
						return toAddr+bottom;
					}
				}
			}
			return PA+bottom;
		}
		bool ChangeWrite(Address &fromAddr ,Address &toAddr){
	    //如果写次数到达阈值，触发一次gap行迁移 
			writetimes=writetimes+1==limit?0:writetimes+1;
			toAddr=gap+bottom;
		    if(writetimes==0){
		    	if(gap==0){
		    		gap=area;
		    		start=(start+1)%(area);
		    		gap=area;
				}
				else gap=gap-1;
			}
			fromAddr=gap+bottom;
			return writetimes==0?1:0;
		} 
	private:
		unsigned areaShift;
		Address  *mapTable;
		unsigned limit;//阈值 
		unsigned *writeTimes;
};
