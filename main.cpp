#include <iostream>
#include <vector>

void sort(std::vector<std::vector<std::string> > letterSorter, std::vector<std::string>& finalF, int n){
  for (int index=0; index < letterSorter.size(); index++){
    if (letterSorter[index].size() == 1){
      finalF.insert(std::end(finalF), std::begin(letterSorter[index]), std::end(letterSorter[index]));
    }
    else if (letterSorter[index].size() != 0) {
      std::vector<std::vector<std::string> > sorter;
      for (int i=0; i < letterSorter[index].size(); i++){
        int ascii = (unsigned char)letterSorter[index][i][n];
        if ((ascii >= 97) && (ascii <= 122)) {
          ascii -= 32;
        }
        if (sorter.size() <= ascii){
          sorter.resize(ascii + 1);
        }
        sorter[ascii].push_back(std::string(letterSorter[index][i]));
      }
      sort(sorter,finalF, n+1);
    }
  }
}
void wordReader(std::vector<std::vector<std::string> > &letterSorter){
  for (std::string line; std::getline(std::cin, line);) {
    int ascii = (unsigned char)line[0];
    //makes all letters capital (essentially ignores case)
    if ((ascii >= 97) && (ascii <= 122)) {
      ascii -= 32;
    }
    //adds vectors inside LS
    if (letterSorter.size() <= ascii){
      letterSorter.resize(ascii + 1);
    }
    letterSorter[ascii].push_back(line);
  }
}
int main(){
  std::vector<std::vector<std::string> > letterSorter;
  std::vector<std::string> finalF;
  wordReader(letterSorter);
  sort(letterSorter, finalF, 1);
  for (int wordIndex = 0; wordIndex < finalF.size(); wordIndex++){
    std::cout << finalF[wordIndex] << std::endl;
  }
  return 0;
}
