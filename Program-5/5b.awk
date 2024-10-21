!/usr/bin/awk

BEGIN {
    no = 0
}

{
    line[++no] = $0  # Store each line in an array
}

END {
    for (i = 1; i <= no; i++) {
        flag = 1
        for (j = 1; j < i; j++) {
            if (line[i] == line[j]) {
                flag = 0  # Mark as duplicate
                break
            }
        }
        if (flag == 1) {
            print line[i] >> "out13a.txt"  # Print unique lines to the file
        }
    }
}

