#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <fstream>

std::map<std::string, int> memory;
int acc;

bool parseInput( std::string& input, std::string& address, int& value){
  std::istringstream iss(input);
  
   if(!(iss >> input)) {
    std::cout << "Invalid command";
    return false;
  }

  if(!(iss >> address)) {
    std::cout << "Invalid address";
    return false;
  }

  if(!(iss >> value)) {
    std::cout << "Invalid value";
    return false;
  }

  return true;
}


bool parseInput( std::string& input, int& value){
  std::istringstream iss(input);
  
  if(!(iss >> input)) {
    std::cout << "Invalid command";
    return false;
  }

  if(!(iss >> value)) {
    std::cout << "Invalid value";
    return false;
  }

  return true;
}


bool parseInput(std::string& input, std::string& address){
  std::istringstream iss(input);
  
  if(!(iss >> input)) {
    std::cout << "Invalid command";
    return false;
  }

  if(!(iss >> address)) {
    std::cout << "Invalid Address";
    return false;
  }

  return true;
}


bool parseInput( std::string& input, std::string& address1, std::string& address2){
  std::istringstream iss(input);

   if(!(iss >> input)) {
    std::cout << "Invalid command";
    return false;
  }

  if(!(iss >> address1)) {
    std::cout << "Invalid address";
    return false;
  }

    if(!(iss >> address2)) {
    std::cout << "Invalid second address";
    return false;
  }


  return true;
}


bool parseInput( std::string& input, std::string& address1, std::string& address2, std::string& address3){
  std::istringstream iss(input);

   if(!(iss >> input)) {
    std::cout << "Invalid command";
    return false;
  }

  if(!(iss >> address1)) {
    std::cout << "Invalid address";
    return false;
  }

    if(!(iss >> address2)) {
    std::cout << "Invalid second address";
    return false;
  }

    if(!(iss >> address3)) {
    std::cout << "Invalid third address";
    return false;
  }


  return true;
}



void sumOperation(const std::string& address) {
  if (memory.find(address) != memory.end()) {
    acc += memory[address];
  } else {
    std::cout << "La Direccion " << address << "No existe en la memoria." << std::endl;
  }
}


void sumOperation(std::string& address1, std::string& address2) {
  if (memory.find(address1) != memory.end() && memory.find(address2) != memory.end() ) {
    acc = memory[address1];
    acc += memory[address2];
  } else {
    std::cout << "La Direccion " << address1 << "No existe en la memoria." << std::endl;
  }
}

void sumOperation( std::string& address1, std::string& address2, std::string& address3){
  if(memory.find(address1) != memory.end() && memory.find(address2) != memory.end() && memory.find(address3) != memory.end()){
    acc = memory[address1];
    acc += memory[address2];
    memory[address3] = acc;
  } else{
    std::cout << "Address " << address1 << "is not in memory." << std::endl;
  }
}


void subOperation1( std::string& address) {
  if (memory.find(address) != memory.end()) {
    acc -= memory[address];
  } else {
    std::cout << "La Direccion " << address << "No existe en la memoria." << std::endl;
  }
}


void subOperation2( std::string& address1, std::string& address2){
  if(memory.find(address1) != memory.end() && memory.find(address2) != memory.end()){
    acc = memory[address1];
    acc -= memory[address2];
  } else{
    std::cout << "La Direccion " << address1 << "No existe en la memoria." << std::endl;
  }
}


void subOperation3(const std::string& address1, std::string& address2, std::string& address3){
  if(memory.find(address1) != memory.end() && memory.find(address2) != memory.end() && memory.find(address3) != memory.end()){
    acc = memory[address1];
    acc -= memory[address2];
    memory[address3] = acc;
  } else{
    std::cout << "Address " << address1 << "is not in memory." << std::endl;
  }
}

void mulOperation(const std::string& address){
  if(memory.find(address) != memory.end()){
    int temp = acc;
    for(int i = 1; i < memory[address]; i++){
      acc += temp;
    }
  } else {
    std::cout << "Address: " << address << "Is not in memory." <<std::endl;
  }
}

void mulOperation(const std::string& address1, std::string& address2){
  if(memory.find(address1) != memory.end() && memory.find(address2) != memory.end()){
    acc = memory[address1];
    int temp = acc;
    for(int i = 1; i < memory[address2]; i++){
      acc += temp;
    }
  } else {
    std::cout << "The addresses " << address1 <<" " << address2 << "are both not in memory" <<std::endl; 
  }
}


void mulOperation(const std::string& address1, std::string& address2, std::string& address3){
  if(memory.find(address1) != memory.end() && memory.find(address2) != memory.end() && memory.find(address3) != memory.end()){
    acc = memory[address1];
    int temp = acc;
    for(int i = 1; i < memory[address2]; i++){
      acc += temp;
    }
    memory[address3] = acc;
  } else {
    std::cout << "The addresses are not in memory." <<std::endl;
  }
}

void divOperation(const std::string& address){
  if(memory.find(address) != memory.end()){
    int temp = memory[address];
    int res = 0;
    while(acc > 0){
      acc -= temp;
      res++;
    }
    acc = res;
  } else {
    std::cout << "Memory Address not valid" <<std::endl;
  }
}


void divOperation(const std::string& address1, std::string& address2){
  if(memory.find(address1) != memory.end()){
    acc = memory[address1];
    int temp = memory[address2];
    int res = 0;
    while(acc > 0){
      acc -= temp;
      res++;
    }
    acc = res;
  } else {
    std::cout << "Memory Address not valid" <<std::endl;
  }
}


void divOperation(const std::string& address1, std::string& address2, std::string& address3){
  if(memory.find(address1) != memory.end()){
    acc = memory[address1];
    int temp = memory[address2];
    int res = 0;
    while(acc > 0){
      acc -= temp;
      res++;
    }
    memory[address3] = res;
  } else {
    std::cout << "Memory Address not valid" <<std::endl;
  }
}

void increment(const std::string& address){
  acc = memory[address] + 1;
  memory[address] = acc;
}

void decrement(const std::string& address){
  acc = memory[address] - 1;
  memory[address] = acc;
}

void showOperation(std::string& address){
  std::ofstream outputFile("output.txt");

  if (outputFile.is_open()) {
  if(memory.find(address) != memory.end()){
      outputFile << memory[address] <<std::endl;
      std::cout << memory[address] << std::endl;
      outputFile.close();
      
      }else if(address == "ACC"){
        outputFile << acc << std::endl;
        std::cout << acc << std::endl;
	outputFile.close();
  } else {
    std::cout << "that address is not in memory";
  }
  } else {
    std::cout << "Failed to create file." << std::endl;
  }
}

void move(const std::string& address1, std::string& address2){
  memory[address2] = memory[address1];
  memory[address1] = 0;
}

void load(const std::string& address){
  if(memory.find(address) != memory.end()){
    acc = memory[address];
  } else{
    std::cout << "That address is not in memory" <<std::endl;
  }
}

void store(const std::string& address){
  
    memory[address] = acc;
  
  }


int countTokens(const std::string& str){
  std::istringstream iss(str);
  return std::distance(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>());
}

void removeNulls(std::string& line) {
  std::string nullString = "NULL";
  size_t pos = line.find(nullString);

  while (pos != std::string::npos) {
    line.erase(pos, nullString.length());
    pos = line.find(nullString, pos);
  }
}


int main() {
  std::string input;
  std::string fileName;
  while (true) {
    std::cout << "Enter a file name: ";
    std::getline(std::cin, fileName);

    std::ifstream file(fileName);
    if(file.is_open()) {
      while (std::getline(file,input)){
	removeNulls(input);
    
    if(input == "END") {
      break;
    }

    std::string command, address, address1, address2, address3;
    int value;

    int tokenCount = countTokens(input);
    std::istringstream iss(input);
        
    
    if(!(iss >> command)) {
      std::cout << "Entered an invalid command or no command" <<std::endl;
      continue;
    }

    if (command == "SET") {
      if(!parseInput(input, address, value)){
	continue;
      }
      memory[address] = value;
    } else if (command == "SUB"){
      if(tokenCount == 2){
	if(!parseInput(input, address)){
	  continue;
	}
	subOperation1(address);
      } else if (tokenCount == 3) {
	if(!parseInput(input, address1, address2)){
	  continue;
	}
	subOperation2(address1, address2);
      } else if (tokenCount == 4) {
	if(!parseInput(input, address1, address2, address3)){
	  continue;
	}
	subOperation3(address1, address2, address3);
      }
    }

    else if(command == "SHW"){
      if(!parseInput(input,address)){
	  continue;
	}
	showOperation(address);
    } else if (command == "ADD"){
      if(tokenCount == 2){
	if(!parseInput(input, address)){
	  continue;
	}
        sumOperation(address);
      } else if (tokenCount == 3) {
	if(!parseInput(input, address1, address2)){
	  continue;
	}
        sumOperation(address1, address2);
      } else if (tokenCount == 4) {
	if(!parseInput(input, address1, address2, address3)){
	  continue;
	}
        sumOperation(address1, address2, address3);
      }
    }  else if (command == "MUL"){
      if(tokenCount == 2){
	if(!parseInput(input, address)){
	  continue;
	}
        mulOperation(address);
      } else if (tokenCount == 3) {
	if(!parseInput(input, address1, address2)){
	  continue;
	}
        mulOperation(address1, address2);
      } else if (tokenCount == 4) {
	if(!parseInput(input, address1, address2, address3)){
	  continue;
	}
        mulOperation(address1, address2, address3);
      }
    }  else if (command == "DIV"){
      if(tokenCount == 2){
	if(!parseInput(input, address)){
	    continue;
	  }
	  divOperation(address);
      } else if (tokenCount == 3){
	if(!parseInput(input, address1, address2)){
	  continue;
	}
	divOperation(address1, address2);
      } else if (tokenCount == 3) {
	if(!parseInput(input, address1, address2, address3)){
	  continue;
	}
	divOperation(address1, address2, address3);
      }
    } else if (command == "INC"){
      if(!parseInput(input, address)){
	  continue;
	}
	increment(address);
    } else if (command == "DEC"){
      if(!parseInput(input, address)){
	  continue;
	}
	decrement(address);
    }  else if (command == "MOV"){
	if(!parseInput(input, address1, address2)){
	    continue;
	  }
	  move(address1, address2);
      } else if (command == "LDR"){
	if(!parseInput(input, address)){
	  continue;
	}
	load(address);
      } else if (command == "STR"){
	if(!parseInput(input, address)){
	  continue;
	}
	store(address);
    } else {
      std::cout << "invalid command" << std::endl;
      continue;
    }


      }
      file.close();
    } else{
      std::cout << "Failed to open file." << std::endl;
    }

  }
}
