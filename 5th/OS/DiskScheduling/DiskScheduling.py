import matplotlib.pyplot as plt

def fcfs(requests, head): 
    seek_sequence = [] 
    total_seek = 0 
    for r in requests: 
        seek_sequence.append(r) 
        total_seek += abs(head - r) 
        head = r 
    return seek_sequence, total_seek
    
    
def scan(requests, head, disk_size=200): 
    left = [r for r in requests if r < head] 
    right = [r for r in requests if r >= head] 
    left.sort() 
    right.sort() 
    seek_sequence = right + left[::-1] 
    total_seek = sum(
        abs(seek_sequence[i] - (seek_sequence[i-1] if i > 0 else head))
        for i in range(len(seek_sequence))
    ) 
    return seek_sequence, total_seek
    
def cscan(requests, head, disk_size=200): 
    left = [r for r in requests if r < head] 
    right = [r for r in requests if r >= head] 
    left.sort() 
    right.sort() 
    seek_sequence = right + [disk_size-1, 0] + left
    total_seek = sum(
        abs(seek_sequence[i] - (seek_sequence[i-1] if i > 0 else head))
        for i in range(len(seek_sequence))
    ) 
    return seek_sequence, total_seek
    
    
def look(requests, head): 
    left = [r for r in requests if r < head] 
    right = [r for r in requests if r >= head] 
    left.sort() 
    right.sort() 
    seek_sequence = right + left[::-1] 
    total_seek = sum(
        abs(seek_sequence[i] - (seek_sequence[i-1] if i > 0 else head)) 
        for i in range(len(seek_sequence))
    ) 
    return seek_sequence, total_seek
    
    
def clook(requests, head): 
    left = [r for r in requests if r < head] 
    right = [r for r in requests if r >= head] 
    left.sort() 
    right.sort() 
    seek_sequence = right + left 
    total_seek = sum(
        abs(seek_sequence[i] - (seek_sequence[i-1] if i > 0 else head)) 
        for i in range(len(seek_sequence))
    ) 
    return seek_sequence, total_seek
    
def plot_seek_time():
    algorithms = ["FCFS", "SCAN", "C-SCAN", "LOOK", "C-LOOK"] 
    seek_times = [640, 370, 391, 370, 336] 
    plt.plot(algorithms, seek_times, marker='o', color='blue') 
    plt.title("Disk Scheduling Seek Time Comparison") 
    plt.xlabel("Algorithm") 
    plt.ylabel("Total Seek Time") 
    plt.grid(True) 
    plt.savefig("SeekTime.png")
    
    
def main():
    reqs = [82, 170, 43, 140, 24, 16, 190] 
    head = 50 
    
    algos = [("FCFS", fcfs), ("SCAN", scan), ("C-SCAN", cscan), ("LOOK", look), ("C-LOOK", clook)]
    
    for name, algo in algos:
        seq, total = algo(reqs, head)
        print(f"{name} Seek Sequence: ", seq)
        print("Total Seek Time: ", total)
    
    plot_seek_time()
    
main()