package Lista_7.ex4Banco;

public class ContaEspecial extends Conta {

    private double limite;

    public ContaEspecial(int num, double s, double lim) throws Exception {
        super(num,s);
        this.limite = -lim;
    }

    @Override
    public double sacar(double saque){
        double aux = saldo - saque;
        if ( aux >= limite){
            saldo -= saque;
            System.out.printf("Sacou: %.2f %nSaldo: %.2f %n",saque, this.saldo);
            return saque;
        }
        else{
            System.out.printf("Saque além do limite disponível %nSaldo: %.2f %n",saldo);
            return 0;
        }
    }
}
