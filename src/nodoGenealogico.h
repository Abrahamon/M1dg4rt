#ifndef NODEOGENEALOGICO_H_
#define NODEOGENEALOGICO_H_

class nodogenealogico{

private:

public:
	std::string Id;
	nodogenealogico* pareja;
	nodogenealogico* hijoDerecho;
	nodogenealogico* hijoIzquierdo;

	nodogenealogico(std::string ID){
		this->pareja = 0;
		this->hijoDerecho = 0;
		this->hijoIzquierdo =0;
	}

	nodogenealogico* getPareja(){
		return this->pareja;
	}

	nodogenealogico* getHijoDer(){
			return this->pareja;
		}

	nodogenealogico* getHijoIzq(){
			return this->pareja;
		}
};

#endif /* NODEOGENEALOGICO_H_ */
