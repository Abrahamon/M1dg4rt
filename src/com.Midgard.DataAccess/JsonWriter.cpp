#include "JsonWriter.h"
#include "Jzon.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
#include <time.h>
using namespace std;

JsonWriter::JsonWriter() {
	Path_to_Json = Constants::JSONS_PATH;
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
		Lista.push_back(temp); // done! now array={102,330,3133,76531,451,000,12,44412}

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
			  //cout<<Lista[i]<<endl;
			  if(Lista[i] == "#"){
				  break;
			  }

		  }

	  }
	  node.add("records", array);
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




