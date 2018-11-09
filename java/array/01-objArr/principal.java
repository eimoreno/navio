public class principal{

	public static void main(String [] args){
		anyClass [] lista = new anyClass[100];
		
		for(int i=0; i<50; i++){
			int pos=posicaoLivre(lista);
			lista[pos] = new anyClass();
		}		
		
		System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		for(int i=0; i<lista.length; i++){
			System.out.print(i+": ");
			if(lista[i]!=null) System.out.println(lista[i].getValor());
			else System.out.println("Vazio");
		}
		
		for(int i=0; i<lista.length; i++)
		  lista[i]=null;
		
		System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		for(int i=0; i<lista.length; i++){
			System.out.print(i+": ");
			if(lista[i]!=null) System.out.println(lista[i].getValor());
			else System.out.println("Vazio");
		}
		
		
	}
	
	public static int posicaoLivre(Object [] list){
		int retorno;
		do{
			retorno=(int)(Math.random()*(list.length-1));			
		}while(list[retorno]!=null);
		return retorno;
	}
}
