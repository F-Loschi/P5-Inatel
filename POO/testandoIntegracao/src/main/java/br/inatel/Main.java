package br.inatel;
import br.inatel.DAO.UserDAO;
import br.inatel.Model.User;

public class Main {
    public static void main(String[] args) {
        UserDAO userDAO = new UserDAO();
        userDAO.connectionTest();
    }
}