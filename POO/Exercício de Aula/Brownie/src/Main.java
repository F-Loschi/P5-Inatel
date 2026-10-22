public class Main {
    public static void main(String[] args) {
        BrownieNutella bn = new BrownieNutella("Jorge", 14, "Nutella");
        BrownieDoceDeLeite bdc = new BrownieDoceDeLeite("Hugo", 12, "Doce de Leite");
        BrownieCafe bc = new BrownieCafe("Otavio", 13, "Cafe");

        bn.adicionaNutella();
        bn.addCarrinhoDeCompras();
        bn.calculaValorTotalCompra();

        bdc.addCarrinhoDeCompras();
        bdc.calculaValorTotalCompra();
        bdc.adicionaDoceDeLeite();

        bc.addCarrinhoDeCompras();
        bc.calculaValorTotalCompra();
        bc.adicionaCafe();
    }
}