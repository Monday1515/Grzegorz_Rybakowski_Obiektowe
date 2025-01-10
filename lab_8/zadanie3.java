class Pizza {

    private String name;
    private String dough;
    private String sauce;
    private String topping;

    private Pizza(PizzaBuilder builder) {
        this.name = builder.name;
        this.dough = builder.dough;
        this.sauce = builder.sauce;
        this.topping = builder.topping;
    }

    @Override
    public String toString() {
        return "Pizza [name=" + name + ", dough=" + dough + ", sauce=" + sauce + ", topping=" + topping + "]";
    }

    public static class PizzaBuilder {

        private String name;
        private String dough;
        private String sauce;
        private String topping;

        public PizzaBuilder name(String name) {
            this.name = name;
            return this;
        }

        public PizzaBuilder dough(String dough) {
            this.dough = dough;
            return this;
        }

        public PizzaBuilder sauce(String sauce) {
            this.sauce = sauce;
            return this;
        }

        public PizzaBuilder topping(String topping) {
            this.topping = topping;
            return this;
        }

        public Pizza build() {
            return new Pizza(this);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Pizza pepperoniPizza = new Pizza.PizzaBuilder()
                .name("Pepperoni Pizza")
                .dough("Thin crust")
                .sauce("Tomato")
                .topping("Pepperoni")
                .build();

        Pizza margaritaPizza = new Pizza.PizzaBuilder()
                .name("Margarita Pizza")
                .dough("Regular crust")
                .sauce("Tomato")
                .topping("Cheese")
                .build();

        System.out.println(pepperoniPizza);
        System.out.println(margaritaPizza);
    }
}
