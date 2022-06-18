package BitMaPNativeLib;

public class BitMaP {
    private String fileName = null;
    private FileHeader FileHeader;
    private DIBHeader DIBHeader;
    private DIBColorProfile DIBColorProfile;
    private Data Data;

    static {
        System.loadLibrary("BitMaPNativeLib");
    }

    private class FileHeader {
        static {
            System.loadLibrary("BitMaPFileHeaderNativeLib");
        }
        char format1, format2;
        int SizeOfFile;
        int reserved;
        int locationOfData;

        FileHeader() {
            this(fileName);
        }
        FileHeader(String fileName) {
           readFromFile(fileName);
        }

        private native int readFromFile(String fileName);

        private native int saveInFile(String fileName);

        public String getFormat() {return new StringBuilder().append(format1).append(format2).toString();}

        public int getSizeOfFile() {return SizeOfFile;}

        public int getReserved() {return  reserved;}

        public int getLocationOfData() {return locationOfData;}
    }

    private class DIBHeader {
        static {
            System.loadLibrary("BitMaPDIBHeaderNativeLib");
        }

        int SizeOfDIBHeader;
        int pixelWidth;
        int pixelHeight;
        short colourPlanes;
        short bitsPerPixel;
        int compressionType;
        int imageSize;
        int horizontalResolution;
        int verticalResolution;
        int numberOfColours;
        int NumberOfImportantColours;

        private int getPixelWidth() {return pixelWidth;}

        private int getPixelHeight() {return pixelHeight;}
        DIBHeader() {
            this(fileName);
        }
        DIBHeader(String fileName) {
            readFromFile(fileName);
        }
        private native int readFromFile(String fileName);

        private native int saveInFile(String fileName);
    }

    private class DIBColorProfile {
        int redmask;
        int greenmask;
        int bluemask;
        int alphamask;
        int colourspace;
        int redendpointX;
        int redendpointY;
        int redendpointZ;
        int greenendpointX;
        int greenendpointY;
        int greenendpointZ;
        int blueendpointX;
        int blueendpointY;
        int blueendpointZ;
        int gammared;
        int gammagreen;
        int gammablue;
        int intent;
        int profileData;
        int profileSize;
        int nothing;

        static {
           System.loadLibrary("BitMaPDIBColorProfileNativeLib");
        }
        DIBColorProfile() {
            this(fileName);
        }
        DIBColorProfile(String filename) {
            readFromFile(filename);
        }
        private native int readFromFile(String fileName);

        private native int saveInFile(String fileName);
    }

    private class Data {
        Pixel[][] Picture;
        static {
            System.loadLibrary("BitMaPDataNativeLib");
        }
        Data(String filename) {
            Picture = readFromFile(filename, DIBHeader.getPixelHeight(), DIBHeader.getPixelWidth());
        }
        private native Pixel[][] readFromFile(String fileName, int Height, int Width);

        private native void saveInFile(String fileName, Pixel[][] Pixels, int Height, int Width);
    }
    public BitMaP() {
        this(null);
    }
    public BitMaP(String filename) {
        this.fileName = filename;
        FileHeader = new FileHeader(fileName);
        DIBHeader = new DIBHeader(fileName);
        DIBColorProfile = new DIBColorProfile(filename);
        Data = new Data(filename);
    }

    public boolean readBMPFromFIle(String fileName) {
        FileHeader.readFromFile(fileName);
        DIBHeader.readFromFile(fileName);
        DIBColorProfile.readFromFile(fileName);
        Data.readFromFile(fileName, DIBHeader.pixelHeight, DIBHeader.pixelWidth);
        return true;
    }

    public boolean saveBMPInFIle(String fileName) {
        FileHeader.saveInFile(fileName);
        DIBHeader.saveInFile(fileName);
        DIBColorProfile.saveInFile(fileName);
        Data.saveInFile(fileName, Data.Picture, DIBHeader.pixelHeight, DIBHeader.pixelWidth);
        return true;
    }

    public void setContrast(double contrast) {
        int lAB = 0;
        for (int j = 0; j < DIBHeader.pixelHeight; j++)
        {
            for (int i = 0; i < DIBHeader.pixelWidth; i++) {
                byte valueB = Data.Picture[j][i].getBlue();
                byte valueG = Data.Picture[j][i].getGreen();
                byte valueR = Data.Picture[j][i].getRed();

                lAB += (int) (Byte.toUnsignedInt(valueR) * 0.299 + Byte.toUnsignedInt(valueG) * 0.587 + Byte.toUnsignedInt(valueB) * 0.114);
            }
        }

//средняя яркость
        lAB /= DIBHeader.pixelHeight * DIBHeader.pixelWidth;

        //Коэффициент коррекции
        double k = 1.0 + (contrast*25500.0);

        byte[] bp = new byte[256];
        //RGB алгоритм изменения контраста
        for (int i = 0; i < 256; i++)
        {
            int delta = (int)i - lAB;
            int temp  = (int)(lAB + k * delta);

            if (temp < 0)
                temp = 0;

            if (temp >= 255)
                temp = 255;
            bp[i] = (byte)temp;
        }

        for (int j = 0; j < DIBHeader.pixelHeight; j++)
        {
            for (int i = 0; i < DIBHeader.pixelWidth; i++) {
                byte value = Data.Picture[j][i].getRed();
                Data.Picture[j][i].setRed((byte)bp[Byte.toUnsignedInt(value)]);
                value = Data.Picture[j][i].getGreen();
                Data.Picture[j][i].setGreen((byte)bp[Byte.toUnsignedInt(value)]);
                value = Data.Picture[j][i].getBlue();
                Data.Picture[j][i].setBlue((byte)bp[Byte.toUnsignedInt(value)]);
            }
        }
    }

    public void setBrightness(double Brightness) {
        Brightness *= 255;
        int const1 = (int)Brightness;
        for (int j = 0; j < DIBHeader.pixelHeight; j++)
        {
            for (int i = 0; i < DIBHeader.pixelWidth; i++) {
                int value = Data.Picture[j][i].getIntRed();
                if ((int)(value+Brightness) > 255) {
                    const1 = 255;
                }
                else if ((int)(value+Brightness) < 0) {
                    const1 = 0;
                }
                else {
                    const1 = (int)(value+Brightness);
                }
                Data.Picture[j][i].setRed((byte)(const1));
                value = Data.Picture[j][i].getGreen();
                Data.Picture[j][i].setGreen((byte)(const1));
                value = Data.Picture[j][i].getBlue();
                Data.Picture[j][i].setBlue((byte)(const1));
            }
        }
    }

    public void SetZoom(double Zoom) {
        Pixel NewPicture[][] = new Pixel[DIBHeader.pixelHeight][DIBHeader.pixelWidth];

    }
}

