import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class test
{ 
	public static void main(String [] args)
	{
		BufferedReader br = null;
		FileReader fr = null;

		try {

			fr = new FileReader("txt.txt");
			br = new BufferedReader(fr);

			String sCurrentLine;
			String pattern = "((\\[)((\\d*\\w*)(=)([^\\]]+))(\\]))";
			
			Pattern r = Pattern.compile(pattern);

			while ((sCurrentLine = br.readLine()) != null) {
				System.out.println(sCurrentLine);
				System.out.println("--------------");
				Matcher m = r.matcher(sCurrentLine);
				
				if(m.find()){
					int count = 0;
                    do {
						System.out.println("Match number "+count);
						System.out.println("start(): "+m.start());
						System.out.println("end(): "+m.end());
						System.out.println("Found value: " + m.group(count) );
						count++;
					}while(m.find());
				}
				else{
					System.out.println("NADA FOI ENCONTRADO...");
				}
				System.out.println("===========");
			}

		} catch (IOException e) {

			e.printStackTrace();

		} finally {

			try {

				if (br != null)
					br.close();

				if (fr != null)
					fr.close();

			} catch (IOException ex) {

				ex.printStackTrace();

			}

		}
	}

}
