import re

valid_operators = {
    'arithmetic': ['+', '-', '*', '/', '%', '**', '//'],
    'comparison': ['==', '!=', '>', '<', '>=', '<='],
    'logical': ['and', 'or', 'not'],
    'assignment': ['=', '+=', '-=', '*=', '/=', '%=', '**=', '//='],
    'bitwise': ['&', '|', '^', '~', '<<', '>>']
}

def lexical_analyzer(source_code):
    valid_ops = []
    invalid_ops = []

    tokens = re.findall(r'\S+', source_code)

    for token in tokens:
        if token in [op for ops in valid_operators.values() for op in ops]:
            valid_ops.append(token)
        elif any(char in token for char in ''.join([op for ops in valid_operators.values() for op in ops])):
            invalid_ops.append(token)

    return valid_ops, invalid_ops

def main():
    with open('input.txt', 'r') as f:
        source_code = f.read()

    valid_ops, invalid_ops = lexical_analyzer(source_code)

    print("Valid Operators:")
    print(valid_ops)
    print("\nInvalid Operators:")
    print(invalid_ops)

main()