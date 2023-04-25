import threading
import time

n = 5
forks = [threading.Semaphore(1) for i in range(n)]
mutex = threading.Semaphore(1)

def philosopher(i):
    while True:
        # think for a while
        print(f"Philosopher {i} is thinking")
        time.sleep(1)
        
        # pick up forks
        mutex.acquire()
        forks[i].acquire()
        forks[(i+1) % n].acquire()
        mutex.release()
        
        # eat for a while
        print(f"Philosopher {i} is eating")
        time.sleep(2)
        
        # put down forks
        forks[i].release()
        forks[(i+1) % n].release()

# create n philosopher threads
philosopher_threads = []
for i in range(n):
    philosopher_thread = threading.Thread(target=philosopher, args=(i,))
    philosopher_thread.start()
    philosopher_threads.append(philosopher_thread)

# wait for philosopher threads to finish
for philosopher_thread in philosopher_threads:
    philosopher_thread.join()