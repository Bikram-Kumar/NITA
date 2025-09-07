from collections import deque 
import matplotlib.pyplot as plt 



def fcfs_scheduling(processes): 
    processes.sort(key=lambda x: x[1]) 
    time = 0 
    result = [] 
    for pid, at, bt in processes: 
        start = max(time, at) 
        ct = start + bt 
        tat = ct - at 
        wt = tat - bt 
        result.append((pid, at, bt, ct, tat, wt)) 
        time = ct 
    return result 
    

 
 
def sjf_scheduling(processes): 
    time = 0 
    completed = [] 
    remaining = processes[:] 
    while remaining: 
        available = [p for p in remaining if p[1] <= time]
        if not available: 
            time += 1 
            continue 
        shortest = min(available, key=lambda x: x[2]) 
        remaining.remove(shortest) 
        pid, at, bt = shortest 
        ct = time + bt 
        tat = ct - at 
        wt = tat - bt 
        completed.append((pid, at, bt, ct, tat, wt)) 
        time = ct 
    return completed 


def priority_scheduling(processes): 
    time = 0 
    completed = [] 
    remaining = processes[:] 
    while remaining: 
        available = [p for p in remaining if p[1] <= time] 
        if not available: 
            time += 1 
            continue 
        highest = min(available, key=lambda x: x[3]) 
        remaining.remove(highest) 
        pid, at, bt, pr = highest 
        ct = time + bt 
        tat = ct - at 
        wt = tat - bt 
        completed.append((pid, at, bt, ct, tat, wt)) 
        time = ct 
    return completed 
    


def round_robin(processes, quantum): 
    time = 0 
    queue = deque() 
    remaining = {p[0]: p[2] for p in processes} 
    at_map = {p[0]: p[1] for p in processes} 
    queue.extend(sorted(processes, key=lambda x: x[1])) 
    result = [] 
    while queue: 
        pid, at, bt = queue.popleft() 
        if at > time: 
            queue.append((pid, at, bt)) 
            time += 1 
            continue 
        exec_time = min(quantum, remaining[pid]) 
        remaining[pid] -= exec_time 
        time += exec_time 
        if remaining[pid] == 0: 
            ct = time 
            tat = ct - at_map[pid] 
            wt = tat - bt 
            result.append((pid, at, bt, ct, tat, wt))
        else: 
            queue.append((pid, at, bt))
    return result
 
def plot_gantt_chart(schedule, name): 
    fig, gnt = plt.subplots() 
    gnt.set_title(name)
    gnt.set_ylim(0, 50) 
    gnt.set_xlim(0, sum(task[2] for task in schedule)) 
    gnt.set_xlabel('Time') 
    gnt.set_ylabel('Process Execution') 
    y = 30 
    start = 0 
    for pid, at, bt, ct, tat, wt in schedule: 
        gnt.broken_barh([(start, bt)], (y, 9), facecolors='tab:blue') 
        gnt.text(start + bt/2 - 0.5, y + 1, pid) 
        start += bt 
    plt.savefig(f"{name}.png")
    
    
def compute_averages(schedule): 
    total_tat = sum(p[4] for p in schedule) 
    total_wt = sum(p[5] for p in schedule) 
    n = len(schedule) 
    print("Average Turnaround Time:", total_tat / n) 
    print("Average Waiting Time:", total_wt / n) 
    
    
    
    
def main():
    
    processes_fcfs = [ 
         ("P1", 0, 5), 
         ("P2", 1, 3), 
         ("P3", 2, 8), 
         ("P4", 3, 6) 
    ] 
    processes_priority = [ 
         ("P1", 0, 10, 3), 
         ("P2", 2, 1, 1), 
         ("P3", 3, 2, 4),
         ("P4", 5, 1, 2) 
    ] 
    
    quantum = 3
    
    algos = [("FCFS", fcfs_scheduling), ("SJF", sjf_scheduling),
             ("Priority", priority_scheduling), ("Round Robin", round_robin)]
        
    for name, algo in algos:
        print("\n", name)
        if algo == priority_scheduling: 
            schedule = algo(processes_priority) 
        elif algo == round_robin: 
            schedule = algo(processes_fcfs, quantum) 
        else:
            schedule = algo(processes_fcfs)
            
        for row in schedule: 
            print(row)
        
        plot_gantt_chart(schedule, name)
        compute_averages(schedule)
        
 
    
main()