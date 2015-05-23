
#ifndef SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#define SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#include <string>
#include "../com.Midgard.DataAccess/Constants.h"
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using namespace std;

class JsonWriter{
private:
	string Path_to_Json;
public:
	JsonWriter();
	void updateVillageInfo(std::string pData, std::string pueblo);
	void startFight(std::string pBool,int A, int B);
};


#endif /* SRC_COM_LDMM_DATAACCESS_JSONWRITER_ */
