import ply.lex as lex

kw_file = open("keywords.txt", "w")
id_file = open("identifiers.txt", "w")
op_file = open("operators.txt", "w")
num_file = open("numbers.txt", "w")



tokens = (
    'ID',
    'NUMBER',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'ASSIGN',
)




t_ignore  = ' \t'


def t_COMMENT_SINGLE(t):
    r'//.*'
    pass


def t_COMMENT_MULTI(t):
    r"/\*[\s\S]*\*/"
    pass




t_PLUS    = r'\+'
t_MINUS   = r'-'
t_TIMES   = r'\*'
t_DIVIDE  = r'/'
t_ASSIGN  = r'='





def t_ID(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    if len(t.value) > 10:
        print(f"Error: Identifier too long '{t.value}' at line {t.lineno}")
        pass

    return t

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)    


    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Illegal character '{t.value[0]}' at line {t.lineno}, column {t.lexpos}")
    t.lexer.skip(1)

lexer = lex.lex()


data = """
x = 50 + y * 2  // comment hai

/* mmmm */

/*
 multiline comment hai
*/

 
ggdggfsfsdasdasdadfsfdgfdgfdfgf87


print(90)

"""
lexer.input(data)


while True:
    tok = lexer.token()
    if not tok:
        break      
    print(f"{tok.type:<10} | {tok.value:<10} | {tok.lexpos}")

    match tok.type :
        case "ID":
            id_file.write(tok.value + "\n")
        case "NUMBER":
            num_file.write(str(tok.value) + "\n")
        case "PLUS" | "MINUS" | "TIMES" | "DIVIDE":
            op_file.write(tok.value + "\n")
        case "ID":
            kw_file.write(tok.value + "\n")

kw_file.close()
num_file.close()
id_file.close()
op_file.close()