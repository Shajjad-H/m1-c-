


/**
 * Main
 */
public class Main {

    public static void main(String[] args) {

        int i_max = 10000;
        int h = 100, l = 100; 
        Image img = new Image(h, l);
        Pixel p = new Pixel(230, 123, 21);

        for (int k = 0; k < i_max; k++) {
            
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < l; j++) {
        
                    img.setPixel(i, j, p);
                    
                }
            }
        }
    }
}