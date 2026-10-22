package computador;

public class Computador {
    public String marca;
    public float preco;
    public HardwareBasico []hardware;
    public SistemaOperacional SO;
    public MemoriaUSB memoriaUSB;

    public Computador(HardwareBasico[] h, SistemaOperacional SO) {
        hardware = h;
        this.SO = SO;
    }

    public void mostraInfo() throws InterruptedException {
        System.out.println("Marca: "+marca);
        Thread.sleep(750);
        System.out.println("Preco: "+preco);
        Thread.sleep(750);
        for(HardwareBasico h : hardware){
            if(h.tipo==1) {
                System.out.println(h.nome + " (" + h.capacidade + "Mhz)");
                Thread.sleep(750);

            }
            else if(h.tipo==2) {
                System.out.println(h.capacidade + " Gb de Memória RAM");
                Thread.sleep(750);

            }
            else if(h.tipo==3) {
                System.out.println(h.nome +" de "+ h.capacidade + "GB");
                Thread.sleep(750);

            }
        }
        System.out.println(SO.nome + "("+SO.tipo+" bits)");
        Thread.sleep(750);
        System.out.println("Acompanha "+memoriaUSB.nome+" de "+SO.tipo+"Gb\n");
    }

    public void addMemoriaUSB(MemoriaUSB musb) {
        this.memoriaUSB = musb;
    }
}