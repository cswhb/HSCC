sh run.sh
git add .
git commit -m "BFS 512KB 4*10^11 8GB"
git push 
cp ../double.cpp src/page-table/page_table.cpp
source env.sh
scons -c
scons -j16
sh run.sh
