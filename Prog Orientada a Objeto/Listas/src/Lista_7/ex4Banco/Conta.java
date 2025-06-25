package Lista_7.ex4Banco;

public class Conta {
    protected int numero;
    protected double saldo;

    public Conta(int num, double s) throws Exception{
        Exception ex = new Exception("Saldo tem que ser maior que 0");
        if (s > 0) {
            this.saldo = s;
        }else {
            throw  ex;
        }
        this.numero = num;
    }

    public double getSaldo() {
        return saldo;
    }

    public double sacar(double saque) throws Exception{
        Exception ex = new Exception("Saque além do limite disponível");

        if (saque <= 0) {
            throw new IllegalArgumentException("Valor do saque deve ser positivo.");
        }

        if ( (saldo - saque >= 0) ){
            saldo -= saque;
            System.out.printf("Sacou: %.2f %nNovo saldo: %.2f %n",saque, this.saldo);
            return saque;
        }
        else{
           throw ex;
        }
    }

    public void depositar(double valor) throws Exception {
        Exception ex = new Exception("Valor de depósito deve ser positivo.");
        if (valor <= 0)
            throw ex;

        this.saldo += valor;
        System.out.println("Depósito de " + valor + " realizado. Novo saldo: " + this.saldo);
    }
}
