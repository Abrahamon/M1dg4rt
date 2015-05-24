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

}

void JsonWriter::JsonSend(std::string pData) {

	string str = pData;
	cout<<"Paso1"<<endl;
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


	/*****************************************************/



	Jzon::Node node = Jzon::object();
	{
	  Jzon::Node array = Jzon::array();
	  {
		  int i = 0;
		  string op = "";
		  while(true){
			  cout<<"Tengo hambr"<<endl;

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
			  cout<<Lista[i]<<endl;
			  if(Lista[i] == "#"){cout<<"sale"<<endl;break;}

		  }

	  }
	  node.add("records", array);
	}


	Jzon::Writer writer;
	writer.writeStream(node, cout);
	writer.writeFile(node, "/home/tvlenin/Dropbox/Universidad/2015/I Semestre/Datos II/Proyectos/Proyecto II/WEBANGULAR/JSON/pueblos.json");
}
/*
 * JsonWriter.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: tvlenin
 */




