package br.inatel.cdg;

public class Conta {
    private int numero;
    private float saldo;
    private float limite;
    private Cliente[] clientes = new Cliente[3];

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setClientes(Cliente clienteA, Cliente clienteB, Cliente clienteC) {
        Cliente cliente1 = new Cliente();
        cliente1.setNome(clienteA.getNome());
        cliente1.setCpf(clienteA.getCpf());
        Cliente cliente2 = new Cliente();
        cliente2.setNome(clienteB.getNome());
        cliente2.setCpf(clienteB.getCpf());
        Cliente cliente3 = new Cliente();
        cliente3.setNome(clienteC.getNome());
        cliente3.setCpf(clienteC.getCpf());

        this.clientes[0] = cliente1;
        this.clientes[1] = cliente2;
        this.clientes[2] = cliente3;
    }

    public void sacar(float valor) {
        if (this.saldo >= valor) {
            this.saldo -= valor;
            System.out.println("Saque realizado com sucesso!");
        }
        else {
            System.out.println("Saldo insuficiente!");
        }
    }

    public void depositar(float valor) {
        if (valor>0) {
            this.saldo += valor;
            System.out.println("Depositado com sucesso!");
        }
    }

    public void getClientes() {
        for (int i = 0; i < clientes.length; i++) {
            if (clientes[i] != null) {
                System.out.println(this.clientes[i].getNome());
                System.out.println(this.clientes[i].getCpf());
            }
        }
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }
}
