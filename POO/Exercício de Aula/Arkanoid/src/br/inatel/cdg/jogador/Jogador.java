package br.inatel.cdg.jogador;

import br.inatel.cdg.inimigo.Bloco;

public class Jogador {
    private int dano;
    private String nome;
    static private int pontuacao = 0;

    public Jogador(int dano, String nome) {
        this.dano = dano;
        this.nome = nome;
    }
    public int getDano() {
        return dano;
    }
    public boolean destruir(Bloco b1){
        if(this.dano>=b1.getVida() && b1.isExiste()){
            System.out.println("Bloco foi pro beleléu!");
        }
        else if(this.dano<b1.getVida() && b1.isExiste()){
            System.out.println("Vai ter que bater de novo");
            return false;
        }
        else if(!b1.isExiste()){
            System.out.println("Tá tentando destruir o que meu filho?");
        }
        return true;
    }
    public String getNome() {
        return nome;
    }
    public static void setPontuacao(int pontuacao) {
        Jogador.pontuacao += pontuacao;
    }
    public static int getPontuacao() {
        return pontuacao;
    }
    public int Conversor(int pontos){
        return 100*pontos;
    }
}
