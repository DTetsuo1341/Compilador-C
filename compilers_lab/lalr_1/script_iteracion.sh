#!/bin/bash
 
BINARY="./build/first_and_follow"
EXAMPLES_DIR="examples"
 
for grammar_dir in "$EXAMPLES_DIR"/*/; do
    # Find the single .txt grammar file in this folder
    grammar_file=$(find "$grammar_dir" -maxdepth 1 -name "*.txt" | head -n 1)
 
    if [[ -z "$grammar_file" ]]; then
        echo "[SKIP] No .txt found in $grammar_dir"
        continue
    fi
 
    echo "Grammar: $grammar_file"
 
    # Iterate over all input files (named input<N> or just input*)
    for input_file in "$grammar_dir"*.c; do
        [[ -f "$input_file" ]] || continue
 
        output_file="${grammar_dir}parseTable.json"
 
        echo "  Running: $BINARY $grammar_file $input_file $output_file"
        "$BINARY" "$grammar_file" "$input_file" "$output_file"
    done
done
 