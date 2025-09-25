from collections import Counter
import matplotlib.pyplot as plt

def fifo(pages, frames): 
    memory = [] 
    faults = 0 
    for p in pages: 
        if p not in memory: 
            faults += 1 
            if len(memory) < frames: 
                memory.append(p) 
            else: 
                memory.pop(0) 
                memory.append(p) 
    return faults
    
    
def lru(pages, frames): 
    memory = [] 
    faults = 0 
    for i, p in enumerate(pages): 
        if p not in memory: 
            faults += 1 
            if len(memory) < frames: 
                memory.append(p) 
            else: 
                lru_idx = min(memory, key=lambda x: pages[:i][::-1].index(x)) 
                memory.remove(lru_idx) 
                memory.append(p) 
    return faults
    
    
def optimal(pages, frames): 
    memory = [] 
    faults = 0 
    for i, p in enumerate(pages): 
        if p not in memory: 
            faults += 1 
            if len(memory) < frames: 
                memory.append(p) 
            else: 
                future = pages[i+1:]
                indices = [future.index(x) if x in future else float('inf') for x in memory] 
                victim = memory[indices.index(max(indices))] 
                memory.remove(victim) 
                memory.append(p)
    return faults
    
def lfu(pages, frames): 
    memory = [] 
    freq = Counter() 
    faults = 0 
    for p in pages: 
        freq[p] += 1 
        if p not in memory: 
            faults += 1 
            if len(memory) < frames: 
                memory.append(p) 
            else: 
                victim = min(memory, key=lambda x: freq[x]) 
                memory.remove(victim) 
                memory.append(p) 
    return faults
    
    
def plot_page_faults(pages, frames):
    
    faults = { 
        'FIFO': fifo(pages, frames), 
        'LRU': lru(pages, frames), 
        'Optimal': optimal(pages, frames), 
        'LFU': lfu(pages, frames) 
    } 
    plt.bar(faults.keys(), faults.values(), color='skyblue') 
    plt.title('Page Fault Comparison') 
    plt.xlabel('Algorithms') 
    plt.ylabel('Page Faults') 
    plt.savefig("PageFaults.png")
    
def main():
    pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2] 
    frames = 3 
    print("FIFO Page Faults:", fifo(pages, frames))
    print("LRU Page Faults:", lru(pages, frames))
    print("Optimal Page Faults:", optimal(pages, frames))
    print("LFU Page Faults:", lfu(pages, frames))
    
    plot_page_faults(pages, frames)
    
main()