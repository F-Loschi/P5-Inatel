public class Brownie {
    protected String nome;
    protected double preco;
    protected String sabor;

    public Brownie(String nome, double preco, String sabor) {
        this.nome = nome;
        this.preco = preco;
        this.sabor = sabor;
    }

    public void addCarrinhoDeCompras(){
        System.out.println(this.nome + " foi adicionado no carrinho de compras");
    }

    public void calculaValorTotalCompra(){
        System.out.println(this.nome + " custa R$ " + this.preco);
    }

    public void mostraInfo(){
        System.out.println("Nome: " + nome);
        System.out.println("Preco: " + preco);
        System.out.println("Sabor: " + sabor);
    }
}
