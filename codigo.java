package leitorescritor;

public class LeitorEscritor {

    public static void main(String[] args) {
       cPublica publica = new cPublica();
       cSemaforo semaforo = new cSemaforo (1);
       cSemaforo db = new cSemaforo (1);
       
       cEscritor escritor1 = new cEscritor (publica, semaforo, db, 1);
       cEscritor escritor2 = new cEscritor (publica, semaforo, db, 2);
       
       cLeitor leitor1 = new cLeitor (publica, semaforo, db, 1);
       cLeitor leitor2 = new cLeitor (publica, semaforo, db, 2);
       
       escritor1.start();
       escritor2.start();
       leitor1.start();
       leitor2.start();
       
    }
    
}

class cSemaforo {
    int sem;
    public cSemaforo (int s){
        sem = s;
    }
    public synchronized void down (String proc, int id) {
        while (sem==0){
            System.out.println (proc+id+"bloqueado");
            try{wait();} catch (InterruptedException e){}
            }
        sem --;
    }
    public synchronized void up(){
        if(sem==0)
            notifyAll();
            sem++;
    }
}

class cPublica {
    int rc;
    public cPublica(){
        rc = 0;
    }
}
class cEscritor extends Thread{
    cPublica publica;
    cSemaforo semaforo, db;
    int identificacao;
    public cEscritor (cPublica vc, cSemaforo s, cSemaforo d, int id){
        publica = vc;
        semaforo =s;
        db = d;
        identificacao = id;
    }
    public void run(){
        db.down("Escritor", identificacao);
        System.out.println ("Escritor"+identificacao+ "libera o livro ...");
        db.up();
        }
}
class cLeitor extends Thread{
    cPublica publica;
    cSemaforo semaforo, db;
    int identificacao;
    public cLeitor (cPublica vc, cSemaforo s, cSemaforo d, int id){
        publica = vc;
        semaforo = s;
        db = d;
        identificacao = id;
        }
    public void run() {
        semaforo.down("Leitor", identificacao);
        ++publica.rc;
        if (publica.rc == 1)
            db.down("Leitor", identificacao);
        semaforo.up();
        System.out.println ("Leitor"+identificacao+"acessando o livro...");
        System.out.println ("Leitor"+identificacao+"liberar o livro");
        semaforo.down("leitor", identificacao);
        --publica.rc;
        if (publica.rc ==0)
            db.up();
            semaforo.up();
        }
}