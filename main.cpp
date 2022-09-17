#include <iostream>
#include <vector>

void sort(std::vector<std::vector<std::string> > letterSorter, std::vector<std::string>& finalF, int n){
  for (int index=0; index < letterSorter.size(); index++){
    if (letterSorter[index].size() == 1){
      finalF.insert(std::end(finalF), std::begin(letterSorter[index]), std::end(letterSorter[index]));
    }
    else if (letterSorter[index].size() == 2){
      if ((int) (unsigned char) letterSorter[index][0][n] > (int) (unsigned char) letterSorter[index][1][n]){
	std::string temp = letterSorter[index][1];
	letterSorter[index][1] = letterSorter[index][0];
	letterSorter[index][0] = temp;
      }
      finalF.insert(std::end(finalF), std::begin(letterSorter[index]), std::end(letterSorter[index]));
    }
    else if (letterSorter[index].size() != 0) {
      std::vector<std::vector<std::string> > lSorter;
      std::vector<std::vector<std::string> > sSorter;
      for (int i=0; i < letterSorter[index].size(); i++){
	int ascii = (unsigned char)letterSorter[index][i][n];
	if (ascii <= 122){
	  if ((ascii >= 97) && (ascii <= 122)) {
	    ascii -= 32;
	  }
	  if (lSorter.size() <= ascii){
	    lSorter.resize(ascii + 1);
	  }
	  lSorter[ascii].push_back(std::string(letterSorter[index][i]));
	}
	else{
	  ascii -= 122;
	  if (sSorter.size() <= ascii){
	    sSorter.resize(ascii + 1);
	  }
	  sSorter[ascii].push_back(letterSorter[index][i]);
	}
      }
      sort(lSorter,finalF, n+1);
      sort(sSorter,finalF, n+1);
    }
  }
}
void wordReader(std::vector<std::vector<std::string> > &letterSorter, std::vector<std::vector<std::string> > &specialSorter){
  for (std::string line; std::getline(std::cin, line);) {
    int ascii = (unsigned char)line[0];
    if (ascii <= 122){
      if ((ascii >= 97) && (ascii <= 122)) {
	ascii -= 32;
      }
      if (letterSorter.size() <= ascii){
	letterSorter.resize(ascii + 1);
      }
      letterSorter[ascii].push_back(line);
    }
    else{
      ascii -= 122;
      if (specialSorter.size() <= ascii){
	specialSorter.resize(ascii + 1);
      }
      specialSorter[ascii].push_back(line);
    }
  }
}
int main(){
  std::vector<std::vector<std::string> > letterSorter;
  std::vector<std::string> finalF;
  std::vector<std::vector<std::string> > specialSorter;
  wordReader(letterSorter, specialSorter);
  sort(letterSorter, finalF, 1);
  sort(specialSorter, finalF, 1);
  //for (int wordIndex = 0; wordIndex < finalF.size(); wordIndex++){
  //  std::cout << finalF[wordIndex] << std::endl;
  //}
  return 0;
}
