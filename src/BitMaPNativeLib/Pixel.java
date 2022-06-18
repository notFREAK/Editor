package BitMaPNativeLib;

public class Pixel {
    private byte Red, Green, Blue;

    public byte getRed() {return Red;}

    public int getIntRed() {return Byte.toUnsignedInt(Red);}
    public byte getGreen() {return Green;}
    public int getIntGreen() {return Byte.toUnsignedInt(Green);}
    public byte getBlue() {return Blue;}
    public int getIntBlue() {return Byte.toUnsignedInt(Blue);}
    public void setRed(byte Red) {this.Red = Red;}

    public void setGreen(byte Green) {this.Green = Green;}

    public void setBlue(byte Blue) {this.Blue = Blue;}

    public Pixel() {
        this((byte)0,(byte)0,(byte)0);
    }
    public Pixel(byte Red, byte Green, byte Blue) {
        this.Red = Red;
        this.Green = Green;
        this.Blue = Blue;
    }
}
