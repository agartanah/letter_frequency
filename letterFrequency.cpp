/***********************************************
 * Автор: Вяткин Владислав                     *       
 * Дата: 07.11.2022                            *
 * Название: Частота повторения букв           *
 *   и двухбуквенных сочетаний                 *
 * OnlineGDB: https://onlinegdb.com/QYRpVlCRA  *
 ***********************************************/
#include <iostream> // cout; cin
#include <stdio.h> // read file
#include <cmath> // abs
#include <cstring> // strlen

using namespace std;

int main() {
  int indexAlphabet = 0, letterFrequency = 1, letterFrequencyArray[75],
  countTwoLetterComb = 0;
  
  char fileLine[100], fileAlphabet[75];
  
  FILE* file = fopen("untitled.txt", "r");
  
  if (file == NULL) {
    return 0;
  }
  
  while (!feof(file)) {
    fscanf(file, "%s", fileLine);
    
    for (int indexLetter = 0; indexLetter < strlen(fileLine); ++indexLetter) {
      if ((fileLine[indexLetter] >= 65 && fileLine[indexLetter] <= 90)
       || (fileLine[indexLetter] >= 97 && fileLine[indexLetter] <= 122)) {
        bool flag = 0;
        int indexLetterRepeated;
        
        if (indexLetter != strlen(fileLine) &&
           (fileLine[indexLetter] == fileLine[indexLetter + 1] || 
        abs(fileLine[indexLetter] -  fileLine[indexLetter + 1]) == 32)) {
          ++countTwoLetterComb;
        }
        
        for (int index = 0; index < indexAlphabet; ++index) {
          if (fileAlphabet[index] == fileLine[indexLetter] || 
          abs(fileAlphabet[index] -  fileLine[indexLetter]) == 32) {
            flag = 1;
            indexLetterRepeated = index;
          }
        }
        
        if (flag == 0) {
          if (!(fileLine[indexLetter] >= 65 && fileLine[indexLetter] <= 90)) {
            fileLine[indexLetter] -= 32;
          }
          
          fileAlphabet[indexAlphabet] = fileLine[indexLetter];
          letterFrequencyArray[indexAlphabet] = letterFrequency;
          
          ++indexAlphabet;
        } else {
          letterFrequencyArray[indexLetterRepeated] += letterFrequency; 
        }
      }
    }
  }
  
  for (int indexOut = 0; indexOut < indexAlphabet; ++indexOut) {
    if (letterFrequencyArray[indexOut] != 1) {
      cout << fileAlphabet[indexOut] << " — " << letterFrequencyArray[indexOut] - 1
           << endl;
    }
  }
  cout << endl;
  
  cout << "Количество двухбуквенный сочетаний: " << countTwoLetterComb << endl;
}
