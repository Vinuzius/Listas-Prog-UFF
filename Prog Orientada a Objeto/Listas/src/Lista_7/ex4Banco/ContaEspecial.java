package Lista_7.ex4Banco;

public class ContaEspecial extends Conta {

    private double limite;

    public ContaEspecial(int num, double s, double lim) throws Exception {
        super(num,s);
        this.limite = -lim;
    }

    public double getLimite() {
        return limite;
    }

    @Override
    public double sacar(double saque){
        double aux = saldo - saque;
        if ( aux >= limite){
            saldo -= saque;
            System.out.printf("Sacou: %.2f %nNovo Saldo: %.2f %n",saque, this.saldo);
            return saque;
        }
        else{
            throw new IllegalArgumentException("Valor do saque é maior que o limite");
        }
    }
}
