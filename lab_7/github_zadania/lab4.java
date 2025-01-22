interface Printer {  // poprawnie
    void print();
}


interface Scanner {
    void scan();
}

class MultiFunctionMachine implements Printer, Scanner {
    @Override
    public void print() {
        System.out.println("Printing document...");
    }

    @Override
    public void scan() {
        System.out.println("Scanning document...");
    }
}

public class Main {
    public static void main(String[] args) {
        MultiFunctionMachine mfm = new MultiFunctionMachine();
        mfm.print();
        mfm.scan();
    }
}
