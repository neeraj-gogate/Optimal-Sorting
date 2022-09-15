using System;
using System.Collections.Generic;

public static class Globals
{
	public static void sort(List<List<string>> letterSorter, List<string> finalF, int n)
	{
	  for (int index = 0; index < letterSorter.Count; index++)
	  {
		if (letterSorter[index].Count == 1)
		{
//C++ TO C# CONVERTER TODO TASK: There is no direct equivalent to the STL vector 'insert' method in C#:
		  finalF.insert(finalF.end(), letterSorter[index].GetEnumerator(), letterSorter[index].end());
		}
		else if (letterSorter[index].Count != 0)
		{
		  List<List<string>> sorter = new List<List<string>>();
		  for (int i = 0; i < letterSorter[index].Count; i++)
		  {
			int ascii = (byte)letterSorter[index][i][n];
			if ((ascii >= 97) && (ascii <= 122))
			{
			  ascii -= 32;
			}
			if (sorter.Count <= ascii)
			{
			  sorter.Resize(ascii + 1);
			}
			sorter[ascii].Add(new string(letterSorter[index][i]));
		  }
		  sort(new List<List<string>>(sorter), finalF, n + 1);
		}
	  }
	}
	public static void wordReader(List<List<string>> letterSorter)
	{
	  for (string line; line = Console.ReadLine();)
	  {
		int ascii = (byte)line[0];
		//makes all letters capital (essentially ignores case)
		if ((ascii >= 97) && (ascii <= 122))
		{
		  ascii -= 32;
		}
		//adds vectors inside LS
		if (letterSorter.Count <= ascii)
		{
		  letterSorter.Resize(ascii + 1);
		}
		letterSorter[ascii].Add(line);
	  }
	}
	internal static void Main()
	{
	  List<List<string>> letterSorter = new List<List<string>>();
	  List<string> finalF = new List<string>();
	  wordReader(letterSorter);
	  sort(new List<List<string>>(letterSorter), finalF, 1);
	  for (int wordIndex = 0; wordIndex < finalF.Count; wordIndex++)
	  {
		Console.Write(finalF[wordIndex]);
		Console.Write("\n");
	  }
	}

}
