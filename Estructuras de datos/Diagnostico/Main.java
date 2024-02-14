import java.io.IOException;
import java.util.Scanner;

class Cuadrado {
    private int ancho;
    private int alto;
    private boolean lleno;
    private int x;
    private int y;

    public Cuadrado(int ancho, int alto, boolean lleno) {
        this.ancho = ancho;
        this.alto = alto;
        this.lleno = lleno;
        this.x = 0;
        this.y = 0;
    }

    public void dibujar() {
        for (int i = 0; i < this.y; i++) {
            System.out.println();
        }
        for (int i = 0; i < this.alto; i++) {
            if (i == 0 || i == this.alto - 1 || lleno) {
                System.out.println(" ".repeat(this.x) + "*  ".repeat(this.ancho));
            } else {
                System.out.println(" ".repeat(this.x) + "*  " + "   ".repeat(this.ancho - 2) + "*");
            }
        }
    }

    public void mover(String direccion) {
        if (direccion.equals("arriba") && this.y > 0) {
            this.y--;
        } else if (direccion.equals("abajo")) {
            this.y++;
        } else if (direccion.equals("izquierda") && this.x > 0) {
            this.x --;
        } else if (direccion.equals("derecha")) {
            this.x ++;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Introduce el ancho del cuadrado: ");
        int ancho = in.nextInt();
        System.out.print("Introduce el alto del cuadrado: ");
        int alto = in.nextInt();
        System.out.print("¿El cuadrado será lleno? (si/no): ");
        boolean lleno = in.next().equalsIgnoreCase("si");

        Cuadrado cuadrado = new Cuadrado(ancho, alto, lleno);

        while (true) {
            limpiarConsola();
            cuadrado.dibujar();
            System.out.print("Introduce la dirección (arriba/abajo/izquierda/derecha): ");
            String direccion = in.next().toLowerCase();
            if(direccion.equals("exit")){
                break;
            }
            cuadrado.mover(direccion);
        }
        in.close();
    }

    public static void limpiarConsola() {
        try {
            final String os = System.getProperty("os.name");
            ProcessBuilder pb;
            if (os.contains("Windows")) {
                pb = new ProcessBuilder("cmd", "/c", "cls");
            } else {
                pb = new ProcessBuilder("clear");
            }
            pb.inheritIO().start().waitFor();
        } catch (final InterruptedException | IOException e) {
            System.out.println("Error al limpiar la consola: " + e.getMessage());
        }
    }
}
