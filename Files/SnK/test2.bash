#!/bin/bash
echo "Namaste"

now="$(date)"
computer_name="$(hostname)"
working_dir="$(pwd)"

echo "Current date and time: $(date)"
echo "Computer name: $computer_name"
echo "Current Working directory is: $working_dir"
echo "The user is: $(whoami)"
