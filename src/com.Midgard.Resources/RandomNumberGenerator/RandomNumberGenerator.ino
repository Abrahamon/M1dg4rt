const int input = A0;
int incomingByte = 0;

void setup() {
  pinMode(input,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available() > 0){
    incomingByte = Serial.read();

    
    int exponente = incomingByte-48;
 //   Serial.println(exponente);
    Serial.println(getNumber(exponente));
  
  }
  //Serial.println(analogRead(input));
  //delay(110);
  
}

int getNumber(int maxType){
  
  int numArray[maxType];
  
  for(int i = 0; i < maxType ; i++){
    numArray[i]=randomBit();
  }
  int num = randomNumber(numArray,0,0,maxType);
  return num;
}

int randomBit(){
  if(analogRead(input) > 15){
    return 1;
  }
  else{
    return 0; 
  }
}

int randomNumber(int numArray[],int ind,int resultado,int maxType){
  if(ind == maxType){
    return resultado;
  }
  else if(numArray[ind] == 1){
    resultado+= pow(2,ind);
    randomNumber(numArray,ind+=1,resultado,maxType);
    
  }
  else{
    randomNumber(numArray,ind+=1,resultado,maxType);
    
  }
}

