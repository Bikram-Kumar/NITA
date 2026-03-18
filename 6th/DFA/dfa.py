from graphviz import Digraph
import networkx as nx
import matplotlib.pyplot as plt

def p1():
    # Simple DFA simulation for regex: a*b
    # States: q0 (start), q1 (final)
    dfa = {
        'q0': {'a': 'q0', 'b': 'q1'},
        'q1': {}
    }
    start_state = 'q0'
    final_states = ['q1']
    def simulate_dfa(string):
        state = start_state
        for char in string:
            if char in dfa[state]:
                state = dfa[state][char]
            else:
                return False
        return state in final_states
    # Test strings
    test_strings = ["b", "ab", "aaab", "a", "abb"]
    for s in test_strings:
        print(s, "->", "Accepted" if simulate_dfa(s) else "Rejected")

def p2():

    # DFA structure
    dfa = {
        'q0': {'a': 'q0', 'b': 'q1'},
        'q1': {}
    }
    G = nx.DiGraph()
    # Add edges
    for state, transitions in dfa.items():
        for symbol, next_state in transitions.items():
            G.add_edge(state, next_state, label=symbol)
    # Draw graph
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=2000)
    edge_labels = nx.get_edge_attributes(G, 'label')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    plt.title("DFA for Regular Expression a*b")
    plt.savefig("dfa.png")



def p3():

    dot = Digraph()
    # States
    dot.node('q0', 'q0 (Start)')
    dot.node('q1', 'q1 (Final)', shape='doublecircle')
    # Transitions
    dot.edge('q0', 'q0', label='a')
    dot.edge('q0', 'q1', label='b')
    # dot.render('dfa_a_star_b', view=True)
    dot.render(outfile='dfa_astarb.svg').replace('\\', '/')




def main():
    p1()
    p2()
    p3()

main()