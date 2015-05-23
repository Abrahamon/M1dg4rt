#include "JsonWriter.h"

using namespace std;

JsonWriter::JsonWriter() {
	Path_to_Json = Constants::JSONS_PATH;
}
void JsonWriter::updateVillageEntitiesList(std::string pPueblo,LinkedList<Entity*>* lista){

	int iterador = 0;
	Node<Entity*>* tmpEntity = lista->getHead();
	string stringToJSON ="";

	while(iterador < 20){
		Genome* p = tmpEntity->getData()->getGenome();

		string NewInfo = tmpEntity->getData()->getName()+" ";
		NewInfo+=
				lexical_cast<string>(p->getAttack())+" "+
				lexical_cast<string>(p->getSpeed())+" "+
				lexical_cast<string>(p->getDefense())+" "+
				lexical_cast<string>(p->getIntelligence())+" "+
				lexical_cast<string>(p->getMagic())+" "+
				lexical_cast<string>(p->getEnergy())+" "+
				lexical_cast<string>(p->getBlot())+" "+
				lexical_cast<string>(p->getRunesPower())+" ";
		stringToJSON += NewInfo;
		tmpEntity = tmpEntity->getNext();
		iterador++;
	}
	stringToJSON+=" #";
	vector<string> Lista;
	stringstream ss(stringToJSON);
	string temp;
	while (ss >> temp)
		Lista.push_back(temp);

	Jzon::Node node = Jzon::object();
	{
	  Jzon::Node array = Jzon::array();
	  {
		  int i = 0;
		  string op = "";
		  while(true){
			  Jzon::Node array_node = Jzon::object();

			  array_node.add("Nombre", Lista[i]);
			  i++;
			  array_node.add("Attack", Lista[i]);
			  i++;
			  array_node.add("Speed", Lista[i]);
			  i++;
			  array_node.add("Defence", Lista[i]);
			  i++;
			  array_node.add("Intelligence", Lista[i]);
			  i++;
			  array_node.add("Magic", Lista[i]);
			  i++;
			  array_node.add("Energy", Lista[i]);
			  i++;
			  array_node.add("Blot", Lista[i]);
			  i++;
			  array_node.add("RunesPower", Lista[i]);
			  i++;
			  array.add(array_node);
			  if(Lista[i] == "#"){
				  break;
			  }

		  }
		  node.add("records", array);
	  }

	}
	Jzon::Writer writer;
	writer.writeFile(node, Path_to_Json+pPueblo+".json");
}

void JsonWriter::startFight(std::string pBool,int A, int B){

	std::string message = pBool+":"+lexical_cast<string>(A)+":"+lexical_cast<string>(B)+":#";
	for (int i=0; i<message.length(); i++){
		if (message[i] == ':')
			message[i] = ' ';
	}
	vector<string> Lista;
	stringstream ss(message);
	string temp;
	while (ss >> temp)
		Lista.push_back(temp);

	Jzon::Node node = Jzon::object();
	{
	  Jzon::Node array = Jzon::array();
	  {
		  int i = 0;
		  string op = "";
		  while(true){
			  Jzon::Node array_node = Jzon::object();

			  array_node.add("FightAvailable", Lista[i]);
			  i++;
			  array_node.add("Pueblo1", Lista[i]);
			  i++;
			  array_node.add("Pueblo2", Lista[i]);
			  i++;
			  array.add(array_node);
			  if(Lista[i] == "#"){
				  break;
			  }

		  }
		  node.add("records", array);
	  }

	}
	Jzon::Writer writer;
	writer.writeFile(node, Path_to_Json+"fight.json");
}
void JsonWriter::updateVillageInfo(std::string pData,string pueblo) {

	string str = pData;
	for (int i=0; i<str.length(); i++)
	{
	    if (str[i] == ':')
	        str[i] = ' ';
	}

	vector<string> Lista;
	stringstream ss(str);
	string temp;
	while (ss >> temp)
	    Lista.push_back(temp); // done! now array={102,330,3133,76531,451,000,12,44412}

	Jzon::Node node = Jzon::object();
	{
	  Jzon::Node array = Jzon::array();
	  {
		  int i = 0;
		  string op = "";
		  while(true){
			  Jzon::Node array_node = Jzon::object();

			  array_node.add("Pueblo", Lista[i]);
			  i++;
			  array_node.add("Edda", Lista[i]);
			  i++;
			  array_node.add("Miembros", Lista[i]);
			  i++;
			  array_node.add("Inteligencia", Lista[i]);
			  i++;
			  array_node.add("Supersticion",Lista[i]);
			  i++;
			  array.add(array_node);
			  //cout<<Lista[i]<<endl;
			  if(Lista[i] == "#"){
				  break;
			  }

		  }

	  }
	  node.add("records", array);
	}

	Jzon::Writer writer;
	//writer.writeStream(node, cout);
	if(pueblo == "Dwarves"){
		writer.writeFile(node, Path_to_Json+"puebloDwarves.json");
	}
	else if (pueblo == "Giants"){
		writer.writeFile(node, Path_to_Json+"puebloGiants.json");
	}
	else if (pueblo == "DarkElves"){
		writer.writeFile(node, Path_to_Json+"puebloDarkElves.json");
	}
	else if (pueblo == "Elves"){
		writer.writeFile(node, Path_to_Json+"puebloElves.json");
	}
}
/*
 * JsonWriter.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: tvlenin
 */




