import os 
import time
from multiprocessing import Process, Array, Queue, Lock, Semaphore

def unnamed_pipe_demo(): 
    r, w = os.pipe() # Create pipe (read-end `r`, write-end `w`) 
    pid = os.fork() # Create child process 
    if pid > 0: # Parent process 
        os.close(r) # Close read-end (parent writes) 
        message = "Hello from parent!"
        os.write(w, message.encode()) # Write to pipe 
        os.close(w) # Close write-end 
    else: # Child process 
        os.close(w) # Close write-end (child reads) 
        data = os.read(r, 100) # Read from pipe 
        print("Child received:", data.decode()) 
        os.close(r) # Close read-end
        os._exit(0)
        
def named_pipe_demo(): 
    fifo_path = os.environ['HOME'] + "/.temp/myfifo"
    os.mkfifo(fifo_path) # Create named pipe 
    pid = os.fork() 
    if pid > 0: # Parent (Writer) 
        with open(fifo_path, 'w') as fifo: 
            fifo.write("Hello from parent via FIFO!") 
    else: # Child (Reader) 
        with open(fifo_path, 'r') as fifo: 
            print("Child received:", fifo.read()) 
        os.unlink(fifo_path) # Remove FIFO file
        os._exit(0)

        
        
def parent_child_pipe(): 
    r, w = os.pipe() 
    pid = os.fork() 
    if pid > 0: # Parent 
        os.close(r) 
        msg = "Parent sends a message" 
        os.write(w, msg.encode()) 
        os.close(w) 
    else: # Child 
        os.close(w) 
        data = os.read(r, 100) 
        print("Child reads:", data.decode()) 
        os.close(r)
        os._exit(0)
        
        
def shared_memory_demo(): 
    arr = Array('i', [0, 1, 2]) # Shared array of integers 
    def modify(): 
        for i in range(len(arr)): 
            arr[i] *= 2 # Double each element 
    p = Process(target=modify) 
    p.start() 
    p.join() 
    print("Modified array:", list(arr))
    
def producer(q, lock): 
    for i in range(5): 
        lock.acquire() 
        q.put(i) 
        print(f"Produced: {i}") 
        lock.release() 
        time.sleep(1)
        
        
def consumer(q, lock): 
    while True: 
        lock.acquire() 
        if not q.empty(): 
            item = q.get() 
            print(f"Consumed: {item}") 
        lock.release() 
        time.sleep(1)
        
        
def task(sem, id): 
    sem.acquire() 
    print(f"Process {id} enters critical section") 
    time.sleep(2) 
    print(f"Process {id} exits critical section") 
    sem.release()
        
        
def main():
    unnamed_pipe_demo()
    named_pipe_demo()
    parent_child_pipe()
    shared_memory_demo()
    
    q = Queue() 
    lock = Lock() 
    p1 = Process(target=producer, args=(q, lock)) 
    p2 = Process(target=consumer, args=(q, lock)) 
    p1.start() 
    p2.start() 
    p1.join() 
    p2.terminate() # Force stop consumer
    
    sem = Semaphore(2) # Allow 2 processes at a time 
    processes = [Process(target=task, args=(sem, i)) for i in range(4)] 
    for p in processes: 
        p.start() 
    for p in processes: 
        p.join()
        
        
main()