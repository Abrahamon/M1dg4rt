
#ifndef SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#define SRC_COM_LDMM_DATAACCESS_JSONWRITER_H_
#include <string>
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;

class JsonWriter{
public:
	JsonWriter();
	void updateVillageInfo(std::string pData, std::string pueblo);
	void startFight(std::string pBool,int A, int B);
};


#endif /* SRC_COM_LDMM_DATAACCESS_JSONWRITER_ */
