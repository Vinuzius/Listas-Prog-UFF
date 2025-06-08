package Lista_7.ex3;

public class Vendedor extends Funcionario {

    public Vendedor(String n, double sal) {
        super(n, sal);
    }

    @Override
    public double salarioLiquido(double salario) {
        double imposto = 0;
        if (salarioBruto < 900)
            imposto = 0;
        else if (salarioBruto <1500)
            imposto = 0.15;
        else
            imposto = 0.2;

        return (salarioBruto * (1-imposto) );
    }

    public double calcularBonus(double bonus){
        return salarioBruto *= (1+bonus/100);
    }
}
