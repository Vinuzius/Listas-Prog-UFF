import java.util.Scanner;

public class ex1 {

    public static void main(String[] args) {
    int j,numA = 0,numB = 0;
    Scanner teclado = new Scanner(System.in);

    do {
        Tabela();
        j = teclado.nextInt();

        if(j<5){
            numA = Inserir("Entre com o 1° numero: ");
            numB = Inserir("Entre com o 2° numero: ");
        }
        switch (j) {
            case 1:
                System.out.println("Resultado: " + (numA+numB) );
                break;

            case 2:
                System.out.println("Resultado: " + (numA-numB) );
                break;

            case 3:
                System.out.println("Resultado: " + (numA*numB) );
                break;

            case 4:
                System.out.println("Resultado: " + (numA/numB) );
                break;

            case 5:
                for (int i = 0; i < 50; ++i) System.out.println();
                break;

            default:
                System.exit(1);
        }
    }
    while (true);

}

    public static void Tabela(){
        System.out.println("====================");
        System.out.println("(1) Somar");
        System.out.println("(2) Subtrair");
        System.out.println("(3) Multiplicar");
        System.out.println("(4) Dividir");
        System.out.println("(5) Limpar");
        System.out.println("(6) Sair do Programa");
        System.out.println("====================");
        System.out.println("Opção: ");
    }

    static int Inserir(String frase){
        Scanner teclado = new Scanner(System.in);

        System.out.println(frase);
        int num ;
        return num = teclado.nextInt();
    }
}
