package BitMaPNativeLib;

public class Point {
    private int X, Y, Z;

    public int getX() {return X;}

    public int getY() {return Y;}

    public int getZ() {return Z;}

    public void setX(int X) {this.X = X;}

    public void setY(int Y) {this.Y = Y;}

    public void setZ(int Z) {this.Z = Z;}

    public Point() {
        this(0,0,0);
    }
    public Point(int X, int Y, int Z) {
        this.X = X;
        this.Y = Y;
        this.Z = Z;
    }
}
