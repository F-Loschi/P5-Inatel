public abstract class Personagem {
    protected String nome;
    protected int vida;
    protected Arma arma[];

    public Personagem(String nome, int vida) {
        this.nome = nome;
        this.vida = vida;
    }

    public void addArma(Arma arma){
        for(int i=0; i<this.arma.length;i++) {
            if (this.arma[i] == null) {
                this.arma[i] = new Arma(arma.getNome(), arma.getDano(), arma.getDurabilidade());
                break;
            }
        }
    }

    public void mostrarArmas(){
        for(Arma arma : arma){
            System.out.println(arma.toString());
        }
    }

    public void atacar(int posicao, Personagem personagem){
        if(this.arma[posicao].getDurabilidade()>0){
            if(personagem.vida>0){
                personagem.vida-=this.arma[posicao].getDano();
                this.arma[posicao].setDurabilidade(0);
            }
            else{
                System.out.println(personagem.nome+" já foi de arrasta");
            }
        }
    }
}
