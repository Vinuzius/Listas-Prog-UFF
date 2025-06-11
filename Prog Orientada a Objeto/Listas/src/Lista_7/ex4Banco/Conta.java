package Lista_7.ex4Banco;

public class Conta {
    protected int numero;
    protected double saldo;

    public Conta(int num, double s) throws Exception{
        Exception ex = new Exception("Saldo tem que ser maior que 0");
        if (saldo < 0) {
            this.saldo = s;
        }else {
            System.out.print("Saldo inválido. ");
            throw  ex;
        }
        this.numero = num;
    }

    public double getSaldo() {
        return saldo;
    }

    public double sacar(double saque){
        if ( (saldo - saque >= 0) ){
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
