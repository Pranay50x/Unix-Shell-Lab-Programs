!/usr/bin/awk -f
{
split($0, arr, "-") 
if (arr[1] < 1 || arr[1] > 31 || arr[2] < 1 || arr[2] > 12) {
    print "Invalid date"
    exit 0
    } 
else {
        print arr[1] 
        if (arr[2] == 1) print "Jan"
        else if (arr[2] == 2) print "Feb"
        else if (arr[2] == 3) print "March"
        else if (arr[2] == 4) print "April"
        else if (arr[2] == 5) print "May"
        else if (arr[2] == 6) print "Jun"
        else if (arr[2] == 7) print "Jul"
        else if (arr[2] == 8) print "Aug"
        else if (arr[2] == 9) print "Sep"
        else if (arr[2] == 10) print "Oct"
        else if (arr[2] == 11) print "Nov"
        else if (arr[2] == 12) print "Dec"
        print arr[3] 
    }
}