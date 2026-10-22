public class SaldoInsuficienteException extends RuntimeException{
    public SaldoInsuficienteException(){
        super("Tá tentando tirar mais do que tu tem, saí fora, otário!");
    }
}
