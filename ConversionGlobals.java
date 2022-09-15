import java.util.*;

public class Globals
{
	public static void sort(ArrayList<ArrayList<String>> letterSorter, ArrayList<String> finalF, int n)
	{
	  for (int index = 0; index < letterSorter.size(); index++)
	  {
		if (letterSorter.get(index).size() == 1)
		{
//C++ TO JAVA CONVERTER TODO TASK: There is no direct equivalent to the STL vector 'insert' method in Java:
		  finalF.insert(finalF.end(), letterSorter.get(index).iterator(), letterSorter.get(index).end());
		}
		else if (letterSorter.get(index).size() != 0)
		{
		  ArrayList<ArrayList<String>> sorter = new ArrayList<ArrayList<String>>();
		  for (int i = 0; i < letterSorter.get(index).size(); i++)
		  {
	//C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
	//ORIGINAL LINE: int ascii = (unsigned char)letterSorter[index][i][n];
			int ascii = (byte)letterSorter.get(index).get(i).charAt(n);
			if ((ascii >= 97) && (ascii <= 122))
			{
			  ascii -= 32;
			}
			if (sorter.size() <= ascii)
			{
			  tangible.VectorHelper.resize(sorter, ascii + 1);
			}
			sorter.get(ascii).add(new String(letterSorter.get(index).get(i)));
		  }
		  sort(new ArrayList<ArrayList<String>>(sorter), finalF, n + 1);
		}
	  }
	}
	public static void wordReader(ArrayList<ArrayList<String>> letterSorter)
	{
	  for (String line; line = new Scanner(System.in).nextLine();)
	  {
	//C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
	//ORIGINAL LINE: int ascii = (unsigned char)line[0];
		int ascii = (byte)line[0];
		//makes all letters capital (essentially ignores case)
		if ((ascii >= 97) && (ascii <= 122))
		{
		  ascii -= 32;
		}
		//adds vectors inside LS
		if (letterSorter.size() <= ascii)
		{
		  tangible.VectorHelper.resize(letterSorter, ascii + 1);
		}
		letterSorter.get(ascii).add(line);
	  }
	}
	public static void main(String[] args)
	{
	  ArrayList<ArrayList<String>> letterSorter = new ArrayList<ArrayList<String>>();
	  ArrayList<String> finalF = new ArrayList<String>();
	  wordReader(letterSorter);
	  sort(new ArrayList<ArrayList<String>>(letterSorter), finalF, 1);
	  for (int wordIndex = 0; wordIndex < finalF.size(); wordIndex++)
	  {
		System.out.print(finalF.get(wordIndex));
		System.out.print("\n");
	  }
	}

}
