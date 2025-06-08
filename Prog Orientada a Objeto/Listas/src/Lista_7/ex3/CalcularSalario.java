package Lista_7.ex3;

public class CalcularSalario {

    public static void main(String[] args) {

        Funcionario[] func = new Funcionario[2];

        func[0] = new Estagiario("Robson", 1500.0);

        func[1]= new Vendedor("Juninho", 3740.0);

        for (Funcionario funcionario : func) {
            double liq = funcionario.salarioLiquido(funcionario.salarioBruto);
            System.out.printf("Funcionario %s, salario: R$%.2f %n", funcionario.nome, liq);
        }

        processarBonusVendedor(func[1], 14);
        System.out.println("Após bonus aplicado: ");
        for (Funcionario funcionario : func) {
            double liq = funcionario.salarioLiquido(funcionario.salarioBruto);
            System.out.printf("Funcionario %s, salario: R$%.2f %n", funcionario.nome, liq);
        }

    }

    static void processarBonusVendedor(Funcionario funcionario, int vendasDoMes) {
        if (funcionario instanceof Vendedor) {
            Vendedor vendedor = (Vendedor) funcionario;
            double bonus = vendedor.calcularBonus(vendasDoMes);
            System.out.printf("Bônus calculado para %s: R$%.2f%n", vendedor.nome, bonus);
        } else {
            System.out.println("O funcionário " + funcionario.nome + " não é um Vendedor, bônus de vendas não aplicável.");
        }
    }

}
