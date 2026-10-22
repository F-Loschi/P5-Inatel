package br.inatel.cdg;

import br.inatel.cdg.inimigo.Bloco;
import br.inatel.cdg.jogador.Jogador;

/*
Vou explicar a ideia da vida do bloco que eu acho que isso ele não pede.
Um bloco por ter vida igual a 1 ou a 2 e o jogador tem um dano fixo de 1.
Isso é para dar a ideia de que existem blocos mais reforçados que o padrão,
em que o jogador tem que bater duas vezes para destruir.
 */

public class Main {
    public static void main(String[] args) {
        boolean venceu = false;//De começo ele ainda não venceu
        //Setando o bloco 1
        Bloco bloco1 = new Bloco();
        Bloco.Blocos();
        bloco1.setExiste(true);
        bloco1.setVida(2);
        //Setando o bloco 2
        Bloco bloco2 = new Bloco();
        Bloco.Blocos();
        bloco2.setExiste(true);
        bloco2.setVida(1);

        //Guardando o número inicial de blocos
        int numBlocosInicial = Bloco.getNumBlocos();

        //Uma variável para guardar quantos blocos ele já destruiu
        int destruido = 0;

        //Criando o jogador
        Jogador jo1 = new Jogador(1, "Jorginho da Hornet");

        //Mostrando quantos blocos ainda existem
        System.out.println("O total de blocos no momento é: " + Bloco.getNumBlocos());
        System.out.println("Você já destruiu " + destruido + " bloco(s).");

        //Fazendo a batalha entre o jogador e o bloco 1
        do{
            System.out.println("O jogador "+jo1.getNome()+" vai bater no bloco");
            venceu = jo1.destruir(bloco1);
            if (!venceu) {
                bloco1.perdeVida(jo1);
            }
            if(venceu){
                bloco1.setExiste(false);
            }
        }while(!venceu);

        //Vendo se ele ganhou para diminuir o número de blocos e somar um ponto
        if(!bloco1.isExiste()){
            Bloco.menosBlocos();
            Jogador.setPontuacao(1);
            destruido++;
        }

        //Vendo quantos blocos ainda existem
        System.out.println("O total de blocos no momento é: " + Bloco.getNumBlocos());
        System.out.println("Você já destruiu " + destruido + " bloco(s).");

        //Fazendo a batalha entre o jogador e o bloco 2
        do{
            System.out.println("O jogador "+jo1.getNome()+" vai bater no bloco");
            venceu = jo1.destruir(bloco2);
            if (!venceu) {
                bloco2.perdeVida(jo1);
            }
            if(venceu){
                bloco2.setExiste(false);
            }
        }while(!venceu);

        //Vendo se o bloco não existe mais para diminuir o número
        if(!bloco2.isExiste()){
            Bloco.menosBlocos();
            Jogador.setPontuacao(1);
            destruido++;
        }

        //Mostrando o número de blocos que ainda existem
        System.out.println("O total de blocos no momento é: " + Bloco.getNumBlocos());
        //Aqui ele já ganhou
        System.out.println("Tandandandandan, tandandandan, tandandaaaaaaan");
        System.out.println("(Isso é o som de vitória)");
        System.out.println("A batalha começou com " + numBlocosInicial + " bloco(s)");
        System.out.println("Você destruiu " + destruido + " bloco(s)");
        System.out.println("Você fez " + Jogador.getPontuacao() + " ponto(s)");
        System.out.println("Você ganhou " + jo1.Conversor(Jogador.getPontuacao()) + " moeda(s)");
    }
}