#set term png
#set output "plot.png"
set xlabel "x"
set ylabel "y"
plot "data.txt" using 1:2 with points  title "data", \
     "ans.txt" using 1:2 with lines linecolor "red" title "function", \
     "res.txt" using 1:2 with lines linecolor "green" title "result"
pause -1