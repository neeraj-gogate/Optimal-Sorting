#include <iostream>
#include <map>
#include <vector>

void sort(std::map<int, std::vector<std::string> > letterSorter, std::vector<std::string>& finalF, int n){
  for (int index=0; index < letterSorter.size(); index++){
    if (letterSorter[index].size() == 1){
      finalF.insert(std::end(finalF), std::begin(letterSorter[index]), std::end(letterSorter[index]));
    }
    else if (letterSorter[index].size() != 0) {
      std::map<int, std::vector<std::string> > sorter;
      for (int i=0; i < letterSorter[index].size(); i++){
        int ascii = (unsigned char)letterSorter[index][i][n];
        if ((ascii >= 97) && (ascii <= 122)) {
          ascii -= 32;
        }
        sorter[ascii].push_back(std::string(letterSorter[index][i]));
      }
      sort(sorter,finalF, n+1);
    }
  }
}
void wordReader(std::map<int, std::vector<std::string> > &letterSorter){
  for (std::string line; std::getline(std::cin, line);) {
    int ascii = (unsigned char)line[0];
    if ((ascii >= 97) && (ascii <= 122)) {
      ascii -= 32;
    }
    letterSorter[ascii].push_back(line);
  }
}
int main(){
  std::map<int, std::vector<std::string> > letterSorter;
  std::vector<std::string> finalF;
  wordReader(letterSorter);
  sort(letterSorter, finalF, 1);
  return 0;
}