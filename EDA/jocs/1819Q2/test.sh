#/bin/bash
for i in {1..1000}; do
    echo $i
    ./Game -s $i  Dummy Dummy Dummy Dummy < default.cnf >& out.cnf; grep "got score" out.cnf > game.txt
    ./Game -s ${i+1}  Dummy Dummy Dummy Dummy < default.cnf >& out.cnf; grep "got score" out.cnf > sec-game.txt
    diff game.txt sec-game.txt
done