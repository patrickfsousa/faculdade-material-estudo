package filosofo;

import static java.time.Clock.system;

public class Filosofo {

    public static void main(String[] args) {
        cPublica publica = new cPublica();
        
        //Números dos filosófos.
        cFilosofo filosofo0= new cFilosofo(publica, 0); 
        cFilosofo filosofo1= new cFilosofo(publica, 1);
        cFilosofo filosofo2= new cFilosofo (publica, 2);
        
        filosofo0.start();
        filosofo1.start();
        filosofo2.start();
        
        
        
        
    }
        
}
class cPublica{
    int[]garfo = new int[3];
    public cPublica(){ // construtor da classe
        for (int i=0; i<3; i++)
            garfo[i] = 0; // 0= garfo livre, 1= garfo ocupado.
   }
public synchronized void pegaGarfo (int g, int f){
    while(garfo[g]==1){
        System.out.println("Filosofo"+f+ "bloqueado ao pegar"+"garfo"+g);
        try{wait();} catch (InterruptedException e) {}    
    }
    garfo[g]= 1;
    System.out.println("Filosofo"+f+"pega garfo"+g+"\t"+garfo[0]+garfo[1+garfo[2]]);

}
public synchronized void soltaGarfo(int g, int f) {
    garfo[g] = 0;
    System.out.println ("Filosofo"+f+"solta garfo"+g+"\t"+garfo[0]+garfo[1]+garfo[2]);
    notifyAll();
}

public void jantar (int f){
    pegaGarfo (f, f);
    pegaGarfo ((f+1)%3, f);
    //faz algum processamento aqui..= jantar
    soltaGarfo (f, f);
    soltaGarfo ((f+1) %3, f);
}
}
class cFilosofo  extends Thread {
    cPublica publica;
    int filosofo;
    public cFilosofo (cPublica p, int f){
        publica = p;
        filosofo = f;
    }
    public void run(){
        publica.jantar(filosofo);
    }


} 