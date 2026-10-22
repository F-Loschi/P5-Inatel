public class Comprador {
    private String nome;
    private double saldo;

    public Comprador(String nome, double saldo) {
        this.nome = nome;
        this.saldo = saldo;
    }

    public void efetuarCompra(Brownie brownie){
        if(this.saldo>= brownie.preco) {
            this.saldo -= brownie.preco;
            System.out.println("Compra efetuada com sucesso!");
        }
        else{
            System.out.println("Tá sem grana irmãozão, volta outro dia.");
        }
    }
}
