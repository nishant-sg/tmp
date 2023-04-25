class Dekker {
    static boolean[] flag = { false, false };
    static int turn = 0;
    static int N = 4;

    static Thread process(int i) {
        return new Thread(() -> {
            int j = 1 - i;
            for (int n = 0; n < N; n++) {
                log(i + ": want CS");
                flag[i] = true;
                while (flag[j]) {
                    if (turn == i) {
                        Thread.yield();
                        continue;
                    }
                    flag[i] = false;
                    while (turn == j)
                        Thread.yield();
                    flag[i] = true;
                }

                log(i + ": in CS" + n);
                sleep(1000 * Math.random());

                log(i + ": done CS");
                turn = j;
                flag[i] = false;
            }
        });
    }

    public static void main(String[] args) {
        try {
            log("Starting 2 processes (threads) ...");
            Thread p0 = process(0);
            Thread p1 = process(1);
            p0.start();
            p1.start();
            p0.join();
            p1.join();
        } catch (InterruptedException e) {
        }
    }

    static void sleep(double t) {
        try {
            Thread.sleep((long) t);
        } catch (InterruptedException e) {
        }
    }

    static void log(String x) {
        System.out.println(x);
    }
}