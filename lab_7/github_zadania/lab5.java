interface MessageService {     // poprawnie
    void sendMessage(String message);
}

class EmailService implements MessageService {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending Email: " + message);
    }
}

class Notification {
    private MessageService messageService;

    public Notification(MessageService service) {
        this.messageService = service;
    }

    public void notify(String message) {
        messageService.sendMessage(message);
    }
}

public class Main {
    public static void main(String[] args) {
        EmailService emailService = new EmailService();
        Notification notification = new Notification(emailService);

        notification.notify("Witaj w SOLID!");
    }
}
