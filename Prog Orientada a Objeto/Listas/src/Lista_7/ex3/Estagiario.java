package Lista_7.ex3;

public class Estagiario extends Funcionario {

    public Estagiario(String n, double sal) {
        super(n, sal);
    }
    @Override
    public double salarioLiquido(double salario) {
        return salario;
    }
}
