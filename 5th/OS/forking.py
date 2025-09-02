import os
import time
from multiprocessing import Process

def p1():
    pid = os.fork() 
    if pid == 0: 
        print("Child process created successfully!") 
        os._exit(0)
    else: 
        print("Parent process, child PID is:", pid)
    
    
def p2():
    pid = os.fork()
    if pid == 0:
        print("Before executing ls command...") 
        os.execvp("ls", ["ls", "-l"])
    
    
def p3():
    print("Current PID:", os.getpid()) 
    print("Parent PID:", os.getppid())
    
def p4():
    pid = os.fork() 
    if pid == 0:
        print("Child running...") 
        time.sleep(2) 
        os._exit(0) 
    else: 
        os.wait() 
        print("Child finished, parent resumes.")
        
        
def p5():
    pid = os.fork() 
    if pid == 0: 
        time.sleep(3) 
        print("Orphan child, new parent PID:", os.getppid()) 

    else: 
        os._exit(0)
        
def p6():
    pid = os.fork() 
    if pid == 0: 
        print("Child exiting...") 
        os._exit(0) 
    else: 
        print("Parent sleeping...") 
        time.sleep(5) 
        os.wait()
    
def p7():
    def background_task(): 
        while True: 
            print("Daemon process running...") 
            time.sleep(2) 
        
    p = Process(target=background_task) 
    p.daemon = True 
    p.start()
    print("Main process exiting in 5 seconds") 
    time.sleep(5)
    p.terminate()
    
    
def p8():
    pid = os.getpid() 
    with open(f"/proc/{pid}/status") as f: 
        print(f.read())
        
        
def main():
    arr = [p1, p2, p3, p4, p5, p6, p7, p8]
    for p in arr:
        p()
        time.sleep(6)


main()