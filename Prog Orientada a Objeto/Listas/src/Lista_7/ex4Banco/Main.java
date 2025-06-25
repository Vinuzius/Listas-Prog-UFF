package Lista_7.ex4Banco;

public class Main {
    public static void main(String[] args) throws Exception {
        ContaEspecial c1 = new ContaEspecial(1,1000,500);

        System.out.println("Saldo Inicial: " + c1.getSaldo() );
        System.out.println("Limite: " + c1.getLimite() );

        c1.sacar(1501);


    }
}
