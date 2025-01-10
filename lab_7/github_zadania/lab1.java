class User {
    private String name;
    private String surename;
    private String mail;

    public User(String name, String surename, String mail) {
        this.name = name;
        this.surename = surename;
        this.mail = mail;
    }

    public String getName() {
        return name;
    }

    public String getSurename() {
        return surename;
    }

    public String getMail() {
        return mail;
    }
}

class UserSaver {
    public void saveUser(User user) {
        System.out.println("Zapisano użytkownika: " + user.getName() + " " + user.getSurename() + " " + user.getMail());
    }
}

public class Main {
    public static void main(String[] args) {
        User user = new User("Grzegorz", "Rybakowski", "user@gmail.com");
        UserSaver userSaver = new UserSaver();
        
        userSaver.saveUser(user);
    }
}
