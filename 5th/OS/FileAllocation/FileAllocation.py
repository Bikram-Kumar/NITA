import matplotlib.pyplot as plt

def sequential_allocation(file_blocks, disk_size): 
    disk = ['Free'] * disk_size 
    for block in file_blocks: 
        if block < disk_size: 
            disk[block] = 'Allocated' 
    return disk
    
def linked_allocation(file_blocks): 
    allocation = {} 
    for i in range(len(file_blocks) - 1): 
        allocation[file_blocks[i]] = file_blocks[i + 1] # Pointer to next block 
        allocation[file_blocks[-1]] = -1 # End of file 
    return allocation
    
def indexed_allocation(index_block, file_blocks): 
    allocation = {index_block: file_blocks} 
    return allocation
    
def search_file(index_block, target_block, indexed_map): 
    if index_block in indexed_map: 
        return target_block in indexed_map[index_block] 
    return False
    
def visualize_fragmentation(disk): 
    frag = {'Allocated': disk.count('Allocated'), 'Free': disk.count('Free')} 
    plt.bar(frag.keys(), frag.values(), color=['red', 'green']) 
    plt.title("Fragmentation Analysis") 
    plt.ylabel("Block Count") 
    plt.savefig("Frag.png")


def main():
    file_blocks = [1, 2, 3, 4] # Contiguous blocks 
    disk = sequential_allocation(file_blocks, 10) 
    print("Disk Status:", disk)


    file_blocks = [5, 3, 7, 9] # Non-contiguous blocks 
    linked_map = linked_allocation(file_blocks) 
    print("Linked Allocation Map:", linked_map)


    index_block = 0 
    file_blocks = [10, 12, 14] # Blocks storing file data 
    indexed_map = indexed_allocation(index_block, file_blocks) 
    print("Indexed Allocation Map:", indexed_map)
    
    
    target = 12 
    found = search_file(index_block, target, indexed_map) 
    print(f"Block {target} found:", found)
    
    visualize_fragmentation(disk)
    
main()