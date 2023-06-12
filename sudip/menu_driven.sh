#!/bin/bash

fetch_program() {
    folder="$1"
    echo "Available programs in $folder folder:"
    ls "$folder" | grep -oE 'q_[0-9]+\.sh' | cut -d'_' -f2 | cut -d'.' -f1 | sed 's/^/Question /'
    echo
    read -p "Enter the question number of the program you want to fetch: " question_number
    program="q_${question_number}.sh"
    if [[ -f "$folder/$program" ]]; then
        cp "$folder/$program" .
        chmod +x "$program"
        clear
        echo "Program $program fetched successfully."
        run_program "$program"
        rm "$program"
    else
        echo "Program $program not found."
    fi
    echo
    
}

run_program() {
    program="$1"
    
    if [[ -x "$program" ]]; then
        ./"$program"
    else
        echo "Program $program not found or not executable."
    fi
    echo
}

while true; do
    echo "MENU:"
    echo "1. Fetch a program from SET 1"
    echo "2. Fetch a program from SET 2"
    echo "3. Fetch a program from SET 3"
    echo "4. Exit"
    echo
    read -p "Enter your choice (1-4): " choice
    echo

    case $choice in
        1)
            fetch_program "set-1"
            ;;
        2)
            fetch_program "set-2"
            ;;
        3)
            fetch_program "set-3"
            ;;
        4)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            echo
            ;;
    esac
done