class lamport extends Thread {

	public int thread_id;
	public static final int countToThis = 200;
	public static final int numberOfThreads = 5;
	public static volatile int count = 0;

	private static volatile boolean[] choosing = new boolean[numberOfThreads];

	private static volatile int[] ticket = new int[numberOfThreads];

	public lamport(int id) {
		thread_id = id;
	}

	public void run() {
		int scale = 2;

		for (int i = 0; i < countToThis; i++) {

			lock(thread_id);
			count = count + 1;
			System.out.println("I am " + thread_id + " and count is: " + count);

			try {
				sleep((int) (Math.random() * scale));
			} catch (InterruptedException e) {
			}
			unlock(thread_id);

		} // for

	}

	public void lock(int id) {
		choosing[id] = true;

		ticket[id] = findMax() + 1;
		choosing[id] = false;

		for (int j = 0; j < numberOfThreads; j++) {

			if (j == id)
				continue;

			while (choosing[j]) {
				/* nothing */ }

			while (ticket[j] != 0 && (ticket[id] > ticket[j] || (ticket[id] == ticket[j] && id > j))) {
				/* nothing */ }

		} // for
	}

	private void unlock(int id) {
		ticket[id] = 0;
	}

	private int findMax() {

		int m = ticket[0];

		for (int i = 1; i < ticket.length; i++) {
			if (ticket[i] > m)
				m = ticket[i];
		}
		return m;
	}

	public static void main(String[] args) {

		for (int i = 0; i < numberOfThreads; i++) {
			choosing[i] = false;
			ticket[i] = 0;
		}

		lamport[] threads = new lamport[numberOfThreads]; // Array of threads.

		for (int i = 0; i < threads.length; i++) {
			threads[i] = new lamport(i);
			threads[i].start();
		}

		for (int i = 0; i < threads.length; i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		System.out.println("\nCount is: " + count);
		System.out.println("\nExpected was: " + (countToThis * numberOfThreads));
	} // main

}
