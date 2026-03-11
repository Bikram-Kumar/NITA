from lark import Lark, UnexpectedInput, Token
from collections import Counter

def p1():
    grammar = r"""
    ?start: statement+
    ?statement: IDENTIFIER "=" expr ";"
    ?expr: term (OP term)*
    ?term: NUMBER | IDENTIFIER

    KEYWORD: "int" | "float" | "if" | "else" | "while" | "return"
    IDENTIFIER: /[a-zA-Z_][a-zA-Z0-9_]*/
    NUMBER: /\d+(\.\d+)?/
    OP: "+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" | "<=" | ">="
    DELIM: "(" | ")" | "{" | "}" | ";" | ","
    %ignore WS
    WS: /[ \t\n]+/
    """
    parser = Lark(grammar, parser="lalr")
    data = "x = 10; y = x + 3.14;"
    tree = parser.parse(data)
    for token in tree.scan_values(lambda v: hasattr(v, 'type')):
        print(token.type, token.value)

def p2():
    grammar = r"""
    start: IDENTIFIER "=" NUMBER ";"
    IDENTIFIER: /[a-zA-Z_][a-zA-Z0-9_]*/
    NUMBER: /\d+/
    %ignore WS
    %ignore /\/\/.*/
    %ignore /\/\*[\s\S]*\*\//
    WS: /[ \t\n]+/
    """
    parser = Lark(grammar, parser="lalr")
    data = """
    // single line comment
    x = 10; 
    /* 
    multi-line comment 
    */
    """
    print(parser.parse(data))

def p3():
    grammar = r"""
    start: WORD+
    WORD: /[a-zA-Z_]+/
    %ignore WS
    WS: /[ \t\n]+/
    """
    parser = Lark(grammar, parser="lalr", propagate_positions=True)
    data = "hello world\ncompiler lab"
    tree = parser.parse(data)
    for token in tree.scan_values(lambda v: isinstance(v, Token)):
        print(f"{token.type} : {token.value} @ line {token.line}, column {token.column}")



def p4():
    grammar = r"""
    start: assignment+
    assignment: IDENTIFIER "=" NUMBER ";"
    IDENTIFIER: /[a-zA-Z_][a-zA-Z0-9_]*/
    NUMBER: /\d+/
    %ignore WS
    WS: /[ \t\n]+/
    """
    parser = Lark(grammar, parser="lalr")
    data = "x = 10 y = 20;" # missing semicolon
    try:
        parser.parse(data)
    except UnexpectedInput as e:
        print("Syntax Error at line", e.line, "column", e.column)
        print("Recovery: Assuming missing semicolon and continuing...")



def p5():
    grammar = r"""
    start: (IDENTIFIER | NUMBER | OPERATOR | KEYWORD)+
    IDENTIFIER: /[a-zA-Z_][a-zA-Z0-9_]*/
    NUMBER: /\d+(\.\d+)?/
    OPERATOR: "+" | "-" | "*" | "/" | "="
    KEYWORD: "int" | "float" | "if" | "else" | "while" | "return"
    %ignore WS
    WS: /[ \t\n]+/
    """
    parser = Lark(grammar, parser="lalr", propagate_positions=True)
    data = "int x = 10 x = x + 5 return x"
    tree = parser.parse(data)
    ids, nums, ops, keys = [], [], [], []
    for token in tree.scan_values(lambda v: isinstance(v, Token)):
        if token.type == "IDENTIFIER":
            ids.append(token.value)
        elif token.type == "NUMBER":
            nums.append(token.value)
        elif token.type == "OPERATOR":
            ops.append(token.value)
        elif token.type == "KEYWORD":
            keys.append(token.value)
    open("identifiers.txt", "w").write("\n".join(ids))
    open("numbers.txt", "w").write("\n".join(nums))
    open("operators.txt", "w").write("\n".join(ops))
    open("keywords.txt", "w").write("\n".join(keys))
    print("Identifier Frequency:", Counter(ids).total())
    print("Number Frequency:", Counter(nums).total())
    print("Operator Frequency:", Counter(ops).total())
    print("Keyword Frequency:", Counter(keys).total())


def main():
    p1()
    p2()
    p3()
    p4()
    p5()

main()