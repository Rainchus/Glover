def replace_lines_in_file(filename, replacements):
    print(f"Processing file: {filename}")
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            print(f"Read {len(lines)} lines from {filename}")
    except FileNotFoundError:
        print(f"Error: File {filename} not found.")
        return
    
    modified_lines = []
    match_found = False

    for line in lines:
        modified = False
        for pattern, replacement in replacements.items():
            if pattern in line:  # Use 'in' to check for the pattern in the line
                print(f"Match found: {line.strip()} -> {replacement}")
                modified_lines.append(replacement + "\n")
                modified = True
                match_found = True
                break
        if not modified:
            modified_lines.append(line)
    
    if match_found:
        with open(filename, 'w', encoding='utf-8') as file:
            file.writelines(modified_lines)
        print(f"Modifications written to {filename}")
    else:
        print(f"No matches found in {filename}")

if __name__ == "__main__":
    replacements = {
        "asm/2D5E0.s": {
            "/* 33934 80132934 04000577 */  bltz       $zero, .L80133F14": ".word 0x04000577",
        },
        "asm/11520.s": {
            "/* 1382C 8011282C 0A00CCA8 */  j          func_880332A0": ".word 0x0A00CCA8",
        }
    }
    
    for filename, patterns in replacements.items():
        replace_lines_in_file(filename, patterns)
    
    print("Replacement complete.")
