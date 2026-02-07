import re

def check_patterns(user_input):
    patterns = {
        "a*": r'^a*$',
        "a*b+": r'^a*b+$',
        "abb": r'^abb$'
    }
    
    matches = []
    
    for label, regex in patterns.items():
        if re.match(regex, user_input):
            matches.append(label)
            
    return matches


while True:
    text = input("Enter a string to test (or 'exit'): ").strip()
    if text.lower() == 'exit': break
    
    results = check_patterns(text)
    
    if results:
        print(f"Match found! String '{text}' matches: {', '.join(results)}")
    else:
        print(f"No match found for '{text}'.")