public class Main {
    public static void main(String[] args) {
        Brownie bn = new BrownieNutella("Jorge", 14, "Nutella");
        Brownie bdc = new BrownieDoceDeLeite("Hugo", 12, "Doce de Leite");
        Brownie bc = new BrownieCafe("Otavio", 13, "Cafe");

        Comprador comprante = new Comprador("O homem", 20);

        if(bc instanceof BrownieCafe) {
            BrownieCafe brownieCafe = (BrownieCafe) bc;
            brownieCafe.addCarrinhoDeCompras();
            brownieCafe.calculaValorTotalCompra();
            comprante.efetuarCompra(bc);
        }
        if(bdc instanceof BrownieDoceDeLeite) {
            BrownieDoceDeLeite brownieDoceDeLeite = (BrownieDoceDeLeite) bdc;
            brownieDoceDeLeite.addCarrinhoDeCompras();
            brownieDoceDeLeite.calculaValorTotalCompra();
            comprante.efetuarCompra(bc);
        }
        if(bn instanceof BrownieNutella) {
            BrownieNutella brownieNutella = (BrownieNutella) bn;
            brownieNutella.addCarrinhoDeCompras();
            brownieNutella.calculaValorTotalCompra();
            comprante.efetuarCompra(bc);
        }
    }
}