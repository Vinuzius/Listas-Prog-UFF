import java.util.Scanner;

public class ex2 {

    public static void main(String[] args) {
        double[] notas = InserirNotas();
        double media = MediaAluno(notas, notas.length);

        StatusAluno(media);
    }

    static double[] InserirNotas() {
        Scanner teclado = new Scanner(System.in);
        int n; double[] nota;

        System.out.printf("Quantas notas o curso tem? ");
        n = teclado.nextInt();
        nota = new double[n];
        for (int i = 0; i < n; i++) {
            System.out.printf("Insira a nota %d: ", i+1);
            nota[i] = teclado.nextDouble();
        }
        return nota;
    }

    public static double MediaAluno(double[] notas, int n){
        double media = 0.0;

        for(int i = 0; i<n;i++)
            media += notas[i];

        media/=n;
        return media;
    }

    static void StatusAluno(double media){
        if (media >= 6.0f) System.out.println("Aprovado");
        else if (media > 4.0f) System.out.println("VS");
        else System.out.println("Reprovado");
    }
}

