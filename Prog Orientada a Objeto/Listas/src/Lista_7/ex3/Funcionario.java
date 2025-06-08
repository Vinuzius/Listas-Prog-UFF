package Lista_7.ex3;

public abstract class Funcionario {

    protected String nome;
    protected double salarioBruto;

    public Funcionario(String n, double sal){
        this.nome = n;
        this.salarioBruto = sal;
    }

    public abstract double salarioLiquido(double salario);
}
