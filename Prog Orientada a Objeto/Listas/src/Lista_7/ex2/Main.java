package Lista_7.ex2;

import java.util.Random;

public class Main {
    public static void main(String[] args){

        Animal[] animais = new Animal[10];
        Random random = new Random();

        // Instancia aleatoriamente Homens, Cães e Gatos no vetor
        for (int i = 0; i < animais.length; i++) {
            definirTipo(animais,random.nextInt(3),i);
        }

        // Loop por todos os animais do vetor, pedindo para eles falarem
        System.out.println("Vamos ver o que os animais têm a dizer:");
        for (int i = 0; i < animais.length; i++) {
            System.out.println("Animal " + (i + 1));
            animais[i].fala();
        }
    }

    static void definirTipo( Animal[] animais, int tipo,int i){
        if (tipo == 0) {
            animais[i] = new Homem();
        } else if (tipo == 1) {
            animais[i] = new Cachorro();
        } else {
            animais[i] = new Gato();
        }
    }
}
