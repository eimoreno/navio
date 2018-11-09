#include <iostream>
#include <fstream>
#include <list>
#include <trace.h>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

// comparison, not case sensitive.
bool sortCondition (const trace& first, const trace& second)
{
  return first.position<second.position;
}

int main(int argc, char* argv[]){
	
	if(argc<2){
	  cout << "Missing parameters:" << endl;
	  cout << "  " << argv[0] << " <prog configuration filename> " << endl;
	  cout << "   prog configuration details " << endl;
	  cout << "     ep: Final address of the program " << endl;
	  cout << "     ji:address,destination,probability " << endl;
	  cout << "       Inconditional jump instruction, meaning that always happens" << endl;
	  cout << "       Address: Decimal value defining where the jump exists" << endl;
	  cout << "       Target: Decimal value defining the target branch" << endl;
	  cout << "     bi:address,destination,probability " << endl;
	  cout << "       Conditional branch instruction, meaning that may happens" << endl;
	  cout << "       Address: Decimal value defining where the jump exists" << endl;
	  cout << "       Target: Decimal value defining the target branch" << endl;
	  cout << "       Probability: value from 0 to 100 defining the probability of a jump to happens" << endl;
	  return 0;
    }
    
    
    ifstream pcf(argv[1]);
    if(!pcf.is_open()){
		cout << "Error opening file " << argv[1] << endl;
		return 0;
	}
	
	int EndPoint, InitialPoint=0;
	int position, target, probability;
	list<trace> progConfig;
	string strAux, instruction;
	char* chrAux;
	char* tok;
	const char s[4] = ":"; 
	cout << "Spliting " << endl;
	while(getline(pcf,strAux)){
		chrAux=new char[strAux.size()];
		strcpy(chrAux,strAux.c_str());
		tok=strtok(chrAux,s);
		if(strcmp(tok,"ep")){
			tok=strtok(0,s);
			EndPoint=atoi(tok);
		}
		else{
			tok=strtok(0,s);
			position=atoi(tok);
			tok=strtok(0,s);
			target=atoi(tok);
			if(strcmp(tok,"bi")){
				tok=strtok(0,s);
				probability=atoi(tok);
			}
		}
		delete chrAux;
	}
	
	pcf.close();	
	
	cout << "Sorting " << endl;
	progConfig.sort(sortCondition);
	
	list<trace>::iterator it;
	cout << "mylist contains:";
	for (it=progConfig.begin(); it!=progConfig.end(); ++it){
		trace t=*it;
		cout << ' ' << t.instruction << ", " << t.position << endl;;
	}
	cout << '\n';	
	
	
	
      
    
    
}
