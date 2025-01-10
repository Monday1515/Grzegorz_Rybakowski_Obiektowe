interface Shape {
    double getArea(); 
}


class Rectangle implements Shape {
    protected double width;
    protected double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public void setWidth(double w) {
        this.width = w;
    }

    public void setHeight(double h) {
        this.height = h;
    }

    @Override
    public double getArea() {
        return width * height;
    }
}

class Square implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public void setSide(double s) {
        this.side = s;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}

public class Main {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(5, 3);
        Square sq = new Square(4);

        Shape shape1 = rect;
        Shape shape2 = sq;

        System.out.println("Area of Rectangle: " + shape1.getArea());
        System.out.println("Area of Square: " + shape2.getArea());
    }
}
