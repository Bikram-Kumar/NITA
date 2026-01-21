import keyword 
import re
from collections import Counter


def analyze_file(filename): 
    with open(filename, 'r') as file: 
        lines = file.readlines() 
    total_lines = len(lines) 
    blank_lines = sum(1 for line in lines if line.strip() == "") 
    total_words = sum(len(line.split()) for line in lines) 
    total_chars = sum(len(line.replace(" ", "").replace("\n", "")) for line in lines) 
    print("Lines:", total_lines) 
    print("Blank Lines:", blank_lines) 
    print("Words:", total_words) 
    print("Characters:", total_chars)
        
def student_data(): 
    n = int(input("Enter number of students: ")) 
    records = [] 
    for _ in range(n): 
        roll = input("Roll No: ") 
        name = input("Name: ") 
        marks = float(input("Marks: ")) 
        records.append((roll, name, marks)) 
    with open("students.txt", "w") as f: 
        for r in records: 
            f.write(f"{r[0]} {r[1]} {r[2]}\n") 
    marks_list = [r[2] for r in records] 
    print("Average Marks:", sum(marks_list)/n) 
    print("Highest Marks:", max(marks_list)) 
    print("Lowest Marks:", min(marks_list))
    


def delete_lines(filename, remove_lines): 
    with open(filename, 'r') as f: 
        lines = f.readlines() 
    with open(filename, 'w') as f: 
        for i, line in enumerate(lines, start=1): 
            if i not in remove_lines: 
                f.write(line)
                
                
def copy_clean(src, dest): 
    with open(src, 'r') as s, open(dest, 'w') as d:
        for line in s: 
            if not line.strip().startswith("#"): 
                d.write(line)
                
                
def lexical_analysis(filename): 
    with open(filename, 'r') as f: 
        code = f.read() 
    tokens = re.findall(r'\b\w+\b|[+\-*/%=<>(),]', code) 
    for token in tokens: 
        if keyword.iskeyword(token): 
            print(token, "-> Keyword") 
        elif token.isidentifier(): 
            print(token, "-> Identifier") 
        elif token.isnumeric(): 
            print(token, "-> Literal") 
        elif token in "+-*/%=<>": 
            print(token, "-> Operator")
        else: 
            print(token, "-> Delimiter")
            
            
            
            
def sanitize(source, drop, report): 
    with open(drop, 'r') as f: 
        forbidden = f.read().split() 
    with open(source, 'r') as f: 
        words = f.read().split() 
    count = Counter(words) 
    filtered = [w for w in words if w not in forbidden] 
    with open(source, 'w') as f: 
        f.write(" ".join(filtered)) 
    with open(report, 'w') as f: 
        for word in forbidden: 
            f.write(f"{word} : {count[word]} times\n")
            
            
def main():
    analyze_file("input.txt")
    student_data()
    delete_lines("delete_lines.txt", [3, 6])
    copy_clean("source.txt", "destination.txt")
    lexical_analysis("source.txt")
    sanitize("input.txt", "drop.txt", "report.txt")
    
main()