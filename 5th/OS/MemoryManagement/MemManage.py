import matplotlib.pyplot as plt 


def mft():
    partition_size = 100 
    memory_size = 500 
    processes = [90, 20, 50, 70, 40] 
    partitions = memory_size // partition_size 
    print("MFT Allocation:") 
    for i in range(partitions): 
        if i < len(processes): 
            print(f"Partition {i+1}: Process {i+1} -> {processes[i]} KB") 
            print(f"Internal Fragmentation: {partition_size - processes[i]} KB") 
        else: 
            print(f"Partition {i+1}: Empty")


def mvt():
    memory_size = 1000 
    processes = [212, 417, 112, 426] 
    total_used = 0 
    print("MVT Allocation:") 
    for i, p in enumerate(processes): 
        if total_used + p <= memory_size: 
            print(f"Process {i+1} allocated {p} KB") 
            total_used += p 
        else: 
            print(f"Process {i+1} -> Not enough memory") 
    print("Memory Left:", memory_size - total_used, "KB")


def allocate_memory(strategy): 
    blocks = [100, 500, 200, 300, 600] 
    processes = [212, 417, 112, 426] 
    allocation = [-1] * len(processes) 
    for i, p in enumerate(processes): 
        idx = -1 
        for j, b in enumerate(blocks): 
            if b >= p: 
                if strategy == "first" and allocation[i] == -1: 
                    idx = j 
                    break
                elif strategy == "best" and (idx == -1 or blocks[j] < blocks[idx]): 
                    idx = j 
                elif strategy == "worst" and (idx == -1 or blocks[j] > blocks[idx]): 
                    idx = j
        if idx != -1: 
            allocation[i] = idx 
            blocks[idx] -= p 
    return allocation
    
def page_address_translation():
    page_table = [5, 1, 2, 6, 3, 4] 
    logical_addresses = [0, 1, 2, 3, 4] 
    frame_size = 100 
    print("Logical to Physical Address Mapping:") 
    for la in logical_addresses: 
        frame_no = page_table[la] 
        pa = frame_no * frame_size 
        print(f"Logical Page {la} -> Frame {frame_no}, Physical Address = {pa}")
        
def page_table_construct():
    pages = [0, 1, 2, 3] 
    frames = [2, 0, 1, 3] 
    print("Page Table:") 
    print("Page No Frame No") 
    for p, f in zip(pages, frames): 
        print(f"{p} {f}")
        
def plot_frag():
    labels = ['Used', 'Internal Fragmentation', 'External Fragmentation'] 
    sizes = [700, 150, 150] 
    plt.pie(sizes, labels=labels, autopct='%1.1f%%') 
    plt.title('Memory Fragmentation') 
    plt.savefig("Frag.png")
    
def main():
    mft()
    mvt()
    
    print("First Fit Allocation:", allocate_memory("first")) 
    print("Best Fit Allocation:", allocate_memory("best")) 
    print("Worst Fit Allocation:", allocate_memory("worst"))
    
    page_address_translation()
    page_table_construct()
    plot_frag()
    
main()