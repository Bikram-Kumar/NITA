from collections import deque 


def mlq_scheduling(processes, quantum=2): 
    system_queue = [p for p in processes if p[3] == "System"] 
    user_queue = deque([p for p in processes if p[3] == "User"]) 
    system_queue.sort(key=lambda x: x[1]) 
    time = 0 
    log = [] 
    # Process System queue (FCFS) 
    for pid, at, bt, qtype in system_queue: 
        if time < at: 
            time = at 
        log.append((time, pid)) 
        time += bt 
    # Process User queue (Round Robin) 
    user_burst = {p[0]: p[2] for p in user_queue} 
    arrival_map = {p[0]: p[1] for p in user_queue} 
    while user_queue: 
        pid, at, bt, _ = user_queue.popleft() 
        if arrival_map[pid] > time: 
            user_queue.append((pid, at, bt, "User")) 
            time += 1 
            continue 
        exec_time = min(quantum, user_burst[pid]) 
        user_burst[pid] -= exec_time 
        log.append((time, pid)) 
        time += exec_time 
        if user_burst[pid] > 0: 
            user_queue.append((pid, at, bt, "User")) 

    return log 
    


def prevent_starvation(processes, max_wait=10): 
    time = 0 
    promoted = [] 
    user_wait = {p[0]: 0 for p in processes if p[3] == "User"} 
    for _ in range(20): 
        for pid in user_wait: 
            user_wait[pid] += 1 
            if user_wait[pid] > max_wait: 
                promoted.append(pid) 
                user_wait[pid] = 0 
    return promoted



def time_sliced_scheduling(processes, time_slice=4): 
    system_q = [p for p in processes if p[3] == "System"] 
    user_q = [p for p in processes if p[3] == "User"] 
    time = 0 
    execution_order = [] 
    while system_q or user_q:
        # system slice 
        slice_used = 0 
        while slice_used < time_slice and system_q:
            pid, at, bt, _ = system_q.pop(0) 
            slice_used += bt 
            time += bt 
            execution_order.append((time, pid)) 
        # user slice 
        slice_used = 0 
        while slice_used < time_slice and user_q: 
            pid, at, bt, _ = user_q.pop(0) 
            exec_time = min(2, bt) 
            slice_used += exec_time
            time += exec_time 
            execution_order.append((time, pid))
    return execution_order



def performance_metrics(log, total_time): 
    first_response = {} 
    for time, pid in log: 
        if pid not in first_response: 
            first_response[pid] = time 
            response_times = list(first_response.values()) 
            avg_response = sum(response_times) / len(response_times) 
            context_switches = len(log) - 1 
            throughput = len(set(pid for _, pid in log)) / total_time 
    return avg_response, throughput, context_switches





def main():
    processes_mlq = [ 
        ("P1", 0, 5, "System"), 
        ("P2", 1, 3, "User"), 
        ("P3", 2, 8, "User"), 
        ("P4", 3, 6, "System") 
    ]
    log = mlq_scheduling(processes_mlq) 
    for entry in log: 
        print(f"Time {entry[0]}: {entry[1]} executed")
    
    print("Starvation-prevention moved to system queue:", 
           prevent_starvation(processes_mlq))
    
    print(time_sliced_scheduling(processes_mlq))
    
    avg_r, thpt, cs = performance_metrics(log, 20) 
    print("Avg Response Time:", avg_r) 
    print("Throughput:", thpt) 
    print("Context Switches:", cs)
main()