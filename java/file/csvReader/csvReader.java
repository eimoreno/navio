
import java.io.*;
import java.util.*;

public class csvReader{

  public static void main(String [] args) throws FileNotFoundException{

  	System.out.print("Informe o nome do arquivo csv a ser consumido: ");
  	Scanner entradaPadrao = new Scanner(System.in);
    String filename=entradaPadrao.nextLine();

  	File arquivo = new File(filename);
  	Scanner entrada = new Scanner(arquivo);
	  
	entrada.useDelimiter(";");
	while(entrada.hasNext())
		System.out.println(entrada.next());	  
  }

}
