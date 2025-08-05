import os 
import shutil 
import subprocess




def main():
    p1()
    p2()
    p3()
    p4()
    p5()
    p6()
    
    
# Simulate Basic Unix Commands (ls, pwd, cd, mkdir, etc.)
def p1():
    print("Current Directory:", os.getcwd()) 
    os.mkdir("demo_dir") 
    print("Directory created: demo_dir") 
    os.chdir("demo_dir") 
    print("Changed Directory:", os.getcwd()) 
    os.chdir("..") 
    
    open("source.txt", "w")
    
    shutil.copy("source.txt", "backup.txt") # cp 
    shutil.move("source.txt", "demo_dir/") # mv 
    os.remove("demo_dir/source.txt") # rmgetcwd())
    os.remove("backup.txt") # rmgetcwd())

    os.rmdir("demo_dir") 
    print("Directory removed: demo_dir") 
    
# List Hidden and Regular Files
def p2():
    files = os.listdir(".") 
    hidden = [f for f in files if f.startswith('.')] 
    regular = [f for f in files if not f.startswith('.')]
    print("Hidden files:", hidden) 
    print("Regular files:", regular)
    
    
    
    
    

# Display Running Processes (ps)
def p3():
    output = subprocess.getoutput("ps aux") 
    print(output)
    
    
    
    
    
# Build a Mini Shell in Python
def p4():
    while True: 
     cmd = input("MyShell$ ") 
     if cmd.lower() in ["exit", "quit"]: 
        break 
     result = subprocess.run(cmd, shell=True, text=True, capture_output=True) 
     print(result.stdout)


    
# Simulate grep and wc Functionality
def p5():
    
    def grep(filename, keyword): 
        with open(filename, 'r') as file: 
            for line in file: 
                if keyword in line: 
                    print(line, end='') 
    def wc(filename): 
        with open(filename, 'r') as file: 
            text = file.read() 
            lines = text.count('\n') 
            words = len(text.split()) 
            chars = len(text) 
            print(f"Lines: {lines}, Words: {words}, Characters: {chars}") 
            
    grep("basic.py", "current") 
    wc("basic.py")



# View/Modify File Permissions
def p6():
    filename = "basic.py" 
    perm = oct(os.stat(filename).st_mode)[-3:] 
    print(f"Current Permissions: {perm}") 
    # Change to 755 (rwxr-xr-x) 
    os.chmod(filename, 0o755) 
    print("Permissions changed to 755")
    
main()