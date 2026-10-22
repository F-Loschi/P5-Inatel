package br.inatel.Model;

public class User {
    private String nome;
    private int id;
    private String cpf;

    public User(String nome, int id, String cpf) {
        this.nome = nome;
        this.id = id;
        this.cpf = cpf;
    }
    public User(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }
}
