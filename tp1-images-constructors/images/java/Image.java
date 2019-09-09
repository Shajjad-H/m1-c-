
/**
 * Image
 */
public class Image {
    protected int h, l;
    protected Pixel[] pixels;

    public Image(int h, int l) {
        this.h = h;
        this.l = l;
        this.pixels = new Pixel[h * l];
    }
    
    protected int getIndex(int h, int l) {
        return this.h * h + l;
    }

    public Pixel getPixel(int h, int l) {
        return this.pixels[ this.getIndex(h, l)];
    }

    public void setPixel(int h, int l, Pixel p) {
        this.pixels[ this.getIndex(h, l)] = p;
    }
}