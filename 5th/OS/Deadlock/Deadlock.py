import networkx as nx
import matplotlib.pyplot as plt

def bankers_algorithm(processes, available, max_req, allocation): 
    n = len(processes)
    need = [[max_req[i][j] - allocation[i][j] for j in range(len(available))] for i in range(n)] 
    work = available.copy() 
    finish = [False] * n 
    safe_seq = [] 
    while len(safe_seq) < n:
        found = False 
        for i in range(n): 
            if not finish[i] and all(need[i][j] <= work[j] for j in range(len(work))): 
                work = [work[j] + allocation[i][j] for j in range(len(work))] 
                finish[i] = True 
                safe_seq.append(processes[i]) 
                found = True 
                
        if not found: return (False, []) 
    return (True, safe_seq)
    
    
def safety_algorithm(processes, available, max_req, allocation): 
    need = [[max_req[i][j] - allocation[i][j] for j in range(len(available))] for i in range(len(processes))] 
    work = available.copy() 
    finish = [False] * len(processes) 
    safe_seq = [] 
    while True: 
        found = False 
        for i in range(len(processes)): 
            if not finish[i] and all(need[i][j] <= work[j] for j in range(len(work))):
                work = [work[j] + allocation[i][j] for j in range(len(work))] 
                finish[i] = True 
                safe_seq.append(processes[i]) 
                found = True
                
        if not found: break 
    return (all(finish), safe_seq)
    
    
def resource_ordering(processes, resources):
    ordered_resources = sorted(resources)
    for p in processes:
        p['resources'] = sorted(p['resources'], key=lambda x: ordered_resources.index(x))
    return processes


def request_resources(process_id, request, available, allocation, need):
    if all(request[j] <= need[process_id][j] for j in range(len(request))):
        if all(request[j] <= available[j] for j in range(len(request))):
            available = [available[j] - request[j] for j in range(len(request))]
            allocation[process_id] = [allocation[process_id][j] + request[j] for j in range(len(request))]
            need[process_id] = [need[process_id][j] - request[j] for j in range(len(request))]
            return (True, available, allocation, need)
    return (False, available, allocation, need)


def draw_rag():
    G = nx.DiGraph()

    processes = ["P1", "P2"]
    resources = ["R1", "R2"]
    G.add_nodes_from(processes, type='process')
    G.add_nodes_from(resources, type='resource')


    # Edges represent requests/allocations 
    # Format: (Process -> Resource) = Request, (Resource -> Process) = Allocation
    G.add_edge("P1", "R1")  # P1 requests R1
    G.add_edge("R1", "P2")  # R1 is held by P2
    G.add_edge("P2", "R2")  # P2 requests R2
    G.add_edge("R2", "P1")  # R2 is held by P1
    
    color_map = []
    for node in G:
        if G.nodes[node]['type'] == 'process':
            color_map.append('lightblue')
        else:
            color_map.append('lightgreen')

    pos = { "P1": (0, 1), "P2": (0, 0), "R1": (1, 1), "R2": (1, 0) }

    # Draw the graph
    nx.draw(
        G, pos, with_labels=True, node_size=1500,
        node_color=color_map, font_size=10,
        arrowsize=20, arrowstyle='->'
    )
    plt.title("Resource Allocation Graph (RAG)")
    plt.savefig("RAG.png")


def main():
    
    processes = ['P0', 'P1', 'P2', 'P3']
    available = [3, 3, 2]
    max_req = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2]]
    allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1]]
    is_safe, seq = bankers_algorithm(processes, available, max_req, allocation) 
    print("Safe State:", is_safe) 
    print("Safe Sequence:", seq)
    
    
    is_safe, seq = safety_algorithm(processes, available, max_req, allocation) 
    print("System is Safe:", is_safe) 
    print("Safe Sequence:", seq)
        
        
    
    processes = [ {'name': 'P1', 'resources': ['R3', 'R1', 'R2']},
                  {'name': 'P2', 'resources': ['R2', 'R1']}  ]
    resources = ['R1', 'R2', 'R3']
    ordered_processes = resource_ordering(processes, resources)
    print("Ordered Processes:", ordered_processes)

    
    
    available = [3, 3, 2] 
    allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1]] 
    need = [[7, 4, 3], [1, 2, 2], [6, 0, 0], [0, 1, 1]] 
    request = [1, 0, 2] 
    success, new_avail, new_alloc, new_need = request_resources(1, request, 
    available, allocation, need) 
    print("Request Granted:", success)
    
    
    draw_rag()

main()