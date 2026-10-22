import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        ArrayList<Dicionario> listaDeDicionario = new ArrayList<>();
        Substativo Subs = new Substativo("Carro", 2);
        listaDeDicionario.add(Subs);
        Substativo Subs2 = new Substativo("Moto", 1);
        listaDeDicionario.add(Subs2);
        Verbos Ver1 = new Verbos("Andar", 3);
        listaDeDicionario.add(Ver1);
        Verbos Ver2 = new Verbos("Cair", 0);
        listaDeDicionario.add(Ver2);
        Palavras P1 = new Palavras("Tio", 4);
        listaDeDicionario.add(P1);
        Palavras P2 = new Palavras("Tom", 5);
        listaDeDicionario.add(P2);

        System.out.println("Ela antes: ");
        for(Dicionario d : listaDeDicionario){
            System.out.println(d.nome+" na casa "+ d.numero);
        }

        Collections.sort(listaDeDicionario);

        System.out.println("Ela depois: ");

        for(Dicionario d : listaDeDicionario){
            System.out.println(d.nome+" na casa "+ d.numero);
        }

    }
}