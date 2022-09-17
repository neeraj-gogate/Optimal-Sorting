#!/usr/bin/python3.9
import sys
def reSizes(thing, size):
  while len(thing) <= size+1:
    letterSorter.append()
def sort(letterSorter, n):
  for letter in letterSorter:
    
    if len(letter) == 1:
      finalF.append(letter[0])

    elif len(letter) == 2:
      if len(letter[0]) > n:
        if len(letter[1]) > n:
          if ord(letter[0][n]) > ord(letter[0][n]):
            temp = letter[1]
            letter[1] = letter[0]
            letter[0] = temp
            finalF.append(letter)
          else:
            finalF.append(letter[1])
            finalF.append(letter[0])
        else:
          finalF.append(letter)
                                
    elif len(letter) != 0:
      w, h = 1, 1
      sorter = [[None for x in range(w)] for y in range(h)]
      
      for word in letter:
        if len(word) > n:
          ascii = ord(word[n])
          if (ascii >= 97) and (ascii <= 122):
            ascii -= 32
          while len(sorter) <= ascii+1:
            sorter.append([])
          sorter[ascii].append(word)
          
        else:
          finalF.append(word)
          
      sort(sorter, n+1)
      
def wordReader(letterSorter):
  
  for word in sys.stdin:
    ascii = ord(word[0])
    if (ascii >= 97) and (ascii <= 122):
      ascii -= 32
    while len(letterSorter) <= ascii+1:
      letterSorter.append([])
    letterSorter[ascii].append(word)

def main():
  global finalF
  global letterSorter
  w, h = 1, 1
  letterSorter = [[None for x in range(w)] for y in range(h)]
  finalF = [None]
  wordReader(letterSorter)
  sort(letterSorter, 1)
  
if __name__ == '__main__' :
  main()
