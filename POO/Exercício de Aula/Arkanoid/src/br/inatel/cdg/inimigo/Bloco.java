package br.inatel.cdg.inimigo;

import br.inatel.cdg.jogador.Jogador;

public class Bloco {
    static private int numBlocos;
    private int vida;
    private boolean existe;


    public static void Blocos(){
        numBlocos++;
    }
    public static void menosBlocos(){
        numBlocos--;
    }
    public void setVida(int vida) {
        this.vida = vida;
    }
    public int getVida() {
        return vida;
    }
    public void perdeVida(Jogador j1){
        this.vida-=j1.getDano();
    }
    public void setExiste(boolean existe) {
        this.existe = existe;
    }
    public boolean isExiste() {
        return existe;
    }
    public static int getNumBlocos() {
        return numBlocos;
    }
}
