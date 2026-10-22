public abstract class Dicionario implements Comparable<Dicionario>{
    protected String nome;
    protected int numero;

    @Override
    public int compareTo(Dicionario o) {
        return Integer.compare(o.getNumero(), this.numero);
    }
    public Dicionario(String nome, int numero){
        this.nome = nome;
        this.numero = numero;
    }

    public int getNumero() {
        return numero;
    }
}
