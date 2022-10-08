gnuplot -e plot "time.txt" using 2:1 with lines title "BST",\
"timesearch.txt" using 2:1 with lines title "RBT"
