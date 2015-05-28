#ifndef SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#define SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#include <string>
#include "Jzon.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
#include <time.h>
#include "../com.Midgard.DataAccess/Constants.h"
#include <boost/lexical_cast.hpp>
#include "../com.Midgard.DataStructures/linkedList.h"
#include "../com.Midgard.DataStructures/vBinaryNode.h"
#include "../com.Midgard.Entities/Entity.h"

using boost::lexical_cast;
using namespace std;

class JsonWriter{
private:
	string Path_to_Json;
public:
	JsonWriter();
	void updateVillageInfo(std::string pData, std::string pueblo);
	void startFight(std::string pBool,int A, int B);
	void updateVillageEntitiesList(std::string pPueblo,LinkedList<Entity*>* lista);
	void resetVillageArmy(std::string pPueblo);
	void updateGodsLife(string pEstadoDeGuerra,int Dios1,int Dios2, int Dios3, int Dios4,int turno);
	void updateTime(int pTime);
};


#endif /* SRC_COM_LDMM_DATAACCESS_JSONWRITER_ */
